# Learn to Swig

Workbench to learn how to use SWIG to invoke C++ code from C#.

## Software Install

```
winget install -e --id SWIG.SWIG
winget install -e --id Kitware.CMake
```

> [!IMPORTANT]  
> winget SWIG installer adds `...\swigwin-4.2.1\CCache` to the environment's PATH, 
> `...\swigwin-4.2.1` should also be added.

## Building

Build codebase to generate Shared library as well as CSharp code

**VSCode:**
1. Hit F1 + CMake: Configure
2. Hit F1 + CMake: Build

**Console:**
1. `cmake -B build -S . -A x64`
2. `cmake --build build --config Release`

Build then Run or Debug codebase-dotnet to see how the bindings work