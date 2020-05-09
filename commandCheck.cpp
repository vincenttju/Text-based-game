#include <iostream>
#include <string>
#include "commandCheck.h"
using namespace std;

// this function check if the noun (second word of the input) is in the noun list (there are 23 correct nouns that can be used in the game)
bool nounCheck(string commands[]){
  string nounList[23] = {"north", "south", "east", "west","drawer","key", "rope", "torch", "phone", "gun", "flashlight", "picture", "letter", "pan", "fruits", "bullet", "battery", "mail", "game", "notepad", "knife", "lock", "inventory"};
  int nounFound = 0;
  for (int i = 0; i < 23; i++){
    if (commands[1] == nounList[i])
    {
      nounFound++;
      break;
    }
  }

  if (nounFound == 0){
    cout << "\n--------------- Invalid Noun ---------------" << endl;
    cout <<   "------------- Some Valid Noun: ------------" << endl;
    cout <<   "-game, key, rope, south, west, north, east-" << endl;
    return true;
  }
  return 0;
}

// this function check if the input is all in lowercase
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

// this function check if the command (first word of the input) is in the command list (there are 7 correct commands)
bool commandCheck2(string commands[]){
  string commandsList[7] = {"go", "take", "examine","view", "use", "answer", "quit"};
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
    cout <<   " go, take, examine, view, use, answer, quit" << endl;
    return true;
  }
  return 0;
}
