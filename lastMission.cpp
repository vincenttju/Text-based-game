#include <iostream>
#include <string>
#include "lastMission.h"
using namespace std;

// this function will output the last mission of the game
bool last_Mission(){
    string answer, choice, useRope;
    int counter = 0;

    cout << "\n===      The ancient gate closed right aways as you entered the room!        ===" << endl;
    cout << "===        There is a password door in front of you now, written:            ===" << endl;
    cout << "===  Please form a word using the 9 given characters throughout the mansion  ===" << endl;
    cout << "===     Type \"hint\" if you want the 9 characters given to your screen        ===" << endl;
    cout << "===                      Input the word in lowercase!                        ===" << endl;
    cout << "\nANSWER:" << endl;

    while (answer != "adventure"){
        cin >> answer;
        if (answer == "hint"){
            cout << "===       The 9 characters you got: D - R - A - E - N - E - T - U - V        ===" << endl;
            continue;
        }
        else if (answer == "adventure"){
            break;
            counter++;
        }
        cout << "Wrong answer, TRY AGAIN!" << endl;
        counter++;
    }
    
    cout << "\n===                       The password door is unlocked!                     ===" << endl;
    cout << "===                          You have tried " << counter  << " times!                         ===" << endl;
    cout << "===  As soon as you opened the door, a hell creature is coming in your way!  ===" << endl;
    cout << "===             What would you choose to kill him? (gun / knife)             ===" << endl;
    cout << "Your choice (gun / knife) : " << endl;

    cin >> choice;
    if (choice == "gun"){
      cout << "\n===                  You loaded your gun with some bullets                   ===" << endl;
      cout << "===        You shot him right on his heart with the silicone bullet!         ===" << endl;
      cout << "===    He is dead now, but not forever, you still have to find the way out!  ===" << endl;
    }
    else if (choice == "knife"){
      cout << "\n===               The creature is too fast to be striked by a knife.         ===" << endl;
      cout << "===                          You are killed instead!                         ===" << endl;
      cout << "====================               GAME OVER!               ====================" << endl;
      return 0;
    }
    else{
      cout << "\n===                    You did not choose the right weapon                   ===" << endl;
      cout << "===         The creature is too fast, you have no other opportunity          ===" << endl;
      cout << "===                            You are killed instead!                       ===" << endl;
      cout << "====================               GAME OVER!              =====================" << endl;
      return 0;
    }

    cout << "\n===               You have escaped from the creepy mansion!                  ===" << endl;
    cout << "===               But you realised that you are on the second floor!         ==="<< endl;
    cout << "===                   Maybe try to use the rope that you got?                ===" << endl;
    getline(cin, useRope);
    if (useRope != "use rope"){
      while (useRope != "use rope"){
        cout << "USE YOUR ROPE!" << endl;
        getline(cin, useRope);
      }
    }
    cout << "\n===              You have finally escaped the creepy mansion!                ===" << endl;
    cout << "===    Luckily you have collected the battery, lets put it into the phone.   ===" << endl;
    cout << "===                             The phone is on!                             ===" << endl;
    cout << "===                   You use your phone to call for help                    ===" << endl;
    cout << "=== Help service arrived 3 hours later, and you are back to your normal life!===" << endl;
    cout << "====================                END GAME!             ======================" << endl;
    cout << "===============           Thank you for playing the game!      =================" << endl;
    string rating;
    cout << " - Please rate the game : (0-10) -" << endl;
    getline(cin, rating);
    cout << " - Thank you for the rating, see you next time! -" << endl;
    return 0;
}
