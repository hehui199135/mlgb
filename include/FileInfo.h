#ifndef FILEINFO_H
#define FILEINFO_H

#include <string>
using namespace std;

class FileInfo
{
private:
    int id;
    string path;
    string name;
    int length;
public:
    FileInfo();
    FileInfo(int id,const string &path,const string &name,int length);

    int getFileID();
    string getPath();
    string getName();
    void setLength(int length);
    virtual ~FileInfo();
protected:

};

#endif // FILEINFO_H
