#pragma once
#include <string>
#include "Point.hpp"
namespace ariel{}
using namespace std;

class Character{
    private:
    Point location;
    int hp;
    string name;


    public:
    
    Character(string name,const Point &location);
    ~Character();
    bool isAlive();
    void hit(int hits);
    string getName();
    Point getLocation();
    virtual string print();
    double distance(const Character &other)const;





};