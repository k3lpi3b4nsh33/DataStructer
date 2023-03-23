/**
 * @file Linked_List.h
 * @author kelpie (kelpie@skiff.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <memory>
template <typename T>
struct Node {
    using ptr = std::shared_ptr<Node<T>>;
    T  data;
    ptr_t next;

    Node(T data_) : data(data_), next(nullptr) {}
    Node(): next(nullptr) {}
};

#endif

