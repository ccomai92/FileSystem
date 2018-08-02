#include <block.h> 

class FileDisk {
public: 
    FileDisk(); 
    ~FileDisk(); 
private: 
    Block* disk[1000]; 
}; 