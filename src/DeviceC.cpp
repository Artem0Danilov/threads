#include "DeviceC.h"
#include <iostream>
#include <thread>
#include <chrono>

DeviceC::DeviceC() {
    std::vector<char> punctuation = { '.', ',', '!', '?', ';', ':', '-', '(', ')', '[', ']', '{', '}' };
    Data = generateRandomString(5, 12, punctuation);
}

void DeviceC::getData() const {
    for (char c : Data) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    std::cout << std::endl;
}