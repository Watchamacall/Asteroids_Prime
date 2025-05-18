#include "KeyboardHandle.h"
#include "GameManager.h"

void KeyboardHandle::CheckInputs()
{
    if (GameManager::GetInstance().GetWindow()->hasFocus())
    {
        bindings->KeyCheck();
    }    
}