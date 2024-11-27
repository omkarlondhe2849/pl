#include <iostream>
using namespace std;

class Mango {
public:
    string category;
    int numberOfMangoes;

    Mango() {
        category = "";
        numberOfMangoes = -1;
    }

    Mango(string cat, int num) {
        category = cat;
        numberOfMangoes = num;
    }
};

class MangoHashTable {
private:
    Mango* table;
    int size;

public:
    MangoHashTable(int s) {
        size = s;
        table = new Mango[size];
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(const Mango& mango) {
        int index = hashFunction(mango.numberOfMangoes);
        int i = 0;
        int newIndex = index;

        // Quadratic Probing to handle collisions
        while (table[newIndex].numberOfMangoes != -1 && i < size) {
            i++;
            newIndex = (index + i * i) % size;
        }

        if (i == size) {
            cout << "Hash table is full, can't insert more mangoes." << endl;
            return;
        }

        table[newIndex] = mango;
    }

    Mango* search(int key) {
        int index = hashFunction(key);
        int i = 0;
        int newIndex = index;

        while (i < size) {
            if (table[newIndex].numberOfMangoes == key) {
                return &table[newIndex];
            }
            i++;
            newIndex = (index + i * i) % size;
        }
        return NULL;
    }

    void display() {
        cout << "Mango Varieties Hash Table:" << endl;
        for (int i = 0; i < size; ++i) {
            if (table[i].numberOfMangoes != -1) {
                cout << "Index " << i << ": Category: " << table[i].category
                     << ", Number of Mangoes: " << table[i].numberOfMangoes << endl;
            } else {
                cout << "Index " << i << ": Empty" << endl;
            }
        }
    }
};

class ColdDrink {
public:
    string name;
    double price;
    int flavourid;

    ColdDrink() {
        name = "";
        price = 0.0;
        flavourid = -1;
    }

    ColdDrink(string n, double p, int f) {
        name = n;
        price = p;
        flavourid = f;
    }
};

class ColdDrinkHashTable {
private:
    ColdDrink* table;
    int size;

public:
    ColdDrinkHashTable(int s) {
        size = s;
        table = new ColdDrink[size];
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(const ColdDrink& drink) {
        int index = hashFunction(drink.flavourid);
        int i = 0;
        int newIndex = index;

        while (table[newIndex].flavourid != -1 && i < size) {
            i++;
            newIndex = (index + i * i) % size;
        }

        if (i == size) {
            cout << "Hash table is full, can't insert more cold drinks." << endl;
            return;
        }

        table[newIndex] = drink;
    }

    ColdDrink* search(int key) {
        int index = hashFunction(key);
        int i = 0;
        int newIndex = index;

        while (i < size) {
            if (table[newIndex].flavourid == key) {
                return &table[newIndex];
            }
            i++;
            newIndex = (index + i * i) % size;
        }
        return NULL;
    }

    void display() {
        cout << "Cold Drink Hash Table:" << endl;
        for (int i = 0; i < size; ++i) {
            if (table[i].flavourid != -1) {
                cout << "Index " << i << ": Name: " << table[i].name 
                     << ", Price: " << table[i].price << ", Flavour ID: " << table[i].flavourid << endl;
            } else {
                cout << "Index " << i << ": Empty" << endl;
            }
        }
    }
};

class node {
public:
    string name;
    int marks;
    int rollno;
    node* next;
    node(string s, int m, int r) {
        name = s;
        marks = m;
        rollno = r;
        next = NULL;
    }
};

class hashchain {
public:
    int size3 = 20;
    node** htable;

    hashchain() {
        htable = new node*[size3];  
        for (int i = 0; i < size3; i++) {
            htable[i] = nullptr;  
        }
    }

    void insert(node* temp) {
        node* p;
        int h = temp->marks % size3;
        if (htable[h] == NULL) {
            htable[h] = temp;
        } else {
            p = htable[h];
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }
    }

    void search(int key) {
        int h = key % size3;
        node* p = htable[h];

        if (p == nullptr) {
            cout << "The key " << key << " is not present" << endl;
        } else {
            bool found = false;
            while (p != NULL) {
                if (p->marks == key) {
                    cout << "The Key " << key << " is found: "
                         << "Name: " << p->name << ", Roll No.: " << p->rollno << endl;
                    found = true;
                    break;
                }
                p = p->next;  
            }
            if (!found) {
                cout << "The key " << key << " is not present" << endl;
            }
        }
    }

    void display() {
        for (int i = 0; i < size3; i++) {
            node* p = htable[i];
            if (p == NULL) {
                cout << "NULL" << endl;
            } else {
                while (p != nullptr) {
                    cout << "Name: " << p->name << " | Marks: " << p->marks << " | Roll No.: " << p->rollno << " -> ";
                    p = p->next;
                }
                cout << "NULL" << endl;
            }
        }
    }
};

int main() {
    int choice;
    int searchKey;

    int size = 11;  
    MangoHashTable mangoTable(size);
    ColdDrinkHashTable colddrinkTable(10);  
    hashchain table;

    Mango mangoes[] = {
        Mango("Category 1", 25),
        Mango("Category 2", 15),
        Mango("Category 3", 10),
        Mango("Category 4", 5),
        Mango("Category 5", 11),
        Mango("Category 6", 19),
        Mango("Category 7", 16),
        Mango("Category 8", 36),
        Mango("Category 9", 42),
        Mango("Category 10", 28),
        Mango("Category 11", 32)
    };

    for (int i = 0; i < size; ++i) {
        mangoTable.insert(mangoes[i]);
    }

    colddrinkTable.insert(ColdDrink("Coke", 1.5, 101));
    colddrinkTable.insert(ColdDrink("Pepsi", 1.2, 102));
    colddrinkTable.insert(ColdDrink("Sprite", 1.3, 103));
    colddrinkTable.insert(ColdDrink("Fanta", 1.4, 104));

    table.insert(new node("Alice", 33, 101));
    table.insert(new node("Bob", 56, 102));
    table.insert(new node("Charlie", 78, 103));
    table.insert(new node("David", 12, 104));
    table.insert(new node("Eve", 10, 105));

    do {
        cout << "\n--- Hashing Techniques Menu ---\n";
        cout << "1. Cold Drink Hash Table\n";
        cout << "2. Mango Hash Table\n";
        cout << "3. Marks Hash Chain Table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nCold Drink Hash Table:\n";
                colddrinkTable.display();
                cout << "\nEnter flavour ID to search for a cold drink: ";
                cin >> searchKey;
                ColdDrink* coldDrinkResult = colddrinkTable.search(searchKey);
                if (coldDrinkResult) {
                    cout << "Cold Drink Found: " << coldDrinkResult->name
                         << ", Price: " << coldDrinkResult->price
                         << ", Flavour ID: " << coldDrinkResult->flavourid << endl;
                } else {
                    cout << "Cold Drink not found!" << endl;
                }
                break;
            }
            case 2: {
                cout << "\nMango Varieties Hash Table:\n";
                mangoTable.display();
                cout << "\nEnter number of mangoes to search for a category: ";
                cin >> searchKey;
                Mango* mangoResult = mangoTable.search(searchKey);
                if (mangoResult) {
                    cout << "Mango Category Found: " << mangoResult->category
                         << ", Number of Mangoes: " << mangoResult->numberOfMangoes << endl;
                } else {
                    cout << "Mango Category not found!" << endl;
                }
                break;
            }
            case 3: {
                cout << "\nMarks Hash Chain Table:\n";
                table.display();
                cout << "\nEnter marks to search for a student: ";
                cin >> searchKey;
                table.search(searchKey);
                break;
            }
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while (choice != 4);

    return 0;
}