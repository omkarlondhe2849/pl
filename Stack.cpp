#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
using namespace std;

#define MAX 20

class stack {
public:
    int top;
    string s[MAX];

    stack() {
        top = -1;
    }

    bool isempty();
    bool isfull();
    string pop();
    void push(string a);
    string rtop();
};

class expression {
public:
    stack s2;
    string prefix_to_infix(string pf);
    string infix_to_postfix(string inf);
    string postfix_eval_single_digit(string pf);
    string postfix_eval_multiple_digit(string pf);
    bool isOperator(char c);
    int Precedence(string opd);
};

bool stack::isempty() {
    return top == -1;
}

bool stack::isfull() {
    return top == MAX - 1;
}

void stack::push(string b) {
    if (isfull()) cout << "Stack is full\n";
    else s[++top] = b;
}

string stack::rtop() {
    return isempty() ? "" : s[top];
}

string stack::pop() {
    if (isempty()) {
        cout << "Stack is empty\n";
        return "";
    }
    return s[top--];
}

string expression::prefix_to_infix(string pf) {
    for (int i = pf.length() - 1; i >= 0; i--) {
        if (isOperator(pf[i])) {
            string op1 = s2.pop();
            string op2 = s2.pop();
            s2.push("(" + op1 + string(1, pf[i]) + op2 + ")");
        } else {
            s2.push(string(1, pf[i]));
        }
    }
    return s2.pop();
}

string expression::infix_to_postfix(string inf) {
    string postfix = "";
    for (int i = 0; i < inf.length(); i++) {
        if (inf[i] == '(') {
            s2.push("(");
        } else if (inf[i] == ')') {
            while (!s2.isempty() && s2.rtop() != "(") {
                postfix += s2.pop();
            }
            if (!s2.isempty()) s2.pop(); // pop the '('
        } else if (!isOperator(inf[i])) {
            postfix += string(1, inf[i]);
        } else {
            while (!s2.isempty() && Precedence(string(1, inf[i])) <= Precedence(s2.rtop())) {
                postfix += s2.pop();
            }
            s2.push(string(1, inf[i]));
        }
    }
    while (!s2.isempty()) {
        postfix += s2.pop();
    }
    return postfix;
}

string expression::postfix_eval_single_digit(string pf) {
    int res;
    for (int i = 0; i < pf.length(); i++) {
        if (isOperator(pf[i])) {
            int op_1, op_2;
            string op2 = s2.pop();
            string op1 = s2.pop();
            stringstream sa(op1), sb(op2);
            sa >> op_1;
            sb >> op_2;
            switch (pf[i]) {
                case '+': res = op_1 + op_2; break;
                case '-': res = op_1 - op_2; break;
                case '*': res = op_1 * op_2; break;
                case '/': res = op_1 / op_2; break;
                case '%': res = op_1 % op_2; break;
                case '^': res = pow(op_1, op_2); break;
            }
            s2.push(to_string(res));
        } else {
            s2.push(string(1, pf[i]));
        }
    }
    return s2.pop();
}

string expression::postfix_eval_multiple_digit(string pf) {
    for (int i = 0; i < pf.length(); i++) {
        if (pf[i] == ' ') continue;
        else if (isOperator(pf[i])) {
            int op_1, op_2;
            string op2 = s2.pop();
            string op1 = s2.pop();
            stringstream sa(op1), sb(op2);
            sa >> op_1;
            sb >> op_2;
            int res;
            switch (pf[i]) {
                case '+': res = op_1 + op_2; break;
                case '-': res = op_1 - op_2; break;
                case '*': res = op_1 * op_2; break;
                case '/': res = op_1 / op_2; break;
                case '%': res = op_1 % op_2; break;
                case '^': res = pow(op_1, op_2); break;
            }
            s2.push(to_string(res));
        } else {
            string temp = "";
            while (i < pf.length() && pf[i] != ' ') {
                temp += pf[i++];
            }
            s2.push(temp);
            --i;
        }
    }
    return s2.pop();
}

bool expression::isOperator(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*' || c == '%' || c == '^');
}

int expression::Precedence(string opd) {
    if (opd == "^") return 3;
    else if (opd == "*" || opd == "/") return 2;
    else if (opd == "+" || opd == "-") return 1;
    else return 0;
}

int main()
{
    int ch;
    stack s1;
    expression e1;
    string a;
    do
    {
        cout << "Choose an option:\n";
        cout << "1: Push an element onto the stack\n";
        cout << "2: Pop an element from the stack\n";
        cout << "3: Convert Prefix to Infix\n";
        cout << "4: Convert Infix to Postfix\n";
        cout << "5: Evaluate Postfix Expression (Single Digits)\n";
        cout << "6: Evaluate Postfix Expression (Multiple Digits)\n";
        cout << "0: Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Enter the element to push: ";
                cin >> a;
                s1.push(a);
                break;
            case 2:
                cout << "Popped element: " << s1.pop() << endl;
                break;
            case 3:
                cout << "Enter the prefix expression to convert: ";
                cin >> a;
                cout << "Infix expression: " << e1.prefix_to_infix(a) << endl;
                break;
            case 4:
                cout << "Enter the infix expression to convert: ";
                cin >> a;
                cout << "Postfix expression: " << e1.infix_to_postfix(a) << endl;
                break;
            case 5:
                cout << "Enter the postfix expression (single digits) to evaluate: ";
                cin >> a;
                cout << "Evaluation result: " << e1.postfix_eval_single_digit(a) << endl;
                break;
            case 6:
                cin.ignore(); // To handle newline character after the integer input
                cout << "Enter the postfix expression (multiple digits) to evaluate: ";
                getline(cin, a); // Use getline to read multi-digit expressions
                cout << "Evaluation result: " << e1.postfix_eval_multiple_digit(a) << endl;
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(ch != 0);
}
