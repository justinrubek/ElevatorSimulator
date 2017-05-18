//
// Created by justi on 5/15/2017.
//

#include <iostream>
#include "Elevator.h"

Elevator::Elevator(int capacity, int startingFloor)
{
  this->maxPassengers = capacity;
  this->currentFloor = startingFloor;
  
  passengers = std::vector<Person>();
  passengers.reserve(capacity);
  
  status = Direction::up;
}

int Elevator::getCurrentFloor()
{
  return currentFloor;
}

void Elevator::moveUp()
{
  status = Direction::up;
  currentFloor++;
  std::cout << "Elevator going up to floor: " << currentFloor << std::endl;
}

void Elevator::moveDown()
{
  status = Direction::down;
  currentFloor--;
  std::cout << "Elevator going down to floor: " << currentFloor << std::endl;
}

void Elevator::addPerson(Person p)
{
  std::cout << p.getName() << " gets on the elevator" << std::endl;
  passengers.push_back(p);
}

Direction Elevator::getStatus()
{
  return this->status;
}

bool Elevator::empty()
{
  return passengers.size() == 0;
}

void Elevator::dismissPassengers()
{
  for (int i = 0; i < passengers.size(); ++i)
  {
    if(passengers[i].getDestination() == currentFloor)
    {
      std::cout << passengers[i].getName() << " exited the elevator at floor " << currentFloor << std::endl;
      passengers.erase(passengers.begin() + i);
      i--; // passengers is one smaller now, decrement index so it doesn't change for next iteration
    }
  }
 
}

bool Elevator::hasSpace()
{
  return passengers.size() < maxPassengers;
}

void Elevator::setDirection(Direction direction)
{
  this->status = direction;
}





