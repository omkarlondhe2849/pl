#include <iostream>
#include <string>
using namespace std;

class Student {
    public :
    string name;
    int prn;
   
   
    void input(){
        cout<<"Enter Your Name : ";
        cin>>name;
        cout<<"Enter Your PRN No. : ";
        cin>>prn;
    }
   
    void display (){
        cout<<"Name : "<< name << " , PRN No. : "<< prn << endl;
    }
};

class StudentList {
    private :
    Student arr[100];
    int n;
   
    public :
    StudentList() : n(0) {}
   
    void create(){
        cout<<"Enter No. Of Student : ";
        cin>>n;
       
        if(n>100) cout<<"Enter No. Less Than 100.";
        else {
            for(int i=0;i<n;i++){
                cout<<"Enter Student ["<<i+1<<"]"<<" Details : \n";
                arr[i].input();
            }
        }
    }
       
    void display() {
        cout<<" Student Details : \n";
        for(int i=0;i<n;i++){
            arr[i].display();
        }
    }
   
    void bubblesort() {
        int swapped = 0;
        for(int i=0;i<n-1;i++){
            swapped = 0;
            for(int j=0;j<n-i-1;j++){
                if(arr[j].prn>arr[j+1].prn){
                    Student x = arr[j] ;
                    arr[j]  = arr[j+1] ;
                    arr[j+1]  = x;
                    swapped = 1;
                }
            }
            if(swapped == 0) break;
        }
    }
   
     void insertionsort() {
         int i , j ;
        for(i=1;i<n;i++){
            Student val = arr[i];
            for(j=i-1;j>=0 && arr[j].name>val.name;j--){
                arr[j+1] = arr[j]; // name
            }
        arr[j+1] = val;
       }
    }
} ;

    void quicksort(StudentList arr, int left, int right){
        for(int i=left;i<right;i++){
            int p = partition(arr,left,right);
            quicksort(arr,left,p-1);
            quicksort(arr,p+1,n-1);
        }
    }
   
    void partition(StudentList arr, int left , int right){
        int p = arr[left];
        int i = left; int j = right;
        while(i<=j){
            while(arr[i]<=p)
            i++;
            while(arr[j]>=p && j>=0)
            j--;
            if(i<j){
                Student x = arr[j] ;
                arr[j]  = arr[i] ;
                arr[i]  = x;
            }
        }
        Student x = p ;
        p = arr[l] ;
        arr[l]  = x;
        return j;
    }

int main(){
    StudentList s1;
    s1.create();
    cout<<"\nBefore Sorting : \n";
    s1.display();
    s1.insertionsort();
    cout<<"\nAfter Sorting : \n";
    s1.display();
    return 0;
}
