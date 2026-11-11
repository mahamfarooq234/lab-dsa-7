#include <iostream>
#include <string>
using namespace std;

// Priority: 1 = Research (sabse zyada urgent), 2 = Assignment, 3 = Casual reading

class Student {
public:
    string name;
    int priority;
    Student* next;
    Student(string n, int p) {
        name = n;
        priority = p;
        next = NULL;
    }
};

string priorityName(int p) {
    if (p == 1) return "Research";
    if (p == 2) return "Assignment";
    return "Casual";
}

class Book {
    string title;
    Student* head;
public:
    Book(string t) {
        title = t;
        head = NULL;
    }

    // priority ke hisab se sahi jagah pe add (same priority = pehle aaya pehle)
    void addStudent(string name, int priority = 3) {
        Student* s = new Student(name, priority);

        if (head == NULL || priority < head->priority) {
            s->next = head;
            head = s;
        } else {
            Student* temp = head;
            while (temp->next != NULL && temp->next->priority <= priority)
                temp = temp->next;
            s->next = temp->next;
            temp->next = s;
        }
    }

    // true return karta hai agar remove hua
    bool removeStudent(string name) {
        if (head == NULL) return false;

        if (head->name == name) {
            Student* del = head;
            head = head->next;
            delete del;
            return true;
        }
        Student* temp = head;
        while (temp->next != NULL && temp->next->name != name)
            temp = temp->next;

        if (temp->next == NULL) return false;

        Student* del = temp->next;
        temp->next = del->next;
        delete del;
        return true;
    }

    // purana node hata ke nayi priority ke sath dobara add
    void updatePriority(string name, int newPriority) {
        if (removeStudent(name)) {
            addStudent(name, newPriority);
            cout << name << " ki priority " << priorityName(newPriority) << " ho gayi\n";
        } else {
            cout << name << " list mein nahi mila\n";
        }
    }

    void display() {
        cout << "--- " << title << " ki reservation list ---\n";
        if (head == NULL) {
            cout << "(khali)\n";
            return;
        }
        Student* temp = head;
        int no = 1;
        while (temp != NULL) {
            cout << no << ". " << temp->name << " [" << priorityName(temp->priority) << "]\n";
            temp = temp->next;
            no++;
        }
    }

    int count() {
        int c = 0;
        Student* temp = head;
        while (temp != NULL) {
            c++;
            temp = temp->next;
        }
        return c;
    }

    // book return hui -> front wale student ko de do
    void bookReturned() {
        if (head == NULL) {
            cout << title << ": koi reservation nahi hai\n";
            return;
        }
        Student* del = head;
        cout << title << " ab " << del->name << " ko issue ho gayi\n";
        head = head->next;
        delete del;
    }
};

int main() {
    Book book1("Data Structures");
    Book book2("Database Systems");

    cout << "=== Book 1 ===\n";
    book1.addStudent("Ali", 3);
    book1.addStudent("Sara", 2);
    book1.addStudent("Ahmed", 1);
    book1.addStudent("Hina", 3);
    book1.display();
    cout << "Total: " << book1.count() << endl;

    cout << "\nHina ki priority update:\n";
    book1.updatePriority("Hina", 1);
    book1.display();

    cout << "\nSara cancel kar rahi hai:\n";
    book1.removeStudent("Sara");
    book1.display();

    cout << "\nBook return ho gayi:\n";
    book1.bookReturned();
    book1.display();
    cout << "Total: " << book1.count() << endl;

    cout << "\n=== Book 2 ===\n";
    book2.addStudent("Usman");
    book2.addStudent("Ayesha", 1);
    book2.addStudent("Bilal", 2);
    book2.display();
    cout << "Total: " << book2.count() << endl;
    book2.bookReturned();
    book2.display();

    return 0;
}
