#include <iostream>
#include <fstream>
#include <string>
#include "generateRoom.h"
using namespace std;

// This function will generate room from each 9 room by using File I/O
// By using input int y and x as the current location of the user, 
// it will read from another txt file and then output the room text

void generateRoom(int y, int x){
  
  int roomNumber = ((x+1)+(y*3));
  string rN = to_string(roomNumber);
  string roomfile = "room" + rN  + ".txt";
  cout << endl;
  
  ifstream fin;
  string message;
  fin.open(roomfile);
  while (getline(fin, message)){    
    cout << message << endl;
  }

  fin.close();
}

