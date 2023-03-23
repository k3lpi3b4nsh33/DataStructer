/**
 * Author: kelpie
 * Date: 3/22/2023
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LinkList;

void CreateListHead(LinkList *&L, ElemType a[], int n);
void CreateListTail(LinkList *&L, ElemType a[], int n);
void InitList(LinkList *&L);
void DestroyList(LinkList *&L);
bool ListEmpty(LinkList *L);
int ListLength(LinkList *L);
void ShowList(LinkList *L);
bool GetListElem(LinkList *L, int i, ElemType &e);
int LocateElem(LinkList *L, ElemType e);
bool ListInsert(LinkList *&L, int i, ElemType e);
bool ListDelete(LinkList *&L, int i, ElemType &e);

#endif
