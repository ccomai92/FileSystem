#include <time.h> 
#include <vector> 
#include <iostream> 
#include "fileDisk.h" 

using namespace std; 
const int MAX_BLOCK = 10; 

class INode {
public: 
    INode();  
    INode(char mode); 
    ~INode(); // erase contents before deleted

    bool addBlock(int numBlocks, FileDisk* disk); 
    bool deleteBlock(int numBlocks, FileDisk* disk); 
private: 
    void update(); 
       
    char mode; // file or directory 
    unsigned int uid; // user group
    unsigned int gid; // global user

    time_t aTime; // use with time(&rawtime); 
    time_t cTime; // time creating 
    time_t mTime; // modified time 
    int size;   // file Size 
    int blockCount; 
    Block* directBlocks[MAX_BLOCK]; 
    Block* firstIndirectB; 
    Block* secondIndirectB; 
    Block* thirdIndirectB; 

}; 