#pragma once
#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

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

    // Methods
    int init();
    //void mv();
    void add(string name);
    void create(string name);
    void del(string name);
    Directory* cd(string name);
    string list();
    string help();
    Directory* find(string name);
    void setParent(Directory* parent);
    

private:
    // Declare any private member variables here
    std::vector<Directory> directories;
    string thisName;
    Directory* parent;
};


#endif // MYHEADER_H