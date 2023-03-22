/**
 * @file DList.c
 * @author kelpie (kelpie@skiff.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "DList.h"

void dlist_init(stDlistHead_P dlist){
    dlist->size = 0;
    dlist->head = NULL;
    dlist->tail = NULL;
    return;
}

void dlist_destory(stDlistHead_P dlist){
    stDlistNode *pNode = NULL;
	
	while(dlist->size > 0)
	{
		pNode = dlist->head;
		dlist->head = dlist->head->next;
		free(pNode);
		dlist->size--;
	}

	memset(dlist,0,sizeof(stDlistHead));

	return;
}

int dlist_insert_head(stDlistHead_P dlist, stDlistNode *pNode, int data){
    if(pNode == NULL){
        pNode = (stDlistNode *)malloc(sizeof(stDlistNode));
        if(pNode == NULL){
            return -1;
        }
    }

    pNode->data = data;
    pNode->prev = NULL;
    pNode->next = NULL;

    if(dlist->size == 0){
        dlist->head = pNode;
        dlist->tail = pNode;
    } else {
        // If dlist size is greater than 0, new Node will be inserted in the head of Dlist.
        pNode->next = dlist->head;
        dlist->head->prev = pNode;
        dlist->head = pNode;
    }

    dlist->size++;
    return 0;
}

void dlist_remove_tail(stDlistHead_P dlist){
    stDlistNode *pNode = NULL;

	if(dlist->size == 0)
	{
		return;
	}

    pNode = dlist->tail;
	if(dlist->size > 1)
	{
		pNode = dlist->tail->prev;
		pNode = NULL;
        free(pNode);
	}
	else
	{
		dlist->head = NULL;
		dlist->tail = NULL;
	}
	dlist->size--;
    return;
	
}

void dlist_remove_node(stDlistHead * dlist, stDlistNode *pNode){
    if((dlist == NULL) || (pNode == NULL)){
        return;
    }

    if(dlist->head == pNode){
        dlist->head = dlist->head->next;
    } 
    else if(dlist->tail == pNode) {
        dlist->tail = pNode->prev;
        dlist->tail->next = NULL;
    } else {
        pNode->prev->next = pNode->next;
        pNode->next->prev = pNode->prev;
    }

    if(dlist->size == 0){
        memset(dlist, 0 , sizeof(stDlistHead));
    }
    return;
}

stDlistNode *dlist_search(stDlistHead * dlist, int data){
    stDlistNode *pNode = dlist->head;
    while(pNode != NULL){
        if(pNode->data == data){
            return pNode;
        }
        pNode = pNode->next;
    }
    return NULL;
}

void dlist_dump(stDlistHead *dlist){
    int no = 0;
    stDlistNode *pNode = dlist->head;
    while(pNode != NULL){
        printf("\r\n [%d] = %d", no++, pNode->data);
        pNode = pNode->next;
    }
    printf("\r\n--- DUMP COMPLETED ---");
    return;
}

void Lru_dlist(stDlistHead_P dlist, int data){
    stDlistNode *pNode = NULL;
    pNode = dlist_search(dlist,data);
    if(pNode != NULL){
        dlist_remove_node(dlist, pNode);
    } 
    else if(dlist->size >= 4){
        dlist_remove_tail(dlist);
    }
    dlist_insert_head(dlist, pNode, data);
    return;
}

int main(){
    stDlistHead dlist = {0};
    stDlistNode *pNode = NULL;

    dlist_init(&dlist);

    printf("\r\n Insert 1,2,3!");
    dlist_insert_head(&dlist, NULL, 1);
    dlist_insert_head(&dlist, NULL, 2);
    dlist_insert_head(&dlist, NULL, 3); // LIST [3,2,1]

    dlist_dump(&dlist);

    dlist_insert_head(&dlist, pNode, 4);
    dlist_dump(&dlist);

    Lru_dlist(&dlist,5);
	dlist_dump(&dlist);
    Lru_dlist(&dlist,6);
	dlist_dump(&dlist);
    Lru_dlist(&dlist,7);
	dlist_dump(&dlist);
    Lru_dlist(&dlist,5);
	dlist_dump(&dlist);

    while(dlist.size > 0)
	{
	    dlist_remove_tail(&dlist);
	}
    printf("\r\nDelete ALL DLIST!\n");

	return 0;
}