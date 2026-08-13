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
    ListNode* doubleIt(ListNode* head) {
        ListNode* revHead = reverseList(head);
        
        int carry = 0;
        ListNode* temp = revHead;

        while(temp->next != nullptr) {
            carry += (temp->val * 2);
            temp->val = (carry % 10);

            carry /= 10;

            temp = temp->next;
        }

        carry += (temp->val * 2);
        temp->val = (carry % 10);
        carry /= 10;

        if(carry > 0) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }

        return reverseList(revHead);
    }
};