#pragma once
#include "GameState.h"
#include <memory>

class StateManager
{
public:
    std::vector<std::unique_ptr<GameState>> states;

    GameState* currentState = nullptr;

    GameState* changingState = nullptr;

public:
    /*
    * Adds a new state to the state manager
    */
    template <typename T, typename... Args>
    T* CreateNewState(Args&&... args)
    {
        static_assert(std::is_base_of<GameState, T>::value, "T must be a subclass of GameState");
        std::unique_ptr<GameState> state = std::make_unique<T>(std::forward<Args>(args)...);
        T* statePtr = static_cast<T*>(state.get());
        states.push_back(std::move(state));
        return statePtr;
    }

    void ChangeState(GameState* newState) { changingState = newState; }

    void FrameCall(float dt)
    {
        if (changingState)
        {
            ChangeState_Internal(changingState);
            changingState = nullptr;
        }
        currentState->FrameCall(dt);
    }

    void Draw(sf::RenderWindow* window)
    {
        currentState->Draw(window);
    }

    /*
    * Returns the current state
    */
    GameState* GetCurrentState(){ return currentState; } 

protected:
    /*
    * Changes the current state to the state with the given name
    */
    void ChangeState_Internal(GameState* newState);
    
};