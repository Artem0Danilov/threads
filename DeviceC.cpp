#include "DeviceC.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>

// Реализация getData для DeviceC
void DeviceC::getData(unsigned int n) {
    std::string data = generateData();  // Генерация данных для DeviceC

    std::cout << "DeviceC data: " << data << "\n";  // Отладочный вывод

    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(n));  // Задержка для n секунд
    }
}

// Генерация случайных символов для DeviceC
std::string DeviceC::generateData() {
    std::string result;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(33, 47);  // Символы от ! до /
    for (int i = 0; i < 8; ++i) {  // Генерируем 8 символов данных
        result += static_cast<char>(dist(rd));
    }
    return result;
}
