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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* mid = head;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            mid = mid->next;
        }
        ListNode* temp = mid;
        ListNode* prev = NULL;
        
        while(temp != NULL) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        
        while(head != mid) {
            if(head->val != prev->val) {
                return false;
            }
            head = head->next;
            prev = prev->next;
        }
        return true;

    }
};