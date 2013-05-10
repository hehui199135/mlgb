#include "QueryProcessor.h"

QueryProcessor::QueryProcessor()
{
    //ctor
}


QueryProcessor::QueryProcessor(const string &path):index(path)
{

}

bool QueryProcessor::isStopWord(const string &str)
{
    string stopWord = "a,able,about,across,after,all,almost,also,am,among,an,any,are,as,at,be,because,been,but,by,can,cannot,could,dear,did,do,does,either,else,ever,every,for,from,get,got,had,has,have,he,her,hers,him,his,how,however,i,if,in,into,is,it,its,just,least,let,like,likely,may,me,might,most,must,my,neither,no,nor,not,of,off,often,on,only,other,our,own,rather,said,say,says,she,should,since,so,some,than,that,the,their,them,then,there,these,they,this,tis,to,too,twas,us,wants,was,we,were,what,when,where,which,while,who,whom,why,will,with,would,yet,you,your";
    if(stopWord.find(str) == string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool QueryProcessor::searchQuery()
{
    cout << "please enter the query:";
    string str;
    getline(cin,str);
    transform(str.begin(),str.end(),str.begin(),::tolower);
    if (str == "q")
    {
        return false;
    }
    istringstream istr(str);
    while(!istr.eof())
    {
        string t;
        istr >> t;

        if(!isStopWord(t))
        {
            Query *p = new Query(t);
            querySet.push_back(p);
        }

    }
    return true;
}


void QueryProcessor::analyzeQuery(const vector<Query*> querySet)
{

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




Query* QueryProcessor::andOperation(Query *left, Query *right)
{
    //map<int,pair<vector<int>,vector<int> > > l,f;
    vector<int> l,r;
    //THIS IS A TEMPORARY SOLUTION maybe bool maybe use skip pointer
    for(vector<wordPos*>::iterator it = *index.(left);it != index.end();it++)
    {

        l.push_back(it->fileId);
    }
    for(vector<wordPos*>::iterator it = *index.(right);it != index.end();it++)
    {

        r.push_back(it->fileID);
    }


    vector<int> sameFileID

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
















///AKA parser don't know how to do



/*
void QueryProcessor::getResult()
{
    vector<string>* queryWords = query.getQueryWords();
    Query::QueryMode mode = query.getMode();
    //to be continued

}*/

//void



























QueryProcessor::~QueryProcessor()
{
    //dtor
}
