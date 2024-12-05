#pragma once
#include "Device.h"

class DeviceC : public Device {
public:
    void getData(unsigned int n) override;  // Переопределение виртуальной функции
    std::string generateData();  // Генерация данных для DeviceC
};
