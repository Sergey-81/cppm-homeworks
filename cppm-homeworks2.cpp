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

    std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
    std::cin >> answer;

    Counter counter;

    if (answer == "��" || answer == "��" || answer == "�" || answer == "y" || answer == "yes") {
        std::cout << "������� ��������� �������� ��������: ";
        std::cin >> initial_value;
        counter = Counter(initial_value);
    }

    char command;

    std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";

    while (std::cin >> command) {
        switch (command) {
        case '+':
            counter.increment();
            std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
            break;

        case '-':
            counter.decrement();
            std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
            break;

        case '=':
            std::cout << counter.get_value() << std::endl;
            std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
            break;

        case 'x':
            std::cout << "�� ��������!" << std::endl;
            return 0;

        default:
            std::cout << "����������� �������! ������� '+', '-', '=' ��� 'x': ";
            break;
        }
    }

    return 0;
}
