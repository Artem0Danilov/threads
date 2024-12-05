#include "DeviceB.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>

// ���������� getData ��� DeviceB
void DeviceB::getData(unsigned int n) {
    std::string data = generateData();  // ��������� ������ ��� DeviceB

    std::cout << "DeviceB data: " << data << "\n";  // ���������� �����

    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(n));  // �������� ��� n ������
    }
}

// ��������� ��������� ��������� ���� ��� DeviceB
std::string DeviceB::generateData() {
    std::string result;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(65, 90);  // �-Z (��������� �����)
    for (int i = 0; i < 8; ++i) {  // ���������� 8 �������� ������
        result += static_cast<char>(dist(rd));
    }
    return result;
}
