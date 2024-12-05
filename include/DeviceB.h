#pragma once

#include "Device.h"

class DeviceB : public Device {
public:
    DeviceB();

    void getData() const override;
};