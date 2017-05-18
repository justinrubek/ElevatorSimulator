//
// Created by justi on 5/15/2017.
//

#ifndef ELEVATOR_BUILDING_H
#define ELEVATOR_BUILDING_H

#include <vector>

#include "Floor.h"
class Building
{
  public:
    Building(int totalFloors);
    
    Floor* getFloorPtr(int floorNum);
    Floor getFloor(int floorNum);
    
    bool empty(); // Return true if every Person has found their floor
  private:
    std::vector<Floor> floors;
};


#endif //ELEVATOR_BUILDING_H
