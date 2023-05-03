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
    stringbuilder += "Files:\n";
    for (File file : files) {
        stringbuilder += file.myName;
        stringbuilder += "\n";
    }
    return stringbuilder;
}

//returns list of commands
string Directory::help() {
    return "Commands:\ncd -n\nlist\ncreate -n\ndel -n\nhelp -n\nadd -n\nload -n\nread\nwrite -m\n";
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
    else if (name == "load") {
        result = "load -n: loads a file with name input to be read and written\n";
    }
    else if (name == "add") {
        result = "add -n: adds the file name -n to the current directory\n";
    }
    else if (name == "read") {
        result = "read: reads the current file contents\n";
    }
    else if (name == "write") {
        result = "write -m: inputs message into file to be stored\n";
    }
    else {
        result = "commands not found\n";
    }
    return result;
}

//will add a file to directory
void Directory::add(string fileName)
{
    File* file = new File(fileName);
    //cout << &file;
    files.push_back(*file);
}

//creates new dir
void Directory::create(string dirName, Directory* dirPtr) {
    Directory* dir = new Directory(dirName, dirPtr);
    directories.push_back(*dir);
}

//deletes item with name -n
void Directory::del(string dirName) {
    auto foundDirIter = find_if(directories.begin(), directories.end(), //looks for directory first
        [dirName](const Directory& dir) { return dir.thisName == dirName; });

    if (foundDirIter != directories.end()) {
        Directory* dirToDelete = &(*foundDirIter);
        directories.erase(foundDirIter);
        delete dirToDelete;
    }
    else {

        auto foundFileIter = find_if(files.begin(), files.end(),
            [dirName](const File& file) { return file.myName == dirName; });

        if (foundFileIter != files.end()) {
            File* fileToDelete = &(*foundFileIter);
            files.erase(foundFileIter);
            delete fileToDelete;
        }
        else {
            cout << "item not found" << endl;
        }
    }
}


Directory* Directory::cd(string dirName) {
    if (dirName == ".." && parent != nullptr) { //If .. is sent return to parent
        return parent;
    }
    else {
        for (auto& dir : directories) {
            if (dir.thisName == dirName) {
                return &dir;//send back the address of this directory
            }
        }
    }
    cout << "Directory not found" << endl;
    return this;
}



Directory* Directory::find(string dirName) { //finds directory in vector via name
    if (thisName == dirName) {
        return this;
    }
    else {
        for (auto& dir : directories) {
            Directory* result = dir.find(dirName); //calls itself over and over again to recursivly find directory
            if (result != nullptr) {
                return result;
            }
        }
    }
    return nullptr;
}

File* Directory::load(string fileName) { //finds directory in vector via name
    for (File& file : files) {
        //std::cout << &file << endl;
        if (file.myName == fileName) {
            return &file;
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


