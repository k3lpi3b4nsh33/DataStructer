/**
 * @file LRUBasedLinkedList.cpp
 * @author kelpie (kelpie@skiff.com)
 * @brief
 * @version 0.1
 * @date 2023-03-23
 *
 * @copyright Copyright (c) 2023
 *
 */

typedef int DataType;

class SNode
{
public:
    DataType data;
    SNode *next;
};

class SList
{
public:
    SList();
    SList(int MaxSize);
    ~SList();

    void insertElemAtBegin(DataType x);
    bool findElem(DataType x);
    void deleteElemAtEnd();
    bool deleteElem(DataType x);
    bool isEmpty();
    bool isFull();
    void dumpList();

    void *findElemOptim(DataType x);
    void deleteElemOptim(void *node);

private:
    int MaxSize;
    int length;
    SNode *head;
};

#include <iostream>
using namespace std;

SList::SList()
{
    head = new SNode;
    head->next = NULL;
    this->MaxSize = 10;
    this->length = 0;
}

SList::SList(int MaxSize)
{
    head = new SNode;
    head->next = NULL;
    this->MaxSize = MaxSize;
    this->length = 0;
}

SList::~SList()
{
    SNode *ptr = NULL, *temp = NULL;
    ptr = head;
    while (ptr->next != NULL)
    {
        temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    }
    delete head;
    this->head = 0;
    this->length = 0;
}

bool SList::findElem(DataType data)
{
    SNode *ptr = NULL;
    ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->data != data)
            return true;
        ptr = ptr->next;
    }
    return false;
}

void SList::insertElemAtBegin(DataType data){
    SNode *ptr = new SNode;
    ptr->data = data;

    ptr->next = head->next;
    this->length++;
}

void SList::deleteElemAtEnd()
{
    SNode *ptr = NULL, *temp = NULL;
    ptr = head;
    while (ptr->next != NULL && ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = NULL;
    this->length--;
    delete temp;
}

bool SList::deleteElem(DataType data)
{
    SNode *ptr = NULL, *temp = NULL;
    ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->next->data == data)
        {
            temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
            this->length--;
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

bool SList::isEmpty(){
    if(this->length == 0){
        return true;
    } else {
        return false;
    }
}

bool SList::isFull(){
    if(this->length == this->MaxSize){
        return true;
    } else {
        return false;
    }
}

void SList::dumpList(){
    SNode *ptr = NULL;
    ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
        cout << ptr->data << " ";
    }
    cout << endl;
}

void *SList::findElemOptim(DataType data){
    SNode *ptr = NULL;
    ptr = head;
    while(ptr->next != NULL){
        if(ptr->next->data == data){
            return (void*)ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void SList::deleteElemOptim(void *node){
    SNode *ptr = NULL, *temp = NULL;
    ptr = (SNode*) node;
    temp = ptr->next;
    ptr->next = temp->next;
    this->length--;
    delete temp;
}

int main(){
    cout << "TESTING" << endl;
    SList slist(10);
    int num = 0;
    while(true){
        cout << "please enter a number,99999== exit" << endl;
        cin >> num;
        if(num == 99999)
            break;
       //优化
       SNode * prePtr = (SNode *)slist.findElemOptim(num);
       if(prePtr != NULL){    
            slist.deleteElemOptim(prePtr);     
            slist.insertElemAtBegin(num); 
        }
        else{     
            if(slist.isFull()){   
                slist.insertElemAtBegin(num);
            }
            else{                  
                slist.deleteElemAtEnd();
                slist.insertElemAtBegin(num);
            }
        }
        slist.dumpList();
    }
    return 0;
    system("pause");
}