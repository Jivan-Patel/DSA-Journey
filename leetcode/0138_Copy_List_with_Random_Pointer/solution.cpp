/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> track;

        Node* temp = head;
        while(temp) {
            Node* newNode = new Node(temp->val);
            track[temp] = newNode;
            temp = temp->next;
        }

        temp = head;
        while(temp) {
            track[temp]->next = track[temp->next];
            track[temp]->random = track[temp->random];
            temp = temp->next;
        }

        return track[head];
    }
};