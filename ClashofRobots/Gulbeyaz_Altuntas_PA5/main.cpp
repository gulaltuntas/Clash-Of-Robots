#include <iostream>
#include <string>
#include "world.h"
#include "robot.h"
#include "robocop.h"
#include "humanic.h"
#include "optimusprime.h"
#include "roomba.h"
#include "bulldozer.h"
#include <cstdlib> // for rand()
#include <ctime>   // for time()

// adding our header files 

using namespace std;
 
 // declaring the const ints (initilizar is 5 meaning we will have 5 robots from each type and types as numbers )

const int INITIALIZERS = 5;
const int OPTIMUSPRIME = 0;
const int ROBOCOP = 1;
const int ROOMBA = 2;
const int BULLDOZER = 3;



int main(){

    srand(time(NULL)); // to get random values
    //declared counts for every robot type

    int robocopCount = 0;
    int bulldozerCount = 0;
    int roombaCount = 0;
    int optimusprimeCount = 0;
    World w; // our world class object 


   while (roombaCount < INITIALIZERS){ // turn until roomba count is smaller than 5 
       
        int randomX = rand() % WORLDSIZE; // getting the x value as random
        int randomY = rand() % WORLDSIZE; // getting the y value as random
        if(w.getAt(randomX, randomY)== NULL) { // if the rand places are null meaning empty, we  place the x and y to that place 
        roombaCount++; 
        Roomba *a1 = new Roomba(randomX, randomY, &w); // adding as dynamic array 
        a1->setRobotName("roomba_" + to_string(roombaCount)); // this is to add the numbers of robots, in this case roomba_0, roomba_1, roomba_2 etc...
        }
    
    }

    // cout << "roomba works" << endl;


    while (bulldozerCount < INITIALIZERS){ // turn until bulldozer count is smaller than 5
        // adding x and y randomly
        int randomX = rand() % WORLDSIZE; 
        int randomY = rand() % WORLDSIZE;
        if(w.getAt(randomX, randomY)== NULL) { // if the place we randomly get is null, we hold the place
        bulldozerCount++;
        Bulldozer *b1 = new Bulldozer(randomX, randomY, &w); // adding our object using dynamic array
        b1->setRobotName("bulldozer_" + to_string(bulldozerCount)); // to print bulldozer_0, bulldozer_1, bulldozer_2 etc....
        }
    
    }

    // cout << "bulldozer works" << endl;

    /* SAME METHOD FOR EACH ROBOT TYPE */

    while (robocopCount < INITIALIZERS){
       
        int randomX = rand() % WORLDSIZE;
        int randomY = rand() % WORLDSIZE;
        if(w.getAt(randomX, randomY)== NULL) {
        robocopCount++;
         Robocop *c1 = new Robocop(randomX, randomY, &w);
         c1->setRobotName("robocop_" + to_string(robocopCount));
        }
    
    }

    //cout << "robocop works" << endl;

    while (optimusprimeCount < INITIALIZERS){
       
        int randomX = rand() % WORLDSIZE;
        int randomY = rand() % WORLDSIZE;
        if(w.getAt(randomX, randomY)== NULL) {
        optimusprimeCount++;
         OptimusPrime *d1 = new OptimusPrime(randomX, randomY, &w);
         d1->setRobotName("optimusprime_" + to_string(optimusprimeCount));
        }
    
    }
   
    // cout << "optimusprime works" << endl;

     /* after declaring the robots */


    w.setNumberOfRobots(INITIALIZERS*4); // setting our number of robots since we have 4 robot types
    
    do{
       // w.Display(); if it's wanted
        w.simulate(); // simulate function ! 
     //  cout << "number of robots " << w.getNumberOfRobots() << endl;
    }while(w.getNumberOfRobots() != 1); // call simulate function until we will have one robot
    
   w.winner();

    return 0;
}