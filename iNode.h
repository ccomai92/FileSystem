#include <time.h> 
#include <block.h>

class INode {
public: 
    INode(); 
    INode(int numBlocks, Block *blocks[]) {
        this->blockCount = numBlocks;
        this->size = numBlocks;
        for (int i = 0; i < numBlocks; i++) {
            directBlocks[i] = blocks[i];
        }
    }

    INode(char mode, unsigned int uid, unsigned int gid, 
            time_t aTime, time_t cTime, time_t mTime, 
            int size, int blockCount); 
    ~INode(); 

    void addBlock(int numBlocks, Block *blocks[]) {
        int availableSize = 10 - this->size;
        int leftOver = numBlocks - availableSize;

        for (int i = 0; i < availableSize; i++) {
            directBlocks[this->size++] = blocks[i];
        }

        if (leftOver > 0) {
            for (int i = 0; i < leftOver; i++) {
            
            }
        }
    }
    

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