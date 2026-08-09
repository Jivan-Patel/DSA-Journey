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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp = dummy;
        unordered_set <int> track(nums.begin(), nums.end());

        while(temp->next) {
            if(track.count(temp->next->val) > 0) {
                temp->next = temp->next->next;
            }
            else temp = temp->next;
        }
        return dummy->next;
    }
};