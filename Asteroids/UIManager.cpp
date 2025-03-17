#include "UIManager.h"
#include "PlayerLives.h"
#include "PlayerScore.h"
#include "Player.h"
#include "GameManager.h"

UIManager::UIManager(Actor* owner) : Component(owner)
{
    if (APlayer* player = dynamic_cast<APlayer*>(owner))
    {    
        player->GetPlayerLives()->damageTaken.get()->AddDelegate([this](int damage)
        { LivesChanged(damage); });

        player->GetPlayerScore()->onScoreAdded->AddDelegate([this](int score)
        { ScoreChanged(score); });    
    }
    
    if (font.loadFromFile(fontLocation))
    {
        score.setFont(font);
        lives.setFont(font);
    }
    else
    {
        printf("Error loading font\n");
    }
    score.setPosition(GameManager::GetInstance().GetWindow()->getSize().x - scorePosition.x, scorePosition.y);
    score.setString("Score: 0");
    score.setFillColor(fontColor);
    score.setCharacterSize(fontSize);
    
    lives.setPosition(livesPosition);
    lives.setString("Lives: 3");
    lives.setFillColor(fontColor);
    lives.setCharacterSize(fontSize);
}

void UIManager::FrameCall(float dt)
{
    GameManager::GetInstance().GetWindow()->draw(score);
    GameManager::GetInstance().GetWindow()->draw(lives);
}

void UIManager::ScoreChanged(int newScore)
{
    score.setString("Score: " + std::to_string(newScore));
}

void UIManager::LivesChanged(int newLives)
{
    lives.setString("Lives: " + std::to_string(newLives));
}
