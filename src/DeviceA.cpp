#include "DeviceA.h"
#include <iostream>
#include <thread>
#include <chrono>

DeviceA::DeviceA() {
    std::vector<char> digits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    Data = generateRandomString(5, 12, digits);
}

void DeviceA::getData() const {
    for (char c : Data) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << std::endl;
}
