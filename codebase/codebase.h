// codebase.h
#ifndef CODEBASE_H
#define CODEBASE_H

#ifdef _WIN32
    #define CODEBASE_EXPORT __declspec(dllexport)
#else
    #define CODEBASE_EXPORT
#endif

CODEBASE_EXPORT typedef struct {
    int value;
} DataStruct;

CODEBASE_EXPORT int processDataByReference(DataStruct data);
CODEBASE_EXPORT int processDataByPointer(DataStruct* data);
CODEBASE_EXPORT DataStruct** createDynamicArray(int count);
CODEBASE_EXPORT int sumDynamicArray(DataStruct** data, int count);

#endif // CODEBASE_H
