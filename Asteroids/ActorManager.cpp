#include "ActorManager.h"
#include <type_traits>
#include "GameManager.h"
#include <set>
#include <regex>

ActorManager::ActorManager()
{

}

bool ActorManager::DestroyActor(Actor* actorToDestroy)
{
    if (!actorToDestroy)
    {
        return false;
    }

    allActors.erase(
        std::remove_if(
            allActors.begin(), allActors.end(), [actorToDestroy] (const std::unique_ptr<Actor>& ptr) 
            {
                return ptr.get() == actorToDestroy;
            }
        ),
        allActors.end()
    );

    return true;
}

void ActorManager::DrawActors(sf::RenderWindow* drawingWindow)
{
    for (auto& sActor : allActors)
    {
        drawingWindow->draw(sActor->GetSprite());
        sf::FloatRect collider = sActor->GetCollider();
        sf::RectangleShape rectangle;
        rectangle.setPosition(collider.left, collider.top);
        rectangle.setSize(sf::Vector2f(collider.width, collider.height));
        rectangle.setFillColor(sf::Color::Transparent);
        rectangle.setOutlineColor(sf::Color::Red);
        rectangle.setOutlineThickness(1.0f);
        drawingWindow->draw(rectangle);
    }
}

bool ActorManager::NameExists(std::string name)
{
    for (auto& sActor : allActors)
    {   
        if (sActor->GetName() == name)
        {
            return true;
        }
    }
    return false;
}

int ActorManager::GetLowestNumber(const std::string& name)
{
    std::set<int> numbers;
    std::regex number_regex("\\d+");

    for (const auto& actor : allActors) 
    {
        std::string actorName = actor->GetName();
        if (actorName.find(name))
        {
            std::smatch match;
            if (std::regex_search(actorName, match, number_regex))
            {
                numbers.insert(std::stoi(match.str()));
            }
        }
    }

    int smallest_missing = 1;
    while (numbers.count(smallest_missing)) {
        ++smallest_missing;
    }
    return smallest_missing;
}

void ActorManager::FrameCall(float dt)
{
    // Collect the raw pointers of actors to be removed
    std::vector<Actor*> toBeRemoved;
    for (const auto& actor : allActors) {
        if (actor->CanDestroy()) {
            toBeRemoved.push_back(actor.get());
        }
    }

    // Remove the unique_ptrs that own the actors in toBeRemoved
    allActors.erase(
        std::remove_if(allActors.begin(), allActors.end(),
            [&toBeRemoved](const std::unique_ptr<Actor>& actor) {
                return std::find(toBeRemoved.begin(), toBeRemoved.end(), actor.get()) != toBeRemoved.end();
            }),
        allActors.end()
    );
    
    for (auto& actor : newActors) {
        actor->SetCollision(true);
        allActors.push_back(std::move(actor));
    }
    newActors.clear();
     
    
    for (size_t i = 0; i < std::size(allActors); i++)
    {

        if (allActors[i].get() != nullptr)
        {
            allActors[i]->FrameCall(dt);
            
            //COLLISION CHECK
            for (size_t j = i+1; j < std::size(allActors); j++)
            {
                if (allActors[j])
                {
                    allActors[i]->TryCollision(allActors[j].get());
                    allActors[j]->TryCollision(allActors[i].get());
                }
            }
        }   
    }
}
