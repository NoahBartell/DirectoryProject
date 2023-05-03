#include<iostream>
#include<cmath>
#include <cstring>
#include <string>
#include "directory.h"
#include "file.h"

using namespace std;

//Debug
//int main() {
//    Directory myDirectory("Main");
//    Directory* dirPtr = &myDirectory;
//    dirPtr->create("Sub");
//    dirPtr->create("Sub2");
//    cout << dirPtr->list();// << myDirectory.help();
//    //<< myDirectory.help();
//       //Directory* ptr = nullptr;
//    Directory* tempptr = &myDirectory;
//    dirPtr = dirPtr->cd("Sub");
//    //myDirectory = *dirPtr;
//    dirPtr->setParent(tempptr);
//    dirPtr->create("SubSub");
//    cout << dirPtr->list();
//    dirPtr = dirPtr->cd("..");
//    dirPtr->del("Sub2");
//    cout << dirPtr->list();
//    return 0;
//}

/*List of avaiible commands :
cd -n
create -n
del -n
help
list
add -n
load -n
read
write -n
*/

//Public
Directory* myDirPtr; // the pointer to the currently selected directory
string command; //Changing command string
string name; //changing name string
File* filePtr; //Pointer to the current loaded file

int main() {

    myDirPtr = new Directory("Main");
    
    cout << "Enter a command, type help! for list of commands" << endl;
    cout << myDirPtr->DirString(myDirPtr) << ">";
    cin >> command;
    while (command != "-1"){

        

        //help
        if (command == "help!") {
            cout << myDirPtr->help();
        }

        if (command == "help") {
            cin >> name;
            cout << myDirPtr->help(name);
        }

        //create
        if (command == "create") {
            cin >> name;
            myDirPtr->create(name, myDirPtr);
        }

        //Delete
        if (command == "del"){
            cin >> name;
            myDirPtr->del(name);
        }

        //list
        if (command == "list") {
            cout << myDirPtr->list();
        }

        //Change Dir
        if (command == "cd") {
            cin >> name;
            myDirPtr = myDirPtr->cd(name);
            filePtr = nullptr;
        }

        //Add
        if (command == "add") {
            cin >> name;
            myDirPtr->add(name);
        }
        
        //Load
        if (command == "load") {
            filePtr = nullptr;
            cin >> name;
            filePtr = myDirPtr->load(name);
            if (filePtr != nullptr) {
                cout << "File Loaded\n";
            }
            else {
                cout << "File not found\n";
            }
        }

        //Read
        if (command == "read") {
            if (filePtr != nullptr) {
                cout << filePtr->contents << "\n";
            }
            else {
                cout << "File not loaded\n";
            }
        }

        //Write
        if (command == "write") {
            if (filePtr != nullptr) {
                cout << "Enter file contents\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);
                filePtr->write(name);
                cout << "Contents added\n";
            }
            else {
                cout << "File not loaded\n";
            }
        }

        cout <<  myDirPtr->DirString(myDirPtr) << ">";
        cin >> command;
    }
    return 0;
}