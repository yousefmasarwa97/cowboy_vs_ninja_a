#pragma once
#include "Character.hpp"
#include <string>

namespace ariel
{
}

class Ninja : public Character{
    private:
    int speed;

    public:
    Ninja(string name,const Point &location);
    ~Ninja();
    void move(const Character* enemy);
    virtual void slash(const Character* enemy);
    int get_hp();

};