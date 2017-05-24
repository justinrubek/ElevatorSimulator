//
// Created by justi on 5/15/2017.
//

#ifndef ELEVATOR_CONVERSION_H
#define ELEVATOR_CONVERSION_H
#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string &s, char delim)
{
  std::vector<std::string> items;

  std::stringstream ss;
  ss.str(s);
  std::string item;

  while (std::getline(ss, item, delim))
  {
    items.push_back(item);
  }

  return items;
}


int stringToInt(std::string s)
{
  int result;
  
  std::stringstream convert(s); // stringstream used for the conversion initialized with s
  
  if (!(convert >> result)) // Give value to result using the characters in the string
    result = 0; // If that fails set Result to 0
  return result;
}
#endif //ELEVATOR_CONVERSION_H
