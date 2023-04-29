#include<iostream>
#include<cmath>
#include <cstring>
#include "directory.h"

using namespace std;

//int main() {
//    Directory myDirectory("Main");
//    myDirectory.create("Sub");
//    cout << myDirectory.list();// << myDirectory.help();
// //<< myDirectory.help();
//    //Directory* ptr = nullptr;
//    if (myDirectory.cd("Sub") != nullptr) {
//        myDirectory = *myDirectory.cd("Sub");
//    }
//    
//    cout << myDirectory.list();
//    return 0;
//}

int main() {
    Directory myDirectory("Main");
    Directory* dirPtr = &myDirectory;
    dirPtr->create("Sub");
    dirPtr->create("Sub2");
    cout << dirPtr->list();// << myDirectory.help();
    //<< myDirectory.help();
       //Directory* ptr = nullptr;
    Directory* tempptr = &myDirectory;
    dirPtr = dirPtr->cd("Sub");
    //myDirectory = *dirPtr;
    dirPtr->setParent(tempptr);
    dirPtr->create("SubSub");
    cout << dirPtr->list();
    dirPtr = dirPtr->cd("..");
    dirPtr->del("Sub2");
    cout << dirPtr->list();
    return 0;
}