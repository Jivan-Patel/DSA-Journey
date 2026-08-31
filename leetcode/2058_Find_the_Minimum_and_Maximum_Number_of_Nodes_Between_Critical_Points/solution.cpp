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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        pair<int, int> criticalPts = {-1, -1};

        int i = 1, prev = head->val, minDis = INT_MAX;
        head = head->next;

        while (head->next != nullptr) {
            if ((head->val > prev && head->val > head->next->val) ||
                (head->val < prev && head->val < head->next->val)) {
                if (criticalPts.first == -1) {
                    criticalPts.first = i;
                } 
                else {
                    if (criticalPts.second != -1) {
                        minDis = min(minDis, i - criticalPts.second);
                    }
                    else {
                        minDis = min(minDis, i - criticalPts.first);
                    }
                    criticalPts.second = i;
                }
            }
            prev = head->val;
            head = head->next;
            i++;
        }

        vector<int> ans(2, -1);
        if(criticalPts.second == -1) return ans;

        ans[0] = minDis;
        ans[1] = criticalPts.second - criticalPts.first;

        return ans;
    }
};