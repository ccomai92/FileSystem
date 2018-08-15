#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string> 
#include <iostream> 
#include <vector> 
#include <map> 
#include "iNode.h"


using namespace std; 

class FileManager {
public: 
    FileManager(); 
    ~FileManager(); 

    bool CreateFile(string fileName, int blockNum);
    bool AddBlock(string fileName, int blockNum); 
    bool DeleteFile(string fileName); 
    bool DeleteBlock(string fileName, int blockNum); 
    void dumpAll(); 
    void dump(); 

private: 

    struct DiskDir {
        int iNodeID = -1;
        int size; 
        // string fileName; 
    };

    map<int, INode*> iNodes; 
    map<string, DiskDir*> dirs; 
    FileDisk* disk;     
    int artificialID;
}; 
#endif