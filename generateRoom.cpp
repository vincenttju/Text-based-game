#include <iostream>
#include <fstream>
#include <string>
#include "generateRoom.H"
using namespace std;

void generateRoom(int Y, int X){
  ifstream fin;
  if (Y == 0 && X == 0){
    string message;
    fin.open("room1.txt");
    while (getline(fin, message)){
      cout << message << endl;
    }
  }
  elif (Y == 0 && X == 1){
    string message;
    fin.open("room2.txt");
    while (getline(fin, message)){
      cout << message << endl;
    }
  }
  
  fin.close();
}
    
