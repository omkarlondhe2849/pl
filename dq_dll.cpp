#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *prev;
        Node() : data(0), next(NULL), prev(NULL) {}
};

class DQ {
    public:
        Node *front, *rear;
        DQ() : front(NULL), rear(NULL) {}
        void insertAtRear(int value);
        void insertAtFront(int value);
        void deleteRear();
        void deleteFront();
        bool isEmpty();
        void display();
};

void DQ::insertAtRear(int value) {
    Node *temp = new Node();
    temp->data = value;
    if (isEmpty()) {
        front = rear = temp;
    } else {
        rear->next = temp;
        temp->prev = rear;
        rear = temp;
    }
}

void DQ::insertAtFront(int value) {
    Node *temp = new Node();
    temp->data = value;
    if (isEmpty()) {
        front = rear = temp;
    } else {
        temp->next = front;
        front->prev = temp;
        front = temp;
    }
}

void DQ::deleteFront() {
    if (isEmpty()) {
        cout << "EMPTY" << endl;
    } else {
        Node *p = front;
        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
            front->prev = NULL;
        }
        delete p;
    }
}

void DQ::deleteRear() {
    if (isEmpty()) {
        cout << "EMPTY" << endl;
    } else {
        Node *p = rear;
        if (front == rear) {
            front = rear = NULL;
        } else {
            rear = rear->prev;
            rear->next = NULL;
        }
        delete p;
    }
}

void DQ::display() {
    if (isEmpty()) {
        cout << "EMPTY" << endl;
    } else {
        Node *p = front;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

bool DQ::isEmpty() {
    return front == NULL;
}

int main() {
    DQ d1, d2;
    int ch, cht, value;

    do {
        cout << "1. Input Restricted\n2. Output Restricted\n0. Exit\nEnter your choice: ";
        cin >> cht;
        switch (cht) {
            case 1:
                do {
                    cout << "1. Insert Rear\n2. Delete Rear\n3. Delete Front\n4. Display\n0. Exit\nEnter your choice: ";
                    cin >> ch;
                    switch (ch) {
                        case 1:
                            cout << "Enter the value: ";
                            cin >> value;
                            d1.insertAtRear(value);
                            break;
                        case 2:
                            d1.deleteRear();
                            break;
                        case 3:
                            d1.deleteFront();
                            break;
                        case 4:
                            d1.display();
                            break;
                    }
                } while (ch != 0);
                break;
            case 2:
                do {
                    cout << "1. Insert Rear\n2. Insert Front\n3. Delete Front\n4. Display\n0. Exit\nEnter your choice: ";
                    cin >> ch;
                    switch (ch) {
                        case 1:
                            cout << "Enter the value: ";
                            cin >> value;
                            d2.insertAtRear(value);
                            break;
                        case 2:
                            cout << "Enter the value: ";
                            cin >> value;
                            d2.insertAtFront(value);
                            break;
                        case 3:
                            d2.deleteFront();
                            break;
                        case 4:
                            d2.display();
                            break;
                    }
                } while (ch != 0);
                break;
        }
    } while (cht != 0);
    
    return 0;
}
