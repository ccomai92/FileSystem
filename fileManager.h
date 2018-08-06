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

    bool CreateFile(string fileName, int blockNum);
    bool AddBlock(string fileName, int blockNum); 
    bool DeleteFile(string fileName); 
    bool DeleteBlock(string fileName, int blockNum); 
    

private: 
    vector<INode*> iNodes; 
    vector<DiskDir*> dirs; 
    FileDisk* disk;     
    int artificialID;
}; 