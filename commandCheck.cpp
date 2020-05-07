#include <iostream>
#include <string>
#include "commandCheck.h"
using namespace std;

bool nounCheck(string commands[]){
  string nounList[19] = {"north", "south", "east", "west","key", "rope", "torch", "phone", "gun", "flashlight", "picture", "letter", "pan", "fruits", "bullet", "battery", "mail", "game", "inventory"};
  int nounFound = 0;
  for (int i = 0; i < 19; i++){
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
