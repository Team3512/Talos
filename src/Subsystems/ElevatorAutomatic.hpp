/*
 * ElevatorAutomatic.hpp
 *
 *  Created on: Feb 6, 2015
 *      Author: amelia
 */

#ifndef SRC_SUBSYSTEMS_ELEVATORAUTOMATIC_HPP_
#define SRC_SUBSYSTEMS_ELEVATORAUTOMATIC_HPP_

#include "Elevator.hpp"
#include <Timer.h>

class ElevatorAutomatic : public Elevator {
public:
    enum ElevatorState {
        STATE_IDLE,
        STATE_WAIT_INITIAL_HEIGHT,
        STATE_SEEK_DROP_TOTES,
        STATE_RELEASE,
        STATE_SEEK_GROUND,
        STATE_GRAB,
        STATE_SEEK_HALF_TOTE
    };

    ElevatorAutomatic();
    virtual ~ElevatorAutomatic();

    void updateState();
    void raiseElevator(int numTotes);
    void stackTotes();

private:
    void stateChanged(ElevatorState oldState, ElevatorState newState);

    const float m_toteHeights[5] {100, 150, 180, 200, 210};

    std::unique_ptr<Elevator> m_elevator;
    ElevatorState m_state;
    std::unique_ptr<Timer> m_grabTimer;
    int m_ntotes;
};

#endif /* SRC_SUBSYSTEMS_ELEVATORAUTOMATIC_HPP_ */

