# Text-based Game

Team Member:
- VINCENT 3035663538
- HAFI KHOIRUL 3035663021

## **Game Description:**
One Night at Nowhere is an uncompromising horror survival text-based game full of challenges and mystery. Feel the tense as you are trapped in a strange and gloomy world full of mysterious creatures, dangers, and surprises. Gather resources and clues to find your way out.

One day, you wake up with a sick head lying on the floor in a dark room filled with an unpleasant odor around you. You don't remember who you are or how you got here? You don’t know what kind of mysterious thing is approaching you ahead. The only important thing is that you have to survive. 

Genre : Survival, Mistery, Horror

**Basic Game Rules:**
Objectives:
- In this game, you will experience a number of situations, in the result of your commands and choices. You will be prompted to perform valid commands based on the current situation. If you performed an invalid command or unavailable situation, you will need to reenter your command. 
- The player is required to find a way out from the map by collecting required adventure items, completing certain tasks, solving riddles and going on the right path without being killed by the Monster. Throughout the game, the player need to input valid commands in the form of:

***COMMANDS OBJECT***  
[The command should only consist of 2 lowercase words, command and object, and separated by space “ “]

E.g: 
- go north
- take key
- examine photograph
- use gun
- answer riddle

There are several important commands that you need to use to complete the game:
- go
- take
- examine
- open
- use
- answer
- quit 
- More to be added ...
	
Required adventure Item : 
- Key
- Rope
- Torch
- Phone
- Gun

**Brief example of gameplay:**

You see a stairway.

Your command: go down
You are walking down the stairway to the second floor.

--- Second Floor ---

There are 4 different rooms in your north,east,south,west. There is a small drawer here.

Your command: break drawer

--Invalid command--

Your command: open drawer

Key is required to open the drawer.

Your command: use key

Opening the drawer reveals a riddle sentence “........”


**The game ends when:**
- Either the player wins by successfully collecting all required adventure items and finds the way out without being killed …. 
- Or the player loses when they are being killed or surrendered 

# **List of features / functions that you plan to implement:**
1. Generation of random game sets or events
- Using srand(time(NULL)) and switch() for:
  - Random event of enemy appearance
  - Random points earned by defeating enemies or completion of certain tasks
2. Data structures for storing game status
- Using struct and array
- Using 2D array of 4x4, to store possible rooms
- Store item 
- Riddle
3. Dynamic memory management
- Using dynamic array to store items collected
- Using pointers to address memory
- Using pass-by-reference with pointers
4. File input/output (e.g., for loading/saving game status)
- Read/save file for game status
- Storing room name, room description, and interactable objects in the room into a txt file. It will be the input for the game.
- Using .txt files to store some functions and then using <fstream> functions to input and output it
5. Program codes in multiple files
- Using .txt files to store some functions and then using <fstream> functions to input and output it
- Using .h and .cpp files to store different functions 
- Using Makefile to be more systematic and efficient

**List of possible functions implemented in the game:**
- printStory()
  -This function will output the introduction at the beginning
- setPlayerName()
  -This function will input the name of the player at the beginning and output it in the intro.
- doCommand()
  -This function will accept input commands from the player and perform several actions using if conditional.
- generateRoom()
  -In the doCommand() function, if (command == go), it will call this function to take input from room.txt file to show room name,description etc.
- useItems()
  -This function will accept input use from the players and then output certain applications of items.
- answerRiddle()
  -This function will accept input “answer” from the players and then output certain clues if players can answer.

