#pragma once
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <iostream>
#include <vector>

using namespace std;


// Declare any constants or global variables here (if necessary)

// Declare any classes or structs here
class Directory
{
public:
    // Declare any public member functions here
    // constructors
    Directory(string name);
    Directory(string name, Directory* parentDir);

    // Methods
    int init();
    //void mv();
    void add(string name);
    void create(string name, Directory* dirPtr);
    void del(string name);
    Directory* cd(string name);
    string list();
    string help();
    string help(string name);
    string DirString(Directory* current);
    
    

private:
    // Declare any private member variables here
    void setParent(Directory* parent);
    Directory* find(string name);
    std::vector<Directory> directories;
    string thisName;
    Directory* parent;
    Directory* getParent();
};


#endif // MYHEADER_H