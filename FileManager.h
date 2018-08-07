#include <string> 
#include <iostream> 
#include <vector> 
#include <map> 
#include "iNode.h"
#include "fileDisk.h"


using namespace std; 

class FileManager {
public: 
    FileManager(); 
    ~FileManager(); 

    bool CreateFile(string fileName, int blockNum);
    bool AddBlock(string fileName, int blockNum); 
    bool DeleteFile(string fileName); 
    bool DeleteBlock(string fileName, int blockNum); 
    

private: 

    struct DiskDir {
        int iNodeID;
        int size; 
        // string fileName; 
    };

    map<int, INode*> iNodes; 
    map<string, DiskDir*> dirs; 
    FileDisk* disk;     
    int artificialID;

    /*
    DiskDir* search(string fileName) {
        int size_ = dirs.size();
        for (int i = 0; i < size_; i++) {
            if (this->dirs[i]->fileName == fileName) {
                return this->dirs[i];
            }
        }
        return NULL;
    }

    INode* search(int INodeID) {
        int size_ = iNodes.size();
        for (int i = 0; i < size_; i++) {
            if (this->iNodes[i]->getiNodeID() == INodeID) {
                return this->iNodes[i];
            }
        }
        return NULL;
    }*/
}; 