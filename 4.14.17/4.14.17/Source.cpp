#include <iostream>
using namespace std;
char input;
char secretWord[10] = { 'h','o','t','c','h','e','e','t','o','s' };
char Guessed[10] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
char correctLetters[10];
int turns = 7;
int correct = 0;
bool gg = false;
int main() {
	while (turns > 0 && correct <10) {
		gg = false;
		cout << "Take a guess" << endl;
		cin >> input;
		for (int i = 0; i < 10; i++) {
			if (input == secretWord[i]) {
				Guessed[i] = input;
				correct++;
				gg = true;
			}
		}

		if (gg == false) {
			cout << "sorry," << input << "is not in the word" << endl;
			turns--;
		}
		else
			cout << "Correct letter" << endl;

		cout << "your word so far:" << endl;
		for (int i = 0; i < 10; i++)
			cout << Guessed[i];
		cout << endl;

		cout << "you have " << turns << " left." << endl;

	}//end loop

}