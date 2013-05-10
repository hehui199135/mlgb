#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H

#include <cctype>
#include <unordered_map>
#include <string>
#include <vector>
#include "Indexer.h"
#include "Query.h"
class Indexer;
class QueryProcessor
{
private:
    string path;
    Query query;
    Indexer index;
    vector<Query*> querySet;
    bool isStopWord(const string &str);
public:
    QueryProcessor();
    QueryProcessor(const string &path);
    bool searchQuery();
    //void getResult(); aka excute
    void analyzeQuery(const vector<Query*> querySet);

    Query* andOperation(Query *left, Query *right);
    Query* spaceOperation(Query *left, Query *right);
    Query* orOperation(Query *left, Query *right);



    virtual ~QueryProcessor();
protected:

};

#endif // QUERYPROCESSOR_H
