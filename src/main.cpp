#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b != 0) return a / b;
            else {
                throw runtime_error("Ошибка: деление на ноль!");
            }
        default:
            throw runtime_error("Ошибка: неизвестная операция!");
    }
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double applyFunction(const string& func, double value) {
    if (func == "sin") return sin(value);
    if (func == "cos") return cos(value);
    if (func == "tan") return tan(value);
    if (func == "sqrt") return sqrt(value);
    if (func == "log") return log(value);
    if (func == "exp") return exp(value);
    throw runtime_error("Ошибка: неизвестная функция " + func);
}

double evaluateExpression(const string& expression) {
    stack<double> values;
    stack<char> operators;
    stack<string> functions;

    for (size_t i = 0; i < expression.length(); ++i) {
        if (isspace(expression[i])) continue;

        if (isdigit(expression[i]) || expression[i] == '.') {
            size_t j = i;
            while (j < expression.length() && (isdigit(expression[j]) || expression[j] == '.')) {
                ++j;
            }
            double value = stod(expression.substr(i, j - i));
            values.push(value);
            i = j - 1;
        }
        else if (isalpha(expression[i])) {
            size_t j = i;
            while (j < expression.length() && isalpha(expression[j])) {
                ++j;
            }
            string func = expression.substr(i, j - i);
            functions.push(func);
            i = j - 1;
        }
        else if (expression[i] == '(') {
            operators.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();
            }
            if (!functions.empty()) {
                string func = functions.top(); functions.pop();
                double value = values.top(); values.pop();
                values.push(applyFunction(func, value));
            }
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.push(expression[i]);
        }
        else {
            throw runtime_error("Ошибка: некорректный символ в выражении!");
        }
    }

    while (!operators.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}

int main() {
    string expression;
    cout << "Введите арифметическое выражение: ";
    getline(cin, expression);

    try {
        double result = evaluateExpression(expression);
        cout << "Результат: " << result << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
