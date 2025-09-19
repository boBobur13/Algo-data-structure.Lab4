#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Linked List class
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    // Insert node at end
    void insert(int val) {
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

    // Method to calculate size using single traversal
    int size() const {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    LinkedList list;

    // Build a list
    list.insert(10);
    list.insert(20);
    list.insert(30);

    // Call size()
    cout << "Size = " << list.size() << endl;

    return 0;
}
