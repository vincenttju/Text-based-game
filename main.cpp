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
using namespace std;


void command(int &count, string commands[]){
  string command, word;
  bool x = true;
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
    if (commandCheck(commands))
      count = 0;
    if (commandCheck2(commands))
      count = 0;
    if (nounCheck(commands))
      count = 0;
  }

}

bool doCommand(int &y, int &x, string * &inventory, int &itemsCarried, int &inventorySize, struct listItems love[]){
  string commands[2];
  int count = 0;

  while (count != 2){
    count = 0;
    command(count, commands);
  }

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

  //else if (commands[0] == "use")
  //  use_command();

  //else if (commands[0] == "answer")
  //  answer_command();

  return true;
}

void game(int Yposition, int Xposition){
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

  int itemsCarried=0, inventorySize = 3;
  string * inventory = new string [inventorySize];
  while (doCommand(Yposition, Xposition, inventory, itemsCarried, inventorySize, love));

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
  fin.open("gameRules.txt");
  while (getline(fin, gameRules)){    
    cout << gameRules << endl;
  }

  fin.close();
  
  mainMenu();
  generateRoom(Yposition, Xposition);
  game(Yposition, Xposition);
  return 0;
}
