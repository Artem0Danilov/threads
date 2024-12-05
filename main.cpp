#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

class Device {
protected:
    string data; // Поле для хранения строки

public:
    virtual ~Device() = default;

    // Виртуальный метод для генерации строки data
    virtual void generateData() = 0;

    // Метод для вывода строки по символам с задержкой
    void getData() {
        for (char c : data) {
            cout << c << flush;
            this_thread::sleep_for(chrono::seconds(getDelay()));
        }
        cout << endl;
    }

    // Виртуальный метод для получения задержки
    virtual int getDelay() const = 0;
};

class DeviceA : public Device {
public:
    DeviceA() {
        generateData();
    }

    // Генерация строки из цифр
    void generateData() override {
        data.clear();
        int length = rand() % 8 + 5; // Длина строки от 5 до 12
        for (int i = 0; i < length; ++i) {
            data += '0' + rand() % 10; // Генерация случайной цифры
        }
    }

    // Задержка 1 секунда
    int getDelay() const override {
        return 1;
    }
};

class DeviceB : public Device {
public:
    DeviceB() {
        generateData();
    }

    // Генерация строки из латинских букв
    void generateData() override {
        data.clear();
        int length = rand() % 8 + 5; // Длина строки от 5 до 12
        for (int i = 0; i < length; ++i) {
            data += 'a' + rand() % 26; // Генерация случайной буквы
        }
    }

    // Задержка 2 секунды
    int getDelay() const override {
        return 2;
    }
};

class DeviceC : public Device {
public:
    DeviceC() {
        generateData();
    }

    // Генерация строки из специальных символов
    void generateData() override {
        data.clear();
        const string symbols = "!;№?%$#@*^|"; // Допустимые символы
        int length = rand() % 8 + 5; // Длина строки от 5 до 12
        for (int i = 0; i < length; ++i) {
            data += symbols[rand() % symbols.size()]; // Случайный символ из symbols
        }
    }

    // Задержка 3 секунды
    int getDelay() const override {
        return 3;
    }
};

void runDevice(Device* device) {
    device->getData();
}

int main() {
    srand(time(nullptr)); // Инициализация генератора случайных чисел

    // Создание объектов устройств
    Device* deviceA = new DeviceA();
    Device* deviceB = new DeviceB();
    Device* deviceC = new DeviceC();

    // Создание потоков
    thread threadA(runDevice, deviceA);
    thread threadB(runDevice, deviceB);
    thread threadC(runDevice, deviceC);

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
