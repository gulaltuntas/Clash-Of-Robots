#include "bulldozer.h"

/*derived class of a base class */


Bulldozer::Bulldozer(int newType, int newStrength, int newHit, string name) : Robot(3,50,200,"bulldozer"){

}

Bulldozer::Bulldozer(int randomX, int randomY, World *w) : Robot(3,50,200,randomX,randomY,w) {

}

int Bulldozer::getDamage(){
 int damage;
 damage = Robot::getDamage(); // gets damage from the robot class
 return damage;

}

string Bulldozer::getRobotType(){ // robot type "bulldozer"
    return robotName;
}


// destructor
Bulldozer::~Bulldozer(){

}