#include "Device.h"
#include <chrono>
#include <thread>
#include <random>

// Constructor to generate random data
Device::Device() {
    // Random number generation for data size between 5 and 12
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(5, 12);  // Range from 5 to 12

    // Generate random size for the data string
    int size = dis(gen);
    data.reserve(size);  // Reserve space for the string to avoid reallocations

    // Derived classes will handle character generation
}

// Definition of the getData method for the base class
void Device::getData(unsigned int n) {
    // Loop through each character of the 'data' string
    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << std::endl;  // Output one character at a time
        std::this_thread::sleep_for(std::chrono::seconds(n));  // Sleep for 'n' seconds
    }
}

// Виртуальный деструктор
Device::~Device() {
    // Очистка ресурсов (если есть), например:
    // data.clear(); // если это нужно
}