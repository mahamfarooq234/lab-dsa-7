#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    Patient* next;
    Patient(string n) {
        name = n;
        next = NULL;
    }
};

class PatientQueue {
    Patient* head;
public:
    PatientQueue() { head = NULL; }

    // naya patient end pe
    void addPatient(string name) {
        Patient* p = new Patient(name);
        if (head == NULL) {
            head = p;
        } else {
            Patient* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = p;
        }
        cout << name << " queue mein add ho gaya\n";
    }

    // cancel karne wala patient remove
    void removePatient(string name) {
        if (head == NULL) {
            cout << "Queue khali hai\n";
            return;
        }
        if (head->name == name) {
            Patient* del = head;
            head = head->next;
            delete del;
            cout << name << " ne cancel kar diya\n";
            return;
        }
        Patient* temp = head;
        while (temp->next != NULL && temp->next->name != name)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << name << " queue mein nahi mila\n";
            return;
        }
        Patient* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << name << " ne cancel kar diya\n";
    }

    void display() {
        if (head == NULL) {
            cout << "Queue khali hai\n";
            return;
        }
        Patient* temp = head;
        int no = 1;
        while (temp != NULL) {
            cout << no << ". " << temp->name << endl;
            temp = temp->next;
            no++;
        }
    }

    int count() {
        int c = 0;
        Patient* temp = head;
        while (temp != NULL) {
            c++;
            temp = temp->next;
        }
        return c;
    }
};

int main() {
    PatientQueue q;

    q.addPatient("Ali");
    q.addPatient("Sara");
    q.addPatient("Ahmed");
    q.addPatient("Fatima");

    cout << "\nCurrent queue:\n";
    q.display();
    cout << "Total patients: " << q.count() << endl;

    cout << "\n";
    q.removePatient("Sara");

    cout << "\nQueue after cancel:\n";
    q.display();
    cout << "Total patients: " << q.count() << endl;

    return 0;
}
