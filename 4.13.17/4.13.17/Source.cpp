#include <Windows.h>
#include <string>
#include <iostream>
using namespace std;
int main() {
	string inv[5];
	string input;
	cout << "Do you want a Magic sword" << endl;
	cin >> input;
	if (input.compare("yes") == 0) {
		inv[0] = "Sword";
		cout << "You got the sword" << endl;
	}
	if (inv[0].compare("Sword") == 0) {
		PlaySound(TEXT("TaDa.wav"), NULL, SND_FILENAME);
		cout << "Ta Da.wav" << endl;
		
	}
	if (inv[0].compare("Sword") != 0) {
		PlaySound(TEXT("Sad.wav"), NULL, SND_FILENAME);
		cout << "Sad.wav" << endl;
		
	}
}
