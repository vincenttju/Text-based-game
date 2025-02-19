#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <cctype>
#include "struct.h"
#include "mainMenu.h"
#include "commands.h"
#include "commandCheck.h"
#include "generateRoom.h"
#include "lastMission.h"
using namespace std;


void command(int &count, string commands[]){
  // this function will check whether the command input (stored in commands[]) is correct
  // count is used to check the number of words of the input
  string command, word;
  bool x = true;
  
  // asking for user input until the input is correct (2 words long)
  while(x){
    cout <<  "\n------> Please input your command : " << endl;
    getline(cin, command);
    istringstream line_in(command);
    while(line_in >> word){
      if (count >= 2){
        count = 0;
        break;
      }
      commands[count] = word;
      count++;
    }
    x = false;
    if (count != 2){
      cout << "\n------------- Invalid Command -------------" << endl;
      cout <<   "------Command should be 2 words long-------" << endl;
    }
    
    // check if the input is all in lowercase
    if (commandCheck(commands))
      count = 0;
    
    // check if the command (first word of the input) is in the command list (there are 7 correct commands)
    if (commandCheck2(commands))
      count = 0;
    
    // check if the noun (second word of the input) is in the noun list (there are 23 correct nouns that can be used in the game)
    if (nounCheck(commands))
      count = 0;
  }
}

bool doCommand(int &y, int &x, string * &inventory, int &itemsCarried, int &inventorySize, struct listItems love[], int &usedItemcount, string usedItems[], bool &lastMission){
  string commands[2];
  // this function will take user input, check it, and execute it
  // x and y inputs are used in several functions for locating the map
  // inventory is a dynamic array of size 3 to store the items taken (take() function), and the item stored can be used (use() function)
  // itemsCarried will count every items taken, inventorySize is the size of the dynamic array (start with 3)
  // if itemsCarried size >= inventorySize, it will grow the dynamic array size
  // the struct array contains information of items in every room
  // usedItems will count the number of items used in (use() function) and store it in usedItems array
  // lastMission is a bool (false), it will be true if some requirement in (use() function) is satisfied
  
  int count = 0;
  // keep asking for input until it satisfied the requirement
  while (count != 2){
    count = 0;
    command(count, commands);
  }
  
  // quit and finish the game if the input is "quit"
  if (commands[0] == "quit")
    return 0;

  else if (commands[0] == "go")
    go_command(y, x, commands[1]);

  else if (commands[0] == "take")
    take_command(y, x, inventory, commands[1], itemsCarried, inventorySize, love);

  else if (commands[0] == "view")
    view_inventory_command(inventory, inventorySize, commands[1]);

  else if (commands[0] == "examine")
    examine_command(y, x, commands[1], inventory, inventorySize);

  else if (commands[0] == "use")
    use_command(y, x, commands[1], inventory, inventorySize, lastMission, usedItems, usedItemcount);
  
  if (lastMission)
    return last_Mission();
  
  return true;
}

void game(int Yposition, int Xposition){
  // this function store all of the required information for the game
  
  listItems love[9];
  love[0] = { 1, "key", "flashlight" };
  love[1] = { 2, "picture" , "phone" };
  love[2] = { 3, "notepad", "gun" };
  love[3] = { 4, "pan" , "fruits" };
  love[4] = { 5, "bullet", "letter" };
  love[5] = { 6, "0", "0" };
  love[6] = { 7, "rope", "knife" };
  love[7] = { 8, "battery", "lock" };
  love[8] = { 9, "torch", "mail" };

  int itemsCarried=0, inventorySize = 3, usedItemCount = 0;
  string * inventory = new string [inventorySize];
  string usedItems[5];
  bool lastMission = false;
  
  // keep using doCommand() function until it encounters the lastMission (return 0) or the user quit game (return 0)
  while (doCommand(Yposition, Xposition, inventory, itemsCarried, inventorySize, love, usedItemCount,usedItems, lastMission));

  delete []inventory;
}
int main(){
  srand(time(NULL));
  int Yposition = rand() % 3;
  int Xposition = rand() % 3;

  string name;
  cout << "************ Welcome to One Night Game ************" << endl;
  cout << "Hello, please enter your name :" << endl;
  getline(cin, name);
  cout << "Hello " << name << ", good luck and have fun" << endl;

  string gameRules;
  ifstream wow;
  wow.open("gameRules.txt");
  while (getline(wow, gameRules)){
    cout << gameRules << endl;
  }

  wow.close();

  cout << "Do you want to start the game? (yes/no)" << endl;
  string startORnot;
  getline(cin, startORnot);

  if (startORnot == "yes"){
    mainMenu();
    generateRoom(Yposition, Xposition);
    game(Yposition, Xposition);
  }

  else if (startORnot == "no"){
    cout << "Bye-bye, " << name << endl;
    cout << "See you at another time!" << endl;

  }

  else{
    cout << "Invalid answer! You have to input yes (lowercase) to continue" << endl;
    cout << "Bye-bye, " << name << "!" << endl;

  }

  return 0;
}
