#include <time.h> 
#include <block.h>

class INode {
public: 
    INode(); 
    //
    INode
    INode(char mode, unsigned int uid, unsigned int gid, 
            time_t aTime, time_t cTime, time_t mTime, 
            int size, int blockCount); 
    ~INode(); 

    

private: 
    char mode; // file or directory 
    unsigned int uid; // user group
    unsigned int gid; // global user

    time_t aTime; // use with time(&rawtime); 
    time_t cTime; // time creating 
    time_t mTime; // modified time 
    int size;   // file Size 
    int blockCount; 
    int directBlocks[10]; 
    Block* firstIndirectB; 
    Block* secondIndirectB; 
    Block* thirdIndirectB; 

}; 