#include "Query.h"

Query::Query()
{
    //ctor
}

Query::Query(const string &queryWords)
{
    this->queryWords = queryWords;
}

string Query::getQueryWords() const
{
    return queryWords;
}















Query::~Query()
{
    //dtor
}









