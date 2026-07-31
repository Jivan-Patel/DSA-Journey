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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        multiset<int> values;
        ListNode* temp = head;

        while(temp != nullptr) {
            values.insert(temp->val);
            temp = temp->next;
        }

        temp = head;

        for(int val : values) {
            temp->val = val;
            temp = temp->next;
        }

        return head;
    }
};