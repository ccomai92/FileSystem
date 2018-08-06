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
    
    CreateFile(string fileName, int numBlocks);
    AddFile(string fileName, int numBlocks);
    DeleteFile(string fileName);
    DeleteBlocks(string fileName, int numBlocks);

private: 
    vector<INode*> iNodes; 
    vector<DiskDir*> dirs; 
    FileDisk* disk;     
    int artificialID; 
}; 