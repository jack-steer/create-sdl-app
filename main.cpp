//
//  main.cpp
//  create-sdl-app
//
//  Created by Jack Steer on 01/02/2024.
//

#include <iostream>
#include <string>
#include <regex>
#include <dirent.h>
using namespace std;

bool containsLib(string dirname) {
    
    DIR* dir = opendir(dirname.c_str());
    if (dir == NULL) {
        return 0;
    }
    
    struct dirent* entity;
    entity = readdir(dir);
    
    regex reg ("(libSDL2[^ ])");
    cmatch matches;
    
    while (entity != NULL) {
        entity = readdir(dir);
        bool result = regex_search(entity->d_name, reg);
        if (result) {
            return 1;
        }
    }
    
    closedir(dir);
    return 0;
}

int main(int argc, const char * argv[]) {
    cout << "`Welcome to Create SDL App`!\n";
    bool libExists = containsLib("/usr/local/Cellar/sdl2/2.28.5/lib");
    if (libExists) {
        cout << "We've found a version of SDL" << endl;
    }
    // If it already exists great
    
    // Create new project, ask user for a name and directory
    
    // Generate the new project with a blank window
    
    // Provide commands to build and run the new app
    return 0;
}
