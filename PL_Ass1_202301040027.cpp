#include<iostream>
using namespace std;
class Adhar{
    string name;
    long AdharNo;
    long MobileNo;
    public:
    void Read();
    void Display();
    void Search(string temp);
    void Update(int pos);
};

void Adhar::Read(){
    cout<<"Enter user name:- "<<endl;
    cin>>name;
    cout<<"Enter user Adhar number:- "<<endl;
    cin>>AdharNo;
    cout<<"Enter user Mobile no:- "<<endl;
    cin>>MobileNo;
}
void Adhar::Display(){
    cout<<"Name:-"<<name<<endl;
    cout<<"AdharNO:-"<<AdharNo<<endl;
    cout<<"MObileNo:-"<<MobileNo<<endl;
}

void Adhar::Search(string temp){
    if(temp==name){
        cout<<"Person Found"<<endl;
    }
}

void Adhar::Update(int pos){
switch (pos) {
    case 1:
        cout << "Enter new name: ";
        cin >> name;
        break;
    case 2:
        cout << "Enter new Mobile number: ";
        cin >> MobileNo;
        break;
    default:
        cout << "Invalid option!" << endl;
        break;
    }

}

int main(){
    Adhar u[10];
    int n;
    cout<<"Enter the no of users you want to enter"<<endl;
    int choice,pos,abcd;
    bool abc=true;
    string temp;
    cin>>n;
    do{
    cout<<"Enter 1 for Enter Adhar details:-"<<endl;
    cout<<"Enter 2 for Display Adhar details:-"<<endl;
    cout<<"Enter 3 for add new Aadhar user:-"<<endl;
    cout<<"Enter 4 for delet user in Aadhar:-"<<endl;
    cout<<"Enter 5 for Search user in Aadhar:-"<<endl;
    cout<<"Enter 6 for update Aadhar details:-"<<endl;
    cin>>choice;
    switch(choice){
        case 1:for(int i=0;i<n;i++){
            u[i].Read();
        }
        break;

        case 2:for(int i=0;i<n;i++){
            u[i].Display();
        }
        break;

        case 3:cin>>pos;
        for(int i=n;i>pos;i--){
            u[i+1]=u[i];
        }
        cout<<"Enter the position you want to save:-"<<endl;
        u[pos].Read();
        n++;
        break;

        case 4:cout<<"Enter the pos of delition:-"<<endl;
              cin>>pos;
              for(int i=pos;i<n;i++){
                u[i]=u[i+1];
              }
              n--;
              break;
        case 5:cout<<"Enter the name of Person You want to search:-"<<endl;
               cin>>temp;
               for(int i=0;i<n;i++){
                 u[i].Search(temp);
                 u[i].Display();
               }
               break;
        case 6:cout<<"Enter the position of user whose details have to update"<<endl;

               cin>>abcd;
               cout<<"Enter 1 for Name update"<<endl;
               cout<<"Enter 2 for Mobile no update"<<endl;
              cin>>pos;
              u[abcd].Update(pos);
              break;
             
               
        default:cout<<"Enter valid option"<<endl;
        break;
    }

    }while(abc==true);
}