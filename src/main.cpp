//
//  main.cpp
//  create-sdl-app
//
//  Created by Jack Steer on 01/02/2024.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <regex>

#include "file.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "`Welcome to Create SDL App`!\n" << "\n\n\n";
    cout << "Checking if SDL is installed via brew..." << endl;
    bool libExists = containsLib("/usr/local/Cellar/sdl2/2.28.5/lib");
    if (!libExists) {
        cout << "Not found a valid version of SDL" << endl;
        return 0;
    }
    
    cout << "SDL Version found..." << endl;
    string projectPath;
    string projectName;
    
    cout << "Please enter the path where your new project will be generated: " << endl;
    cin >> projectPath;
    
    if (!opendir(projectPath.c_str())) {
        cout << "Error: Project path " << projectPath << " not found." << endl;
        
        return 0;
    }
    
    cout << "Please enter a name for your project: " << endl;
    cin >> projectName;
    
    // Generate the new project with a blank window
    generateTargetDirectory(projectPath, projectName);
    cout << "Your new C++ SDL project has been generated!" << endl;
    cout << "To run this project, run the following commands: " << endl;
    
    cout << "cd " << projectPath << "/" << projectName << endl;
    cout << "clang++ main.cpp -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2 -rpath /Library/Frameworks" << endl;
    cout << "./a.out" << endl;
    return 0;
}
