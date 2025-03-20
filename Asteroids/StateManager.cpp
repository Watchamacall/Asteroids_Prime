#include "StateManager.h"

void StateManager::ChangeState_Internal(GameState *newState)
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
