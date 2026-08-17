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
        if (head == nullptr || head->next == nullptr)
            return head;

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
        if (left == right || head == nullptr || head->next == nullptr)
            return head;
        int i = 1;
        ListNode* travel = head;
        while (i < left - 1 && travel->next) {
            travel = travel->next;
            i++;
        }

        ListNode* mid = left > 1 ? travel->next : head;
        if (left > 1)
            travel->next = nullptr;
        ListNode* firstEnd = travel;
        travel = mid;

        for (int i = left; i < right; i++) {
            travel = travel->next;
        }

        ListNode* last = nullptr;
        if (travel) {
            last = travel->next;
            travel->next = nullptr;
        }

        ListNode* revMid = reverseList(mid);

        if (left > 1) firstEnd->next = revMid;
        else head = revMid;

        mid->next = last;

        return head;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;

        while (temp) {
            temp = temp->next;
            len++;
        }
        
        for (int i = 1; i + k - 1 <= len; i += k) {
            cout << i << " " << i + k - 1 << endl;
            head = reverseBetween(head, i, i + k - 1);
        }

        return head;
    }
};