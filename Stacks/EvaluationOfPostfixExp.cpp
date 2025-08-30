#include <iostream>
#include <cstring>

using namespace std;

class Stack {
private:
    int size;
    int top;
    int *S;

public:
    Stack(int capacity) {
        size = capacity;
        top = -1;
        S = new int[size];
    }

    ~Stack() {
        delete[] S;
    }

    void push(int x) {
        if (size - top == 1) {
            cout << "Stack Overflow"<<endl;
        } else {
            top++;
            S[top] = x;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow"<<endl;
            return -1;
        } else {
            return S[top--];
        }
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return size - top == 1;
    }
};

bool isOperand(char s) {
    return !(s == '*' || s == '/' || s == '+' || s == '-' || s == '^' || s == '(' || s == ')');
}

int evaluatePostfix(const char *postfix) {
    Stack st(strlen(postfix));

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            st.push(postfix[i] - '0');
        } else {
            int x2 = st.pop();
            int x1 = st.pop();
            int result;

            switch (postfix[i]) {
                case '+':
                    result = x1 + x2;
                    break;
                case '-':
                    result = x1 - x2;
                    break;
                case '*':
                    result = x1 * x2;
                    break;
                case '/':
                    result = x1 / x2;
                    break;
                default:
                    result = 0;
                    break;
            }

            st.push(result);
        }
    }

    return st.pop();
}

int main() {
    const char postfix[] = "2362/*+";
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;
    return 0;
}