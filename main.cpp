#include <iostream>
#include <thread>
#include <vector>
#include "DeviceA.h"
#include "DeviceB.h"
#include "DeviceC.h"

int main() {
    srand(static_cast<unsigned>(time(0)));

    DeviceA deviceA;
    DeviceB deviceB;
    DeviceC deviceC;

    std::thread threadA([&]() {
        deviceA.getData();
        });
    std::thread threadB([&]() {
        deviceB.getData();
        });
    std::thread threadC([&]() {
        deviceC.getData();
        });

    threadA.join();
    threadB.join();
    threadC.join();

}
