#include "block.h"

Block::Block(): contents("") {}

Block::~Block() {}

bool Block::isEmpty() {
    return contents == ""; 
}

bool Block::write(string contents) {
    this->contents = contents; 
}

void Block::erase() {
    this->contents=""; 
}