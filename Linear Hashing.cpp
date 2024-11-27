#include<iostream>
using namespace std;

class hash{
    int data[9];
    bool check[9];
    public:
        hash{
            for(int i=0;i<9;i++){
                data[i] = -1;
                check[i] = false;
            }
        }

            int give(int key){
                return key%9;
            }

            void Insert(int key){
                int index = give(key);
                while(check[index]!=false){
                    index = (index+1)%9;
                }
                data[index] = key;
                check[index] = true;
            }

            void Display(){
                for(int i=0;i<9;i++){
                    cout<<i<<" : "<<data[i]<<endl;
                }
            }
};

int main(){
    hash obj;
    int arr[9] = {7,34,98,12,87,19,67,51,44};
    for(int i=0;i<9;i++){
        obj.Insert(arr[i]);
    }
    obj.Display();
}