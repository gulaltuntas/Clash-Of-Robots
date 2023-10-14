#include "robot.h"

/* CONSTRUCTORS OF THE ROBOT CLASS */


Robot::Robot(){ // default constructor 
    robotName = "";
    robotType = 0;
    strength = 0;
    hitpoints = 0;
    x = 0;
    y = 0;
    world = NULL;
    moved = false;
}

Robot::Robot(int randomX, int randomY, World *w){ // getting the x and y value and world object 
    robotName = "";
    robotType = 0;
    strength = 0;
    hitpoints = 0;
    x = randomX;
    y = randomY;
    this->world = w;
    moved = false;
    world->setAt(x, y, this);
}

Robot::Robot(int newType, int newStrength, int newHit, string name){ // constructor that takes these values
    robotName = name;
    robotType = newType;
    strength = newStrength;
    hitpoints = newHit;
}


Robot::Robot(int newType, int newStrength, int newHit, int randomX, int randomY, World *w) { // constructor for all 
    robotType = newType;
    strength = newStrength;
    hitpoints = newHit;
    x = randomX;
    y = randomY;
    this->world = w;
    moved = false;
    world->setAt(x, y, this);
}

/* SETTERS AND GETTERS */

void Robot::setRobotType(int newType){
    robotType = newType;
}

void Robot::setStrength(int newStrength){
    strength = newStrength;
}

void Robot::setHitpoints(int newHits){
   // hitpoints -= newHits;
     hitpoints = newHits;
}

void Robot::setRobotName(string name){
    robotName = name;
}



int Robot::getHitpoints(){return hitpoints; }
int Robot::getStrength(){return strength;}
string Robot::getRobotName(){return robotName;}
int Robot::getintrobottype(){return robotType;}



int Robot::getDamage(){
    int damage;
    damage = rand() % strength + 1; // getting a random damage value 
    return damage;
}


void Robot::hitTarget(int damage){
    
    hitpoints -= damage; // hit target means that we will take from our hitpoins with the damage value
  
}


bool Robot::fight(int x1, int y1, int x2, int y2){ // takes 4 parameters, 2 x values for the both robots and 2 y values
    
    int damage; // declared a new damage 
    int dead = 0; // dead flag
    
    do{  // do get damage and hit until one of them is dead

    damage = world->grid[x1][y1]->getDamage(); // getting the damage value from the attacker 
    cout << world->grid[x1][y1]->getRobotName() << " attacked " << world->grid[x2][y2]->getRobotName() << " with " << damage << " points!" << endl;
    world->grid[x2][y2]->hitTarget(damage); // taking from the victim's hitpoints the amount of damage
    cout << "The new hitpoints of " << world->grid[x2][y2]->getRobotName() << " is " <<  world->grid[x2][y2]->hitpoints << endl;
    if (world->grid[x2][y2]->getHitpoints() <= 0){ // if the victim is dead, turn the flag into one and exit the looğ
        cout << "The dead robot is " << world->grid[x2][y2]->getRobotName() << endl;
        dead = 1;
    }else { // else, do the same operation for victim to attacker
        damage = world->grid[x2][y2]->getDamage();
        cout << world->grid[x2][y2]->getRobotName() << " attacked " << world->grid[x1][y1]->getRobotName() << " with " << damage << " points!" << endl;
        hitTarget(damage);
        cout << "The new hitpoints of " << world->grid[x1][y1]->getRobotName() << " is " << hitpoints << endl;
        if(world->grid[x1][y1]->getHitpoints()<= 0){
            cout << "The dead robot is " << world->grid[x1][y1]->getRobotName() << endl;
            dead = -1;
        }
    }
    }while(dead == 0);

    cout << endl;
    if(dead == 1){
        return true; // returning true if the attacker wons 
    }
    else{return false;}    // returning false if the victim wons


}

/*MOVE FUNCTION THAT RANDOMLY MOVES ROBOTS AND MAKES THEM FIGHT WITH EACH OTHER */

void Robot::Move(){

    int prevX = x; // holds the value of the x and y that we get from the start 
    int prevY = y;
    int dir = rand() % 4; // random direction 
    while (true) {
        if(dir == 0) {
            if((y>0) && (world->getAt(x,y-1) == NULL) && (y-1 != prevY)) { // if the left is null, we move the robot to that place 
                world->setAt(x,y-1,world->getAt(x,y));
                world->setAt(x,y,NULL);
                y--;
                moved = true; // turning the moved flag into true
            }
            else if ((y>0) && (world->getAt(x, y-1) != NULL)){ // if the place is not null, we call the fight function

                    if(fight(x, y, x, y-1)){ // if the first robot will win, it will delete the other and replace it 
                    delete (world->grid[x][y-1]);
                    world->grid[x][y-1] = this;
                    world->setAt(x,y,NULL);
                    y--;
                    }
                    else{ // if the second robot wins, we call the if_victim function in the world class to delete the robot object 
                        world->if_Victim(x,y);
                        moved = true;
                    }
                    return;
                  
                }
                  prevX = x; // setting the x and y to it's new place
                  prevY = y;
            }

      

        else if(dir == 1) { 
            if((y<WORLDSIZE-1) && (world->getAt(x,y+1) == NULL)) { // if the right place of the robot is null it moves there 
                world->setAt(x,y+1,world->getAt(x,y));
                world->setAt(x,y,NULL);
                y++;
                moved = true;
            }
            else if((y<WORLDSIZE-1) && (world->getAt(x, y+1) != NULL)){ // if not null we call the fight function 
               if(fight(x, y, x, y+1)){ // if the first robot will win, it will delete the other and replace it 
                        delete (world->grid[x][y+1]);
                        world->grid[x][y+1] = this;
                        world->setAt(x,y,NULL);
                        y++;
                    }
                    else{ // if the second robot wins, it will call the if_victim function to delete the attacker
                         world->if_Victim(x,y); 
                         moved = true;
                    }
                    return;
                   
            }
              prevX = x;
              prevY = y;
        }


        else if(dir == 2) {
            if((x>0) && (world->getAt(x-1,y) == NULL) && (x-1 != prevX)) { // it moves to down if it's null
                world->setAt(x-1,y,world->getAt(x,y));
                world->setAt(x,y,NULL);
                x--;
                 moved = true;
            }
            else if((x>0) && (world->getAt(x-1,y) != NULL)){ // if not we call the move function
                if(fight(x, y, x-1, y)){ // if the first robot will win, it will delete the other and replace it 
                    delete (world->grid[x-1][y]);
                    world->grid[x-1][y] = this;
                    world->setAt(x,y,NULL);
                    x--;
                    }
                    else{ // if the second robot wins, it will call the if-victim function and turn the flag into true for world class
                         world->if_Victim(x,y);
                         moved = true;
                    }
                    return;
                    
            }
              prevX = x;
              prevY = y;
        }

        else { // it moves up 
            if((x<WORLDSIZE-1) && (world->getAt(x+1,y) == NULL) && (x+1 != prevX)) {
                world->setAt(x+1,y,world->getAt(x,y));
                world->setAt(x,y,NULL);
                x++;
                moved = true;
            }
            else if((x<WORLDSIZE-1) && (world->getAt(x+1,y) != NULL)){ // if not null we call the fight function
               if(fight(x, y, x+1, y)){ // if the first robot will win, it will delete the other and replace it 
                    delete (world->grid[x+1][y]);
                    world->grid[x+1][y] = this;
                    world->setAt(x,y,NULL);
                    x++;// increasing x for the new place
                    }
                    else{ // if the second robot wins, we call the if_victim function to delete the robot object 
                         world->if_Victim(x,y);
                         moved = true;
                    }
                    return;
                 
            }
        prevX = x;
        prevY = y;
        }
        dir = rand() % 4; // getting the random repeatedly until it moves to a new place 
    }
}

// destructor of the robot object 
Robot::~Robot(){

}