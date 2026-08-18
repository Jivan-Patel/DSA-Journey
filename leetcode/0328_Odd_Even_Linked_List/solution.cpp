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

        ListNode* even = new ListNode(0);

        ListNode *temp = head, *temp1 = even;

        while (temp->next != nullptr) {
            temp1->next = temp->next;
            temp->next = temp->next->next;
            temp1 = temp1->next;

            if (temp->next) temp = temp->next;
        }

        temp1->next = nullptr;
        temp->next = even->next;

        return head;
    }
};