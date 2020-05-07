#include <iostream>
#include <string>
#include "generateRoom.h"
#include "commands.h"
#include "struct.h"
using namespace std;

void grow_inventory(string * &invertory, int &inventorySize, int n);

bool check_inventory(string itemTaken, string * invertory, int itemsCarried);

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

void take_command(int y, int x, string * &invertory, string itemTaken, int &itemsCarried, int &inventorySize, listItems love[])
{
  int roomNumber = ((x)+(y*3));
  if (itemsCarried >= inventorySize){
    grow_inventory(invertory, inventorySize, 3);
  }

  if ((itemTaken == love[roomNumber].item1) || (itemTaken == love[roomNumber].item2)){
    if (check_inventory(itemTaken, invertory, itemsCarried)){
      invertory[itemsCarried] = itemTaken;
      itemsCarried += 1;
      cout << itemTaken << " is taken into the inventory" << endl;
    }
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

void grow_inventory(string * &invertory, int &inventorySize, int n){
  string * new_inventory = new string [inventorySize + n];
  for (int i = 0; i < inventorySize; i++){
    new_inventory[i] = invertory[i];
  }
  delete [] invertory;
  invertory = new_inventory;
  inventorySize += n;
  cout << "Inventory size increased" << endl; // cout hanya buat test bisa work atau kagak
}

bool check_inventory(string itemTaken, string * invertory, int itemsCarried){
  if (itemsCarried == 0)
    return true;
  else{
    for (int i = 0; i < itemsCarried; i++){
      if (invertory[i] == itemTaken){
        cout << "You already took the item" << endl;
        return 0;
      }
    }
  }
  return true;
}

void view_invertory_command(string * &invertory, int inventorySize, string itemViewed){
  if (itemViewed == "invertory"){
    if (inventorySize == 0){
      cout << "empty!" << endl;
    }
    else{
      for (int i=0; i<inventorySize; i++){
        cout << invertory[i] << " ";
      }
      cout << endl;
    }
  }
}
