#include "KeyboardHandle.h"

void KeyboardHandle::CheckInputs(sf::Event eventPoll)
{
    if (eventPoll.type == sf::Event::KeyPressed)
    {
        for (auto& key : bindings->GetKeys())
        {
            if (eventPoll.key.code == key)
            {
                bindings->HandleInput(key);
            }
            
        }
        
    }
    
}