cmake_minimum_required(VERSION 4.0)
Project(Goal Tracker)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(GoalTracker 
    src/main.cpp 
    src/app/goal.cpp
    src/app/goal.h
    src/app/progressLog.cpp
    src/app/progressLog.h
)
include_directories(src/app)