// Copyright (c) 2015-2017 FRC Team 3512. All Rights Reserved.

#pragma once

#include "../Settings.hpp"

/**
 * Base class for all robot subsystems
 */
class SubsystemBase {
public:
    virtual ~SubsystemBase() = default;

    virtual void reloadPID() = 0;
    virtual void resetEncoders() = 0;

protected:
    Settings m_settings{"/home/lvuser/RobotSettings.txt"};
};
