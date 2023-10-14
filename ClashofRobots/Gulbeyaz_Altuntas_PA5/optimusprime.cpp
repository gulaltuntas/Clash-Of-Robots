#include "optimusprime.h"
#include "humanic.h"


/* derived class of a derived class */


OptimusPrime::OptimusPrime(){

}


OptimusPrime::OptimusPrime(int newType, int newStrength, int newHit, string name) : Humanic(0,100,100,"optimusprime") {

}

OptimusPrime::OptimusPrime(int randomX, int randomY, World *w) : Humanic(0,100,100,randomX,randomY,w){

}

int OptimusPrime::getDamage(){
 int damage;
 damage = Humanic::getDamage(); // getting the damage from humanic class
 int chance;
 chance = rand() % 100 +1;
 if (chance <= 15){ // optimus prime has a %15 chance to double its attack so if we get the chance we will double the damage
    damage *= 2;
    return damage;
 }else{
    return damage; // if %85, then it means it will return just the normal damage we got from humanic class
 }
 }

string OptimusPrime::getRobotType(){ // setting the robottype as a string name
    return robotName;
}

//destructor

OptimusPrime::~OptimusPrime(){

}