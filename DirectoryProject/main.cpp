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
    myDirectory.create("Sub");
    cout << myDirectory.list();// << myDirectory.help();
    //<< myDirectory.help();
       //Directory* ptr = nullptr;
    if (myDirectory.cd("Sub") != nullptr) {
        myDirectory = *myDirectory.cd("Sub");
    }

    cout << myDirectory.list();
    return 0;
}