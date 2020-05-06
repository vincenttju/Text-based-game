#include <iostream>
#include <string>
using namespace std;

void take_command(int y, int x, string invertory[], string itemTaken, int &count, struct listItems love[]){
  int roomNumber = ((x)+(y*3));
  
  if ((itemTaken == love[roomNumber].item1) || (itemTaken == love[roomNumber].item2)){
    invertory[count] += itemTaken;
    count += 1;
  }
  else{
    cout << "invalid items!" << endl;
  }
}
  
