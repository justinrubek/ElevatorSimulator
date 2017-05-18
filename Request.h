//
// Created by justi on 5/12/2017.
//

#ifndef ELEVATOR_REQUEST_H
#define ELEVATOR_REQUEST_H

#include "Direction.h"

class Request
{
  public:
    Request(unsigned int currentFloor, unsigned int destinationFloor);
  
    unsigned int currentFloor;
    unsigned int destinationFloor;
    Direction direction;
    
    bool operator== (const Request& rhs);
};


#endif //ELEVATOR_REQUEST_H
