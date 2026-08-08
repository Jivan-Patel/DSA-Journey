class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* temp = head;

        vector<ListNode*> splitList(k, nullptr);

        while (temp) {
            length++;
            temp = temp->next;
        }

        int extra = length % k;
        temp = head;

        for (int i = 0; i < k - 1; i++) {
            int elements = length / k - 1;
            ListNode* curList = temp;

            if (extra > 0) {
                elements++;
                extra--;
            }

            while (temp && elements > 0) {
                elements--;
                temp = temp->next;
            }

            if (temp) {
                ListNode* lastNode = temp;
                temp = temp->next;
                lastNode->next = nullptr;
            }

            splitList[i] = curList;
        }

        splitList.back() = temp;

        return splitList;
    }
};