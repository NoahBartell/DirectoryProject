#include<iostream>
#include<cmath>
#include <cstring>
//#include<C:\Users\barnoac\OneDrive - Dunwoody College of Technology\Documents\CompOrgProject\src\file.hpp>
//#include<C:\Users\barnoac\OneDrive - Dunwoody College of Technology\Documents\CompOrgProject\src\directory.hpp>
#include <C:\Users\barnoac\OneDrive - Dunwoody College of Technology\Documents\CompOrgProject\headers\directory.hpp>
//#include<directory.hpp>
using namespace std;

int main(){
    Directory myDirectory("Main");
    myDirectory.create("Sub");
    cout << myDirectory.list();// << myDirectory.help();
    myDirectory.del("Sub");
    cout << myDirectory.list(); //<< myDirectory.help();
    return 0;
}