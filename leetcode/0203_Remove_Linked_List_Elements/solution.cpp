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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        while(head != nullptr && head->val == val){
            ListNode* deleteNode = head;
            head = head->next;
            deleteNode->next = nullptr;
            delete deleteNode;
        }
        if(head == nullptr) return head;

        ListNode* temp = head;
        while(temp->next != nullptr) {
            while(temp->next != nullptr && temp->next->val != val) {
                temp = temp->next;
            }
            if(temp->next != nullptr) {
                ListNode* deleteNode = temp->next;
                temp->next = temp->next->next;
                deleteNode->next = nullptr;
                delete deleteNode;
            }
        }

        // if(head->val == val && head->next ==  nullptr){
        //     head = nullptr;
        // }

        return head;
    }
};