#include <iostream>
#include <thread>
#include <mutex>
#include "DeviceA.h"
#include "DeviceB.h"
#include "DeviceC.h"

// Мьютекс для потокобезопасного вывода
std::mutex coutMutex;

// Функция для запуска getData для DeviceA
void runDeviceA(DeviceA& device) {
    std::cout << "DeviceA thread starting...\n";
    device.getData(1);  // Запускаем DeviceA с n = 1 секунда
    std::cout << "DeviceA thread completed.\n";
}

// Функция для запуска getData для DeviceB
void runDeviceB(DeviceB& device) {
    std::cout << "DeviceB thread starting...\n";
    device.getData(2);  // Запускаем DeviceB с n = 2 секунды
    std::cout << "DeviceB thread completed.\n";
}

// Функция для запуска getData для DeviceC
void runDeviceC(DeviceC& device) {
    std::cout << "DeviceC thread starting...\n";
    device.getData(3);  // Запускаем DeviceC с n = 3 секунды
    std::cout << "DeviceC thread completed.\n";
}

int main() {
    // Создаем объекты DeviceA, DeviceB и DeviceC
    DeviceA deviceA;
    DeviceB deviceB;
    DeviceC deviceC;

    std::cout << "Starting threads...\n";

    // Создаем потоки для каждого устройства
    std::thread threadA(runDeviceA, std::ref(deviceA));
    std::thread threadB(runDeviceB, std::ref(deviceB));
    std::thread threadC(runDeviceC, std::ref(deviceC));

    // Ожидаем завершения всех потоков
    threadA.join();
    threadB.join();
    threadC.join();

    std::cout << "All threads completed!\n";

    // Ожидаем ввода, чтобы окно консоли не закрылось
    std::cin.get();

    return 0;
}
