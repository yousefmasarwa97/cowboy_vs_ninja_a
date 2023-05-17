#include "Ninja.hpp"
#include "Character.hpp"
#include"Point.hpp"

namespace ariel {
}


Ninja::Ninja(string name,const Point &location):Character(name,location),speed(){    
}

Ninja::~Ninja(){}
void Ninja::move(const Character *enemy){}
void Ninja::slash(const Character *enemy){}
int Ninja::get_hp(){return 100;}
