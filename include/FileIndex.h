#ifndef FILEINDEX_H
#define FILEINDEX_H

#include "Index.h"
#include "Collection.h"


class FileIndex : public Index
{
    private:
        int length;
        Collection collection;

    public:
        FileIndex();
        FileIndex(const Collection &collection);
        void generateIndex();
        virtual ~FileIndex();
    protected:

};

#endif // FILEINDEX_H
