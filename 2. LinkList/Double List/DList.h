/**
 * @file DList.h
 * @author kelpie (kelpie@skiff.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

#define Elemtype int

// The list node
typedef struct DlistNode{
    struct DlistNode *prev;
    struct DlistNode *next;
    Elemtype data;
} stDlistNode;

// The whole list
typedef struct Dlisthead{ 
    int size;
    stDlistNode *head;
    stDlistNode *tail;
} stDlistHead, *stDlistHead_P ;