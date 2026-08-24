/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode *slow = head->next, *fast = head->next->next;

        while (fast && fast->next && slow != fast) {
            fast = fast->next->next;
            slow = slow->next;
        }

        if (slow != fast) return nullptr;

        slow = head;

        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};
