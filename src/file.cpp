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

void generateTargetDirectory(string projectPath, string projectName) {
    source_location src = source_location::current();
    regex reg ("^(.+)src/([^//]+)$");
    cmatch matches;
    regex_search(src.file_name(), matches, reg);
    filesystem::path targetParent = projectPath + "/" + projectName;

    filesystem::path p = matches[1].str() + "main";

    try
    {
        filesystem::create_directories(targetParent);
        filesystem::copy_file(p, targetParent  / "main.cpp", filesystem::copy_options::overwrite_existing);
    }
    catch (std::exception& e)
    {
    }
}
