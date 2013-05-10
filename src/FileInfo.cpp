#include "../include/FileInfo.h"

FileInfo::FileInfo()
{
    //ctor
}

FileInfo::FileInfo(int id,const string &path,const string &name,const int length)
{
    this->id = id;
    this->name = name;
    this->path = path;
    this->length = length;

}

int FileInfo::getFileID()
{
    return id;
}

string FileInfo::getName()
{
    return name;
}

string FileInfo::getPath()
{
    return path;
}

void FileInfo::setLength(int length)
{
    this->length = length;
}


FileInfo::~FileInfo()
{
    //dtor
}
