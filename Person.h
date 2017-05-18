//
// Created by justi on 5/12/2017.
//

#ifndef ELEVATOR_PERSON_H
#define ELEVATOR_PERSON_H

#include <string>
#include "Request.h"

class Person
{
  public:
    Person(std::string name, int destination);
    
    std::string getName();
    int getDestination();
    
    Request makeRequest(int currentFloor);
  private:
    std::string name;
    
    int destination;
};


#endif //ELEVATOR_PERSON_H
