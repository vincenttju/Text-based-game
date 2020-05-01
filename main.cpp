#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

void mainMenu(){
  string name;
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
  cout << " Find also another pieces of clues to get out of here " << endl;
  cout << "   Be careful of him, human flesh is his favourite    " << endl;
  cout << "------------------------------------------------------" << endl;
}

bool commandCheck(string commands[]){
  for (int i = 0 ; i < 2; i++){
    for (int j = 0; j < commands[i].length();j++){
      if (isupper(commands[i][j])){
        cout << "--------- Invalid Command --------" << endl;
        cout << "--Command should be in lowercase--" << endl;
        return true;
      }
    }
  }
  return 0;
}

void command(int &count, string commands[]){
  string command, word;
  bool x = true;
  while(x){
    cout <<  "Your command" << endl;
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
      cout << "--------- Invalid Command --------" << endl;
      cout << "--Command should be 2 words long--" << endl;
    }
    if (commandCheck(commands))
      count = 0;
  }
}

void doCommand(){
  string commands[2];
  int count = 0;
  while (count != 2){
    count = 0;
    command(count, commands);
  }
}

int main(){
  srand(time(NULL));
  int Yme = rand() % 3;
  int Xme = rand() % 3;
  int map[3][3];
  //generateRoom(Yme, Xme);
  mainMenu();
  doCommand();
}
