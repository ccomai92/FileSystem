#include <string> 
#include <vector>
using namespace std; 

const int BLOCK_SIZE = 512; // 512 K 
// I think we need to consider this block
// as a place holder for the disk if it is there. 
class Block {
public: 
    Block();
    ~Block();

    void erase(); 
    bool addBlock(vector<Block*> &blocks); 
private: 
    vector<int> index; // for indirect blocks 
    string contents; 

    
}; 