#include "codebase.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <stdlib.h>
#include <string.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

CODEBASE_EXPORT int processDataByReference(DataStruct data) {
    data.value += 1;
    return data.value;
}

CODEBASE_EXPORT int processDataByPointer(DataStruct* data) {
    if (data == NULL) {
        return -1;
    }
    
    data->value += 1;
    return data->value;
}

CODEBASE_EXPORT DataStruct** createDynamicArray(int count) {
    if (count <= 0) {
        return NULL;
    }

    
    DataStruct** array = (DataStruct**)malloc(count * sizeof(DataStruct*));
    if (array == NULL) {
        return NULL;
    }

    for (int i = 0; i < count; i++) {
        array[i] = (DataStruct*)malloc(sizeof(DataStruct));
        if (array[i] == NULL) {
            // Free already allocated memory on failure
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return NULL;
        }

        array[i]->value = i;
    }
    return array;
}

CODEBASE_EXPORT int sumDynamicArray(DataStruct** data, int count) {
    if (data == NULL || count <= 0) {
        return -1;
    }
    
    int sum = 0;
    for (int i = 0; i < count; i++) {
        if (data[i] != NULL) {
            sum += data[i]->value;
        }
    }
    return sum;
}