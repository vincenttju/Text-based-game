#ifndef COMMANDS_H
#define COMMANDS_H
#include <string>
#include "struct.h"
using namespace std;

void go_command(int &y, int &x, string userInput);

void take_command(int y, int x, string invertory[], string itemTaken, int &count, struct listItems love[]);

#endif
