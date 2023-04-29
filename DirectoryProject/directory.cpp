#include "directory.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>a

Directory::Directory(string name) {
    thisName = name;
    //directories.push_back(*this);
    cout << "Created directory with name: " << thisName << endl;
}
//Methods
int Directory::init() {
    return 0;
}

string Directory::list() {
    string stringbuilder = "Current Directory: " + this->thisName + "\nSubdirectories:";
    for (Directory dir : directories) {
        stringbuilder += dir.thisName;
        stringbuilder += "\n";
    }
    return stringbuilder;
}

string Directory::help() {
    return "Commands:\ncd -n: Change directory, changes directory to said -n, name of directory\n";
}

void Directory::add(string name)
{
}

void Directory::create(string name) {
    directories.push_back(Directory(name));
}


void Directory::del(string name) {
    auto foundDirIter = find_if(directories.begin(), directories.end(),
        [name](const Directory& dir) { return dir.thisName == name; });

    if (foundDirIter != directories.end()) {
        directories.erase(foundDirIter);
    }
    else {
        // directory not found
    }
}


Directory* Directory::cd(string name) {
    if (name == "..") {
        return parent;
    }
    else {
        for (auto& dir : directories) {
            if (dir.thisName == name) {
                return &dir;
            }
        }
    }
    cout << "Directory not found";
    return this;
}



Directory* Directory::find(string name) {
    if (thisName == name) {
        return this;
    }
    else {
        for (auto& dir : directories) {
            Directory* result = dir.find(name); //calls itself over and over again to recursivly find directory
            if (result != nullptr) {
                return result;
            }
        }
    }
    return nullptr;
}

void Directory::setParent(Directory* parentDir){
    this->parent = parentDir;
}
