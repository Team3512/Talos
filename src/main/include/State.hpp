// Copyright (c) 2015-2020 FRC Team 3512. All Rights Reserved.

#pragma once

#include <functional>
#include <string>
#include <string_view>

/**
 * Defines State in StateMachine class
 */
class State {
public:
    explicit State(std::string_view name) : m_name{name} {}

    State(State&&) = default;
    State& operator=(State&&) = default;

    const std::string& Name() const { return m_name; }

    // entry() is run when the state is first transitioned to.
    std::function<void()> entry = [] {};

    /* transition() transitions the state of the state machine to the state
     * which has the name returned. If "" is returned, the current state will be
     * maintained.
     */
    std::function<std::string()> transition = [] { return ""; };

    // run() is run while the state machine is in that state.
    std::function<void()> run = [] {};

    // std::exit() is run when the state is being transitioned away from.
    std::function<void()> exit = [] {};

private:
    // Contains the name of the state
    std::string m_name;
};
