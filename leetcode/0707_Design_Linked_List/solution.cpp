class Node {
public:
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = nullptr;
    }
};

class MyLinkedList {
private:
    Node* head;

public:
    MyLinkedList() { head = nullptr; }

    int get(int index) {
        if (head == nullptr)
            return -1;

        int i = 0;
        Node* temp = head;

        while (temp && i < index) {
            i++;
            temp = temp->next;
        }

        if (temp && i == index)
            return temp->val;

        return -1;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if (head != nullptr) {
            newNode->next = head;
        }
        head = newNode;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;
        int i = 0;

        while (temp->next && i < index - 1) {
            i++;
            temp = temp->next;
        }
        if (temp == nullptr || i != index - 1)
            return;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (head == nullptr) return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
            return;
        }
        Node* temp = head;
        int i = 0;
        while (temp->next && i < index - 1) {
            i++;
            temp = temp->next;
        }
        if (i != index - 1) return;

        if (temp->next == nullptr) return;

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */