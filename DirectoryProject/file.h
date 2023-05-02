#pragma once
#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <vector>

using namespace std;


// Declare any constants or global variables here (if necessary)

// Declare any classes or structs here
class File
{
public:
    // Declare any public member functions here
    // constructors
    File();
    // Methods
    string read();


private:
    // Declare any private member variables here
    string contents;
};


#endif // MYHEADER_H