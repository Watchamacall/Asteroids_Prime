#include "PlayerScore.h"
#include "Player.h"
#include "Component.h"

void PlayerScore::AddScore(int scoreToAdd)
{
    currentScore += scoreToAdd;

    onScoreAdded->Execute(currentScore);
}
