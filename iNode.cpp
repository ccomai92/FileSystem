#include "iNode.h"

INode::INode() {}

INode::INode(): cTime(time(0)), aTime(time(0)), mTime(time(0)), 
                size(0) {

}

INode::~INode() {
    // erase contents in the blocks 

}


bool INode::addBlock(int numBlocks, FileDisk* disk) {
    vector<Block*> blocks (numBlocks); 
    if (!(disk->findBlocks(numBlocks, blocks))) {
        return false;
    } 
    
    /*int availableSize = 10 - this->size;
    int leftOver = numBlocks - availableSize;
    this->aTime = time(0);

        for (int i = 0; i < availableSize; i++) {
            directBlocks[this->size++] = blocks[i];
        }

        if (leftOver > 0) {
            for (int i = 0; i < leftOver; i++) {
            
            }
        }
        this->mTime = time(0);*/ 
        return true;
}

bool INode::deleteBlock(int numBlocks, FileDisk* disk) {
    
}