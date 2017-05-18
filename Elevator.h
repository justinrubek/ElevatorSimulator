//
// Created by justi on 5/15/2017.
//

#ifndef ELEVATOR_ELEVATOR_H
#define ELEVATOR_ELEVATOR_H

#include <vector>

#include "Direction.h"
#include "Person.h"

class Elevator
{
  public:
    Elevator(int capacity = 5, int startingFloor = 0);
    
    // Getters
    int getCurrentFloor();
    Direction getStatus();
    
    void setDirection(Direction direction);
    
    bool empty();
    bool hasSpace();
    
    // Change the position of the elevator
    void moveUp();
    void moveDown();
    //void move(); // Moves the elevator either up or down depending on last status
    
    // Modify the contents of the elevator
    void addPerson(Person p);
    
    void dismissPassengers();
    
  private:
    
    std::vector<Person> passengers;
    
    int currentFloor;
    int maxPassengers;
    
    Direction status;
  
};


#endif //ELEVATOR_ELEVATOR_H
