#include "fileDisk.h"

FileDisk::FileDisk(): blocksLeft(MAX_NUM_BLOCK) {
    for (int i = 0; i < MAX_NUM_BLOCK; i++) {
        this->disk[i] = new Block(); 
    }
}

FileDisk::~FileDisk() {
    for (int i = 0; i < MAX_NUM_BLOCK; i++) {
        delete this->disk[i]; 
        this->disk[i] = nullptr; 
    }
}

bool FileDisk::findBlocks(int numBlocks, vector<Block*>& blocks) {
    if (this->blocksLeft < numBlocks) {
        cerr << "Disk is full " << endl; 
        return false;
    }
    
    for (int i = 0; i < MAX_NUM_BLOCK; i++) {
        if (blocks.size() == numBlocks) {
            return true; 
        }
        Block* current = this->disk[i]; 
        if (current->isEmpty()) {
            current->write("occupied"); 
            blocks.push_back(current); 
        }
    }
    if (blocks.size() == numBlocks) {
        return true; 
    }
    return false; 
}

void FileDisk::dump() {
    Block* block = this->disk[0]; 
    cout << "["; 
    if (block->isEmpty()) {
        cout << "1"; 
    } else {
        cout << "0"; 
    }

    for (int i = 1; i < MAX_NUM_BLOCK; i++) {
        block = this->disk[i];
        if (block->isEmpty()) {
            cout << ", 1"; 
        } else {
            cout << ", 0";
        }
    }

    cout << "]" << endl; 
}