// Copyright (c) 2015-2017 FRC Team 3512. All Rights Reserved.

#pragma once

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "State.hpp"

/* The default state is "IDLE". States that end the state machine should return
 * "IDLE" from transition(). Call run() periodically to operate the state
 * machine
 */

/**
 * Provides an easier way to create state machines
 */
class StateMachine : public State {
public:
    explicit StateMachine(std::string name);

    /* Ownership of 'state' will be transferred to this class, which will handle
     * destroying it.
     */
    void AddState(std::unique_ptr<State> state);

    template <
        class T,
        class = std::enable_if_t<!std::is_same<std::decay_t<T>, State>::value>>
    void EmplaceState(T&& state) noexcept(
        std::is_nothrow_assignable<State&, T>::value) {
        m_states.push_back(std::make_unique<State>(std::forward<T>(state)));
    }

    /* Moves the state machine to the given state. If the next state is found,
     * std::exit() for the current state and entry() for the next state are
     * called.
     * 'true' is returned if the next state was found and 'false' otherwise.
     */
    bool SetState(const std::string& nextState);

    // Returns name of current state
    const std::string GetState() const;

private:
    std::vector<std::unique_ptr<State>> m_states;
    State* m_currentState = nullptr;
};
