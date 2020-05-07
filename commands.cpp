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
      cout << "Maybe try to examine it?" << endl;
    }
  }

  else{
    cout << "invalid items!" << endl;
  }
}

void item_function(string item){
  if (item == "drawer"){
    cout << "There is a notepad and a gun inside a drawer." << endl;
    cout << "You can take these items if you haven't." << endl;
    cout << "Maybe try to examine it?" << endl;
    cout << "There is \"T\" character written inside the drawer." << endl;

  }
  else if (item == "letter"){
    cout << "________________________________________________" << endl;
    cout << endl;
    cout << " If you find this message, keep it in mind      " << endl;
    cout << " IT IS ALWAYS WATCHING YOU! The bloody creature " << endl;
    cout << " will kill you in the blink of an eye. " << endl;
    cout << " Find  gun and the bullet, it will kill him " << endl;
    cout << "Your next character is \"U\" " << endl;
    cout << "________________________________________________" << endl;
  }

  else if (item == "notepad"){
    cout << "___________________________________________________________" << endl;
    cout << endl;
    cout << " 1. I TURN ONCE, WHAT IS OUT WILL NOT GET IN, " << endl;
    cout << "    I TURN AGAIN, WHAT IS IN WILL NOT GET OUT. " << endl;
    cout << endl;
    cout << " 2. I CAN FILL AN ENTIRE ROOM WITHOUT TAKING UP ANY SPACE. " << endl;
    cout << endl;
    cout << " 3. THE MORE OF THIS THERE IS, THE LESS YOU SEE." << endl;
    cout << " \"N\" IS MY FAVOURITE CHARACTER!" << endl;
    cout << "___________________________________________________________" << endl;
  }

  else if (item == "mail"){
    cout << "_______________________________________________________" << endl;
    cout << endl;
    cout << " You can't open the gate without me! " << endl;
    cout << " I follow you all the time and I know your every move, " << endl;
    cout << " but you can’t never touch me or catch me." << endl;
    cout << " \"V\" is one of the character you will need " << endl;
    cout << "_______________________________________________________" << endl;
  }

  else if (item == "picture"){
    cout << " It is a family black and white photograph " << endl;
    cout << " In the photo you can see a mysterious guy " << endl;
    cout << " with a big and gloomy feature " << endl;
    cout << " There is a huge \"A\" character in the background of the picture " << endl;
  }

  else if (item == "fruits"){
    cout << " You have a bunch of rotten fruits " << endl;
    cout << " banana, apple, mango, and orange  " << endl;
    cout << " You cannot eat these garbage! " << endl;
  }

  else
    cout << "This item cannot be examined" << endl;
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
        item_function(itemExamined);
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

void use_command(int y, int x, string itemUsed, string * &inventory, int inventorySize){
  int roomNumber = ((x+1)+(y*3));
  int count1 = 0;
  string Uitem;

  if (inventorySize == 0){
        cout << "invalid command" << endl;
        cout << "You don't have this item in the inventory" << endl;
  }
  else{
    for (int i=0; i<inventorySize; i++){
      if (itemUsed == inventory[i]){
        Uitem = itemUsed;
        count1 +=1;
      }
    }
  }

  if (count1 == 0){
    cout << "invalid command" << endl;
    cout << "You don't have this item in the inventory" << endl;
  }
  else{
    //item_function(Uitem);
  }
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
