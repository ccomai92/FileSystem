#include "iNode.h"

INode::INode(): mode('f'), uid("CSS430"), gid("CSS430"),
                cTime(time(0)), aTime(time(0)), mTime(time(0)), 
                size(0), blockCount(0), 
                firstIndirectB(nullptr), secondIndirectB(nullptr),
                thirdIndirectB(nullptr) {
    for (int i = 0; i < MAX_BLOCK; i++) {
        this->directBlocks[i] = nullptr;
    }
}

INode::INode(char mode): mode(mode), uid("CSS430"), gid("CSS430"), 
                cTime(time(0)), aTime(time(0)), mTime(time(0)), 
                size(0), blockCount(0), 
                firstIndirectB(nullptr), secondIndirectB(nullptr),
                thirdIndirectB(nullptr) {
    for (int i = 0; i < MAX_BLOCK; i++) {
        this->directBlocks[i] = nullptr;
    }
}

INode::~INode() {
    // erase contents in the blocks 
    this->firstIndirectB->erase(); 
    this->firstIndirectB = nullptr; 
    this->secondIndirectB->erase(); 
    this->secondIndirectB = nullptr; 
    this->thirdIndirectB->erase(); 
    this->thirdIndirectB = nullptr; 
    
    for (int i = 0; i < MAX_BLOCK; i++) {
        this->directBlocks[i]->erase();     
    }

}


bool INode::addBlock(int numBlocks, FileDisk* disk) {
    vector<Block*> blocks (numBlocks); 
    if (!(disk->findBlocks(numBlocks, blocks))) {
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
    if (this->blockCount < numBlocks) {
        cerr << "Illegal argument exception the file is smaller" << endl; 
        return false; 
    }

    for (int i = 0; i < numBlocks; i++) {
        int currentIndex = this->blockCount - 1 - i; 
        this->directBlocks[currentIndex]->erase(); 
        this->directBlocks[currentIndex] = nullptr; 
    }

    this->blockCount -= numBlocks; 
    this->update(); 
    return true; 
}

void INode::update() { 
    this->aTime = time(0); 
    this->mTime = time(0); 
    this->size = 512 * this->blockCount; 
}