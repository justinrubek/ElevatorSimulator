//
// Created by justi on 5/15/2017.
//

#include "Building.h"

Building::Building(int totalFloors)
{
  floors = std::vector<Floor>(totalFloors);
  
}

bool Building::empty()
{
  for (auto f : floors)
  {
    if (!f.empty())
      return false;
  }
  
  return true;
}

Floor* Building::getFloorPtr(int floorNum) // You better use a 0 based index
{
  return &floors[floorNum];
}

Floor Building::getFloor(int floorNum)
{
  return floors[floorNum];
}

