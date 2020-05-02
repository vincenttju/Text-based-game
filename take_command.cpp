#include <iostream>
#include <string>
using namespace std;

void take_command(int y, int x, string invertory[], string itemTaken, int count){
  int roomNumber = ((x+1)+(y*3));
  invertory[count] += itemTaken;
}
  
