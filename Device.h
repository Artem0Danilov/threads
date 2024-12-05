#pragma once

#include <vector>

class Device {
protected:
    std::string Data;

    std::string generateRandomString(int minLength, int maxLength, const std::vector<char>& validChars);

public:
    Device();

    virtual void getData() const = 0;

};