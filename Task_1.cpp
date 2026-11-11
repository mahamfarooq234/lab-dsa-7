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

Node* head = NULL;   // koi tail pointer nahi

// Node banao aur end pe laga do
void CreateNode(int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {          // list khali hai
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)   // last node tak jao
        temp = temp->next;
    temp->next = newNode;
}

void Display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    CreateNode(10);
    CreateNode(20);
    CreateNode(30);
    CreateNode(40);
    Display();
    return 0;
}
