/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) { 
        ListNode* i = head;
        int count = 0;
        // It will run n times
        while(i != NULL && count < n) {
            i = i->next;
            count++;
        }
        if(i == NULL) {
            return head->next;
        }

        // It will run length - n times
        ListNode* j = head;
        while(i->next != NULL) {
            j = j->next;
            i = i->next;
        }

        j->next = j->next->next;
    
        return head;
    }
};