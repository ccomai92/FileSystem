#include "FileManager.h"

FileManager::FileManager(): disk(new FileDisk()), artificialID(0) {}

FileManager::~FileManager() {
    delete this->disk; 
}


bool FileManager::CreateFile(string fileName, int numBlocks) {
    // create new INode
    map<string, DiskDir*>::iterator it = this->dirs.find(fileName); 
    if (it == this->dirs.end()) { // see if fileName is in the diskdirectory
        return false;
    }
    // no fileName exists so make one and putinto directory  
    DiskDir *diskDir = new DiskDir{this->artificialID, numBlocks};
      // this should be later added 

    // create iNode and insert blocks for the iNode 
    INode *iNode = new INode();
    iNode->addBlock(numBlocks, this->disk); 
    

    // don't forget to update inodeSize 
    this->iNodes[this->artificialID] = iNode; 
    this->dirs[fileName] = diskDir; 
    this->artificialID++; 
    // put these disk blocks into the iNode
    // Make Time Stamp for 3 of all times
    
}
    
bool FileManager::AddBlock(string fileName, int numBlocks) {
    map<string, DiskDir*>::iterator it = this->dirs.find(fileName); 
    if (it == this->dirs.end()) { // see if fileName is in the diskdirectory
        cerr << "no such file exists" << endl; 
        return false;
    }

    int id = this->dirs[fileName]->iNodeID; 
    if (!(this->iNodes[id]->addBlock(numBlocks, this->disk))) {
        cerr << "failed to add Block" << endl; 
        return false; 
    }  

    // update iNodeSize 

    return true; 
}
    
bool FileManager::DeleteFile(string fileName) {
    map<string, DiskDir*>::iterator it = this->dirs.find(fileName); 
    if (it == this->dirs.end()) { // see if fileName is in the diskdirectory
        cerr << "no such file exists" << endl; 
        return false;
    }
    
    int id = this->dirs[fileName]->iNodeID;
    
    delete this->iNodes[id]; 
    this->iNodes.erase(id); 
    
    delete this->dirs[fileName]; 
    this->dirs.erase(fileName); 
    return true; 
}

bool FileManager::DeleteBlock(string fileName, int numBlocks) {
    map<string, DiskDir*>::iterator it = this->dirs.find(fileName); 
    if (it == this->dirs.end()) { // see if fileName is in the diskdirectory
        cerr << "no such file exists" << endl; 
        return false;
    }

    int id = this->dirs[fileName]->iNodeID;
    this->iNodes[id]->deleteBlock(numBlocks, this->disk); 

    // update filesize in this->dirs 
}
