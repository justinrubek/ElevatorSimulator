//
// Created by justi on 5/12/2017.
//

#include "Request.h"

Request::Request(unsigned int currentFloor, unsigned int destinationFloor)
{
  this->currentFloor = currentFloor;
  this->destinationFloor = destinationFloor;
  
  if (currentFloor < destinationFloor)
    direction = Direction::up;
  else
    direction = Direction::down;
}

bool Request::operator==(const Request& rhs)
{
  return this->currentFloor == rhs.currentFloor && this->destinationFloor == rhs.destinationFloor;
}
