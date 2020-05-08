# Text-based Game

## **Team Member:**
- VINCENT 3035663538
- HAFI KHOIRUL 3035663021

## **Problem Statement:**

## **Game Description:**
One Night at Nowhere is an uncompromising horror survival text-based game full of challenges and mystery. Feel the tense as you are trapped in a strange and gloomy world full of mysterious creatures, dangers, and surprises. Gather resources and clues to find your way out.

One day, you wake up with a sick head lying on the floor in a dark room filled with an unpleasant odor around you. You don't remember who you are or how you got here? You don’t know what kind of mysterious thing is approaching you ahead. The only important thing is that you have to survive. 

Genre : Adventure,Survival, Mystery, Horror

**Basic Game Rules:**
Objectives:
- In this game, you will experience a number of situations, in the result of your commands and choices. You will be prompted to perform valid commands based on the current situation. If you performed an invalid command or unavailable situation, you will need to reenter your command. 
- The player is required to find a way out from the map by collecting required adventure items, completing certain tasks, and solving riddles by collecting all of the characters scattered throughout the room. Throughout the game, the player need to input valid commands in the form of:

***COMMANDS OBJECT***  
[The command should only consist of 2 lowercase words, "command" and "object", and separated by space “ “]

E.g: 
- go north
- take key
- examine photograph
- use gun
- quit game

There are several important commands that you need to use to complete the game:
- go
- take
- examine
- use
- view
- quit 
	
Required adventure Item : 
- Key
- Rope
- Torch
- Phone
- Gun
- Bullet
- Knife

**The game ends when:**	  
There are 3 conditions:  
- The player quits the game by entering "quit game" command
- Either the player wins by successfully collecting all required adventure items and finds the way out without being killed. 
- Or the player loses when they are being killed by a monster in the game 

## **List of features / functions that have been implemented:**
1. Generation of random game sets or events
- Using srand(time(NULL)) for:
  - Randomized the first room appearance
  
2. Data structures for storing game status
- Using struct and array
- Using 2D array of 3x3, to store possible rooms
- Store item 
- Riddle

3. Dynamic memory management
- Using dynamic array as inventory to store items collected througout the game
- The inventory size is 3 at the start of the game
- The size will be enlarged by 3, everytime the inventory is full
- The code is inspired by grow_phonebook() function from module 8 of ENGG1340 course

4. File input/output 
- Read file using <fstream> functions to input, for showing description of each rooms (from room1.txt until room9.txt)
	
5. Program codes in multiple files
- Using .txt files to store descriptions of each rooms and then using <fstream> functions to input it
- Using .h and .cpp files to store struct and different functions 
- Using Makefile to ease compilation process

## **Compilation and execution instructions:**
- in CS environment (x2go)
- Compile by using "make main"
- Execute by using "./main"

