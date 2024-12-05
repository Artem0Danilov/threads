#pragma once

#include "Device.h"

class DeviceC : public Device {
public:
    DeviceC();

    void getData() const override;
};