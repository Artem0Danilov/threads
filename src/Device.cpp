#include "Device.h"
#include <iostream>
#include <thread>
#include <cstdlib>
#include <chrono>

// Реализация методов базового класса Device
void Device::getData() {
    for (char c : data) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(getDelay()));
    }
    std::cout << std::endl;
}

// Реализация методов DeviceA
DeviceA::DeviceA() {
    generateData();
}

void DeviceA::generateData() {
    data.clear();
    int length = rand() % 8 + 5; // Длина строки от 5 до 12
    for (int i = 0; i < length; ++i) {
        data += '0' + rand() % 10; // Генерация случайной цифры
    }
}

int DeviceA::getDelay() const {
    return 1; // Задержка 1 секунда
}

// Реализация методов DeviceB
DeviceB::DeviceB() {
    generateData();
}

void DeviceB::generateData() {
    data.clear();
    int length = rand() % 8 + 5; // Длина строки от 5 до 12
    for (int i = 0; i < length; ++i) {
        data += 'a' + rand() % 26; // Генерация случайной буквы
    }
}

int DeviceB::getDelay() const {
    return 2; // Задержка 2 секунды
}

// Реализация методов DeviceC
DeviceC::DeviceC() {
    generateData();
}

void DeviceC::generateData() {
    data.clear();
    const std::string symbols = "!;№?%$#@"; // Допустимые символы
    int length = rand() % 8 + 5; // Длина строки от 5 до 12
    for (int i = 0; i < length; ++i) {
        data += symbols[rand() % symbols.size()]; // Случайный символ из symbols
    }
}

int DeviceC::getDelay() const {
    return 3; // Задержка 3 секунды
}
