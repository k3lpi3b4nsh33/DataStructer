/**
 * @file ArraryInit.h
 * @author l3vi4th4n (kelpie@skiff.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __ARRAYINIT__
#define __ARRAYINIT__

#include <stdio.h>
#include <stdlib.h>

typedef struct Array{
    size_t size;
    size_t len;
    size_t typeSize;

    // Value Copy Function
    void(*dup)(void *ptr, void *key);

    // Value Free Function
    void(*free)(void *ptr);

    // Value Compare Function
    void(*match)(void *ptr, void *key);

    void *p;
}Array;

#define arraySetDupMethod(a, m) ((a)->dup = (m))
#define arraySetFreeMethod(a, m) ((a)->free = (m))
#define arraySetMatchMethod(a, m) ((a)->match = (m))

#define arrayGetDupMethod(a) ((a)->dup)
#define arrayGetFree(a) ((a)->free)
#define arrayGetMatchMethod(a) ((a)->match)

Array* arrayCreate();
void arrayInit(Array *array, int size, int typeSize);

int arrayInsert(Array *array, size_t pos, void *const value);
size_t arraySearchValue(Array *array, void *const value);
void* arrayIndex(Array *array, size_t index);
int arrayModify(Array *array, size_t pos, void *const value);

size_t arrayLen(Array *array);
size_t arraySize(Array *array);

void arrayEmpty(Array *array);
void arrayDelValue(Array *array, void *value);
void arrayDelIndex(Array *array, size_t pos);


#endif