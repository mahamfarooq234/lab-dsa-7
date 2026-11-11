#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void deleteByValue(int value) {
        if (head == NULL) {
            cout << "List khali hai\n";
            return;
        }
        // agar pehla node hi delete karna hai
        if (head->data == value) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Value " << value << " nahi mili\n";
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBeginning(10);
    list.insertAtEnd(40);
    cout << "List: ";
    list.display();

    list.deleteByValue(30);
    cout << "30 delete ke baad: ";
    list.display();

    list.deleteByValue(99);
    return 0;
}
