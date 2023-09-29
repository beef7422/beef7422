/* This program generates a random number on a twenty-sided dice for two players. The
dice are compared to see which dice roll is bigger. The bigger number wins the round.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
	//Get the handle to standard output device(the console)
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	
	unsigned seed;						//random generator seed
	int twentydice1, twentydice2;		//twenty-sided dice for each player
	string player1, player2;			//player names
	
	int color1 = 10;					//color set to green
	int color2 = 12;					//color set to red
	
	seed = time(0);
	srand(seed);
	
	//Generates random numbers for each player
	twentydice1 = rand() % 20 + 1;
	twentydice2 = rand() % 20 + 1;
	
	//Asks for players names
	cout << "Enter name of player 1: ";
	getline(cin, player1);
	cout << "Enter name of player 2: ";
	getline(cin, player2);
	
	//Shows the players and the number they rolled
	cout << player1 << " rolled a " << twentydice1 << endl;
	cout << player2 << " rolled a " << twentydice2 << endl;
	
	//Compares the two dice rolls
	if (twentydice1 > twentydice2)
	{
		cout << player1 << " won the round." << endl;
	}
	else if (twentydice1 == twentydice2)
	{
		cout << player1 << " and " << player2 <<  " are evenly matched." << endl;
	}
	else
	{
		cout << player2 << " won the round." << endl;
	}
	
	//Checks to see if dice rolls 1 or 20
	if (twentydice1 == 1)
	{
		//Sets color to red
		SetConsoleTextAttribute(screen, color2);
		cout << player1 << "'s roll was a Critical Failure" << endl;
	}
	if (twentydice1 == 20)
	{
		//Sets color to green
		SetConsoleTextAttribute(screen, color1);
		cout << player1 << "'s roll was a Critical Success" << endl;
	}
	
	if (twentydice2 == 1)
	{
		//Sets color to red
		SetConsoleTextAttribute(screen, color2);
		cout << player2 << "'s roll was a Critical Failure" << endl;
	}
	if (twentydice2 == 20)
	{
		//Sets color to green
		SetConsoleTextAttribute(screen, color1);
		cout << player2 << "'s roll was a Critical Success" << endl;
	}
	SetConsoleTextAttribute(screen, 7);
}