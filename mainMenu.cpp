#include <iostream>
#include <string>
using namespace std;

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
  cout << "There is a door in your north side" << endl;
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
