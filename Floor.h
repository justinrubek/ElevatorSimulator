//
// Created by justi on 5/12/2017.
//

#ifndef ELEVATOR_FLOOR_H
#define ELEVATOR_FLOOR_H

#include <vector>
#include <queue>
#include <map>

#include "Person.h"
#include "Direction.h"

class Floor
{
  public:
    Floor();
    bool hasGoingUp();
    bool hasGoingDown();
    bool empty(); // Return true if the floor has no Person seeking to go to another floor
    bool empty(Direction direction);
    
    // Removes, and returns the next Person in the queue
    Person getNextGoingUp();
    Person getNextGoingDown();
    Person getNext(Direction direction);
    Person getNext();
    
    // Add to the floor
    void addPerson(Person person, Direction direction);
    
    void addToDestination(Person p); // Add Person when this is their destination floor
    
  private:
    std::map<Direction, std::queue<Person>> elevatorQueue;
    //std::queue<Person> up;
    //std::queue<Person> down;
    
    std::vector<Person> arrivals;
};


#endif //ELEVATOR_FLOOR_H
