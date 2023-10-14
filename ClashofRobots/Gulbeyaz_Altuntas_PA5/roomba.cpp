#include "roomba.h"
/*derived class of a base class*/
Roomba::Roomba(){

}

Roomba::Roomba(int newType, int newStrength, int newHit, string name) : Robot(2,3,10,"roomba") { // sending the roomba values such as robot type, strength, hit point and name

}

Roomba::Roomba(int randomX, int randomY, World *w) : Robot(2,3,10,randomX,randomY,w) { // sending the other parameters such as x value and y value on the grid

}


int Roomba::getDamage(){
    int damage;
    int damage_twice;
    /* since roomba's are so fast they get to attack twice which means we will declare two damages and add them and return them */
    damage = Robot::getDamage(); 
    damage_twice = Robot::getDamage();
    damage += damage_twice; // adding damage(1) and damage_two to each other
    return damage;
}

string Roomba::getRobotType() { // returning the robot name "robocop"
   return robotName;
}

// destructor

Roomba::~Roomba(){

}