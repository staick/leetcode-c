#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**********************LeetCoe Start****************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    int result = 0;
    while (head) {
        result <<= 1;
        result |= head->val;
        head = head->next;
    }

    return result;
}