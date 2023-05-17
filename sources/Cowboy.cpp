#include "Cowboy.hpp"
#include <cstddef>
#include <string>
#include "Character.hpp"

namespace ariel {}

Cowboy::Cowboy(string name,const Point& location):Character(name,location),boolets(6){
}



void Cowboy::shoot(const Character *enemy){
}

bool Cowboy::hasboolets(){
    return true;
}

void Cowboy::reload(){
}

string Cowboy::print(){
    return "";
}

int Cowboy::boolets_num(){
    return boolets;
}

