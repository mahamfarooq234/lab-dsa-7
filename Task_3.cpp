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

Node* head = NULL;

int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtPosition(int value, int pos) {
    int total = countNodes();
    if (pos < 1 || pos > total + 1) {
        cout << "Galat position!\n";
        return;
    }
    Node* newNode = new Node(value);
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(int pos) {
    int total = countNodes();
    if (pos < 1 || pos > total) {
        cout << "Galat position!\n";
        return;
    }
    Node* del;
    if (pos == 1) {
        del = head;
        head = head->next;
    } else {
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;
        del = temp->next;
        temp->next = del->next;
    }
    delete del;
}

void searchElement(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << value << " position " << pos << " pe mila\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << value << " list mein nahi hai\n";
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value, pos;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert at position\n";
        cout << "2. Delete at position\n";
        cout << "3. Search element\n";
        cout << "4. Count nodes\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Value: ";    cin >> value;
            cout << "Position: "; cin >> pos;
            insertAtPosition(value, pos);
        }
        else if (choice == 2) {
            cout << "Position: "; cin >> pos;
            deleteAtPosition(pos);
        }
        else if (choice == 3) {
            cout << "Value: "; cin >> value;
            searchElement(value);
        }
        else if (choice == 4) {
            cout << "Total nodes: " << countNodes() << endl;
        }
        else if (choice == 5) {
            display();
        }
    } while (choice != 6);

    return 0;
}
