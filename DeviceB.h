#pragma once
#include "Device.h"

class DeviceB : public Device {
public:
    void getData(unsigned int n) override;  // ��������������� ����������� �������
    std::string generateData();  // ��������� ������ ��� DeviceB
};
