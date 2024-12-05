#include "DeviceA.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>

// ���������� getData ��� DeviceA
void DeviceA::getData(unsigned int n) {
    std::string data = generateData();  // ��������� ������ ��� DeviceA

    std::cout << "DeviceA data: " << data << "\n";  // ���������� �����

    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(n));  // �������� ��� n ������
    }
}

// ��������� ��������� ����� ��� DeviceA
std::string DeviceA::generateData() {
    std::string result;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 9);  // ����� �� 0 �� 9
    for (int i = 0; i < 8; ++i) {  // ���������� 8 �������� ������
        result += std::to_string(dist(rd));
    }
    return result;
}
