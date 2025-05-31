cmake_minimum_required(VERSION 4.0)
Project(Goal-Tracker)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(GoalTracker 
    src/core/main.cpp 
    src/core/goalStorage.cpp
    src/core/progStorage.cpp
    src/app/goal.cpp
    src/app/progressLog.cpp
    src/app/cli.cpp
)
include_directories(src/app
    src/core
)