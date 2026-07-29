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
private:


public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) {
            head = nullptr;
            return head;
        }

        int count = 0;
        ListNode* temp = head;
        
        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }
        int half = (count / 2) - 1;
        count = 0;

        temp = head;
        while(count < half) {
            temp = temp->next;
            count++;
        }

        ListNode* deleteNode = temp->next;
        temp->next = temp->next->next;

        deleteNode->next = nullptr;
        delete deleteNode;

        return head;
    }
};