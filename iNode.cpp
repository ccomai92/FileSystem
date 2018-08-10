#include "iNode.h"

INode::INode(): mode("-rwxr--r--"), uid("CSS430"), gid("CSS430"),
                cTime(time(0)), aTime(time(0)), mTime(time(0)), 
                size(0), blockCount(0), 
                firstIndirectB(nullptr), secondIndirectB(nullptr),
                thirdIndirectB(nullptr) {
    for (int i = 0; i < MAX_BLOCK; i++) {
        this->directBlocks[i] = nullptr;
    }
}

INode::INode(string mode): mode(mode), uid("CSS430"), gid("CSS430"), 
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
    if (this->firstIndirectB != nullptr) {
        this->firstIndirectB->erase(); 
        this->firstIndirectB = nullptr; 
    }

    if (this->secondIndirectB != nullptr) {
        this->secondIndirectB->erase(); 
        this->secondIndirectB = nullptr; 
    }

    if (this->thirdIndirectB != nullptr) {
        this->thirdIndirectB->erase(); 
        this->thirdIndirectB = nullptr; 
    }
    
    for (int i = 0; i < MAX_BLOCK; i++) {
        if (this->directBlocks[i] != nullptr) {
            this->directBlocks[i]->erase();
            this->directBlocks[i] = nullptr; 
        }
    }

}

string INode::getType() {
    return this->mode; 
}

string INode::getUID() {
    return this->uid;
}

string INode::getGID() {
    return this->gid;
}

int INode::getSize() {
    return this->size; 
}

// reference: 
// https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string INode::currentDateTime() {
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&this->aTime);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}


bool INode::addBlock(int numBlocks, FileDisk* disk) {
    vector<Block*> blocks; 
    if (!(disk->findBlocks(numBlocks, blocks))) {
        return false;
    } 
    
    int potentialCount = this->blockCount + numBlocks; 

    if (potentialCount <= MAX_BLOCK) { // 10 
        for (int i = this->blockCount; i < potentialCount; i++) {
            this->directBlocks[i] = blocks[i - blockCount]; 
        } 
    } else { 
        cerr << "File size is too big" << endl; 
        return false; 
    }

    // this->dump(); 
    this->blockCount += numBlocks;
    this->update(); 
    
    return true;
}

bool INode::deleteBlock(int numBlocks, FileDisk* disk) {
    if (this->blockCount < numBlocks) {
        cerr << "Illegal argument exception the file is smaller" << endl; 
        return false; 
    }

    // this->dump(); 
 
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
    this->size = 524288 * this->blockCount; // 512K in bytes 
}

void INode::dump() {
    for (int i = 0; i < this->blockCount; i++) {
        cout << "Block Index = " << i << ": "
            << this->directBlocks[i]->isEmpty() << endl; 
    }

}