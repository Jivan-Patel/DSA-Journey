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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* t1 = l1, *t2 = l2, *temp = head;

        while(t1 != nullptr && t2 != nullptr) {
            carry += t1->val + t2->val;
            ListNode* newNode = new ListNode(carry % 10);
            temp->next = newNode;

            carry /= 10;

            t1 = t1->next;
            t2 = t2->next;
            temp = temp->next;
        }

        while(t1 != nullptr) {
            carry += t1->val;
            ListNode* newNode = new ListNode(carry % 10);
            temp->next = newNode;

            carry /= 10;

            t1 = t1->next;
            temp = temp->next;
        }

        while(t2 != nullptr) {
            carry += t2->val;
            ListNode* newNode = new ListNode(carry % 10);
            temp->next = newNode;

            carry /= 10;

            t2 = t2->next;
            temp = temp->next;
        }

        if(carry > 0) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }

        return head->next;
    }
};