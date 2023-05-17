#include "Point.hpp"
#include<stdio.h>
#include <string>


namespace ariel {}

Point::Point(double x,double y):x(x),y(y){}
double Point::get_x(){return x;}
double Point::get_y(){return y;}
double Point::distance(const Point &other){
    return 1;
}
void Point::print(){}
Point Point::moveTowards(Point base, Point destination, double distance){
    Point tmp(1,1);
    return tmp;
}


