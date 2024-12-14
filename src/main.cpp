#include <iostream>
#include <limits>

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

bool CalculateIsComplete() {
    char choice;
    std::cout << "Хотите продолжить? (y/n): ";
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return choice == 'y' || choice == 'Y';
}

int main() {
    double a, b;
    bool continueCalculation = true;


    while (continueCalculation) {
        std::cout << "Введите два числа:" << std::endl;

        while (!(std::cin >> a >> b)) {
            std::cout << "Ошибка ввода. Пожалуйста, введите два числа." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

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

        continueCalculation = CalculateIsComplete();
    }
    return 0;
}
