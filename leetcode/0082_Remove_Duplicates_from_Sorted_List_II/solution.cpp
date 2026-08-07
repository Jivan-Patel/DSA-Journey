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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0, head);

        ListNode* unique = dummy, *travel = head;

        while(travel && travel->next) {
            if(travel->val != travel->next->val) {
                unique->next = travel;
                unique = travel;
            }
            while(travel->next && travel->val == travel->next->val) {
                travel = travel->next;
            }
            travel = travel->next;         
        }

        if(travel) {
            unique->next = travel;
            unique = travel;
        }
        
        unique->next = nullptr;
        
        return dummy->next;
    }
};