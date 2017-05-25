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

    bool hasRequests(Direction direction);

    std::vector<Request>::iterator getNext(Direction direction, int currentFloor);

  private:
    std::map<Direction, std::vector<Request>> requests;

    std::vector<Request> up;
    std::vector<Request> down;

    bool isDuplicate(Request request);
};


#endif //ELEVATOR_REQUESTS_H
