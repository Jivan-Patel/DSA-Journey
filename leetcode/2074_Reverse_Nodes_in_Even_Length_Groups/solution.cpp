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
        if (head == nullptr || head->next == nullptr) return head;

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || head == nullptr || head->next == nullptr) return head;
        int i = 1;
        ListNode* travel = head;
        while (i < left - 1 && travel->next) {
            travel = travel->next;
            i++;
        }

        ListNode* mid = left > 1 ? travel->next : head;
        if (left > 1) travel->next = nullptr;
        ListNode* firstEnd = travel;
        travel = mid;

        for(int i = left; travel && i < right; i++) {
            travel = travel->next;
        }
        
        ListNode* last = nullptr;
        if(travel) {
            last = travel->next;
            travel->next = nullptr;
        }

        ListNode* revMid = reverseList(mid);

        if(left > 1) firstEnd->next = revMid;
        else head = revMid;

        mid->next = last;

        return head;
    }

public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int groupLen = 1, left = 1;
        ListNode* temp = head;

        while(temp != nullptr) {
            int len = 0;
            while(temp && len < groupLen) {
                temp = temp->next;
                len++;
            }
            int right = left + len - 1;
            
            if(len % 2 == 0) {
                head = reverseBetween(head, left, right);
            } 
            
            left = right + 1;
            groupLen++;
        } 

        return head;
    }
};