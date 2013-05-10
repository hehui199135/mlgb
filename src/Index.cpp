#include "../include/Index.h"

Index::Index()
{
    //ctor
}

Index::Index(const Collection &collection):collection(collection)
{
    fileIndex = collection.getFileCollection();
}


Index::~Index()
{
    //dtor
}


void Index::delPunct(string &str)
{
    for(string::iterator it = str.begin(); it != str.end();)
    {
        if(ispunct(*it))
        {
            if((*it == '-') && str.size() != 1)
            {
                it++;
            }
            else
            {
                it = str.erase(it);
            }
        }
        else
        {
            *it = tolower(*it);
            it++;
        }
    }
}


void Index::generateIndex()
{

    for(vector<FileInfo*>::iterator it = fileIndex.begin(); it != fileIndex.end();it++)
    {
        string file = (*it)->getFilePath()+"/"+(*it)->getFileName();
        ifstream inFile(file.c_str());
        string temp;
        int fileid = (*it)->getFileID();
        int pos = 0;
        while(inFile >> temp)
        {
            delPunct(temp);
            /*FilePos f = {fileid,pos};
            FilePos *fp = &f;
            invertedIndex[temp].push_back(fp);*/


            //cout << temp << " ";
            invertedIndex[temp][fileid].insert(pos);
            pos++;
        }
//        (*it)->setLength(pos+1);


    }


}


void Index::printIndex()
{
    /*for(vector<string>::iterator it = wordList.begin(); it != wordList.end(); it++)
    {
        invertedIndex[word]
    }
    */
    int c= 0;
    //for(unordered_map<string,vector<FilePos *> >::iterator wordit = invertedIndex.begin();wordit != invertedIndex.end();wordit++)

    for (unordered_map<string, unordered_map<int,set<int> > >::iterator wordit = invertedIndex.begin();wordit != invertedIndex.end();wordit++)

    {
        cout << wordit->first<< endl;
        c++;
    }
    cout << c;

}
