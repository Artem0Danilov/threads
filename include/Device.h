#ifndef DEVICE_H
#define DEVICE_H

#include <string>

// Базовый класс Device
class Device {
protected:
    std::string data; // Поле для хранения строки

public:
    virtual ~Device() = default;

    // Виртуальный метод для генерации строки data
    virtual void generateData() = 0;

    // Метод для вывода строки по символам с задержкой
    void getData();

    // Виртуальный метод для получения задержки
    virtual int getDelay() const = 0;
};

// Устройство A
class DeviceA : public Device {
public:
    DeviceA();
    void generateData() override;
    int getDelay() const override;
};

// Устройство B
class DeviceB : public Device {
public:
    DeviceB();
    void generateData() override;
    int getDelay() const override;
};

// Устройство C
class DeviceC : public Device {
public:
    DeviceC();
    void generateData() override;
    int getDelay() const override;
};

#endif // DEVICE_H
