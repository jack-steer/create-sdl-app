//
//  file.hpp
//  create-sdl-app
//
//  Created by Jack Steer on 18/02/2024.
//

#ifndef file_hpp
#define file_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <regex>
#include <dirent.h>
#include <filesystem>
#include <source_location>

using namespace std;
namespace fs = std::filesystem;

bool sdl2FrameworkSearch();
bool containsLib(string);
void generateTargetDirectory(string, string);

#endif /* file_hpp */
