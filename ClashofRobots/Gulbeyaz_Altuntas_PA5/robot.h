#ifndef ROBOT_H
#define ROBOT_H
#include <string>
#include "world.h"
#include <iostream>
using namespace std;
class World;

class Robot{
    friend class World; // added world class as a friend class to access protected or private datas

    protected:
    int robotType; 
    int strength;
    int hitpoints;
    string robotName;
    int x;
    int y;
    World *world;
    bool moved;


    public:
   
    Robot(); // default
    Robot(int newType, int newStrength, int newHit, string name); // declared a constructor for to have type, strength, hitpoints and name of the robot
    Robot(int randomX, int randomY, World *w); // sending the grid numbers
    Robot(int newType, int newStrength, int newHit, int randomX, int randomY, World *w);
    
    //setters and getters for the values
    void setRobotType(int newType);
    void setStrength(int newStrength);
    void setHitpoints(int newHits);
    void setRobotName(string name);

    int getintrobottype();
    int getStrength();
    int getHitpoints();
    string getRobotName();
    virtual int getDamage(); // declared getdamage virtually 
    virtual string getRobotType() = 0; // declared string robot type as virtually 
    void hitTarget(int damage); // hit target function takes points from our hitpoints (meaning heart) 
    void Move(); // function to move the robots randomly 
    bool fight(int x1, int x2, int y1, int y2); // sending the x and y values on the grid for 
    
    virtual ~Robot();

};





#endif