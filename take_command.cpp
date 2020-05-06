#include <iostream>
#include <string>
using namespace std;

void take_command(int y, int x, string invertory[], string itemTaken, int &count, struct listItems test[]){
  int roomNumber = ((x)+(y*3));
  
  if ((itemTaken == test[roomNumber].item1) || (itemTaken == test[roomNumber].item2)){
    invertory[count] += itemTaken;
    count += 1;
  }
  else{
    cout << "invalid items!" << endl;
  }
}
  
