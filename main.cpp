#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cctype>
#include "generateRoom.h"
using namespace std;

struct listItems{
  int room;
  string item1;
  string item2;
};

void mainMenu(){
  string name, firstInput;
  cout << "************ Welcome to One Night Game ************" << endl;
  cout << "Hello, please enter your name." << endl;
  getline(cin, name);
  cout << "Hello " << name << ", good luck and have fun" << endl;
  cout << "\nOn one unpleasant day, you woke up with a sick head lying on the floor" << endl;
  cout << "in a dark room filled with an unpleasant odor " << endl;
  cout << "\nYou have no idea of who you are and how you got here" << endl;
  cout << "You see a strange scroll on your left saying:" << endl;
  cout << "---------------------------------------------------" << endl;
  cout << "If you read this message, I probably have already dead" << endl;
  cout << "      You need to get out of this creepy mansion      " << endl;
  cout << "           or you will be dead by one night           " << endl;
  cout << "  Find the unique items scattered around the mansion  " << endl;
  cout << "            and use it in the ancient gate            " << endl;
  cout << "   Find several pieces of clues to get out of here    " << endl;
  cout << "   Be careful of him, human flesh is his favourite    " << endl;
  cout << "------------------------------------------------------" << endl;
  cout << "You can go north" << endl;
  cout <<  "------> Please input your command : " << endl;
  getline(cin, firstInput);
  while (firstInput != "go north"){
    cout << "------------- Invalid Command -------------" << endl;
    cout << "-------- Valid Command : go north ---------" << endl;
    cout << "------> Please input your command : " << endl;
    getline(cin, firstInput);
  }
}

bool nounCheck(string commands[]){
  string nounList[18] = {"north", "south", "east", "west","key", "rope", "torch", "phone", "gun", "flashlight", "picture", "letter", "pan", "fruits", "bullet", "battery", "mail", "game"};
  int nounFound = 0;
  for (int i = 0; i < 18; i++){
    if (commands[1] == nounList[i])
    {
      nounFound++;
      break;
    }
  }

  if (nounFound == 0){
    cout << "\n--------------- Invalid Noun --------------" << endl;
    cout <<   "------------- Some Valid Noun: -----------" << endl;
    cout <<   "--- game, key, rope, torch, phone, gun  --" << endl;
    return true;
  }
  return 0;
}

bool commandCheck(string commands[]){
  for (int i = 0 ; i < 2; i++){
    for (int j = 0; j < commands[i].length();j++){
      if (isupper(commands[i][j])){
        cout << "\n------------- Invalid Command -------------" << endl;
        cout <<   "------Command should be in lowercase-------" << endl;
        return true;
      }
    }
  }
  return 0;
}

bool commandCheck2(string commands[]){
  string commandsList[7] = {"go", "take", "examine", "open", "use", "answer", "quit"};
  int commandFound = 0;
  for ( int i = 0; i < 7; i++){
    if (commands[0] == commandsList[i])
    {
      commandFound++;
      break;
    }
  }

  if (commandFound == 0){
    cout << "\n------------- Invalid Command -------------" << endl;
    cout <<   "-------------  Valid commands: ------------" << endl;
    cout <<   " go, take, examine, open, use, answer, quit" << endl;
    return true;
  }
  return 0;
}

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

bool doCommand(int &y, int &x){
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

  //else if (commands[0] == "take")
  //  take_command();

  //else if (commands[0] == "examine")
  //  examine_command();

  //else if (commands[0] == "open")
  //  open_command();

  //else if (commands[0] == "use")
  //  use_command();

  //else if (commands[0] == "answer")
  //  answer_command();
  
  return true;
}

int main(){

  listItems love[9];
  love[0] = { 1, "key", "flashlight" };
  love[1] = { 2, "picture" , "phone" };
  love[2] = { 3, "letter", "gun" };
  love[3] = { 4, "pan" , "fruits" };
  love[4] = { 5, "bullet", "letter" };
  love[5] = { 6, "0", "0" };
  love[6] = { 7, "rope", "0" };
  love[7] = { 8, "battery", "key" };
  love[8] = { 9, "torch", "mail" };

  srand(time(NULL));
  int Yposition = rand() % 3;
  int Xposition = rand() % 3;
  int map[3][3];
  for (int y=0; y<3; y++){
    for (int x=0; x<3; x++){
      int value = ((x+1)+(y*3));
      map[y][x] = value;
    }
  }

  mainMenu();
  //generateRoom(Yposition, Xposition);
  while (doCommand(Yposition, Xposition));
}
