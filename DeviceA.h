#pragma once
#include "Device.h"
#include <random>

class DeviceA : public Device {
public:
    void getData(unsigned int n) override;  // ��������������� ������������ ������
    std::string generateData();  // ��������� ��������� ������ ��� DeviceA
};
