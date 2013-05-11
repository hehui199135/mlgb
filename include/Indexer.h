#ifndef COLLECTION_H
#define COLLECTION_H

#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include "FileInfo.h"
#include "Query.h"
using namespace std;

struct wordPos
{
    int fileID;
    int position;
    wordPos(int f,int p)
    {
        fileID = f;
        position = p;
    }
};

class Indexer
{
private:
    string path;
    unordered_map<string,vector<wordPos*>> invertedIndex;
    vector<FileInfo*> fileIndex;
    void scanFile();
    void generateIndex(const boost::filesystem::path &path,int id);
    void delPunct(string &str);
public:
    Indexer();
    Indexer(const string& path);
    void printCollection();
    void printIndex();
    vector<wordPos*>* locate(const Query &query) ;
    FileInfo* getFileInfo(int id);
    virtual ~Indexer();
protected:

};

#endif // COLLECTION_H
