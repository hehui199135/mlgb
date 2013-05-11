#ifndef QUERY_H
#define QUERY_H
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
class Query
{
private:
    unordered_map<int,unordered_map<string,vector<int>>*> result; // to be modified
    string queryWords;
public:

    Query();
    Query(const string &queryWords);

    string getQueryWords() const;

    virtual ~Query();


};

#endif // QUERY_H
