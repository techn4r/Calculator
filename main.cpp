#include <iostream>

double addition(double &a, double &b) {
    return a + b;
}

double subtraction(double &a, double &b) {
    return a - b;
}

double multiplication(double &a, double &b) {
    return a * b;
}

double division(double &a, double &b) {
    return a / b;
}


int main() {
    double a, b;

    std::cout << "Введите два числа:" << std::endl;
    std::cin >> a >> b;

    char operation;
    std::cout << "Введите операцию: + - * /" << std::endl;
    std::cin >> operation;

    double result;
    bool validOperation = true;

    switch (operation) {
        case '+':
            result = addition(a, b);
            break;

        case '-':
            result = subtraction(a, b);
            break;

        case '*':
            result = multiplication(a, b);
            break;

        case '/':
            if (b != 0) {
                result = division(a, b);
            } else {
                std::cout << "Ошибка: деление на ноль" << std::endl;
                validOperation = false;
            }
            break;

        default:
            std::cout << "Неверная операция" << std::endl;
            validOperation = false;
    }

    if (validOperation) {
        std::cout << "Результат: " << result << std::endl;
    }

    return 0;
}
