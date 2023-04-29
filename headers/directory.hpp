#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

// Include any necessary standard library headers here
#include <iostream>
//#include <cstring>
//#include <string>
#include <vector>
// #include <algorithm>
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
        void cd(string name);
        string list();
        string help();


    private:
        // Declare any private member variables here
        std::vector<Directory> directories;
        string thisName;
    };
    // //Constructor
    // Directory::Directory(string name){
    //         thisName = name;
    // }
    // //Methods
    // int Directory::init(){
    //     return 0;
    // }

    // string Directory::list(){
    //     string stringbuilder = "Current Directory: " + thisName + "\nSubdirectories:";
    //     for (Directory dir : directories){
    //         stringbuilder += dir.thisName;
    //         stringbuilder += "\n";
    //     }
    //     return stringbuilder;
    // }

    // string Directory::help(){
    //     return "Commands:\ncd -n: Change directory, changes directory to said -n, name of directory\n";
    // }

    // void Directory::create(string name){
    //     directories.push_back(Directory(name));
    // }

    // void Directory::del(string name){
    //     for(auto i = directories.begin(); i <= directories.end(); i++){
    //                 Directory temp = *i;
    //                 if(temp.thisName == name){
    //                     directories.erase(i);
    //                 }
    //             }

        //for (Directory dir : directories){
    //         if(dir.thisName == name){
    //             //auto it;
    //             for(auto i = directories.cbegin(); i != directories.end(); i++){
                    
    //                 // if(*i == name){
    //                 //     //it = i;
    //                 // }
    //             }
    //             //directories.erase(it);
    //         }
    //     }
     //}

    //  Declare any standalone functions here (if necessary)

#endif // MYHEADER_H
