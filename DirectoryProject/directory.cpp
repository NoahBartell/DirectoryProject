#include "directory.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

//Constructors
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
//List lists all items in directory
string Directory::list() {
    string stringbuilder = "Current Directory: " + this->thisName + "\nSubdirectories:\n";
    for (Directory dir : directories) {
        stringbuilder += dir.thisName;
        stringbuilder += "\n";
    }
    return stringbuilder;
}

//returns list of commands
string Directory::help() {
    return "Commands:\ncd -n\nlist\ncreate -n\ndel -n\nhelp -n\n";
}

//gives more details about a specific command
string Directory::help(string name)
{
    string result;
    if (name == "cd") {
        result = "cd -n: Changes directory to the name of the input. Type .. to return to parent folder\n";
    }
    else if (name == "list") {
        result = "list: Shows all files and directories inside current folder\n";
    }
    else if (name == "create") {
        result = "create -n: creates a directory with the name input\n";
    }
    else if (name == "del") {
        result = "del -n: deletes a file or directory inside current directory\n";
    }
    else if (name == "help") {
        result = "help -n: shows the commands and shows specific commands\n";
    }
    else {
        result = "commands not found\n";
    }
    return result;
}

//will add a file to directory
void Directory::add(string name)
{
}

void Directory::create(string name, Directory* dirPtr) {
    directories.push_back(Directory(name, dirPtr));
}


void Directory::del(string name) {
    auto foundDirIter = find_if(directories.begin(), directories.end(),
        [name](const Directory& dir) { return dir.thisName == name; });

    if (foundDirIter != directories.end()) {
        Directory* dirToDelete = &(*foundDirIter);
        directories.erase(foundDirIter);
        delete dirToDelete;
    }
    else {
        cout << "directory not found" << endl;
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
    cout << "Directory not found" << endl;
    return this;
}



Directory* Directory::find(string name) { //finds directory in vector via name
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

string Directory::DirString(Directory* current)
{
    string stringBuilder = "";
    string temp = "";
    Directory* tempPtr = current;
    while (tempPtr->getParent() != nullptr) { //does this until gets to master dir whos parent is nullptr
        temp = tempPtr->getParent()->thisName;
        temp += "\\";
        temp += stringBuilder; // puts the dir name before current
        stringBuilder = temp;
        tempPtr = tempPtr->getParent();
    }

    temp = "C:\\";
    temp += stringBuilder; //puts c:\ at the beginning of string
    stringBuilder = temp;

    stringBuilder += thisName;
    return stringBuilder;
}

Directory* Directory::getParent()
{
    return this->parent;
}


