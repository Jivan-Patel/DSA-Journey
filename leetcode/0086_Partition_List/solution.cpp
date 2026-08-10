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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next)
            return head;

        ListNode* greater = new ListNode(0);
        ListNode* less = new ListNode(0);
        ListNode *temp = head, *temp1 = less, *temp2 = greater;

        while (temp != nullptr) {
            if (temp->val < x) {
                temp1->next = temp;
                temp1 = temp1->next;
            } 
            else {
                temp2->next = temp;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        
        temp2->next = nullptr;
        temp1->next = greater->next;

        return less->next;
    }
};