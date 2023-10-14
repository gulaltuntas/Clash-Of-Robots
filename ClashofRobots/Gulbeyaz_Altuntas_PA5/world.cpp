#include "world.h"
#include <iostream>
using namespace std;


World::World() { // default constructor
    numberOfRobots = 0;
    int i,j;
    for(i = 0; i < WORLDSIZE;i++) {
        for(j = 0;j < WORLDSIZE;j++) {
            grid[i][j] = NULL;  // setting all the places in the map to null since it's default
        }
    }
}


void World::setAt(int x,int y, Robot *robot){
     
     if((x>=0) && (x<WORLDSIZE) && (y>=0) && (y<WORLDSIZE)) { // inside our world map, setting the x and y point to our robot object
        grid[x][y] = robot;  // assigning the robot 
    }

}

Robot* World::getAt(int x, int y){ // turning the places of the robot object 
    if((x>=0) && (x<WORLDSIZE) && (y>=0) && (y<WORLDSIZE))
    return grid[x][y];
    return NULL;

}

/* this function is not necessarily needed but just wanted to have an option to print */

void World::Display() {
    int i,j;
    cout << endl << endl;
    for(j = 0; j < WORLDSIZE;j++) {
        for(i = 0;i < WORLDSIZE;i++) {
            if(grid[i][j] == NULL)
                cout << ".";
            else if(grid[i][j]->getintrobottype()== 0) // optimus prime print
                cout << "O"; 
            else if(grid[i][j]->getintrobottype()== 1) // robocop
                cout << "R";
            else if(grid[i][j]->getintrobottype()== 2) // roomba
                cout << "M";
            else if(grid[i][j]->getintrobottype()== 3) // bulldozer
                cout << "B";
           }
        cout << endl;
    }
    
}


/* this if_victim functions means that in our robot class, if the attacker dies, we send the x and y (that holds the place) to our
 world function to assign it into null and delete the robot here */

void World::if_Victim(int &x, int &y){
    delete(grid[x][y]);
    grid[x][y] = NULL;
}


/* our simulate function that checks the world map */


void World::simulate(){
    
    int i, j; // declared to values for the map

    for(i = 0; i < WORLDSIZE;i++) {
        for(j = 0;j < WORLDSIZE;j++) {
            if(grid[i][j] != NULL) grid[i][j]->moved = false; // scanning the field and resetting the moved flag for every robot
        }
    }
    for(i = 0; i < WORLDSIZE;i++) {
        for(j = 0;j < WORLDSIZE;j++) {
            if((grid[i][j] != NULL) ) { // if there is a robot in that place and if the robot's flag is false
                if(grid[i][j]->moved == false) { // checking if the robot is not yet moved
                    numberOfRobots--; // everytime we call the move function a robot dies so we decrease the number of robots
                    grid[i][j]->Move(); // and moving the robot that didn't move, calling the move function
                }
            }
            if(numberOfRobots <= 1) { // if there is only one robot, then we return and exit this function
                return;
            }
        }
    }
}

int World::winner(){

    Robot* winner = NULL;
    for(int i = 0; i < WORLDSIZE; i++) {
        for(int j = 0; j < WORLDSIZE; j++) {
            if(grid[i][j] != NULL) {
                 winner = grid[i][j]; //  last remaining robot is the winner
            }
        }
    }

    if(winner != NULL) {
            cout << "The winner is " << winner->getRobotName() << "!" << endl;
    }

    return 0;
}


World::~World() { // destructor function
    int i,j;
   
    for(i = 0; i < WORLDSIZE;i++) {
        for(j = 0;j < WORLDSIZE;j++) {
            if(grid[i][j] != NULL) delete (grid[i][j]); // if the place is not null we delete it
        }
    }

}
