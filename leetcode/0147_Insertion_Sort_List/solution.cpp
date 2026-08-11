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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* sortNode = dummy;

        while (sortNode->next) {
            ListNode *smallNode = sortNode->next, *temp = sortNode->next;
            while (temp) {
                if (temp->val < smallNode->val) {
                    smallNode = temp;
                }
                temp = temp->next;
            }
            swap(smallNode->val, sortNode->next->val);
            sortNode = sortNode->next;
        }

        return dummy->next;
    }
};