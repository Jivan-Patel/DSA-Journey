/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) return head;

        Node* temp = head;
        stack<Node*> track;

        while (temp != nullptr) {
            if(temp->child != nullptr) {
                if(temp->next) track.push(temp->next);
                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = nullptr;
            }
            temp = temp->next;
        }

        temp = head;

        while (track.size() > 0) {
            while(temp->next) temp = temp->next;
            temp->next = track.top();
            temp->next->prev = temp;
            track.pop();
        }

        return head;
    }
};