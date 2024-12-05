#pragma once
#include <iostream>
#include <string>

class Device {
public:
    Device();  // Конструктор
    virtual ~Device();  // Виртуальный деструктор

    virtual void getData(unsigned int n) = 0;  // Виртуальный метод
    std::string data;
};
