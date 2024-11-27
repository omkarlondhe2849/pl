#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    int id;
    string name;
    float price;
    int quantity;
    Item *next;

    Item() {
        next = NULL;
    }
};

class BillingSystem {
    Item *head;
public:
    BillingSystem() {
        head = NULL;
    }

    void addItem();
    void insertItem();
    void displayItems();
    void removeItem();
    void updateItem();
    void calculateTotal();
    void sortItems();
};

void BillingSystem::addItem() {
    Item *temp = new Item();
    cout << "Enter Item ID: ";
    cin >> temp->id;
    cout << "Enter Item Name: ";
    cin >> temp->name;
    cout << "Enter Price: ";
    cin >> temp->price;
    cout << "Enter Quantity: ";
    cin >> temp->quantity;

    if (head == NULL) {
        head = temp;
    } else {
        Item *p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

void BillingSystem::insertItem() {
    Item *temp = new Item();
    cout << "Enter Item ID: ";
    cin >> temp->id;
    cout << "Enter Item Name: ";
    cin >> temp->name;
    cout << "Enter Price: ";
    cin >> temp->price;
    cout << "Enter Quantity: ";
    cin >> temp->quantity;

    int position;
    cout << "Enter insertion position (1 = Beginning, 2 = After specific ID, 3 = End): ";
    cin >> position;

    if (position == 1) {
        // Insert at beginning
        temp->next = head;
        head = temp;
    } else if (position == 2) {
        // Insert after a specific item ID
        int afterId;
        cout << "Enter the ID after which to insert: ";
        cin >> afterId;
        Item *p = head;
        while (p != NULL && p->id != afterId) {
            p = p->next;
        }
        if (p != NULL) {
            temp->next = p->next;
            p->next = temp;
        } else {
            cout << "ID not found. Adding item at the end.\n";
            Item *p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }
    } else if (position == 3) {
        // Insert at end
        if (head == NULL) {
            head = temp;
        } else {
            Item *p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }
    } else {
        cout << "Invalid position choice.\n";
    }
}

void BillingSystem::displayItems() {
    Item *p = head;
    if (p == NULL) {
        cout << "Cart is empty!" << endl;
        return;
    }
    cout << "\nID\tName\tPrice\tQuantity\n";
    while (p != NULL) {
        cout << p->id << "\t" << p->name << "\t" << p->price << "\t" << p->quantity << endl;
        p = p->next;
    }
}

void BillingSystem::removeItem() {
    int id;
    cout << "Enter Item ID to remove: ";
    cin >> id;
    Item *p = head, *prev = NULL;
    bool found = false;

    while (p != NULL) {
        if (p->id == id) {
            found = true;
            if (p == head) {
                head = head->next;
            } else {
                prev->next = p->next;
            }
            delete p;
            cout << "Item removed successfully.\n";
            return;
        }
        prev = p;
        p = p->next;
    }
    if (!found) cout << "Item not found!" << endl;
}

void BillingSystem::updateItem() {
    int id;
    cout << "Enter Item ID to update: ";
    cin >> id;
    Item *p = head;
    while (p != NULL) {
        if (p->id == id){
            cout << "Enter new Price: ";
            cin >> p->price;
            cout << "Enter new Quantity: ";
            cin >> p->quantity;
            cout << "Item updated successfully.\n";
            return;
        }
        p = p->next;
    }
    cout << "Item not found!" << endl;
}

void BillingSystem::calculateTotal() {
    Item *p = head;
    float total = 0;
    while (p != NULL) {
        total += (p->price * p->quantity);
        p = p->next;
    }
    cout << "Total amount: $" << total << endl;
}

void BillingSystem::sortItems() {
    if (head == NULL || head->next == NULL) return;
    for (Item *p = head; p->next != NULL; p = p->next) {
        for (Item *q = head; q->next != NULL; q = q->next) {
            if (q->price > q->next->price) { // Sort by price
                swap(q->id, q->next->id);
                swap(q->name, q->next->name);
                swap(q->price, q->next->price);
                swap(q->quantity, q->next->quantity);
            }
        }
    }
}

int main() {
    BillingSystem bs;
    int choice;
    do {
        cout << "\n1. Add Item\n2. Insert Item\n3. Display Items\n4. Remove Item\n5. Update Item\n6. Calculate Total\n7. Sort Items by Price\n8. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: bs.addItem(); break;
            case 2: bs.insertItem(); break;
            case 3: bs.displayItems(); break;
            case 4: bs.removeItem(); break;
            case 5: bs.updateItem(); break;
            case 6: bs.calculateTotal(); break;
            case 7: bs.sortItems(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 8);
    return 0;
}
