//
//  file.hpp
//  create-sdl-app
//
//  Created by Jack Steer on 18/02/2024.
//

#ifndef file_hpp
#define file_hpp

#include <stdio.h>
#include <string>
#include <regex>
#include <dirent.h>
#include <filesystem>
#include <source_location>

bool containsLib(std::string);

void generateTargetDirectory(std::string, std::string);

#endif /* file_hpp */
