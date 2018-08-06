
#include "iNode.cpp"

iNode::iNode() {

}


iNode::INode(char mode, unsigned int uid, unsigned int gid, 
            time_t aTime, time_t cTime, time_t mTime, 
            int size, int blockCount) {
    this.mode = mode;
    this.uid = uid;
    this.gid = gid;
    this.aTime = aTime;
    this.cTime = cTime;
    this.mTime = mTime;
    this.size = size;
    this.blockCount = blockCount;
    }
    
iNode::~INode() {
    
} 