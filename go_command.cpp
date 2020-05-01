#include <iostream>
#include <string>
#include "generateRoom.h"
using namespace std;

void go_command(int &y, int &x, string userInput){
  int roomNumber = ((x+1)+(y*3));
  
  if (userInput == "go north"){
    if (roomNumber == 1 || roomNumber == 2 || roomNumber == 3){
      cout << "----- You cannot go there -----" << endl;
      doCommand();
    }
    else{
      y -= 1;
      x += 0;
    }
  }
  
  else if (userInput == "go south"){
    if (roomNumber == 7 || roomNumber == 8 || roomNumber == 9){
      cout << "----- You cannot go there -----" << endl;
      doCommand();
    }
    else{
      y += 1;
      x += 0;
    }
  }
  
  else if (userInput == "go east"){
    if (roomNumber == 3 || roomNumber == 6 || roomNumber == 9){
      cout << "----- You cannot go there -----" << endl;
      doCommand();
    }
    else{
      y += 0;
      x += 1;
    }
  }
  
  else if (userInput == "go west"){
    if (roomNumber == 1 || roomNumber == 4 || roomNumber == 7){
      cout << "----- You cannot go there -----" << endl;
      doCommand();
    }
    else{
      y += 0;
      x -= 1;
    }
  }
  generateRoom(y, x);
}
