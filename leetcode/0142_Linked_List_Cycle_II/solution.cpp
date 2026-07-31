/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> track;
        ListNode* temp = head;

        while (temp != nullptr) {
            if (track.count(temp)) return temp;
            track.insert(temp);
            temp = temp->next;
        }

        return nullptr;
    }
};