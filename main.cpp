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

bool doCommand(int &y, int &x, string * &inventory, int &itemsCarried, int &inventorySize, struct listItems love[], int &usedItemcount, string usedItems[], bool &lastMission){
  string commands[2];
  int count = 0, 
  
  if (lastMission){
    string answer, choice, useRope;
    int counter = 0;
    
    cout << "The ancient gate closed right aways as you entered the room!" << endl;
    cout << "There is a password door in front of you now, written:" << endl;
    cout << "Please form a word using the 9 given characters throughout the mansion" << endl;
    cout << "The 9 characters you got: D - R - A - E - N - E - T - U - V " << endl;
    cout << "Input the words in lowercase!" << endl;
    cout << "ANSWER:" << endl;
    
    cin >> answer;
    while (answer != "adventure"){
      cin >> answer;
      counter++;
    }
    cout << "The password door is unlocked!" << endl;
    cout << "You have tried " << counter << "times!" << endl;
    cout << "As soon as you opened the door, a wild monster is coming in your way!" << endl;
    cout << "What would you choose to kill him? (gun / knife)" << endl;
    cout << "Your choice (gun / knife) : " << endl;
    
    cin >> choice;
    if (choice == "gun")
      cout << "You shot him right on his head!" << endl;
    else if (choice == "knife"){
      cout << "The monster is too fast to be striked by a knife." << endl;
      cout << "You are killed instead!" << endl;
      cout << "========= GAME OVER! =========" << endl;
      return 0;
    }
    else{
      cout << "You did not choose the right weapon" << endl;
      cout << "The monster is too fast, you have no other opportunity" << endl;
      cout << "You are killed instead!" << endl;
      cout << "========= GAME OVER! =========" << endl;
      return 0;
    }
    
    cout << "You have escaped from the mansion! But you realised that you are on the second floor!" << endl;
    cout << "Maybe try to use the rope that you got?" << endl;
    getline(cin, useRope);
    while (useRope != "use rope"){
      getline(cin, useRope);
      cout << "use rope" << endl;
    }
    cout << "You have finally escaped the mansion!" << endl;
    cout << "You use your phone to call for help" << endl;
    cout << "Help service arrived 3 hours later, and you are back to your normal life!" << endl;
    cout << "============ END GAME! ============" << endl;
    return 0;
  }
  
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

  else if (commands[0] == "use")
    use_command(y, x, commands[1], inventory, inventorySize, lastMission, usedItems, usedItemCount);

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

  int itemsCarried=0, inventorySize = 3, usedItemCount = 0;
  string * inventory = new string [inventorySize];
  string usedItems[5];
  bool lastMission = false;
  
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
