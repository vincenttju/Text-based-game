#include <iostream>
#include <fstream>
#include <string>
#include "generateRoom.h"
using namespace std;

void generateRoom(int Y, int X){
  int roomNumber = (X + 1) + (Y*3);
  string rN = to_string(roomNumber);
  string roomfile = "room" + rN  + ".txt";

  ifstream fin;
  string message;
  fin.open(roomfile);
  while (getline(fin, message)){
    cout << message << endl;
  }

  fin.close();
}
