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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        k %= count;
        if (k == 0) return head;

        temp = head;

        int steps = count - k - 1;
        while (steps > 0) {
            temp = temp->next;
            steps--;
        }

        cout << temp->val;
        ListNode* newHead = temp->next;
        temp->next = nullptr;

        temp = newHead;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = head;
        head = newHead;
        
        return head;
    }
};