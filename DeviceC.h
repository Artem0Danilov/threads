#pragma once
#include "Device.h"

class DeviceC : public Device {
public:
    void getData(unsigned int n) override;  // ��������������� ����������� �������
    std::string generateData();  // ��������� ������ ��� DeviceC
};
