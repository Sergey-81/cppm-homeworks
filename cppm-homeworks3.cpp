#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class Address {
private:
    std::string city;
    std::string street;
    int house;
    int apartment;

public:

    Address(std::string city, std::string street, int house, int apartment)
        : city(city), street(street), house(house), apartment(apartment) {
    }

    std::string get_output_address() {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ofstream create_input("in.txt");
    if (create_input.is_open()) {
        create_input << "3\n";
        create_input << "������\n";
        create_input << "����������\n";
        create_input << "34\n";
        create_input << "12\n";
        create_input << "����\n";
        create_input << "�������\n";
        create_input << "2\n";
        create_input << "13\n";
        create_input << "�����������\n";
        create_input << "����\n";
        create_input << "85\n";
        create_input << "64\n";
        create_input.close();
        std::cout << "���� in.txt ������ � ��������� �������" << std::endl;
    }
    else {
        std::cout << "������ �������� ����� in.txt" << std::endl;
        return 1;
    }

    std::ifstream input("in.txt");
    std::ofstream output("out.txt");

    if (!input.is_open()) {
        std::cout << "�� ������� ������� ���� in.txt" << std::endl;
        return 1;
    }

    if (!output.is_open()) {
        std::cout << "�� ������� ������� ���� out.txt" << std::endl;
        input.close();
        return 1;
    }

    int N;
    input >> N;

    Address** addresses = new Address * [N];

    for (int i = 0; i < N; i++) {
        std::string city, street;
        int house, apartment;

        input >> city;
        input >> street;
        input >> house;
        input >> apartment;

        addresses[i] = new Address(city, street, house, apartment);
    }

    output << N << std::endl;

    for (int i = N - 1; i >= 0; i--) {
        output << addresses[i]->get_output_address() << std::endl;
    }

    for (int i = 0; i < N; i++) {
        delete addresses[i];
    }
    delete[] addresses;

    input.close();
    output.close();

    std::cout << "������ ������� ���������� � �������� � out.txt" << std::endl;
    std::cout << "����� in.txt � out.txt ��������� � ����� � ����������" << std::endl;

    return 0;
}