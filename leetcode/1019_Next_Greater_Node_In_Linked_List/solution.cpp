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
    vector<int> nextLargerNodes(ListNode* head) {
        int maxVal = 0;
        vector<int> res;
        ListNode* temp1 = head;

        while (temp1) {
            ListNode* temp2 = temp1->next;
            while(temp2 && temp2->val <= temp1->val) {
                temp2 = temp2->next;
            }
            res.push_back(temp2 ? temp2->val : 0);

            temp1 = temp1->next;
        }
        return res;
    }
};