# Monkey Interpreter 🐒
An implementation of an interpreter for the [Monkey programming language](https://monkeylang.org/) written in C++.

## Build
The project includes all that is needed to build with CMake, including the doctest header-only library used for unit tests.

## Project Structure
```
├── src (all source files incl. header files)
│   ├── *.cpp
│   ├── *.h
├── lib (external header files)
│   ├── *.h
│   ├── *.hpp
├── build (build artifacts; makefiles, binaries, etc;)
├── tests (unit tests w/ doctest)
│   ├── *_test.cpp
│   ├── CMakeLists.txt
├── CMakeLists.txt
└── .gitignore
```
