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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr ||
            head->next->next == nullptr) {
            return head;
        }

        ListNode* even = head->next;

        ListNode *i = head, *j = even;

        while (j != nullptr && j->next != nullptr) {
            i->next = j->next;
            i = i->next;
            j->next = i->next;
            j = j->next;
        }

        i->next = even;

        return head;
    }
};