#ifndef WORLD_H
#define WORLD_H
#include "robot.h"

using namespace std;

const int WORLDSIZE = 10; // declared our worldsize as const int since it wont change
class Robot;

class World{

    // added other functions as friend class
    friend class Robot;
    friend class Roomba;
    friend class Humanic;
    friend class OptimusPrime;
    friend class Robocop;
    
    public:

    World();
    Robot* getAt(int x, int y); // sending our x and y values that holds the place in the map to robot class
    void setAt(int x,int y, Robot *robot); 
    void Display(); // to print the map, not necessary but if it's wanted 
    void simulate(); // this is for to activate the robots' fights
    void setNumberOfRobots(int newNumber) {numberOfRobots = newNumber;} // we get our number of robots
    int getNumberOfRobots() {return numberOfRobots;}
    void if_Victim(int&x, int& y); // this is a special function 
    ~World();
    int winner();


    private:
        int numberOfRobots; 
        Robot* grid[WORLDSIZE][WORLDSIZE]; // the map
};

#endif