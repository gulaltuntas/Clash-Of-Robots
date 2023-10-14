#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H
#include <string>
#include "robot.h"
#include "humanic.h"

using namespace std;

class OptimusPrime : public Humanic{ // optimusprime is a derived class from a derived class called humanic

    friend class World; // added world as friend class to access to the members
    public:
    OptimusPrime(); 
    OptimusPrime(int newType, int newStrength, int newHit, string name);
    OptimusPrime(int randomX, int randomY, World *w);

    string getRobotType();
    int getDamage();


     ~OptimusPrime(); // destructor




};


#endif