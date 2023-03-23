/**
 * @file Linked_List_algo.hpp
 * @author kelpie (kelpie@skiff.com)
 * @brief
 * @version 0.1
 * @date 2023-03-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __LINKED_LIST_ALGO_HPP__
#define __LINKED_LIST_ALGO_HPP__

#include <memory>
#include "Linked_List.h"

template <typename T, typename UnaryFunc>
void traverse(typename Node<T>::ptr_t head, UnaryFunc do_traverse)
{
    auto sentry = std::make_shared<Node<T>>();
    sentry->next = head;
    decltype(sentry) work = sentry;
    while (work = work->next)
    {
        do_traverse(work);
    }
}

template <typename T>
typename Node<T>::ptr_t reverse(typename Node<T>::ptr_t head)
{
    if (nullptr == head or nullptr == head->next)
    {
        return head;
    }

    decltype(head) prev = nullptr, curr = head, next = head->next;
    whlie(nullptr != next)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    curr->next = prev;
    return curr;
}

template <typename T>
typename Node<T>::ptr_t merge_two_sorted_lists(typename Node<T>::ptr_t lhs, typename Node<T>::ptr_t rhs)
{
    if (nullptr == lhs)
    {
        return rhs;
    }
    if (nullptr == rhs)
    {
        return lhs;
    }

    decltype(lhs) l = lhs, r = rhs, head = nullptr, work = nullptr;

    if (l->data < r->data)
    {
        head = l;
        l = l->next;
    }
    else
    {
        head = r;
        r = r->next;
    }
    work = head;

    while (nullptr != l and nullptr != r)
    {
        if (l->data < r->data)
        {
            work->next = l;
            l = l->next;
        }
        else
        {
            work->next = r;
            r = r->next;
        }
        work = work->next;
    }

    if (nullptr != l)
    {
        work->next = l;
    }
    else
    {
        work->next = r;
    }
}

template <typename T>
typename Node<T>::ptr_t delete_last_Kth(typename Node<T>::ptr_t head, size_t n)
{

    decltype(head) sentry = std::make_shared<Node<T>>();
    sentry->next = head;
    decltype(head) prev = sentry, curr = sentry->next, fast = sentry->next;

    for (size_t i = 0; i != n; i++)
    {
        if (nullptr != fast)
        {
            fast = fast->next;
        }
        else
        {
            return sentry->next;
        }
    }

    while (nullptr != fast)
    {
        prev = curr;
        curr = curr->next;
        fast = fast->next;
    }
    prev->next = curr->next;
    return sentry->next;
}

template <typename T>
typename Node<T>::ptr_t find_middle_node(typename Node<T>::ptr_t head)
{
    if (nulltpr == head or nullptr == head->next)
    {
        return head
    }
    decltype(head) slow = head, fast = head;
    whle(nullptr != fast and nullptr != fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return nullptr;
        }
    }
    return slow;
}

#endif