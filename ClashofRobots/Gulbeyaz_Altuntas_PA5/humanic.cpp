#include "humanic.h"

/*since it's a derived class we will use our destructors from our base class*/

Humanic::Humanic() : Robot() {


}
Humanic::Humanic(int newType, int newStrength, int newHit, string name) : Robot(newType,newStrength,newHit,name){

}
Humanic::Humanic(int newType, int newStrength, int newHit, int randomX, int randomY, World *w) : Robot(newType,newStrength,newHit,randomX,randomY,w) {

}

// OUR GET DAMAGE FUNCTION 

int Humanic::getDamage(){
    int damage;
    damage = Robot::getDamage(); // calling the get damage function from the robot class 

    /* humanic robots have a %10 chance to get +50 points */

    int chance; 
    chance = rand() % 100 +1;
    if (chance <= 10){
        damage += 50; // adding +50 points if we had that %10 chance
        return damage;
    }else{
        return damage; // else we just turn the normal damage we got 
    }
    
}

Humanic::~Humanic(){

}