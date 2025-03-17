#include "VoidDelegate.h"
#include <functional>
#include <memory>
#include "Component.h"

class APlayer;

class PlayerScore : public Component
{
public:
    PlayerScore(Actor* owner) : Component(owner)
    {
        onScoreAdded = std::make_unique<Delegate<void, int>>();
    }

    int GetScore() { return currentScore; }

    void AddScore(int ScoreToAdd);
protected:
    int currentScore = 0;
public:
    std::unique_ptr<Delegate<void,int>> onScoreAdded;
};   