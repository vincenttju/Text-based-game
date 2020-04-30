#include <iostream>
using namespace std;

void mainMenu(){
  string name;
  cout << "************ Welcome to One Night Game ************" << endl;
  cout << "Hello, please enter your character name." << endl;
  getline(cin, name);
  cout << "You woke up with a sick head lying on the floor" << endl;
  cout << "in a dark room filled with an unpleasant odor " << endl;
  cout << "\nYou have no idea of who you are and how you got here" << endl;
  cout << "You see a scroll on your left saying:" << endl;
  cout << "---------------------------------------------------" << endl;
  cout << "Find 4 adventure items scattered around the mansion" << endl;
  cout << "     and use it in the ancient adventure gate" << endl;
  cout << "  Be careful of him, human flesh is his favourite  " << endl;
  cout << "---------------------------------------------------" << endl;
}
int main(){
  int map[3][3];
  mainMenu();
}
