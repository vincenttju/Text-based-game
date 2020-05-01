#include <iostream>
#include <string>
#include "generateRoom.h"
using namespace std;

void go_command(int &y, int &x, string userInput, int map[][3]){
  if (userInput == "go north"){
    if (map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 3){
      cout << "----- You cannot go there -----" << endl;
      doCommand();
    }
    else{
      y -= 1;
      x += 0;
    }
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
