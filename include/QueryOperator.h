#ifndef QUERYOPERATOR_H
#define QUERYOPERATOR_H

#include <Query.h>
#include <string>

class QueryOperator : public Query
{
    private:

    public:
        QueryOperator();
        QueryOperator(const string &str);
        virtual ~QueryOperator();
    protected:

};

#endif // QUERYOPERATOR_H
