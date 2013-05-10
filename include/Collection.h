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
using namespace std;

struct wordPos
{
    int fileID;
    int position;
    wordPos(int f,int   p)
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
public:
    Indexer();
    Indexer(const string& path);
    bool buildCollection();

    void printCollection();
    void delPunct(string &str);
    void generateIndex(const boost::filesystem::path &path,int id);
    void printIndex();

    virtual ~Indexer();
protected:

};

#endif // COLLECTION_H
