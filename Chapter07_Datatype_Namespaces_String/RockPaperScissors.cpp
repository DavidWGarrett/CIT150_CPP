// David Garrett
// Chapter 7 Lab 1 Rock Paper Scissors
// 10-21-22

#include <iostream>
using namespace std;

enum rpsChoice { ROCK, PAPER, SCISSORS, NONE };

void displayRules();
void inputValidation(char& input);
void userInput(char& input);
rpsChoice choice(char input);
void displayRPS(rpsChoice choice);
rpsChoice winningObject(rpsChoice user1, rpsChoice user2);
void displayResults(int games, int playerOneWins, int playerTwoWins);

// Program is a game of rock-paper-scissors. Two players inputs a character corresponding
// to one of those objects. When the players are done, the results are displayed

int main()
{
	char userOneInput, userTwoInput, startGame;
	int userOneWins = 0, userTwoWins = 0, gameCount = 0;
	rpsChoice userOneChoice, userTwoChoice;

	// Shows a list of rules
	displayRules();

	do {
		// Players enter their choice of object. Users must input approprioate
		// character before program moves forward

		cout << "Player 1 enter your choice: ";
		userInput(userOneInput);
		inputValidation(userOneInput);
		cout << "Player 2 enter your choice: ";
		userInput(userTwoInput);
		inputValidation(userTwoInput);

		userOneChoice = choice(userOneInput);
		userTwoChoice = choice(userTwoInput);
		gameCount++;

		// Converts rspChoice variable to a cout << message
		cout << "Player 1 chose "; 
		displayRPS(userOneChoice);
		cout << " and Player 2 chose ";
		displayRPS(userTwoChoice);
		cout << ".\n" << endl;

		// Test to see who wins or if it is a tie

		if (userOneChoice == userTwoChoice)
		{
			cout << "The result is a tie!" << endl;
		}
		else if (userOneChoice == winningObject(userOneChoice, userTwoChoice))
		{
			userOneWins++;
			cout << "Player One Wins!" << endl;
		}
		else
		{
			userTwoWins++;
			cout << "Player Two Wins!" << endl;
		}

		// If player enters "y", then the do-while loop iterates again. If not, exit the loop
		cout << "Press Y if you want to play again. Press anything else to display results: ";
		cin >> startGame;
		cin.clear();
		cout << "\n";

	} while (startGame == 'Y' || startGame == 'y');

	// Shows results
	displayResults(gameCount, userOneWins, userTwoWins);

}

void displayRules()
{
	// Output rules
	cout << " Welcome to the game of Rock, Paper, "
		 << "and Scissors." << endl;
	cout << " This is a game for two players. For each "
		 << "game, each" << endl;
	cout << " player selects one of the objects, Rock, "
		 << "Paper or Scissors." << endl;
	cout << " The rules for winning the game are: " << endl;
	cout << "1. If both players select the same object, it "
		 << "is a tie." << endl;
	cout << "2. Rock breaks Scissors: So player who selects "
		 << "Rock wins." << endl;
	cout << "3. Paper covers Rock: So player who selects "
		 << "Paper wins." << endl;
	cout << "4. Scissors cut Paper: So player who selects "
		 << "Scissors wins." << endl << endl;
	cout << "Enter R or r to select Rock, P or p to select "
		 << "Paper, and S or s to select Scissors." << endl;
}

void inputValidation(char& input)
{
	// User must enter appropriate input for their choice of object
	// Cannot leave function without doing so first

	bool validation = false;

	switch (input)
	{
		case 'R':
		case 'r':
		case 'P':
		case 'p':
		case 'S':
		case 's':
			validation = true;
	}

	if (!validation)
	{
		cout << "Try again. Enter r, s, or p: ";
		userInput(input);
		inputValidation(input);
	}
}

void userInput(char& input)
{
	cin.clear();
	cin >> input;
	cin.clear();
	cin.ignore(200, '\n');
}

rpsChoice choice(char input)
{
	// Corresponds character enter to rpsChoice datatype value ROCK, PAPER, or SCISSORS

	rpsChoice choice = NONE;

	if (input == 'R' || input == 'r')
		choice = ROCK;
	else if (input == 'P' || input == 'p')
		choice = PAPER;
	else if (input == 'S' || input == 's')
		choice = SCISSORS;

	return choice;
}

void displayRPS(rpsChoice choice)
{
	switch (choice)
	{
	case ROCK:
		cout << "Rock";
		break;
	case PAPER:
		cout << "Paper";
		break;
	case SCISSORS:
		cout << "Scissors";
		break;
	}
}

rpsChoice winningObject(rpsChoice user1, rpsChoice user2)
{
	// Determins the winning object

	if ((user1 == ROCK && user2 == SCISSORS) || (user2 == ROCK && user1 == SCISSORS))
		return ROCK;
	else if ((user1 == ROCK && user2 == PAPER) || (user2 == ROCK && user1 == PAPER))
		return PAPER;
	else
		return SCISSORS;
}

void displayResults(int games, int playerOneWins, int playerTwoWins)
{
	// Show results

	cout << "The total number of plays: " << games << endl;
	cout << "The number of plays won by player 1: " << playerOneWins << endl;
	cout << "The number of plays won by player 2: " << playerTwoWins << endl;
}