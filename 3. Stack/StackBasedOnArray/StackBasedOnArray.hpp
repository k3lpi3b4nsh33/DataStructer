/**
 * @file StackBaseOnArray.hpp
 * @author kelpie (kelpie@skiff.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

template<class T> class ArrayStack
{
    public:
        ArrayStack();
        ArrayStack(int size);
        ~ArrayStack();

        void push(T data);
        T pop();
        T peek();

        int StackSize();
        int stackMaxSize();
    
    private:
    int flag;
    int count;
    T *array;

};