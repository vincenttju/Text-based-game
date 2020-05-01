#include <iostream>
#include <string>
#include "generateRoom.h"
using namespace std;

void goCommand(int &y, int &x, string userInput, int map[][3]){
  int roomNumber = (x + 1) + (y*3);
  if (userInput == "go north"){
    y -= 1;
    x += 0;
  }
  else if (userInput == "go south"){
    y -= 1;
    x += 0;
  }
  else if (userInput == "go east"){
    y += 0;
    x += 1;
  }
  else if (userInput == "go west"){
    y += 0;
    x += 1;
  }
  generateRoom(y, x);
}
