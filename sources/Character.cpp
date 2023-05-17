#include "Character.hpp"
// #include <cstddef>
#include "Point.hpp"
namespace ariel{}


Character::Character(string name,const Point &location):location(location),name(name){
}
Character::~Character(){}
Point Character::getLocation(){
    return this->location;
}
string Character::getName(){
    return this->name;
}
bool Character::isAlive(){
    return true;
}
double Character::distance(const Character &other)const{
    return 1;
}
void Character::hit(int hits){}
string Character::print(){
    return " ";
}
