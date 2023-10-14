#include "robocop.h"
#include "humanic.h"

/* derived class of a derived class */

Robocop::Robocop(){
    
}

Robocop::Robocop(int newType, int newStrength, int newHit, string name) : Humanic(1,30,40,"robocop") { // sending the robocop values as parameters

}

Robocop::Robocop(int randomX, int randomY, World *w) : Humanic(1,30,40,randomX, randomY, w){ // sending the x and y value and also world object

}


int Robocop::getDamage(){
 int damage;
 damage = Humanic::getDamage(); // it returns the damage it got from the humanic class
 return damage;
}

string Robocop::getRobotType(){ // turning the robot type as a string in this case "robocop"
    return robotName;
}



// destructor

Robocop::~Robocop() {

}
