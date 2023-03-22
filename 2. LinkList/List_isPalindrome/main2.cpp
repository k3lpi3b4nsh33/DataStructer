#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};

/* Function to check if a linked list is palindrome. */
bool isPalindrome(struct ListNode* head) {
    /* Check for empty list or single node list. */
    if (head == NULL || head->next == NULL) {
        return true;
    }

    /* Find the middle node of the linked list. */
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse the second half of the linked list. */
    struct ListNode *prev = NULL;
    struct ListNode *curr = slow->next;
    struct ListNode *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    slow->next = prev;

    /* Compare the first half with the reversed second half. */
    struct ListNode *p1 = head;
    struct ListNode *p2 = slow->next;
    while (p2 != NULL) {
        if (p1->val != p2->val) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}

/* Test function */
int main() {
    /* Create linked list: 1 -> 2 -> 3 -> 2 -> 1 */
    struct ListNode *head = (ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (ListNode *)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 2;
    head->next->next->next->next = (ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 1;
    head->next->next->next->next->next = NULL;

    /* Test the isPalindrome function */
    bool result = isPalindrome(head);
    printf("Result: %d\n", result);

    /* Free the memory used by the linked list */
    struct ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
