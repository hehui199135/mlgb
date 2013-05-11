#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H

#include <cctype>
#include <unordered_map>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include "Indexer.h"
#include "Query.h"
#include "QueryOperator.h"
class Indexer;
class QueryProcessor
{
private:
    string path;
    Indexer index;
    vector<Query*>* p_querySet;
    bool isStopWord(const string &str);
    void trim(string &str);
public:
    QueryProcessor();
    QueryProcessor(const string &path);
    bool searchQuery();
    //void getResult(); aka excute
    bool translate(const string &str);  // translate the query line to Queries;
    void print (map<int,vector<int> > &result);
    void singleQuery();  //const vector<Query*> querySet?
    void complexQuery(); //const vector<Query*> querySet?
    bool isOperator(const Query *query);

    Query* andOperation(const Query &left,const Query &right);
    Query* spaceOperation(const Query &left,const Query &right);
    Query* orOperation(const Query &left,const Query &right);



    virtual ~QueryProcessor();
protected:

};

#endif // QUERYPROCESSOR_H
