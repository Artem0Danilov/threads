#include "DeviceA.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>

// Реализация getData для DeviceA
void DeviceA::getData(unsigned int n) {
    std::string data = generateData();  // Генерация данных для DeviceA

    std::cout << "DeviceA data: " << data << "\n";  // Отладочный вывод

    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(n));  // Задержка для n секунд
    }
}

// Генерация случайных чисел для DeviceA
std::string DeviceA::generateData() {
    std::string result;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 9);  // Числа от 0 до 9
    for (int i = 0; i < 8; ++i) {  // Генерируем 8 символов данных
        result += std::to_string(dist(rd));
    }
    return result;
}
