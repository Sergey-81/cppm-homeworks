#include <iostream>
#include <string>
#include <Windows.h>

class Counter {
private:
    int value;

public:

    Counter() : value(1) {}

    Counter(int initial_value) : value(initial_value) {}

    void increment() {
        value++;
    }

    void decrement() {
        value--;
    }

    int get_value() {
        return value;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string answer;
    int initial_value;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> answer;

    Counter counter;

    if (answer == "да" || answer == "Да" || answer == "д" || answer == "y" || answer == "yes") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initial_value;
        counter = Counter(initial_value);
    }

    char command;

    std::cout << "Введите команду ('+', '-', '=' или 'x'): ";

    while (std::cin >> command) {
        switch (command) {
        case '+':
            counter.increment();
            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            break;

        case '-':
            counter.decrement();
            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            break;

        case '=':
            std::cout << counter.get_value() << std::endl;
            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            break;

        case 'x':
            std::cout << "До свидания!" << std::endl;
            return 0;

        default:
            std::cout << "Неизвестная команда! Введите '+', '-', '=' или 'x': ";
            break;
        }
    }

    return 0;
}
