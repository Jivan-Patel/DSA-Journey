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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next->next, *start = head;

        while(temp) {
            while(temp && temp->val != 0) {
                start->next->val += temp->val;
                temp = temp->next;
            }

            start = start->next;
            start->next->val = 0;
            temp = temp->next;
        }

        start->next = nullptr;

        return head->next;
    }
};