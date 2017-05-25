//
// Created by Justin on 5/24/2017.
//

#include "Requests.h"

void Requests::addRequest(Request request)
{
  if (!isDuplicate(request))
    requests[request.direction].push_back(request); // Only add if the request does not exist already
}

bool Requests::isDuplicate(Request request)
{
  for (auto req : requests[request.direction])
  {
    if (req.currentFloor == request.currentFloor)
      return true;
  }

  return false;
}

std::vector<Request>::iterator Requests::getNext(Direction direction, int currentFloor)
{
  // Should not be able to return currentFloor
  // Get the next floor with a request
  std::vector<Request>::iterator next;

  int closest = INT32_MAX; // Should be good enough

  for (auto it = requests[direction].begin(); it != requests[direction].end(); ++it)
  {
    // Find the closest floor in the current direction
    int diff = INT32_MAX;

    if (direction == Direction::up)
      diff = it->currentFloor - currentFloor;
    else if (direction == Direction::down)
      diff = currentFloor - it->currentFloor;

    if (diff < closest)
    {
      next = it;
      closest = diff;
    }
  }

  return next;
}

bool Requests::hasRequests(Direction direction)
{
  return !requests[direction].empty();
}
