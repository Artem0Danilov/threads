#include "DeviceB.h"
#include <iostream>
#include <thread>
#include <chrono>

DeviceB::DeviceB() {
    std::vector<char> letters;
    for (char c = 'a'; c <= 'z'; ++c) letters.push_back(c);
    for (char c = 'A'; c <= 'Z'; ++c) letters.push_back(c);

    Data = generateRandomString(5, 12, letters);
}

void DeviceB::getData() const {
    for (char c : Data) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    std::cout << std::endl;
}
