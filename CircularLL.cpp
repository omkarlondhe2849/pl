#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class order{
    public:
    int orderid;
    string pizza;
    int quantity;
    float price;
    order *next;
    order(){
        next=NULL;
    }
};
class pizzashop{
    order *head;
    public:
    pizzashop(){
        head = NULL;
    }
    void orderpizza();
    void delivery();
    void display();
    void search(int id);
    void update(int id);
};

void pizzashop:: orderpizza(){
    order *temp;
    temp = new order();
    cout<<"Enter the order 1.OrderID 2.PizzaName 3.Quanity 4.Price"<<endl;
    cin>>temp->orderid>>temp->pizza>>temp->quantity>>temp->price;
    if(head == NULL){
        head = temp;
        temp->next = head;
    }else{
        order *p;
        while(p->next!=head){
            p=p->next;
        }
        p->next = temp;
        temp->next = head;
    }
}

void pizzashop :: delivery(){
    order *p;
    if(head->next == head){
        p=head;
        head = NULL;
        p->next=NULL;
        delete (p);
    }else{
        p=head;
        while(p->next!=head){
            p = p->next;
        }
        p->next = head->next;
        p=head;
        head = head->next;
        delete (p);
    }
}

void pizzashop :: display(){
    order *p;
    if(head==NULL){
        cout<<"No order yet";
        return;
    }
    p=head;
    cout<<"---------------------ORDER-------------------------"<<endl;
     cout<<"OrderId"<<"\t"<<"Pizza Name"<<"\t"<<"Quantity"<<"\t"<<"Price"<<"\t"<<"Total Cost"<<endl;
    do{
        cout<<p->orderid<<"\t"<<p->pizza<<"\t"<<p->quantity<<"\t"<<p->price<<"\t"<<(p->price*p->quantity)<<endl;
        p=p->next;
    }while(p!=head);
    cout<<"--------------------------------------------------"<<endl;
}
void pizzashop :: update(int id){
    order *p=head;
    if(p==NULL){
        cout<<"No Order to update"<<endl;
        return;
    }
    do{
        if(p->orderid==id){
            cout<<"Enter New Pizza Name"<<endl;
            cin>>p->pizza;
            cout<<"Enter New Quantity"<<endl;
            cin>>p->quantity;
            cout<<"Enter New Price"<<endl;
            cin>>p->price;
            return;
        }
        p=p->next;
    }while(p!=head);
    cout<<"Order ID not found"<<endl;
}

void pizzashop :: search(int id){
    order *p = head;
    if(p==NULL){
        cout<<"No Order to Search"<<endl;
        return;
    }
    do{
        if(p->orderid==id){
            cout<<"Order Found: Order ID: "<<p->orderid<<endl;
            cout<<"Pizza: "<<p->pizza<<endl;
            cout<<"Quantity: "<<p->quantity<<endl;
            cout<<"Price: "<<p->price<<endl;
            cout<<"Total Cost: "<<(p->price* p->quantity)<<endl;
        }
    }while(p!=head);
    cout<<"Order Id not found"<<endl;
}

int main(){
    pizzashop shop;
    int choice, id;

    while (true) {
        cout << "1. Order\n2. Deliver\n3. Display\n4. Update\n5. Search\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                shop.orderpizza();
                break;
            case 2:
                shop.delivery();
                cout<<"Order Delivered"<<endl;
                break;
            case 3:
                shop.display();
                break;
            case 4:
                cout << "Enter order ID to update: ";
                cin >> id;
                shop.update(id);
                break;
            case 5:
                cout << "Enter order ID to search: ";
                cin >> id;
                shop.search(id);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

}