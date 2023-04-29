#include "directory.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

Directory::Directory(string name) {
    thisName = name;
    parent = nullptr;
    //cout << "Created directory with name: " << thisName << endl;
}

Directory::Directory(string name, Directory* parentDir) {
    thisName = name;
    parent = parentDir;
}
//Methods
int Directory::init() {
    return 0;
}

string Directory::list() {
    string stringbuilder = "Current Directory: " + this->thisName + "\nSubdirectories:\n";
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

void Directory::create(string name, Directory* dirPtr) {
    directories.push_back(Directory(name, dirPtr));
}

//void Directory::create(string name) {
//    directories.emplace_back(name, this);
//}


void Directory::del(string name) {
    auto foundDirIter = find_if(directories.begin(), directories.end(),
        [name](const Directory& dir) { return dir.thisName == name; });

    if (foundDirIter != directories.end()) {
        Directory* dirToDelete = &(*foundDirIter);
        directories.erase(foundDirIter);
        delete dirToDelete;
    }
    else {
        // directory not found
    }
}


Directory* Directory::cd(string name) {
    if (name == ".." && parent != nullptr) {
        return parent;
    }
    else {
        for (auto& dir : directories) {
            if (dir.thisName == name) {
                return &dir;
            }
        }
    }
    cout << "Directory not found\n";
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
