#pragma once
#include <memory>

class Actor;

class Component {
protected:
    Actor* owner;

public:
    explicit Component(Actor* owner) : owner(owner) {}
    virtual ~Component() = default;

    virtual void FrameCall(float dt) {};
};