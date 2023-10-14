#ifndef ROOMBA_H
#define ROOMBA_H
#include <string>
#include "robot.h"


using namespace std;
class World;
class Roomba : public Robot{ // roomba is a derived class from the robot class
    
    friend class World;
    
    public:
    Roomba();
    Roomba(int randomX, int randomY, World *w);
    Roomba(int newType, int newStrength, int newHit, string name);
    int getDamage();
    string getRobotType();
   
    ~Roomba(); // destructor



};


#endif