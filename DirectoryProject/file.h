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
    File(string name); //Constructs file with name
    // Methods
    string read(); //Sends back contents
    void write(string text); //Enters value into contents
    string myName; //Files name
    string contents; //Contents of file

private:
    // Declare any private member variables here
    
};


#endif // FILE_H