#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H

#include "Index.h"


class InvertedIndex : public Index
{
    public:
        InvertedIndex();
        void generateIndex();
        virtual ~InvertedIndex();
    protected:
    private:
};

#endif // INVERTEDINDEX_H
