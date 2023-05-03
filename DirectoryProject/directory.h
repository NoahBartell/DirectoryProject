#pragma once
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <iostream>
#include <vector>
#include "file.h"

using namespace std;


// Declare any constants or global variables here (if necessary)

// Declare any classes or structs here
class Directory
{
public:
    // Declare any public member functions here
    // constructors
    Directory(string name); //Constructor for master directory (doesnt have a parent)
    Directory(string name, Directory* parentDir); //Constructor for child directories

    // Methods
    //void mv();
    void add(string fileName); //adds a file
    void create(string dirName, Directory* dirPtr); //Creates new directory and gives it current directories pointer
    void del(string name); //Deletes the named directory or file -Note this method deletes all with the same name
    Directory* cd(string dirName); //Changes directory with the inputted name, has to be direct subdirectory
    string list(); //Lists all items in directory
    string help(); //List all commands
    string help(string name); //Gives specific directions on each command
    string DirString(Directory* current); //Converts the current dir into a string with all parent directories
    File* load(string name); //loads file with name
    
    

private:
    // Declare any private member variables here
    void setParent(Directory* parent); //sets the parent dir
    Directory* find(string name); // finds the directory
    std::vector<Directory> directories; //Dir vector contains all child dirs
    string thisName; //Name of dir
    Directory* parent; //Dir parent pointer
    Directory* getParent(); //Gets the parent of a dir, null if none
    std::vector<File> files; //vector of files

};


#endif // DIRECTORY_H