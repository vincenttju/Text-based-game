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
    if (check_inventory(itemTaken, inventory, itemsCarried)){
      inventory[itemsCarried] = itemTaken;
      itemsCarried += 1;
      cout << itemTaken << " is taken into the inventory" << endl;
      cout << "Maybe try to examine or use it?" << endl;
    }
  }

  else{
    cout << "invalid items!" << endl;
  }
}


void item_usage(string item, int room, bool &lastMission, string usedItems[], int &count, int inventorySize, string inventory[]){
  if ((item == "key") && (room == 6)){
    int requiredItem = 0;
    for (int i = 0; i < inventorySize; i++){
      string a = inventory[i];
      if (a == "phone" || a == "bullet" || a == "gun" || a == "torch" || a == "key" || a == "rope" || a == "knife")
        requiredItem++;
    }
    if (requiredItem == 7){
      usedItems[count] = "key";
      count++;
      cout << "The gate is unlocked" << endl;
      cout << "But the climbing vine is blocking your way" << endl;
      cout << "Maybe try to burn it?" << endl;
    }
    else{
      cout << "It is better if you collect all this item before entering this ancient gate!" << endl;
      cout << "                 key, torch, rope, knife, bullet, gun, phone" << endl;
      cout << "                Otherwise, it will be hard for you to escape!" << endl;
    }
  }

  else if ((item == "key") && (room != 6)){
    cout << "You cannot use it here!" << endl;
  }

  else if ((item == "torch") && (room == 6)){
    if (usedItems[0] == "key"){
      lastMission = true;
      usedItems[count] = "torch";
      count++;
      cout << "You have just burned the vine." << endl;
      cout << "Now the path is clear. " << endl;
    }
    else
      cout << "Use the key to open the gate first!" << endl;
  }

  else if ((item == "torch") && (room != 6)){
    cout << "You will burn the entire room if you use it here." << endl;
    cout << "Try it in another room." << endl;
  }

  else if (item == "flashlight"){
    cout << "The flashlight need a battery." << endl;
  }

  else if (item == "battery"){
    cout << "You cannot use it, " << endl;
    cout << "The battery is dead." << endl;
  }

  else if (item == "knife"){
    cout << "The knife has been possessed!" << endl;
    cout << "You have just lost your left arm!" << endl;
  }

  else if ((item == "pan") && (room == 4)){
    cout << "You cannot use the pan" << endl;
    cout << "You dont know how to cook!" << endl;
  }

  else if ((item == "pan") && (room != 4)){
    cout << "You cannot use it here" << endl;
  }

  else if (item == "rope"){
    cout << "You cannot use it here" << endl;
  }

  else if (item == "phone"){
    cout << "You cannot use it here" << endl;
    cout << "No signal inside this mansion." << endl;
  }

  else if (item == "bullet"){
    cout << "It is a sillicon bullet!" << endl;
    cout << "This item is very useful, dont waste it!" << endl;
    cout << "Use this to load the gun!" << endl;
  }

  else if (item == "gun"){
    cout << "Use this to kill it!" << endl;
  }

  else if (item == "lock"){
    cout << "The lock is cursed!" << endl;
    cout << "Suddenly, you feel extreme pain in your shoulder." << endl;
  }

  else{
    cout << "The item cannot be used!" << endl;
  }
}

void examine_command(int y, int x, string itemExamined, string * &inventory, int inventorySize){
  int count1=0;
  int roomNumber = ((x+1)+(y*3));
  string Xitem;
  if (inventorySize == 0){
        cout << "invalid command" << endl;
        cout << "You don't have this item in the inventory" << endl;
  }
  else{
    for (int i=0; i<inventorySize; i++){
      if (itemExamined == inventory[i] || itemExamined == "drawer"){
        Xitem = itemExamined;
        item_function(itemExamined, roomNumber);
        count1++;
        break;
      }
    }
  }

  if (count1 == 0){
    cout << "invalid command" << endl;
    cout << "You don't have this item in the inventory" << endl;
  }
}

void use_command(int y, int x, string itemUsed, string * &inventory, int inventorySize, bool &lastMission, string usedItems[], int &count){
  int roomNumber = ((x+1)+(y*3));
  int count1 = 0;
  if (inventorySize == 0){
        cout << "invalid command" << endl;
        cout << "You don't have this item in the inventory" << endl;
  }
  else{
    for (int i=0; i<inventorySize; i++){
      if (itemUsed == inventory[i]){
        item_usage(itemUsed, roomNumber, lastMission, usedItems, count, inventorySize, inventory);
        count1++;
        break;
      }
    }
  }

  if (count1 == 0){
    cout << "invalid command" << endl;
    cout << "You don't have this item in the inventory" << endl;
  }

}


void grow_inventory(string * &inventory, int &inventorySize, int n){
  string * new_inventory = new string [inventorySize + n];
  for (int i = 0; i < inventorySize; i++){
    new_inventory[i] = inventory[i];
  }
  delete [] inventory;
  inventory = new_inventory;
  inventorySize += n;
  cout << "Inventory size increased" << endl;
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
  if (itemViewed == "inventory"){
    if (inventorySize == 0){
      cout << "empty!" << endl;
    }
    else{
      cout << "Inventory: " << endl;
      for (int i=0; i<inventorySize; i++){
        cout << i+1 << ". " << inventory[i] << endl;
      }
    }
  }
  else{
    cout << "Invalid input!" << endl;
  }
}
