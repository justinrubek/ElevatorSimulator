//
// Created by Justin on 5/24/2017.
//

#ifndef ELEVATOR_REQUESTS_H
#define ELEVATOR_REQUESTS_H

#include <vector>
#include <map>
#include "Request.h"

class Requests
{
  public:

    void addRequest(Request request);

    void removeRequests(Direction direction, int currentFloor); // Removes all requests in the current direction at the current floor
    bool hasRequests(Direction direction);                      // Checks if there are any requests in the current direction

    std::vector<Request>::iterator getNext(Direction direction, int currentFloor);  // Returns the next request in the current direction

  private:
    std::map<Direction, std::vector<Request>> requests;

    std::vector<Request> up;
    std::vector<Request> down;

    bool isDuplicate(Request request);
};


#endif //ELEVATOR_REQUESTS_H
