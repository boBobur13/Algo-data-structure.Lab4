#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string value;
    Node* next;

    Node(const string& val) {
        value = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = nullptr;
    }

    void addBack(const string& e) {
        Node* newNode = new Node(e);
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
            if (current->next) cout << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int N;
    cin >> N;

    SinglyLinkedList list;
    string element;

    for (int i = 0; i < N; ++i) {
        cin >> element;
        list.addBack(element);
    }

    list.display();
    return 0;
}
