#include <time.h> 
#include "block.h"


class INode {
public: 
    INode(); 
    INode(int iNodeID, int numBlocks, Block *blocks[]) {
        this->iNodeID = iNodeID;
        this->blockCount = numBlocks;
        this->size = numBlocks;
        this->addBlock(numBlocks, blocks);
        this->cTime = time(0);
        

    }

    INode(char mode, unsigned int uid, unsigned int gid, 
            time_t aTime, time_t cTime, time_t mTime, 
            int size, int blockCount); 
    ~INode(); 

    bool addBlock(int numBlocks, Block *blocks[]) {
        int availableSize = 10 - this->size;
        int leftOver = numBlocks - availableSize;
        this->aTime = time(0);

        for (int i = 0; i < availableSize; i++) {
            directBlocks[this->size++] = blocks[i];
        }

        if (leftOver > 0) {
            for (int i = 0; i < leftOver; i++) {
            
            }
        }
        this->mTime = time(0);
        return true;
    }
    
    int getiNodeID() {
        return this->iNodeID;
    }


private: 
    int iNodeID;
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