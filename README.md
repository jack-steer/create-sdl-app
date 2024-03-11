# Create-SDL-App (Work in Progress)

## Summary
Generates the necessary dependencies and builds a start up C++ w/SDL blank project.

This project intention is to help alleviate the difficulties of setting up a basic C++ project that includes SDL that can run for everyone. This will intitially allow the user to run the program from the command line, but would be beneficial to have IDE set up for the future.

## Prerequisites

To generate the built executable, you'll need g++ or clang++ compilers installed.

## Installation

1. Clone the repo
```
git clone https://github.com/jack-steer/create-sdl-app.git
```

2. Change directory and generate executable to run the program
```
cd create-sdl-app
clang++ -std=c++20 src/main.cpp src/file.cpp
```
Can substitute clang++ with g++ if preffered.

3. Invoke the executable and refer to onscreen prompts
```
./a.out
```