#ifndef HUMANIC_H
#define HUMANIC_H
#include <string>
#include "robot.h"


using namespace std;
class World;

class Humanic : public Robot{ // humanic is a derived class from robot
    friend class World;
    public:

    Humanic(); // default 
    Humanic(int newType, int newStrength, int newHit, string name);
    Humanic(int newType, int newStrength, int newHit, int x, int y, World* w);
    virtual string getRobotType() = 0; // described as virtual since it will be derived into two classes again ( robocop and optimusprime)
    int getDamage();


     ~Humanic(); // destructor



};


#endif