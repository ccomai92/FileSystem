#include "iNode.h"

INode::INode(): cTime(time(0)), aTime(time(0)), mTime(time(0)), 
                size(0), mode('f'), blockCount(0), 
                firstIndirectB(nullptr), secondIndirectB(nullptr),
                thirdIndirectB(nullptr) {
    for (int i = 0; i < MAX_BLOCK; i++) {
        this->directBlocks[i] = nullptr;
    }
}

INode::INode(char mode): cTime(time(0)), aTime(time(0)), mTime(time(0)), 
                size(0), mode(mode), blockCount(0), 
                firstIndirectB(nullptr), secondIndirectB(nullptr),
                thirdIndirectB(nullptr) {
    for (int i = 0; i < MAX_BLOCK; i++) {
        this->directBlocks[i] = nullptr;
    }
}

INode::~INode() {
    // erase contents in the blocks 
    this->firstIndirectB->erase(); 
    this->secondIndirectB->erase(); 
    this->thirdIndirectB->erase(); 
    
    for (int i = 0; i < MAX_BLOCK; i++) {
        this->directBlocks[i]->erase();     
    }

}


bool INode::addBlock(int numBlocks, FileDisk* disk) {
    vector<Block*> blocks (numBlocks); 
    if (!(disk->findBlocks(numBlocks, blocks))) {
        cerr << "Disk is full" << endl; 
        return false;
    } 
    
    int potentialCount = this->blockCount + numBlocks; 

    if (potentialCount <= MAX_BLOCK) { // 10 
        for (int i = blockCount; i < potentialCount; i++) {
            this->directBlocks[i] = blocks[i - blockCount]; 
        }
    } else { 
        cerr << "File size is too big" << endl; 
        return false; 
    }

    this->blockCount += numBlocks;
    this->update(); 
    
    return true;
}

bool INode::deleteBlock(int numBlocks, FileDisk* disk) {

}

void INode::update() { 
    this->aTime = time(0); 
    this->mTime = time(0); 
    this->size = 512 * this->blockCount; 
}