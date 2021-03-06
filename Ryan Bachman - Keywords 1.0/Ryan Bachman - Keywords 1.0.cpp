// Keywords.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Ryan Bachman
// CSC215 C/C++ Programming
// University of Advancing Technology
// CIA Keywords assignment.
// October 20, 2018

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    char playAgain = 'y';

	while (playAgain == 'y')
	{
		// enum adds a number for the amount of fields. So it gets the word, the hint and gets the number of fields.
	    enum fields {WORD, HINT, NUM_FIELDS};
		// Sets a boundary for rows to 10.
		const int NUM_WORDS = 10;
		// Creates a constant string array where rows is 5 and columns is calculated by NUM_FIELDS which is 2
		const string WORDS[NUM_WORDS][NUM_FIELDS] =
		{
			// Initializes the array with the WORD and then the HINT.
			{"bananas", "Gwen Stefani can spell it... Can you?"},
			{"rowboat", "George Washington crossed the Delaware because of it."},
			{"secret", "Because you can't spell secret code without it."},
			{"hacker", "You can decode stuff. I bet you think you're a top of the line one of these..."},
			{"matrix", "'Mr. Anderson...' That's you, secret agent man!"},
			{"enthusiasm", "I lost all of mine watching you try and break these codes."},
			{"shepherd", "Those Germans sure made a great dog!"},
			{"intelligence", "You better get this right, it's in your name."},
			{"watergate", "On one hand, this really got Nixon in trouble. On the other, it stops a flood!"},
			{"terrorist", "You're supposed to stop these guys!"}
		};

		// Seeds the random number generator to time.
		srand(static_cast<unsigned int>(time(nullptr)));
		
		// Keeps track of how many attempts the player has tried.
		int attempts = 0;
		// Keeps track of how many times the word was correct.
		int correct = 0;
		// Keeps track of how many hints the agent had to use.
		int hintsUsed = 0;
		// Keeps track of the users guess.
		string guess;
		

		// Welcoming the player.
		cout << "\t\t\tWelcome to Keywords! (A C.I.A. training program, but don't tell anyone that...)\n\n";
		cout << "\t\t\t\t\tCongratulations on making it into the C.I.A.\n";
		cout << "\t\t\t\tOur enemy has outsmarted our technology by 'dumbing things down'.\n";
		cout << "\t\t\t\tAll you have to do here, is unscramble the word into a real one.\n";
		cout << "\t\t\t\tThis program will help you succeed where our technology has failed us.\n\n";
		cout << "\t\t\t\t\t\tEnter 'hint' for a hint.\n";
		cout << "\t\t\t\t\t\tEnter 'quit' to quit the game.\n\n";

		// Enter the game loop.
		while (correct < 3)
		{
			// Makes choice a random number within the amount of NUM_WORDS.
			int playerChoice = (rand() % NUM_WORDS);
			string ciaWord = WORDS[playerChoice][WORD]; // The word to guess.
			string ciaHint = WORDS[playerChoice][HINT]; // The hint for the word to guess.

			string jumble = ciaWord; // Jumbled version of the selected word.
			int length = jumble.size(); // Gets the size of the word to jumble and sets it to an integer called length.
			for (int i = 0; i < length; i++)
			{
				// index1 and index2 generates two random positions and swaps characters at those positions.
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}

			// Nested while loop so the player can keep guessing the word without it doing the main loop and changes the word.
			while (guess != ciaWord)
			{
				cout << "The jumble is: " << jumble;
				cout << "\n\nYour guess: ";
				cin >> guess;

				if (guess == "hint")
				{
					cout << ciaHint << "\n\n";
					hintsUsed++;
				}
				else if (guess == "quit")
				{
					cout << "Goodbye quitter...\n\n" << endl;
					return 0;
				}
				else if (guess == ciaWord)
				{
					cout << "Correct\n\n";
					correct++;
					attempts++;
				}
				else
				{
					cout << "Sorry, that's not it.\n\n";
					attempts++;
				}
			}
		}

		// Displays the stats to the trainee. Uses an if else if statement to add attitude to the score.
		cout << "\nTraining complete.\n\n";
		cout << "\t\t\tYour stats\n";
		cout << "=============================================================\n";
		if ((attempts == correct) && (hintsUsed == 0))
		{
			cout << "Out of " << attempts << " attempts you got " << correct << " right. I'm pretty sure you cheated!\n";
			cout << "You cheated because you used " << hintsUsed << " hints.";
		}
		else if (attempts == correct)
		{
			cout << "Out of " << attempts << " attempts you got " << correct << " right. Great job!\n";
			cout << "You also used " << hintsUsed << " hints.";
		}
		else if (attempts >= (correct + 3))
		{
			cout << "Out of " << attempts << " attempts you got " << correct << " right. I'm not sure why we even hired you...\n";
			cout << "You also used " << hintsUsed << " hints.";
		}
		else
		{
			cout << "Out of " << attempts << " attempts you got " << correct << " right. Average, at best.\n";
			cout << "You also used " << hintsUsed << " hints.";
		}

		// Starts the process to play the simulation again if the user chooses to.
		cout << "\n\nDo you want to play again? (y/n): ";
		cin >> playAgain;
		cout << "\n\n";
	}

	return 0;
}