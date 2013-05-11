#include "QueryProcessor.h"

QueryProcessor::QueryProcessor()
{
    //ctor
}


QueryProcessor::QueryProcessor(const string &path):index(path)
{

}






bool QueryProcessor::searchQuery()
{
    p_querySet = new vector<Query*>;
    cout << "please enter the query:";

    //Query q("a");
    //index.locate(q);

    string str;
    getline(cin,str);
    trim(str);
    transform(str.begin(),str.end(),str.begin(),::tolower);
    if (str == "q")
    {
        delete p_querySet;
        return false;
    }

    if(str.find("and") == string::npos && str.find("or") == string::npos && str.find(" ") == string::npos)
    {
        if(!translate(str))
        {
            cout << "illegal search..." << endl;
            delete p_querySet;
            return true;
        }
        singleQuery();
    }
    else
    {
        translate(str);
        complexQuery();
    }
    delete p_querySet;
    return true;
}




bool QueryProcessor::translate(const string &str)
{
    stringstream istr(str);
    bool previous_is_operator = true;
    while(!istr.eof())
    {
        string t;
        istr >> t;

        if(!isStopWord(t))
        {
            if(!previous_is_operator)
            {
                Query *p_Space = new QueryOperator(" ");
                p_querySet->push_back(p_Space);
            }

            Query *p = new Query(t);
            p_querySet->push_back(p);

        }
        else if(t == "and" || t == "or")
        {
            Query *p = new QueryOperator(t);
            p_querySet->push_back(p);
            previous_is_operator = true;
        }
    }
    if(p_querySet->empty())
    {
        return false;
    }
    else
    {
        return true;
    }
}







void QueryProcessor::singleQuery()
{
    vector<wordPos*>* p_result;
    p_result = index.locate(*(*(p_querySet->begin())));
    map<int,vector<int> > result;
    for(vector<wordPos*>::iterator it = p_result->begin(); it != p_result->end();it ++)
    {
        result[(*it)->fileID].push_back((*it)->position);

    }



    print(result);
}
//=========================this is a temporary version of printer======
void QueryProcessor::print( map<int,vector<int> > &result)
{
   for(map<int,vector<int> >::iterator itm = result.begin(); itm != result.end();itm++)
   {
       cout << "In file " << index.getFileInfo(itm->first)->getName() <<": ";
       for(vector<int>::iterator itv = (itm->second).begin(); itv != (itm->second).end(); itv++ )
       {
           cout << *itv<<" ";
       }
       cout << endl;
   }

}

//=======================only for debugging==========================


bool QueryProcessor::isOperator(const Query *query)
{
    cout << typeid(*query).name();
    if(query->getQueryWords() == "and" ||query->getQueryWords() == "or" ||query->getQueryWords() == " "  )
    {
        cout << "FUCK!!!!!!!!!!!!!!!!!";
        return true;
    }
    else
    {
        return false;
    }

}




void QueryProcessor::complexQuery() //this is a parser
{

    Query *previousQuery = (*p_querySet)[0];
    Query *tempQueryOp;
    for(vector<Query*>::iterator it = (p_querySet->begin())+1;it != p_querySet->end();it++)
    {
       cout << (*it)->getQueryWords() << endl;
        if(!isOperator(*it))
        {
            cout << "what the fuck" << endl;
            if(tempQueryOp->getQueryWords() == "and")
            {
                previousQuery = andOperation(*previousQuery,*(*it));
                cout << "and found!";
            }
            else if(tempQueryOp->getQueryWords() == "or")
            {

            }
            else if(tempQueryOp->getQueryWords() == " ")
            {

            }




        }
        else
        {
            tempQueryOp = *it;
        }




    }






    //use stack
    /*while(!eof){
        cin >> str;
        push str to stack
        if ("()"occur or And occur)
        {
         left = stack.pop();
        Query newone = AndOperation(Query left,Query right);
        push newone to the stack
        }
    }*/
    //sholud look up the solution for 逆波兰 http://wenku.baidu.com/view/45c7afdfad51f01dc281f1ad
    //

}


Query* QueryProcessor::andOperation(const Query &left,const Query &right)
{


    Query *reutrnQuery = new Query(left.getQueryWords()+" AND "+ right.getQueryWords());

    //map<int,pair<vector<int>,vector<int> > > l,f;
    vector<int> l,r;
    //THIS IS A TEMPORARY SOLUTION maybe bool maybe use skip pointer
    for(vector<wordPos*>::iterator it = (index.locate(left.getQueryWords()))->begin();it != index.locate(left.getQueryWords())->end();it++)
    {
        l.push_back((*it)->fileID);
    }
    for(vector<wordPos*>::iterator it = index.locate(right.getQueryWords())->begin();it != index.locate(right.getQueryWords())->end();it++)
    {
        r.push_back((*it)->fileID);
    }
    vector<int> sameFileID;

    for (vector<int>::iterator itl = l.begin();itl != l.end();itl++)
    {
        for(vector<int>::iterator itr = r.begin();itr != r.end();itr++)
        {
            if(*itl == * itr)
            {
                sameFileID.push_back(*itl);
            }
        }
    }





    //think about what should be in Query
    //what if    XXX AND (XXX OR XXX)








    //---------------------------------------------Jeffery Ye---------------------------------------------
    /*query &query_operator::operator_and(query &l, query r)
{
    vector<word_position*> results;
    for (vector<word_position*>::iterator lit=l.results.begin(); lit!=l.results.end(); ++lit )
    {
        for (vector<word_position*>::iterator rit=r.results.begin(); rit!=r.results.end(); ++rit )
        {
            if ((*lit)->document_name == (*rit)->document_name)
            {
                results.push_back(*lit);
                results.push_back(*rit);
                //do this temporarily....
            }
        }
    }

    l.words=l.words+" AND "+r.words;
    l.results=results;
    return l;
}
    */
//----------------------------------------------------end---------------------------------------------------------------
}
















///AKA excute don't know how to do
////may be done.This should be the same as search query...

/*
void QueryProcessor::getResult()
{
    vector<string>* queryWords = query.getQueryWords();
    Query::QueryMode mode = query.getMode();
    //to be continued

}*/



















//=======================function below is about string handling============

bool QueryProcessor::isStopWord(const string &str)
{
    static set<string> stopWord = {"and","or","a","able","about","across","after","all","almost","also","am","among","an","any","are","as","at","be","because","been","but","by","can","cannot","could","dear","did","do","does","either","else","ever","every","for","from","get","got","had","has","have","he","her","hers","him","his","how","however","i","if","in","into","is","it","its","just","least","let","like","likely","may","me","might","most","must","my","neither","no","nor","not","of","off","often","on","only","other","our","own","rather","said","say","says","she","should","since","so","some","than","that","the","their","them","then","there","these","they","this","tis","to","too","twas","us","wants","was","we","were","what","when","where","which","while","who","whom","why","will","with","would","yet","you","your"};
    if(stopWord.find(str) == stopWord.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

void QueryProcessor::trim(string &str)
{
   str.erase(str.begin(), std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
   str.erase(std::find_if(str.rbegin(), str.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());
//!!!!!!!!!!!!!!!!!!!!!!!!!!need to be examined;
}

//========================================================================

QueryProcessor::~QueryProcessor()
{
    //dtor
}
