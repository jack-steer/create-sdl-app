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
    cout << "`Welcome to Create SDL App`!\n" << "\n\n\n";
    
    cout << "Checking if SDL is installed via brew..." << endl;
    bool libExists = containsLib("/usr/local/Cellar/sdl2/2.28.5/lib");
    if (libExists) {
        cout << "We've found a version of SDL" << endl;
    }
    
    string projectPath;
    string projectName;
    
    cout << "Please enter the path where your new project will be generated: " << endl;
    cin >> projectPath;
    
    // Check project path is valid
    
    cout << "Please enter a name for your project: " << endl;
    cin >> projectName;
    
    // Generate the new project with a blank window
    
    // Provide commands to build and run the new app
    
    cout << "Your new C++ SDL project has been generated!" << endl;
    cout << "To run this project, run the following commands: " << endl;
    
    cout << "cd " << projectPath << "/" << projectName << endl;
    cout << "clang++ main.cpp ./glad/src/glad.c -I/Library/Frameworks/SDL2.framework/Headers -I./glad/include -F/Library/Frameworks -framework SDL2 -rpath /Library/Frameworks";
    cout << "./a.out" << endl;
    return 0;
}
