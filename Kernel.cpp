
#include <string> 
#include <iostream> 
#include "fileManager.h"
using namespace std;

int main() {
    // while loop taking commands 
    string command; 
    FileManager* fileManager = nullptr; 
    

    while(true) {
        cout << ">> "; 
        cin >> command;
        if (command == "FM") {
            if (fileManager != nullptr) {
                cerr << "File Structure already opened" << endl;  
            } else {
                fileManager = new FileManager(); 
            }
        } else { 
            if (fileManager == nullptr) {
                cerr << "File Structure has not been built yet" << endl;
            } else {
                string fileName; 
                int blockNum; 

                if (command == "NF") {
                    cin >> fileName >> blockNum; 
                    fileManager->createFile(fileName, blockNum); 
                } else if (command == "MF") {
                    cin >> fileName >> blockNum; 
                    fileManager->addBlock(fileName, blockNum); 

                } else if (command == "DF") {
                    cin >> fileName; 
                    fileManager->deleteFile(fileName); 

                } else if (command == "DB") {
                    cin >> fileName >> blockNum; 
                    fileManager->deleteBlock(fileName, blockNum); 

                }
            }
        }
    }

    return 0; 
}