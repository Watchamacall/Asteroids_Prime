#pragma once
#include <random>

class Random
{
public:
    static int RandomInt(int min, int max) 
    { 
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);

        return dis(gen);
    }

    static float RandomFloat(float min, float max)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(min, max);

        return dis(gen);
    }
};