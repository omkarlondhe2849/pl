#include <iostream>
using namespace std;

class sparse{
    public:
    int sp[50][3];
    void accept(){
        cout << "Enter the number of rows, columns, and non-zero elements: ";
        cin >> sp[0][0] >> sp[0][1] >> sp[0][2];
        for (int i = 1; i <= sp[0][2]; i++) {
            cout << "Enter row index, column index, and value of non-zero element " << i << ": ";
            cin >> sp[i][0] >> sp[i][1] >> sp[i][2];
        }
    }
    void display(){
        cout<<sp[0][0]<<sp[0][1]<<sp[0][2]<<endl;
        for(int i=1;i<=sp[0][2];i++){
        cout<<sp[i][0]<<" "<<sp[i][1]<<" "<<sp[i][2];
        cout<<endl;
        }
    }

    void simple_tr(sparse s1){
        sp[0][0] = s1.sp[0][1];
        sp[0][1] = s1.sp[0][0];
        sp[0][2] = s1.sp[0][2];
        int k=1;
        for(int i=0;i<sp[0][1];i++){
            for(int j=1;j<=sp[0][2];j++){
                if(s1.sp[j][1]==i){
                   sp[k][0] = s1.sp[j][1];
                   sp[k][1] = s1.sp[j][0];
                   sp[k][2] = s1.sp[j][2];
                   k++;
                }
            }
        }
    }
};

int main(){

  sparse s1, s2, s3;
  s1.accept();
  s3.simple_tr(s1);
  s3.display();
}