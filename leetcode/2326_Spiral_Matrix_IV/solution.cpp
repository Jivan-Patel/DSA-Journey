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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int i = 0, j = 0;
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        ListNode* temp = head;

        while (temp) {
            // left -> right
            while (temp && j < n && matrix[i][j] == -1) {
                matrix[i][j] = temp->val;
                temp = temp->next;
                j++;
            }
            j--;

            // top->bottom
            i++;
            while (temp && i < m && matrix[i][j] == -1) {
                matrix[i][j] = temp->val;
                temp = temp->next;
                i++;
            }
            i--;

            // right->left
            j--;
            while (temp && j >= 0 && matrix[i][j] == -1) {
                matrix[i][j] = temp->val;
                temp = temp->next;
                j--;
            }
            j++;

            // bottom->top
            i--;
            while (temp && i >= 0 && matrix[i][j] == -1) {
                matrix[i][j] = temp->val;
                temp = temp->next;
                i--;
            }
            i++;

            j++;
        }
        
        return matrix;
    }

};