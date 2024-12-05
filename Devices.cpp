#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <mutex>

class Device {
protected:
    std::string Data;
    std::string generateRandomString(int minLength, int maxLength, const std::vector<char>& validChars) {
        int length = rand() % (maxLength - minLength + 1) + minLength;
        std::string result;
        for (int i = 0; i < length; ++i) {
            result += validChars[rand() % validChars.size()];
        }
        return result;
    }
public:
    Device() {
    }

    virtual void getData() const = 0;
    };

    class DeviceA : public Device {
    public:
        DeviceA() {
            std::vector<char> digits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
            Data = generateRandomString(5, 12, digits);
        }

        void getData() const override {
            for (char c : Data) {
                std::cout << c << std::flush;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            std::cout << std::endl;
        }
    };

    class DeviceB : public Device {
    public:
        DeviceB() {
            std::vector<char> letters;
            for (char c = 'a'; c <= 'z'; ++c) letters.push_back(c);
            for (char c = 'A'; c <= 'Z'; ++c) letters.push_back(c);

            Data = generateRandomString(5, 12, letters);
        }

        void getData() const override {
            for (char c : Data) {
                std::cout << c << std::flush;
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
            std::cout << std::endl;
        }
    };

    class DeviceC : public Device {
    public:
        DeviceC() {
            std::vector<char> punctuation = { '.', ',', '!', '?', ';', ':', '-', '(', ')', '[', ']', '{', '}' };
            Data = generateRandomString(5, 12, punctuation);
        }

        void getData() const override {
            for (char c : Data) {
                std::cout << c << std::flush;
                std::this_thread::sleep_for(std::chrono::seconds(3));
            }
            std::cout << std::endl;
        }
    };

    int main() {
        srand(time(0));

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
