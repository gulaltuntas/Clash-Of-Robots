#ifndef BULLDOZER_H
#define BULDOZER_H
#include <string>
#include "robot.h"


using namespace std;
class World;

class Bulldozer : public Robot{ // definition of a derived class
    friend class World;
    public:
    Bulldozer(); // default constructor
    Bulldozer(int randomX, int randomY, World *w); // x, y and our world object
    Bulldozer(int newType, int newStrength, int newHit, string name); 
    int getDamage(); // virtual get damage function 
    string getRobotType(); // virtual get robot type function
   


     ~Bulldozer(); // destructor
 






};


#endif