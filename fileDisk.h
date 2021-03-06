#ifndef FILE_DISK_H
#define FILE_DISK_H
#include "block.h" 
#include <iostream>

using namespace std; 

const int MAX_NUM_BLOCK = 1000; 

class FileDisk {
public: 
    FileDisk(); 
    ~FileDisk(); 

    bool findBlocks(int numBlocks, vector<Block*>& blocks); 
    void dump(); 


private: 
    Block* disk[MAX_NUM_BLOCK]; 
    int blocksLeft; 
}; 

#endif