#pragma once

#include "Device.h"

class DeviceA : public Device {
public:
    DeviceA();

    void getData() const override;
};