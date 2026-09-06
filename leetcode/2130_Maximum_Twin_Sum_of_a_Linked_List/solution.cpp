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
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* rev = nullptr;

        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = rev;
            rev = head;
            head = next;
        }

        return rev;
    }

public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* rev = reverseList(slow);

        int maxTwinSum = head-> val + rev->val;

        while(rev != nullptr && head != nullptr) {
            maxTwinSum = max(maxTwinSum, head->val + rev->val);
            rev = rev->next;
            head = head->next;
        }

        return maxTwinSum;
    }
};