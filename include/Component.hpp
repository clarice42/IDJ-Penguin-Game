#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <iostream>

using namespace std;

class GameObject;

class Component
{
public:
    Component(GameObject &);
    virtual ~Component();
    void virtual Update(float) = 0;
    void virtual Render() = 0;
    bool virtual Is(string) = 0;
    void virtual Start() = 0;

protected:
    GameObject &associated;
};

#endif