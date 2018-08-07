#include "block.h" 

class FileDisk {
public: 
    FileDisk(); 
    ~FileDisk() {
        for (int i = 0; i < 1000; i++) {
            delete disk[i];
        }
    } 

    bool findBlocks(int numBlocks, vector<Block*>& blocks); 

private: 
    Block* disk[1000]; 
}; 