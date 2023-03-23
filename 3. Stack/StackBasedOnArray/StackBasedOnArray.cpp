/**
 * @file StackBasedOnArray.cpp
 * @author kelpie (kelpie@skiff.com)
 * @brief
 * @version 0.1
 * @date 2023-03-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include "StackBasedOnArray.hpp"

using namespace std;

template <class T>
ArrayStack<T>::ArrayStack()
{
    this->count = 10;
    this->flag = 0;
    this->array = new T[this->count];
    if (!this->array)
    {
        cout << "array malloc failed!" << endl;
    }
}

template <class T>
ArrayStack<T>::ArrayStack(int count)
{
    this->count = count;
    this->flag = 0;
    this->array = new T[this->count];
    if (!this->array)
    {
        cout << "array malloc failed!" << endl;
    }
}

template <class T>
void ArrayStack<T>::push(T data)
{
    // enlarge the stack
    if (this->flag == this->count)
    {
        cout << "Stack is full, should enlarge 1.5x" << endl;
        this->count = int(1.5 * this->count);
        T *temp = new T[this->count];
        for (int i = 0; i < this->flag; i++)
        {
            temp[i] = this->array[i];
        }

        delete[] this->array;
        temp[this->flag] = data;
        this->flag++;
        this->array = temp;
    }
    else
    {
        this->array[this->flag] = data;
        this->flag++;
    }
}

template <class T>
T ArrayStack<T>::pop()
{
    this->flag--;
    T temp = this->array[this->flag];
    return temp;
    // Actually the elem didn't delete which still in memory :-)
}

template <class T>
T ArrayStack<T>::peek()
{
    T temp = this->array[this->flag - 1];
    return temp;
}

template <class T>
int ArrayStack<T>::StackSize()
{
    return this->flag;
}

template <class T>
int ArrayStack<T>::stackMaxSize()
{
    return this->count;
}

int main()
{
    cout << " === test begin ===" << endl;
    ArrayStack<int> arrstack(12);
    arrstack.push(10);
    arrstack.push(20);
    arrstack.push(30);
    arrstack.push(40);
    arrstack.push(50);
    arrstack.push(60);
    arrstack.push(70);
    arrstack.push(80);
    arrstack.push(90);
    arrstack.push(100);
    arrstack.push(110);
    arrstack.push(120);
    arrstack.push(130);
    arrstack.push(140);
    arrstack.push(150);

    cout << "peek , not delete " << arrstack.peek() << endl;
    cout << "pop , delete " << arrstack.pop() << endl;

    arrstack.push(210);
    arrstack.push(220);

    cout << "peek , not delete " << arrstack.peek() << endl;
    cout << "pop , delete " << arrstack.pop() << endl;

    system("pause");
    return 0;
}