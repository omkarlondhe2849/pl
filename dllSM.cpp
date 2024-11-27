#include <iostream>
using namespace std;

class node {
public:
    int val;
    node* next;
    node* prev;

    node() : val(0), next(nullptr), prev(nullptr) {}
    node(int value) : val(value), next(nullptr), prev(nullptr) {}
};

class dll {
public:
    node* head;

    dll() : head(nullptr) {}

    void create();
    void display();
    void sort();
    void merge(dll& l2);
};

void dll::create() {
    char ch;
    node* temp;
    node* p;
    do {
        int value;
        cout << "Enter a value: ";
        cin >> value;
        temp = new node(value);
        if (head == nullptr) {
            head = temp;
        } else {
            p = head;
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = temp;
            temp->prev = p;
        }
        cout << "Add more elements? (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

void dll::display() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    node* p = head;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

void dll::sort() {
    if (head == nullptr || head->next == nullptr) return;

    for (node* i = head; i != nullptr; i = i->next) {
        for (node* j = head; j->next != nullptr; j = j->next) {
            if (j->val > j->next->val) {
                std::swap(j->val, j->next->val);
            }
        }
    }
}
void dll::merge(dll& l2) {
    dll l3;
    node* p = head;
    node* q = l2.head;

    if (p == nullptr) return l2;
    if (q == nullptr) return *this;

    if (p->val <= q->val) {
        l3.head = p;
        p = p->next;
    } else {
        l3.head = q;
        q = q->next;
    }

    node* r = l3.head;

    while (p != nullptr && q != nullptr) {
        if (p->val <= q->val) {
            r->next = p;
            p->prev = r;
            r = p;
            p = p->next;
        } else {
            r->next = q;
            q->prev = r;
            r = q;
            q = q->next;
        }
    }

    if (p != nullptr) {
        r->next = p;
        p->prev = r;
    }

    if (q != nullptr) {
        r->next = q;
        q->prev = r;
    }
}



int main() {
    dll l1, l2, l3;
    
    cout << "Creating first list:\n";
    l1.create();
    cout << "Sorting first list...\n";
    l1.sort();
    cout << "First list after sorting:\n";
    l1.display();

    cout << "Creating second list:\n";
    l2.create();
    cout << "Sorting second list...\n";
    l2.sort();
    cout << "Second list after sorting:\n";
    l2.display();

    cout << "Merging the two sorted lists...\n";
    l3 = l1.merge(l2);
    cout << "Merged list:\n";
    l3.display();

    return 0;
}
