#pragma once
#include "GameState.h"

class StateManager
{
public:
    std::vector<std::unique_ptr<GameState>> states;

    GameState* currentState = nullptr;

public:
    /*
    * Adds a new state to the state manager
    */
    template <typename T>
    T* AddState()
    {
        static_assert(std::is_base_of<GameState, T>::value, "T must be a subclass of GameState");
        std::unique_ptr<GameState> state = std::make_unique<T>();
        T* statePtr = static_cast<T*>(state.get());
        states.push_back(std::move(state));
        return statePtr;
    }

    /*
    * Changes the current state to the state with the given name
    */
    void ChangeState(GameState* newState)
    {
        for (auto& state : states)
        {
            if (state.get() == newState)
            {
                if (currentState)
                {
                    currentState->Exit();
                }
                currentState = state.get();
                currentState->Enter();
                return;
            }
        }
    }

    /*
    * Returns the current state
    */
    GameState* GetCurrentState(){ return currentState; }
};