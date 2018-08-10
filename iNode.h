#ifndef INode_H
#define INode_H 

#include <time.h> 
#include <vector> 
#include <iostream> 
#include <string>
#include "fileDisk.h"  

using namespace std; 
const int MAX_BLOCK = 10; 

class INode {
public: 
    INode();  
    INode(string mode); 
    ~INode(); // erase contents before deleted

    bool addBlock(int numBlocks, FileDisk* disk); 
    bool deleteBlock(int numBlocks, FileDisk* disk); 
private: 
    void update(); 
    void dump(); 
       
    string mode; // file or directory 
    string uid; // user group
    string gid; // global user

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

#endif 