#include <C:\Users\barnoac\OneDrive - Dunwoody College of Technology\Documents\CompOrgProject\headers\directory.hpp>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

Directory::Directory(string name){
        thisName = name;
}
//Methods
int Directory::init(){
    return 0;
}

string Directory::list(){
    string stringbuilder = "Current Directory: " + thisName + "\nSubdirectories:";
    for (Directory dir : directories){
        stringbuilder += dir.thisName;
        stringbuilder += "\n";
    }
    return stringbuilder;
}

string Directory::help(){
    return "Commands:\ncd -n: Change directory, changes directory to said -n, name of directory\n";
}

void Directory::create(string name){
    directories.push_back(Directory(name));
}

void Directory::del(string name){
    for(auto i = directories.begin(); i <= directories.end(); i++){
                Directory temp = *i;
                if(temp.thisName == name){
                    directories.erase(i);
                }
        }
}

void add(string name){
    //fill in later
}

void cd(string name){

}