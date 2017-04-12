#include <iostream>
#include <ctime>
using namespace std;
char input1;
int input2;
char computer;
int main() {
	srand(static_cast<unsigned int>(time(0)));
	cout << "Welcome one and all to a round of Rock, Paper, " << endl;
	cout << "Scissors, Lizard, Spock! (Enter R, P, S, L, or K)" << endl;
	cin >> input1;
	input2 = rand() % 5;
	if (input2 == 0)
		cout << "Rock" << endl;
	else if (input2 == 1)
		cout << "Paper" << endl;
	else if (input2 == 2)
		cout << "Scissors" << endl;
	else if (input2 == 3)
		cout << "Lizard" << endl;
	else if (input2 == 4)
		cout << "Spock" << endl;
	////////////////////genratoorri

	if ((input1 == 'r') && (input2 == 1 || input2 == 4))
		cout << "YOU LUSS FEG" << endl;
	else if ((input1 == 'r') && (input2 == 3 || input2 == 2))
		cout << "GANG geng" << endl;
	else if ((input1 == 'r') && (input2 == 0))
		cout << "Well played -.-" << endl;
	////////////////////
	if ((input1 == 's') && (input2 == 0 || input2 == 4))
		cout << "now u juss succ" << endl;
	else if ((input1 == 's') && (input2 == 1 || input2 == 3))
		cout << "Snips snipss" << endl;
	else if ((input1 == 's') && (input2 == 2))
		cout << "u succ we ti" << endl;
	///////////////////
	if ((input1 == 'p') && (input2 == 2 || input2 == 3))
		cout << "rip trees" << endl;
	else if ((input1 == 'p') && (input2 == 0 || input2 == 4))
		cout << "You're the weiner" << endl;
	else if ((input1 == 'p') && (input2 == 1))
		cout << "you can Write on Me too;)" << endl;
	///////////////
	if ((input1 == 'l') && (input2 == 0 || input2 == 2))
		cout << "YOU LOSE" << endl;
	else if ((input1 == 'l') && (input2 == 2 || input2 == 4))
		cout << "You win" << endl;
	else if ((input1 == 'l') && (input2 == 3))
		cout << "Tied" << endl;
	//////////////////////
	if ((input1 == 'k') && (input2 == 3 || input2 == 1))
		cout << "Your move is illogical" << endl;
	else if ((input1 == 'k') && (input2 == 0 || input2 == 2))
		cout << "Live long and prosper" << endl;
	else if ((input1 == 'k') && (input2 == 4))
		cout << "Health and Long life" << endl;
}