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
private:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* rev = reverseList(head);
        ListNode* temp = rev;
        int maxVal = rev->val;

        while (temp->next) {
            if (temp->next->val < maxVal) {
                temp->next = temp->next->next;
            } 
            else temp = temp->next;
            maxVal = max(maxVal, temp->val);
        }

        head = reverseList(rev);

        return head;
    }
};