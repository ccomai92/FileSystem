#include <time.h> 
#include <vector> 
#include "fileDisk.h" 

using namespace std; 

class INode {
public: 
    INode();  
    ~INode(); // erase contents before deleted

    bool addBlock(int numBlocks, FileDisk* disk); 
    bool deleteBlock(int numBlocks, FileDisk* disk); 
private: 
       
    char mode; // file or directory 
    unsigned int uid; // user group
    unsigned int gid; // global user

    time_t aTime; // use with time(&rawtime); 
    time_t cTime; // time creating 
    time_t mTime; // modified time 
    int size;   // file Size 
    int blockCount; 
    Block* directBlocks[10]; 
    Block* firstIndirectB; 
    Block* secondIndirectB; 
    Block* thirdIndirectB; 

}; 