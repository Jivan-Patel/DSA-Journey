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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) {
            head = nullptr;
            return head;
        }
        ListNode* temp = head;
        int len = 0;

        while (temp) {
            len++;
            temp = temp->next;
        }
        int deleteIdx = len - n - 1;
        temp = head;

        if (deleteIdx < 0) {
            head = head->next;
            temp->next = nullptr;
            delete temp;
            return head;
        }

        while (deleteIdx > 0) {
            temp = temp->next;
            deleteIdx--;
        }

        ListNode* deleteNode = temp->next;
        temp->next = deleteNode->next;
        deleteNode->next = nullptr;
        
        delete deleteNode;

        return head;
    }
};