#include <iostream>
#include <string>
#include <algorithm>
#include "SpaceType.h"
#include "Levels.h"
#include "Monster.h"
#include "Weapons.h"

using namespace std;
int main()
{
    Levels levels; // Create an instance of Levels
    string startInput;

    cout << "Would you like to start the game?";
    getline(cin, startInput); // gets the users input
    transform(startInput.begin(), startInput.end(), startInput.begin(), ::tolower); // convert to lowercase

    if (startInput == "yes" || startInput == "y") {
        levels.play();  // Calls play from Levels.h
    }
    else if (startInput == "no" || startInput == "n") {
        cout << "Exiting game\n";
    }
    else
    {
        cout << "Invalid input, use yes or no\n";
        main();
    }
    return 0;
};