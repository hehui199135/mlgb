#include "../include/FileIndex.h"

FileIndex::FileIndex()
{
    //ctor
}

FileIndex::FileIndex(const Collection& collextion)
{
    this->collection = collection;

}

FileIndex::~FileIndex()
{
    //dtor
}

void FileIndex::generateIndex()
{
    vector<FileInfo*> fileCollection = collection.getFileCollection();



}
