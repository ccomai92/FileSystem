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
    

private: 
    vector<INode*> iNodes; 
    vector<DiskDir*> dirs; 
    FileDisk* disk;     
    int artificialID; 
}; 