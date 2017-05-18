//
// Created by justi on 5/15/2017.
//

#ifndef ELEVATOR_ELEVATORMANAGER_H
#define ELEVATOR_ELEVATORMANAGER_H

#include "Elevator.h"
#include "Request.h"
#include "Person.h"
#include "Direction.h"
#include "Floor.h"
#include "Building.h"

class ElevatorManager
{
  public:
    ElevatorManager(int maxFloor = 10);
    ~ElevatorManager();
    
    void addRequest(Request r);
    void addRequest(int currentFloor, int destinationFloor);
    
    void removeRequest(int floor); // Remove the first request to the current floor
    
    void addPerson(Person p, int floor);
    void addPassengersFromFloor();
    
    void update();
    
    void moveElevator(); // Moves the elevator where it needs to be depending on last status/floor limits
    
    bool solved();
    
  private:
    Elevator elevator;
    Building building;
    
    std::vector<Request> requests;
    
    int minFloor;
    int maxFloor;
};


#endif //ELEVATOR_ELEVATORMANAGER_H
