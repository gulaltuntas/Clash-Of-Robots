#ifndef ROBOCOP_H
#define ROBOCOP_H
#include <string>
#include "robot.h"
#include "humanic.h"


using namespace std;
class World;

class Robocop : public Humanic{ // robocop is a derived class of a derived class called humanic

    friend class World;
    public:
    Robocop(); 
    Robocop(int newType, int newStrength, int newHit, string name);
    Robocop(int randomX, int randomY, World *w);
    string getRobotType(); 
    int getDamage();
    



     ~Robocop(); // destructor





};


#endif