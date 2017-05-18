//
// Created by justi on 5/12/2017.
//

#include <iostream>
#include "Floor.h"

Floor::Floor()
{
  elevatorQueue[Direction::up] = std::queue<Person>(); // Why doesn't this work????
  elevatorQueue[Direction::down] = std::queue<Person>();
}

bool Floor::hasGoingUp()
{
  return !elevatorQueue[Direction::up].empty();
}

bool Floor::hasGoingDown()
{
  return !elevatorQueue[Direction::down].empty();
}

bool Floor::empty()
{
  return !(hasGoingUp() || hasGoingDown());
}

void Floor::addPerson(Person person, Direction direction)
{
  elevatorQueue[direction].push(person);
}

Person Floor::getNextGoingUp()
{
  return getNext(Direction::up);
}

Person Floor::getNextGoingDown()
{
  return getNext(Direction::down);
}

Person Floor::getNext(Direction direction)
{
  Person person = elevatorQueue[direction].front();
  elevatorQueue[direction].pop();
  return person;
}

bool Floor::empty(Direction direction)
{
  return elevatorQueue[direction].empty();
}
/*
Person Floor::getNext()
{
  Direction direction;
  if (elevatorQueue[Direction::up].empty())
  {
    direction = Direction::down;
  }
  else if (elevatorQueue[Direction::down].empty())
  {
    direction = Direction::up;
  }
  
  Person person = elevatorQueue[direction].front();
  elevatorQueue[direction].pop();
  return person;
}
*/




