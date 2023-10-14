cmake_minimum_required(VERSION 3.26)
project(GPGC)

set(CMAKE_CXX_STANDARD 11)

add_library(GPGCLib
        include/Ptr.hpp
        include/Ptr.hpp
        src/Managed.cpp
        include/Managed.hpp
        src/Managed.cpp
        include/Managed.hpp
        src/MemoryManager.cpp
        include/MemoryManager.hpp
        src/MemoryManager.cpp
        include/MemoryManager.hpp
        src/Configuration.cpp
        include/Configuration.hpp)
