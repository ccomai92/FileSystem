

#include <string> 
#include <iostream> 

#include "FileManager.h"
using namespace std;

int main() {
    // while loop taking commands 
    string command; 
    FileManager* fileManager = nullptr; 
    

    while(true) {
        cout << ">> "; 
        cin >> command;
        if (command == "quit") {
            fileManager->dumpAll();     
            break;
        } else if (command == "ls") {
            if (fileManager == nullptr) {
                cerr << "File Structure has not been built yet" << endl;
            } else {
                fileManager->dump(); 
            }
        } else if (command == "FM") {
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
                    fileManager->CreateFile(fileName, blockNum); 
                } else if (command == "MF") {
                    cin >> fileName >> blockNum; 
                    fileManager->AddBlock(fileName, blockNum); 

                } else if (command == "DF") {
                    cin >> fileName; 
                    fileManager->DeleteFile(fileName); 

                } else if (command == "DB") {
                    cin >> fileName >> blockNum; 
                    fileManager->DeleteBlock(fileName, blockNum); 

                }
            }
        }
    }

    return 0; 
}