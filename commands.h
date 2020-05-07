#ifndef COMMANDS_H
#define COMMANDS_H
#include <string>
#include "struct.h"
using namespace std;

void go_command(int &y, int &x, string userInput);

void take_command(int y, int x, string * &inventory, string itemTaken, int &itemsCarried, int &inventorySize, listItems love[]);

void examine_command(int y, int x, string itemExamined, string * &inventory, int inventorySize);

void view_inventory_command(string * &inventory, int inventorySize, string itemViewed);

#endif
