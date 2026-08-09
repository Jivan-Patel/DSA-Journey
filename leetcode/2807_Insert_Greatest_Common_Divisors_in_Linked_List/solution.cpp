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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;

        while (temp->next) {
            int a = temp->val, b = temp->next->val;            
            while(b != 0) {
                int rem = a % b;
                a = b;
                b = rem;
            }

            ListNode* gcdNode = new ListNode(a, temp->next);
            temp->next = gcdNode;

            temp = gcdNode->next;
        }

        return head;
    }
};