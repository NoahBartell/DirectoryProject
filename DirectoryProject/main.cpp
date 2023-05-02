#include<iostream>
#include<cmath>
#include <cstring>
#include "directory.h"

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

*/

//Public
Directory* myDirPtr; // the pointer to the currently selected directory
string command;
string name;

int main() {
    myDirPtr = new Directory("Main");
    
    cout << "Enter a command, type help! for list of commands" << endl;
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
        }

        if (command == "ex") {
            cout << myDirPtr->DirString(myDirPtr);
        }

        cout <<  myDirPtr->DirString(myDirPtr) << ">";
        cin >> command;
    }
    return 0;
}