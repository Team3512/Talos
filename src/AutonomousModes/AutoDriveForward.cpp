// =============================================================================
// File Name: AutoDriveForward.cpp
// Description: Drives forward
// Author: FRC Team 3512, Spartatroniks
// =============================================================================

#include "../Robot.hpp"

void Robot::AutoDriveForward() {
    Timer timer;
    timer.Start();

    while (!timer.HasPeriodPassed(2.5) && IsAutonomous() && IsEnabled()) {
        DS_PrintOut();
        robotDrive.drive(-0.4, 0.0, false);
        std::this_thread::sleep_for(10ms);
    }
    robotDrive.drive(0.0, 0.0, false);
}

