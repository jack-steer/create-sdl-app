//
//  file.cpp
//  create-sdl-app
//
//  Created by Jack Steer on 18/02/2024.
//

#include "file.hpp"
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
