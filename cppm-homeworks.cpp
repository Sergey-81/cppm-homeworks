#include <iostream>
#include <Windows.h>

class Calculator {
private:
    double num1;
    double num2;

public:

    double add() {
        return num1 + num2;
    }

    double multiply() {
        return num1 * num2;
    }

    double subtract_1_2() {
        return num1 - num2;
    }

    double subtract_2_1() {
        return num2 - num1;
    }

    double divide_1_2() {
        return num1 / num2;
    }

    double divide_2_1() {
        return num2 / num1;
    }

    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        return false;
    }

    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        return false;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Calculator calc;
    double input1, input2;

    while (true) {

        std::cout << "Введите первое число: ";
        std::cin >> input1;

        if (!calc.set_num1(input1)) {
            std::cout << "Неверный ввод! Число не должно быть равно нулю." << std::endl;
            continue;
        }

        std::cout << "Введите второе число: ";
        std::cin >> input2;

        if (!calc.set_num2(input2)) {
            std::cout << "Неверный ввод! Число не должно быть равно нулю." << std::endl;
            continue;
        }

        std::cout << "\nРезультаты вычислений:" << std::endl;
        std::cout << "Первое число + второе число = " << calc.add() << std::endl;
        std::cout << "Первое число - второе число = " << calc.subtract_1_2() << std::endl;
        std::cout << "Второе число - первое число = " << calc.subtract_2_1() << std::endl;
        std::cout << "Первое число * второе число = " << calc.multiply() << std::endl;
        std::cout << "Первое число / второе число = " << calc.divide_1_2() << std::endl;
        std::cout << "Второе число / первое число = " << calc.divide_2_1() << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

    return 0;
}