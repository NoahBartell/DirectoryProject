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
    Directory* find(string name);
    void setParent(Directory* parent);
    string DirString(Directory* current);
    Directory* getParent();
    

private:
    // Declare any private member variables here
    std::vector<Directory> directories;
    string thisName;
    Directory* parent;
};


#endif // MYHEADER_H