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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

public:
    void reorderList(ListNode* head) { 
        if (head->next == nullptr || head->next->next == nullptr ) return;

        ListNode *fast = head, *slow = head;

        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* revHalf = reverseList(slow->next);
        slow->next = nullptr;

        ListNode *temp1 = head, *temp2 = revHalf;
        while(temp1 && temp2){
            ListNode* temp3 = temp1->next;
            ListNode* temp4 = temp2->next;
            temp1->next = temp2;
            temp2->next = temp3;
            temp1 = temp3;
            temp2 = temp4;
        }
    }
};