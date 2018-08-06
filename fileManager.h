#include <string> 
#include <iostream> 
#include <vector> 
#include "iNode.h"
#include "fileDisk.h"

using namespace std; 

struct DiskDir {
    int iNodeID;
    int size; 
    string fileName; 
};

class FileManager {
public: 
    FileManager(); 
    ~FileManager(); 

    bool createFile(string fileName, int blockNum); 
    bool addBlock(string fileName, int blockNum); 
    bool deleteFile(string fileName); 
    bool deleteBlock(string fileName, int blockNum); 
    

private: 
    vector<INode*> iNodes; 
    vector<DiskDir*> dirs; 
    FileDisk* disk;     
    int artificialID; 
}; 