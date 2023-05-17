#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Ninja.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Point.hpp"
#include "sources/Team.hpp"
#include <string>
#include <vector>
#include <math.h>
#include <sstream>
#include <cmath>
using namespace ariel;
using namespace std;

TEST_SUITE("Point")
{

    TEST_CASE("Testing distance between two points")
    {
        Point p1(1, 1);
        Point p2(4, 5);
        Point p3(17, 5);
        Point p4(15, 2);
        CHECK(p1.distance(p2) == 5);
        CHECK(p2.distance(p3) == 13);
        CHECK_LT(p1.distance(p3), 17);
        CHECK_GT(p1.distance(p3), 16);
        CHECK_LT(p1.distance(p2), p2.distance(p3));
        CHECK(p1.distance(p1) == 0);
    }

   
   
    TEST_CASE("Testing MoveToWards function")
    {
        Point p1(0, 0);
        Point p2(12, 0);
        Point p3(15, 0);
        Point p4 = p1.moveTowards(p1, p3, 14);
        CHECK(p4.get_x() == p2.get_x());
        CHECK(p4.get_y() == p2.get_y());

        Point p5(13.5,0);
        p4 = p1.moveTowards(p1, p3, 14);
        CHECK(p4.get_x() == p5.get_x());
        CHECK(p4.get_y() == p5.get_y());

        Point p6(14.1,0);
        p4 = p1.moveTowards(p1, p3, 14);
        CHECK(p4.get_x() == p5.get_x());
        CHECK(p4.get_y() == p5.get_y());
    }
}

TEST_SUITE("Character")
{
    Point first_char_loc(1,1);
    Character first_char("first_char",first_char_loc);
    Point second_char_loc(2,2);
    Character second_char("second_char",second_char_loc);
    Point cowboy_loc(15,4);
    Cowboy cowboy("andiana jones",cowboy_loc);
    Point youngninja_loc(12,87);
    YoungNinja youngninja("youngninja",youngninja_loc);
    Point trainedninja_loc(65.32,11);
    TrainedNinja trainedninja("trainedninja",trainedninja_loc);
    Point oldninja_loc(43.76,23.6);
    OldNinja oldninja("oldninja",oldninja_loc);
    Point ninja_loc(98,5.3);
    Ninja ninja("ninja",ninja_loc);
    
    TEST_CASE("isAlive() function")
    {
        CHECK(first_char.isAlive());
        CHECK(second_char.isAlive());
        CHECK(cowboy.isAlive());
        CHECK(youngninja.isAlive());
        CHECK(trainedninja.isAlive());
        CHECK(oldninja.isAlive());
        CHECK(ninja.isAlive());
    }

    TEST_CASE("test hit() function")
    {
        first_char.hit(100);
        second_char.hit(100);
        cowboy.hit(100);
        youngninja.hit(100);
        trainedninja.hit(100);
        oldninja.hit(100);
        ninja.hit(100);

        CHECK_FALSE(first_char.isAlive());
        CHECK_FALSE(second_char.isAlive());
        CHECK_FALSE(youngninja.isAlive());
        CHECK(cowboy.isAlive());
        CHECK(trainedninja.isAlive());
        CHECK(oldninja.isAlive());
        CHECK(ninja.isAlive());

        cowboy.hit(50);
        youngninja.hit(50);
        trainedninja.hit(50);
        oldninja.hit(50);
        ninja.hit(50);
        CHECK_FALSE(cowboy.isAlive());
        CHECK_FALSE(youngninja.isAlive());
        CHECK_FALSE(trainedninja.isAlive());
        CHECK_FALSE(oldninja.isAlive());
        CHECK_FALSE(ninja.isAlive());   
    }

    TEST_CASE("Testing getName() and getLocation finctions")
    {
        CHECK(first_char.getName()=="first_char");
        CHECK(first_char_loc.get_x()==first_char.getLocation().get_x());
        CHECK(first_char_loc.get_y()==first_char.getLocation().get_y());
        CHECK(second_char.getName()=="second_char");
        CHECK(second_char_loc.get_x()==second_char.getLocation().get_x());
        CHECK(second_char_loc.get_y()==second_char.getLocation().get_y());
        CHECK(youngninja.getName()=="youngninja");
        CHECK(youngninja_loc.get_x()==youngninja.getLocation().get_x());
        CHECK(youngninja_loc.get_y()==youngninja.getLocation().get_y());
        CHECK(cowboy.getName()=="andiana jones");
        CHECK(cowboy_loc.get_x()==cowboy.getLocation().get_x());
        CHECK(cowboy_loc.get_y()==cowboy.getLocation().get_y());
        CHECK(trainedninja.getName()=="trainedninja");
        CHECK(trainedninja_loc.get_x()==trainedninja.getLocation().get_x());
        CHECK(trainedninja_loc.get_y()==trainedninja.getLocation().get_y());
        CHECK(oldninja.getName()=="oldninja");
        CHECK(oldninja_loc.get_x()==oldninja.getLocation().get_x());
        CHECK(oldninja_loc.get_y()==oldninja.getLocation().get_y());
        CHECK(ninja.getName()=="ninja");
        CHECK(ninja_loc.get_x()==ninja.getLocation().get_x());
        CHECK(ninja_loc.get_y()==ninja.getLocation().get_y());
        
    }
    TEST_CASE("Testing print function"){
        string a1=first_char.print();
        string a2=second_char.print();
        string a3=cowboy.print();
        string a4=youngninja.print();
        string a5=oldninja.print();
        string a6=trainedninja.print();
        string a7=ninja.print();

        CHECK_EQ(a1,"first_char,100,(1,1)");
        CHECK_EQ(a2,"second_char,100,(2,2)");
        CHECK_EQ(a3,"andiana jones,110,(15,4)");
        CHECK_EQ(a4,"youngninja,100,(12,87)");
        CHECK_EQ(a5,"oldninja,150,(43.76,23.6)");
        CHECK_EQ(a6,"traindeninja,120,(65.32,11)");
        CHECK_EQ(a7,"ninja,100,(98,5.3)");

        first_char.hit(200);
        second_char.hit(200);
        cowboy.hit(200);
        youngninja.hit(200);
        trainedninja.hit(200);
        oldninja.hit(200);
        ninja.hit(200);
        a1=first_char.print();
        a2=second_char.print();
        a3=cowboy.print();
        a4=youngninja.print();
        a5=oldninja.print();
        a6=trainedninja.print();
        a7=ninja.print();
        CHECK_EQ(a1,"(first_char)");
        CHECK_EQ(a2,"(second_char)");
        CHECK_EQ(a3,"C(andiana jones)");
        CHECK_EQ(a4,"N(youngninja)");
        CHECK_EQ(a5,"N(oldninja)");
        CHECK_EQ(a6,"N(traindeninja)");
        CHECK_EQ(a7,"N(ninja");

    }
}
TEST_SUITE("Cowboy"){
    Point cowboy1_loc(15,4);
    Cowboy cowboy1("andiana jones",cowboy1_loc);
    Point cowboy2_loc(100,3.5);
    Cowboy cowboy2("tom",cowboy2_loc);
    Point cowboy3_loc(87,34);
    Cowboy cowboy3("sandro",cowboy3_loc);
    Point cowboy4_loc(298,18.18);
    Cowboy cowboy4("francesco",cowboy4_loc);

    TEST_CASE("cheking if the inizialtion is correct"){
        CHECK(cowboy1.hasboolets());
        CHECK(cowboy2.hasboolets());
        CHECK(cowboy3.hasboolets());
        CHECK(cowboy4.hasboolets());  
    }

    TEST_CASE("cheking the reload function"){
        cowboy1.shoot(&cowboy2);
        cowboy2.shoot(&cowboy3);
        cowboy3.shoot(&cowboy4);
        cowboy4.shoot(&cowboy1);
        cowboy1.reload();
        cowboy2.reload();
        cowboy3.reload();
        cowboy4.reload();

        CHECK_EQ(cowboy1.boolets_num(),6);
        CHECK_EQ(cowboy2.boolets_num(),6);
        CHECK_EQ(cowboy3.boolets_num(),6);
        CHECK_EQ(cowboy4.boolets_num(),6);
    }
     


}

TEST_SUITE("Ninja")
{ 
    Point youngninja_loc(0,0);
    YoungNinja youngninja("youngninja",youngninja_loc);
    Point trainedninja_loc(200,200);
    TrainedNinja trainedninja("trainedninja",trainedninja_loc);
    Point oldninja_loc(300,300);
    OldNinja oldninja("oldninja",oldninja_loc);
    Point ninja_loc(400,400);
    Ninja ninja("ninja",ninja_loc);

    TEST_CASE("cheking the move function"){
    youngninja.move(&trainedninja);
    youngninja.move(&oldninja);
    youngninja.move(&ninja);
    CHECK(youngninja.distance(trainedninja)==141.4213562373);
    CHECK(youngninja.distance(oldninja)==282.8427124746);
    CHECK(youngninja.distance(ninja)==424.2640687119);
    }
    TEST_CASE("cheking the slash() function"){
        youngninja.slash(&trainedninja);
        youngninja.slash(&oldninja);
        youngninja.slash(&ninja);
        CHECK(trainedninja.get_hp()==120);
        CHECK(oldninja.get_hp()==150);
        CHECK(ninja.get_hp()==100);

        youngninja.move(&trainedninja);
        youngninja.move(&oldninja);
        youngninja.move(&ninja);
        youngninja.move(&trainedninja);
        youngninja.move(&oldninja);
        youngninja.move(&ninja);
        CHECK(trainedninja.get_hp()==80);
        CHECK(oldninja.get_hp()==110);
        CHECK(ninja.get_hp()==60);

    }

    
  
}