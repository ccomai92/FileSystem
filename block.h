#ifndef BLOCK_H
#define BLOCK_H

#include <string> 
#include <vector>
using namespace std; 

const int BLOCK_SIZE = 524288; //bytes = 512 K 
// I think we need to consider this block
// as a place holder for the disk if it is there. 
class Block {
public: 
    Block();
    ~Block();

    bool isEmpty();

    bool write(string contents); 
    void erase(); 
private: 
    vector<int> index; // for indirect blocks 
    string contents; 

    
}; 
#endif