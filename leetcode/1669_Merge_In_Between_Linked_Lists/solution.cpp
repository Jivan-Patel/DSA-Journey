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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i = 0;
        ListNode* temp1 = list1;
        while(i < a-1) {
            i++;
            temp1 = temp1->next;
        }

        ListNode* lastJoin = temp1;
        temp1 = temp1->next;

        while(i < b) {
            i++;
            temp1 = temp1->next;
        }

        ListNode* temp2 = list2;
        while(temp2->next) {
            temp2 = temp2->next;
        }

        lastJoin->next = list2;
        temp2->next = temp1;

        return list1;
    }
};