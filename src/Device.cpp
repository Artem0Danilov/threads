#include "Device.h"

Device::Device() {}

std::string Device::generateRandomString(int minLength, int maxLength, const std::vector<char>& validChars) {
    int length = rand() % (maxLength - minLength + 1) + minLength;
    std::string result;
    for (int i = 0; i < length; ++i) {
        result += validChars[rand() % validChars.size()];
    }
    return result;
}
