#include <iostream>
using namespace std;

class Deque {
    int front, rear, size;
    int *arr;

public:
    Deque(int capacity) {
        size = capacity;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertAtFront(int value) {
        if (isFull()) {
            cout << "Deque is full" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front = front - 1;
        }
        arr[front] = value;
    }

    void insertAtRear(int value) {
        if (isFull()) {
            cout << "Deque is full" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }
        arr[rear] = value;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear = rear - 1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        cout << "Deque elements are: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        } else {
            for (int i = front; i < size; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity, choice, subChoice, value;
    cout << "Enter the capacity of the deque: ";
    cin >> capacity;
    Deque dq(capacity);

    do {
        cout << "\n1. Input-Restricted Deque\n2. Output-Restricted Deque\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Input-Restricted Deque (Only Insert at Rear)
                do {
                    cout << "\nInput-Restricted Deque Menu:\n";
                    cout << "1. Insert at Rear\n2. Delete from Front\n3. Delete from Rear\n4. Display\n0. Exit\nEnter your choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter the value to insert at rear: ";
                            cin >> value;
                            dq.insertAtRear(value);
                            break;
                        case 2:
                            dq.deleteFront();
                            break;
                        case 3:
                            dq.deleteRear();
                            break;
                        case 4:
                            dq.display();
                            break;
                        case 0:
                            cout << "Returning to main menu...\n";
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                    }
                } while (subChoice != 0);
                break;

            case 2: // Output-Restricted Deque (Only Delete from Front)
                do {
                    cout << "\nOutput-Restricted Deque Menu:\n";
                    cout << "1. Insert at Rear\n2. Insert at Front\n3. Delete from Front\n4. Display\n0. Exit\nEnter your choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter the value to insert at rear: ";
                            cin >> value;
                            dq.insertAtRear(value);
                            break;
                        case 2:
                            cout << "Enter the value to insert at front: ";
                            cin >> value;
                            dq.insertAtFront(value);
                            break;
                        case 3:
                            dq.deleteFront();
                            break;
                        case 4:
                            dq.display();
                            break;
                        case 0:
                            cout << "Returning to main menu...\n";
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                    }
                } while (subChoice != 0);
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    delete[] dq.arr; // Clean up dynamically allocated memory
    return 0;
}
