//
//  file.cpp
//  create-sdl-app
//
//  Created by Jack Steer on 18/02/2024.
//

#include "file.hpp"
using namespace std;

bool sdl2FrameworkSearch()
{
    const string sdl2Paths[] = {
        "/opt/homebrew/Cellar/sdl2",
        "/usr/local/Cellar/sdl2"};

    for (const auto &path : sdl2Paths)
    {

        cout << "Checking path: " << path << endl;
        if (!filesystem::exists(path))
        {
            cout << "SDL2 directory not found" << endl;
            continue;
        }

        for (const auto &entry : fs::directory_iterator(path))
        {
            if (entry.is_directory())
            {
                string versionDirectory = entry.path().string() + "/lib";

                if (fs::exists(versionDirectory))
                {
                    for (const auto &file : fs::directory_iterator(versionDirectory))
                    {
                        if (file.is_regular_file())
                        {
                            smatch match;
                            string filename = file.path().filename().string();
                            if (regex_search(filename, match, regex("(libSDL2[^ ]+)")))
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

void generateTargetDirectory(string projectPath, string projectName)
{
    source_location src = source_location::current();
    regex reg("^(.+)src/([^//]+)$");
    cmatch matches;
    regex_search(src.file_name(), matches, reg);
    filesystem::path targetParent = projectPath + "/" + projectName;

    try
    {
        fs::create_directories(targetParent);
        fs::copy_file(matches[1].str() + "example-code", targetParent / "example-code", filesystem::copy_options::overwrite_existing);
    }
    catch (exception &e)
    {
        cout << "Error when creating directory: " << e.what() << endl;
    }
}
