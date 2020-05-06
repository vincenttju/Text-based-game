#include <iostream>
#include <string>
#include "generateRoom.h"
#include "commands.h"
#include "struct.h"
using namespace std;

void go_command(int &y, int &x, string userInput){
  int roomNumber = ((x+1)+(y*3));
  
  if (userInput == "north"){
    if (roomNumber == 1 || roomNumber == 2 || roomNumber == 3){
      cout << "----- You cannot go there -----" << endl;
    }
    else{
      y -= 1;
      x += 0;
      generateRoom(y, x);
    }
  }
  else if (userInput == "south"){
    if (roomNumber == 7 || roomNumber == 8 || roomNumber == 9){
      cout << "----- You cannot go there -----" << endl;
    }
    else{
      y += 1;
      x += 0;
      generateRoom(y, x);
    }
  }
  else if (userInput == "east"){
    if (roomNumber == 3 || roomNumber == 6 || roomNumber == 9){
      cout << "----- You cannot go there -----" << endl;
    }
    else{
      y += 0;
      x += 1;
      generateRoom(y, x);
    }
  }
  else if (userInput == "west"){
    if (roomNumber == 1 || roomNumber == 4 || roomNumber == 7){
      cout << "----- You cannot go there -----" << endl;
    }
    else{
      y += 0;
      x -= 1;
      generateRoom(y, x);
    }
  }
}

void take_command(int y, int x, string invertory[], string itemTaken, int &itemsCarried, struct listItems love[]){
  int roomNumber = ((x)+(y*3));
  
  if ((itemTaken == love[roomNumber].item1) || (itemTaken == love[roomNumber].item2)){
    invertory[itemsCarried] += itemTaken;
    itemsCarried += 1;
  }
  else{
    cout << "invalid items!" << endl;
  }
}

void examine_command(){

}

void open_command(){

}

void use_command(){

}

void answer_command(){

}
