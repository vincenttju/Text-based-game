#include <iostream>
#include <string>
#include "generateRoom.h"
#include "commands.h"
#include "struct.h"
using namespace std;

void grow_inventory(string * &inventory, int &inventorySize, int n);

bool check_inventory(string itemTaken, string * inventory, int itemsCarried);

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

void take_command(int y, int x, string * &inventory, string itemTaken, int &itemsCarried, int &inventorySize, listItems love[])
{
  int roomNumber = ((x)+(y*3));
  if (itemsCarried >= inventorySize){
    grow_inventory(inventory, inventorySize, 3);
  }

  if ((itemTaken == love[roomNumber].item1) || (itemTaken == love[roomNumber].item2)){
<<<<<<< HEAD
    if (check_inventory(itemTaken, inventory, itemsCarried)){
=======
    if (check_inventory(itemTaken, invertory, itemsCarried)){
>>>>>>> 29c320bea1c7f2044160b0d5c21a9372167c9315
      inventory[itemsCarried] = itemTaken;
      itemsCarried += 1;
      cout << itemTaken << " is taken into the inventory" << endl;
      cout << "Maybe try to examine it?" << endl;
    }
  }

  else{
    cout << "invalid items!" << endl;
  }
}

void examine_command(){

}

void use_command(int y, int x, string itemUsed, string * &inventory, int inventorySize){
  int roomNumber = ((x+1)+(y*3));

  string item;

  if (inventorySize == 0){
        cout << "invalid command" << endl;
        cout << "You don't have this item in the inventory" << endl;
  }
  else{
    for (int i=0; i<inventorySize; i++){
      if (itemUsed == inventory[i]){
        item = itemUsed;
      }
    }
  }
  //item_function(item);
}

void answer_command(){

}

void grow_inventory(string * &inventory, int &inventorySize, int n){
  string * new_inventory = new string [inventorySize + n];
  for (int i = 0; i < inventorySize; i++){
    new_inventory[i] = inventory[i];
  }
  delete [] inventory;
  inventory = new_inventory;
  inventorySize += n;
<<<<<<< HEAD
  cout << "Inventory size increased" << endl;
=======
  cout << "Inventory size increased" << endl; 
>>>>>>> 29c320bea1c7f2044160b0d5c21a9372167c9315
}

bool check_inventory(string itemTaken, string * inventory, int itemsCarried){
  if (itemsCarried == 0)
    return true;
  else{
    for (int i = 0; i < itemsCarried; i++){
      if (inventory[i] == itemTaken){
        cout << "You already took the item" << endl;
        return 0;
      }
    }
  }
  return true;
}

void view_inventory_command(string * &inventory, int inventorySize, string itemViewed){
  if (itemViewed == "invertory"){
    if (inventorySize == 0){
      cout << "empty!" << endl;
    }
    else{
      for (int i=0; i<inventorySize; i++){
        cout << inventory[i] << " ";
      }
      cout << endl;
    }
  }
  else{
    cout << "Invalid input!" << endl;
  }
}
