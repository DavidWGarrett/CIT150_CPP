/*
David Garrett
Chapter 13 Lab 2
12-5-22
*/

#include <iostream>
#include "SoccerPlayer.h"

using namespace std;

const static int NUMBER_OF_PLAYERS = 11;

int main()
{
    SoccerPlayer players[NUMBER_OF_PLAYERS];
    int bestPlayerIndex = 0;

    for (int i = 0; i < NUMBER_OF_PLAYERS; i++)
    {
        playerInfo player; // struct with player's info

        // Input player's info
        cout << "Enter the soccer player's jersey number: ";
        cin >> player.jerseyNumber;

        cout << "Enter the goals scored by player #" << player.jerseyNumber << ": ";
        cin >> player.goals;

        cout << "Enter the number of assists by player #" << player.jerseyNumber << ": ";
        cin >> player.assists;
        cout << endl;

        // Instantiate player object in array
        players[i] >> player;

        // Determine if player has greatest amount of goals/assists
        if (players[i] > players[bestPlayerIndex])
        {
            bestPlayerIndex = i;
        }
    }

    // Output player info
    for (int i = 0; i < NUMBER_OF_PLAYERS; i++)
    {
        cout << players[i];
    }

    // Display which player has greatest amount of goals/assists
    cout << "\nThe great player is " << players[bestPlayerIndex];
}

