#pragma once
#include <iostream>
#include <string>

class Device {
public:
    Device();  // �����������
    virtual ~Device();  // ����������� ����������

    virtual void getData(unsigned int n) = 0;  // ����������� �����
    std::string data;
};
