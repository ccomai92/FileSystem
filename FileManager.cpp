#include "FileManager.h"

FileManager::FileManager() {

}


FileManager::~FileManager() {}


bool FileManager::CreateFile(string fileName, int numBlocks) {
    // create new INode
    //  if diskDir.contains(file)
    //        return false;

    DiskDir *diskDir = new DiskDir{artificialID++, numBlocks, fileName};
    this->dirs.push_back(diskDir);   
    // find diskblokcs from disk 
    Block *blocks[numBlocks]; // = find available blocks and parameter is num of blocks and returns address of the blocks/
    INode *iNode_ = new INode(artificialID++, numBlocks, blocks);
    
    // put these disk blocks into the iNode
    // Make Time Stamp for 3 of all times
    
}
    
bool FileManager::AddBlock(string fileName, int numBlocks) {
    DiskDir *temp = this->search(fileName);
    if (temp == NULL) {
        return false;
    }
    Block *blocks[numBlocks]; // = find available blocks and parameter is num of blocks and returns address of the blocks/
    INode *tempINode = this->search(temp->iNodeID);

    if (tempINode == NULL) {
        return false;
    }
    
    if (tempINode->addBlock(numBlocks, blocks)) {
        return true;
    }
    return false;


    
    // check if fileName exists or not
    // if not return false:
    // if yes:
    /*
        
        find filename from disk directory 
        go into that iNode 

        check the size of array of blocks
        while size of array of blocks is less 11:
            just add block to the array

        if oversiezed :
            move to indirect array 
        modify access and modified time stamp
    */
}
    
bool FileManager::DeleteFile(string fileName) {
    /*
    check if !fileName

        deallocate disk blocks
        del iNode
        del disk directory
    */
}

bool FileManager::DeleteBlock(string fileName, int numBlocks) {
    /*
        check fil existence

        deallocate dis blocks from back.
        modify access and modified time stamp.
    */
}
