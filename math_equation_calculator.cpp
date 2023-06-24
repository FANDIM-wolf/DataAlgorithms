/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <stack>
#include <string>

int calculate(const char* expr, size_t& i) {
    std::stack<int> st;
    char op = '+';
    int num = 0;
    int result = 0;

    while (expr[i] != '\0') {
        char ch = expr[i++];

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        } else if (ch == '(') {
            num = calculate(expr, i);
        }

        if ((!isdigit(ch) && !isspace(ch)) || expr[i] == '\0') {
            switch (op) {
                case '+':
                    result += num;
                    break;
                case '-':
                    result -= num;
                    break;
                case '*':
                    result *= num;
                    break;
                case '/':
                    result /= num;
                    break;
                case '%':
                    result %= num;
                    break;
            }

            if (ch == ')') {
                break;
            }

            op = ch;
            num = 0;
        }
    }

    return result;
}

int calculate(const char* expr) {
    size_t i = 0;
    return calculate(expr, i);
}

int main() {
    const char* expr = "(2+2)+(2*2)+(2/2)";
    std::cout << calculate(expr) << std::endl;
    return 0;
}
