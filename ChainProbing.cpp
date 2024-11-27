#include<iostream>
using namespace std;

class node{
    int data;
    node* next;
    public:
    node(int val){
        data=val;
        next=NULL;
    }
    friend class hash1;
};

class hash1{
    node* table[15];
    public:
    hash1(){
        for(int i=0;i<15;i++){
            table[i] = NULL;
        }
    }
    
    void Insert(int key){
        int index  = key%15;
        node* newNode = new node(key);
        if(table[index]!=NULL){
            node* temp = table[index];
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        else{
            table[index] = newNode;
        }
    }
    
    void view(){
        for(int i=0;i<15;i++){
            cout<<i<<" : ";
            node* temp = table[i];
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
    }
};

int main(){
    hash1 obj;
    int arr[15] = {5, 9, 12, 56, 98, 32, 8, 16, 57, 734, 87, 342, 45, 1, 87};
    for (int i = 0; i < 15; i++) {
        obj.Insert(arr[i]);
    }
    obj.view();
    return 0;
}