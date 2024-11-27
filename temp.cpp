#include <iostream>
using namespace std;
#define max 10
class stack{
    public:
    string a[max];
    int top;
    stack(){
        top=-1;
    }
    bool isempty(){
        return top==-1;
    }

    bool isfull(){
        return top ==  max-1;
    }

    void push(string s){
        if(isfull()) cout<<"cannot enter";
        else a[++top]=s;
    }

    string pop(){
        if (isempty()) {
        cout << "Stack is empty\n";
        return "";
    }
    return a[top--];
    }

    string rtop(){
        return isempty() ? " ":a[top];
    }
};

class expression{
    public:
    stack s2;

    bool isoperator(char c){
        return(c=='+'||c=='-'||c=='*'||c=='/'||c=='%'||c=='^'); 
    }

    int precidence(string s){
        if(s=="^") return 3;
        else if(s=="*"||s=="/") return 2;
        else if(s=="+"||s=="-") return 1;
        else return 0;
    }
    string prefix_to_infix(string s){
        for(int i=s.length()-1;i>=0;i--){
            if(isoperator(s[i])){
                string op1 = s2.pop();
                string op2 = s2.pop();
                s2.push("("+op1+string(1,s[i])+op2+")");
            }
            else{
                s2.push(string(1,s[i]));
            }
        }
    return s2.pop();
    }

    string infix_to_postfix(string s){
        string postfix="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') s2.push("(");
            else if(s[i]==')'){
                while(!s2.isempty()&&s2.rtop()=="("){
                    postfix+=s2.pop();
                }
                if(!s2.isempty()) s2.pop();
            }
            else if(!isoperator(s[i])) postfix+=string(1,s[i]);
            else{
                while(!s2.isempty()&& precidence(string(1,s[i])) < precidence(s2.rtop())){
                    postfix+=s2.pop();
                }
                s2.push(string(1,s[i]));
            }
        }
        while (!s2.isempty()) {
        postfix += s2.pop();
        }
        return postfix;
    }
};

int main() {
    expression e;
    string a;
    cout << "Enter an infix expression: ";
    cin >> a;

    // Infix to postfix conversion
    string postfix = e.infix_to_postfix(a);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
