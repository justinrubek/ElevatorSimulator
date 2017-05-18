//
// Created by justi on 5/12/2017.
//

#include "Person.h"

Person::Person(std::string name, int destination)
{
  this->name = name;
  this->destination = destination;
  
}

std::string Person::getName()
{
  return this->name;
}

int Person::getDestination()
{
  return this->destination;
}

Request Person::makeRequest(int currentFloor)
{
  return Request(currentFloor, this->destination);
}
