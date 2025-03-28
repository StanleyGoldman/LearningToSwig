// codebase.h
#ifndef CODEBASE_H
#define CODEBASE_H

#ifdef _WIN32
    #define CODEBASE_EXPORT __declspec(dllexport)
#else
    #define CODEBASE_EXPORT
#endif

#endif // CODEBASE_H
