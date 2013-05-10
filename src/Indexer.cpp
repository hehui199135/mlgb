#include "../include/Indexer.h"

Indexer::Indexer()
{
    //ctor
}


Indexer::~Indexer()
{
    //dtor
}

Indexer::Indexer(const string &path)
{
    this->path = path;
    scanFile();
}

void Indexer::scanFile()
{
    try
    {
        boost::filesystem::path p(this->path);
        boost::filesystem::recursive_directory_iterator iter(p);
        boost::filesystem::recursive_directory_iterator end;
        int fileID=0;
        for (; iter != end; ++iter)
        {
            if(boost::filesystem::is_regular_file(*iter))
            {
                generateIndex(iter->path(),fileID);
                fileID++;
            }

        }
    }
    catch(boost::filesystem::filesystem_error)
    {
        cout << "Error: such folder";
    }
}

void Indexer::delPunct(string &str)
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


void Indexer::generateIndex(const boost::filesystem::path &path,int id)
{
    ifstream inFile(path.c_str());
    string temp;
    int fileid = id;
    int pos = 0;

    while(inFile >> temp)
    {
        delPunct(temp);
        wordPos *t= new wordPos(fileid,pos);
        invertedIndex[temp].push_back(t);
        pos++;
    }
    fileIndex.push_back( new FileInfo(id,path.branch_path().string(),path.leaf().string(),pos));
}



void Indexer::printCollection()
{
    for(vector<FileInfo*>::iterator it = fileIndex.begin(); it != fileIndex.end(); it++)
    {
        cout << (*it)->getPath() <<"/"<< (*it)->getName() << endl;
    }
}


void Indexer::printIndex()
{
    for(unordered_map<string,vector<wordPos*>>::iterator mapit = invertedIndex.begin(); mapit != invertedIndex.end(); mapit++)
    {
        cout << mapit->first << ":" << endl;
        for (vector<wordPos*>::iterator vecit = (mapit->second).begin(); vecit != (mapit->second).end(); vecit++)
        {
            cout << "   fileid:" << (*vecit)->fileID << "pos:" << (*vecit)->position << endl;
        }
        cout << endl;
    }
}

vector<wordPos*>* Indexer::locate(const string word)
{
    return &invertedIndex[word];
}

FileInfo* Indexer::getFileInfo(int id)
{
    return fileIndex[id];
}








