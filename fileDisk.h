#include <block.h> 

class FileDisk {
public: 
    FileDisk(); 
    ~FileDisk() {
        for (int i = 0; i < 1000; i++) {
            delete disk[i];
        }
    } 
private: 
    Block* disk[1000]; 
}; 