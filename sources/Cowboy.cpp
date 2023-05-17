#include "Cowboy.hpp"
#include <cstddef>
#include <string>
#include "Character.hpp"

namespace ariel {}

Cowboy::Cowboy(string name,const Point &location):Character(name,location,110),boolets(6){
}

Cowboy::~Cowboy(){}

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

