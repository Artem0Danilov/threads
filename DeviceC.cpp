#include "DeviceC.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>

// ���������� getData ��� DeviceC
void DeviceC::getData(unsigned int n) {
    std::string data = generateData();  // ��������� ������ ��� DeviceC

    std::cout << "DeviceC data: " << data << "\n";  // ���������� �����

    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(n));  // �������� ��� n ������
    }
}

// ��������� ��������� �������� ��� DeviceC
std::string DeviceC::generateData() {
    std::string result;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(33, 47);  // ������� �� ! �� /
    for (int i = 0; i < 8; ++i) {  // ���������� 8 �������� ������
        result += static_cast<char>(dist(rd));
    }
    return result;
}
