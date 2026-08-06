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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* temp1 = head;
        while(temp1 && temp1->next) {
            ListNode* temp2 = temp1->next;
            while(temp2 && temp1->val == temp2->val) {
                temp2 = temp2->next;
            }
            temp1->next = temp2;
            temp1 = temp1->next;
        }
        return head;
    }
};