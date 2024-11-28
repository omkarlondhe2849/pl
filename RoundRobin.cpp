#include <iostream>
#define max 50
using namespace std;

class Process {
public:
    int process_id;
    int BT; // Burst Time
    int RT; // Remaining Time
};

class ProcessQueue {
public:
    Process data[max];
    int rear, front;

    ProcessQueue() {
        rear = front = -1;
    }

    int isempty() {
        return rear == -1;
    }

    int isfull() {
        return (rear + 1) % max == front;
    }

    void enqueue(Process x) {
        if (isfull()) {
            cout << "Queue is full! Cannot insert the element!" << endl;
        } else if (isempty()) {
            rear = front = 0;
            data[0] = x;
        } else {
            rear = (rear + 1) % max;
            data[rear] = x;
        }
    }

    Process dequeue() {
        Process x;
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return x;
        } else {
            x = data[front];
            if (rear == front) {
                rear = front = -1; // Reset queue if last element is dequeued
            } else {
                front = (front + 1) % max;
            }
        }
        return x;
    }
};

void RoundRobin(ProcessQueue &pq, int QT) {
    int total_time = 0;
    while (!pq.isempty()) {
        Process p = pq.dequeue();
        if (p.RT > QT) {
            total_time += QT;
            p.RT -= QT;
            cout << "Process " << p.process_id << " scheduled for " << QT 
                 << " units; Remaining time: " << p.RT << endl;
            pq.enqueue(p); // Re-enqueue process with remaining time
        } else {
            total_time += p.RT;
            cout << "Process " << p.process_id << " completed execution; "
                 << "Time used: " << p.RT << " units." << endl;
        }
    }
    cout << "Total time for all processes: " << total_time << " units." << endl;
}

int main() {
    ProcessQueue pq;
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Process p;
        cout << "Enter process ID and Burst Time: ";
        cin >> p.process_id >> p.BT;
        p.RT = p.BT; // Initialize remaining time to burst time
        pq.enqueue(p);
    }

    int QT;
    cout << "Enter the Quantum Time: ";
    cin >> QT;

    RoundRobin(pq, QT);

    return 0;
}
