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
    ListNode* middleNode(ListNode* head) {
        if (head->next == nullptr)
            return head;

        ListNode *fast = head, *slow = head;

        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next)
            return slow->next;

        return slow;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = middleNode(head);
        ListNode* rev = reverseList(mid);

        ListNode* temp1 = head, *temp2 = rev;
        while(temp1 != mid) {
            if(temp1->val != temp2->val) return 0;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return 1;
    }
};