#include "Device.h"
#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>

// Вспомогательная функция для запуска устройства
void runDevice(Device* device) {
    device->getData();
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Инициализация генератора случайных чисел

    // Создание объектов устройств
    Device* deviceA = new DeviceA();
    Device* deviceB = new DeviceB();
    Device* deviceC = new DeviceC();

    // Создание потоков
    std::thread threadA(runDevice, deviceA);
    std::thread threadB(runDevice, deviceB);
    std::thread threadC(runDevice, deviceC);

    // Ожидание завершения потоков
    threadA.join();
    threadB.join();
    threadC.join();

    // Удаление объектов
    delete deviceA;
    delete deviceB;
    delete deviceC;

    return 0;
}
