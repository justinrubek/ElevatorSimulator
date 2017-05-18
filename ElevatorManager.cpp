//
// Created by justi on 5/15/2017.
//

#include <iostream>
#include "ElevatorManager.h"

ElevatorManager::ElevatorManager(int maxFloor)
: building(maxFloor), elevator(5,0)
{
  this->minFloor = 0;
  this->maxFloor = maxFloor;
  
  requests = std::vector<Request>();
  
  //elevator = new Elevator(5, 0);
  
}

ElevatorManager::~ElevatorManager()
{
  //delete elevator;
  //delete building;
}

void ElevatorManager::addRequest(Request r)
{
  this->requests.push_back(r);
}

void ElevatorManager::addRequest(int currentFloor, int destinationFloor)
{
  Request r(currentFloor, destinationFloor);
  addRequest(r);
}

bool ElevatorManager::solved() // Return true if there are no people looking to change floors in the building
{
  return building.empty() && elevator.empty();
}

void ElevatorManager::addPerson(Person p, int floor)
{
  if (floor < maxFloor)
  {
    Request request = p.makeRequest(floor);
    
    building.getFloorPtr(floor)->addPerson(p, request.direction);
    //requests.push_back(request);
  }
  else
    std::cerr << "Attempted to add person to floor that does not exist in building" << std::endl;
}

void ElevatorManager::removeRequest(int floor)
{
  // Remove the first request to the current floor
  
}

void ElevatorManager::moveElevator()
{
  switch (elevator.getStatus())
  {
    case Direction::up:
      
      if (elevator.getCurrentFloor() < maxFloor - 1)
        elevator.moveUp();
      else
        elevator.moveDown();
      
      break;
    case Direction::down:
      
      if (elevator.getCurrentFloor() > minFloor)
        elevator.moveDown();
      else
        elevator.moveUp();
      
      break;
    case Direction::idle:
      // u wot m8
      break;
  }

  if (elevator.getCurrentFloor() == minFloor)
    elevator.setDirection(Direction::up);
  else if (elevator.getCurrentFloor() == maxFloor - 1)
    elevator.setDirection(Direction::down);
}

void ElevatorManager::update()
{
  addPassengersFromFloor();
  moveElevator();
  elevator.dismissPassengers();
}

void ElevatorManager::addPassengersFromFloor()
{
  int floorNum = elevator.getCurrentFloor();
  Direction direction;// = elevator.getStatus();
  
  Floor* floor = building.getFloorPtr(floorNum);
  
  if (floorNum == maxFloor)
    direction = Direction::down;
  else if (floorNum == minFloor)
    direction = Direction::up;
  else
    direction = elevator.getStatus();
  
  while (elevator.hasSpace() && !floor->empty(direction)) // There's people that can be moved to the elevator
  {
    Person person = floor->getNext(direction);
    elevator.addPerson(person);
  }
  
}
