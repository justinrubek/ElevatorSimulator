#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <ctime>

#include "ElevatorManager.h"
#include "conversion.h"

int randomUpTo(int limit)
{
  return std::rand() % limit;
}
void loadPeople(std::string fileName, ElevatorManager& sim)
{
  std::string line;
  
  std::ifstream fin(fileName);
  
  while (fin >> line)
  {
    // Need a way to specify max floor/ elevator capacity;
    std::vector<std::string> details = split(line, ','); // [0]: name, [1]: starting floor, [2]: destination
    
    std::string name = details[0];
    if (details[0] != "")
    {
      int startingFloor = stringToInt(details[1]);
      int destinationFloor = stringToInt(details[2]);
      
      Person p = Person(name, destinationFloor);
      
      sim.addPerson(p, startingFloor);
      
      //std::cout << line << std::endl;
    }
  }
}

std::string generateName(int length = 5)
{
  std::string name;
  
  for (int i = 0; i < length; ++i)
  {
    char c = 'A' + randomUpTo(26);
    name += c;
  }
  //std::cout << "New person: " << name << std::endl;
  return name;
}

void promptToAddPeople(ElevatorManager& sim)
{
  std::cout << "Prompted" << std::endl;
  
  int maxFloor = 0;
  int totalPeople = 1;
  
  std::cout << "Enter the amount of floors in the building" << std::endl;
  std::cin >> maxFloor;
  
  std::cout << "Enter the amount of people to put in the building" << std::endl;
  std::cin >> totalPeople;
  
  sim = ElevatorManager(maxFloor);
  
  for (int i = 0; i < totalPeople; ++i)
  {
    std::string name = generateName();
    int startingFloor = randomUpTo(maxFloor);
    int destinationFloor = randomUpTo(maxFloor);
    
    while (startingFloor == destinationFloor) // Make sure that they don't overlap
      startingFloor = randomUpTo(maxFloor);
    
    std::cout << "New Person: " << name << " starting at floor " << startingFloor << " and going to floor " << destinationFloor << std::endl;
    Person person(name, destinationFloor);
    
    sim.addPerson(person, startingFloor);
  }
}

int runElevatorSimulation(std::string peopleFile = "")
{
  ElevatorManager sim;
  
  if (peopleFile == "")
    promptToAddPeople(sim);
  else
    loadPeople(peopleFile, sim);
  
  int count = 0;
  while (!sim.solved())
  {
    sim.update();
    //std::cout << ++count << std::endl;
    count++;
  }

  return count;
}

int main()
{
  std::srand(time(NULL));
  std::cout << "Took " << runElevatorSimulation("people.txt") << " actions to complete." << std::endl;
  return 0;
}