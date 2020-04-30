#include <iostream>
#include <cstdlib>
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
  cout << "   Find 4 unique items scattered around the mansion   " << endl;
  cout << "            and use it in the ancient gate            " << endl;
  cout << "    Be careful of him, human flesh is his favourite   " << endl;
  cout << "------------------------------------------------------" << endl;
}
void doCommand(){
  cout <<  "Your command" << endl;
  string command;
  getline(cin, command);
  string word;
  if (
}
  
int main(){
  srand(time(NULL));
  int Yme = rand() % 3;
  int Xme = rand() % 3;
  int map[3][3];
  generateRoom(Yme, Xme);
  mainMenu();
}
