#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    
    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class IntLinkedList {
public:
    Node* head;

    IntLinkedList() {
        head = nullptr;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->value;
            if (current->next) cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void deleteValue(int value) {
        Node* current = head;
        if (current && current->value == value) {
            head = current->next;
            delete current;
            return;
        }
        
        Node* prev = nullptr;
        while (current) {
            if (current->value == value) {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    bool search(int value) {
        Node* current = head;
        while (current) {
            if (current->value == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    IntLinkedList linkedList;
    linkedList.append(5);
    linkedList.append(10);
    linkedList.append(15);
    linkedList.display();

    linkedList.insertAtBeginning(0);
    linkedList.display();

    linkedList.deleteValue(10);
    linkedList.display();

    cout << "Found 5: " << linkedList.search(5) << endl;
    cout << "Found 20: " << linkedList.search(20) << endl;

    return 0;
}
