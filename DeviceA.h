#pragma once
#include "Device.h"
#include <random>

class DeviceA : public Device {
public:
    void getData(unsigned int n) override;  // Переопределение виртуального метода
    std::string generateData();  // Генерация случайных данных для DeviceA
};
