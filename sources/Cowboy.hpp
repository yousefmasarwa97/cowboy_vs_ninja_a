#pragma once
#include "Character.hpp"
namespace ariel{}



class Cowboy : public Character{
    private:
    int boolets;
    public:
    Cowboy(string name,const Point &lacation);
    ~Cowboy();
    void shoot(const Character* enemy);
    bool hasboolets();
    void reload();
    string print();
    int boolets_num();



};