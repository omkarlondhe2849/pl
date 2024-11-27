#include<iostream>
using namespace std;

const int sz = 6;
const int sz1 = 11;
const int sz2 = 20;

class Drink {
private:
    string flName;
    int flId;
    int sugCt;

public:
    Drink() : flName(""), flId(-1), sugCt(0) {}  // Default constructor
    void setDrink(int id, const string& name) {
        flId = id;
        flName = name;
    }
    int getId() const { return flId; }
    string getName() const { return flName; }
};

class node(){
    public:
    int marks;
    node *next;
    node(){
        next=NULL;
    }
};

class HashTable_LinearP {
private:
    Drink A[sz];

public:
    HashTable_LinearP() {
        for(int i = 0; i < sz; i++) {
            A[i] = Drink();
        }
    }

    void insert(int f) {
        int h = f % sz;
        int i = 0;
        while(A[(i + h) % sz].getId() != -1 && i < sz) {
            i++;
        }
        if(i == sz) {
            cout << "Space is not available/hash table is full" << endl;
            return;
        } else {
            int index = (h + i) % sz;
            cout << "Enter the flavour name: ";
            string name;
            cin >> name;
            A[index].setDrink(f, name);
        }
    }

    void display() {
        for(auto& i : A) {
            if(i.getId() != -1)
                cout << i.getId() << "  " << i.getName() << endl;
        }
    }

    void search(int f) {
        int h = f % sz;
        int i = 0;
        while(A[(i + h) % sz].getId() != f && i < sz) {
            i++;
        }
        if(i == sz) {
            cout << "Element not found" << endl;
            return;
        } else {
            cout << A[(i + h) % sz].getId() << "  " << A[(i + h) % sz].getName() << endl;
        }
    }
};

class HashTable_QuadraticP {
private:
    Drink B[sz1];

public:
    HashTable_QuadraticP() {
        for(int i = 0; i < sz1; i++) {
            B[i] = Drink();
        }
    }

    void insert(int f) {
        int h = f % sz;1
        int i = 0;
        while(B[(i * i + h) % sz1].getId() != -1 && i*i < sz1) {
            i++;
        }
        if(i == sz1) {
            cout << "Space is not available/hash table is full" << endl;
            return;
        } else {
            int index = (h + i * i) % sz1;
            cout << "Enter the flavour name: ";
            string name;
            cin >> name;
            B[index].setDrink(f, name);
        }
    }

    void display() {
        for(auto& i : B) {
            if(i.getId() != -1)
                cout << i.getId() << "  " << i.getName() << endl;
        }
    }

    void search(int f) {
        int h = f % sz1;
        int i = 0;
        while(B[(i * i + h) % sz1].getId() != f && i*i < sz1) {
            i++;
        }
        if(i == sz1) {
            cout << "Element not found" << endl;
            return;
        } else {
            cout << B[(i * i + h) % sz1].getId() << "  " << B[(i * i + h) % sz1].getName() << endl;
        }
    }
};

class hash_chain{
    public:
    node *htable[sz2];
    hash_chain(){
        for(int i=0;i<sz2;i++){
            htable[i]=new node();
            htable[i]=NULL;
        }
    }

    void insert(int key){
         node *p;
         node *temp = new node();
         cout<<"Enter the marks of student"<<endl;
         cin>>temp->data;

         int h=key%sz2;
         if(htable[h]==NULL){
            htable[h]=temp;
         }
         else{
            p=htable[h];
            while(p->next!=NULL){
                p=p->next;
            }
            p->next=temp;
         }
    }

    void display(){
        for(int i=0;i<sz2;i++){
            while{
                
            }
        }
    }


    
}

int main() {
    int choice;
    do {
        cout << "1 for Linear Probing\n2 for Quadratic Probing\n0 to Exit: ";
        cin >> choice;
        
        if (choice == 1) {
            HashTable_LinearP linearHash;
            int ch1;
            do {
                cout << "Enter 1 for insert\n2 for display\n3 for search\n0 to exit: ";
                cin >> ch1;

                switch (ch1) {
                    case 1: {
                        int f;
                        cout << "Enter flavour ID: ";
                        cin >> f;
                        linearHash.insert(f);
                        break;
                    }
                    case 2:
                        linearHash.display();
                        break;
                    case 3: {
                        int f;
                        cout << "Enter flavour ID to search: ";
                        cin >> f;
                        linearHash.search(f);
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                }
            } while (ch1 != 0);
        } else if (choice == 2) {
            HashTable_QuadraticP quadraticHash;
            int ch1;
            do {
                cout << "Enter 1 for insert\n2 for display\n3 for search\n0 to exit: ";
                cin >> ch1;

                switch (ch1) {
                    case 1: {
                        int f;
                        cout << "Enter flavour ID: ";
                        cin >> f;
                        quadraticHash.insert(f);
                        break;
                    }
                    case 2:
                        quadraticHash.display();
                        break;
                    case 3: {
                        int f;
                        cout << "Enter flavour ID to search: ";
                        cin >> f;
                        quadraticHash.search(f);
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                }
            } while (ch1 != 0);
        }
    } while (choice != 0);

    return 0;
}
