#include <iostream>
using namespace std;
int main() {
	int Greivous = 0;
	int DarthMaul = 0;
	int Palpatine = 0;
	int DarthVader = 0;
	char input;
	cout << "What star wars villain are you?" << endl;
	{
		cout << "favorite color?" << endl;
		cout << "Red(m), Blue(p), Black(v),Green & blue(g)" << endl;
		cin >> input;
		if (input == 'm')
			DarthMaul += 2;
		else if (input == 'p')
			Palpatine += 2;
		else if (input == 'v')
			DarthVader += 2;
		else if (input == 'g')
			Greivous += 2;
	}
	{
		cout << "favorite genre of music?" << endl;
		cout << "Rock(m), pop(g), country(p), Rap(v)" << endl;
		cin >> input;
		if (input == 'm')
			DarthMaul += 2;
		else if (input == 'p')
			Palpatine += 2;
		else if (input == 'v')
			DarthVader += 2;
		else if (input == 'g')
			Greivous += 2;
	} {
		cout << "Favorite activity?" << endl;
		cout << "Using dual-bladed lightsabers(m), Killing jedi for their lightsabers(g)," << endl;
			cout<<"Shooting lightning from my hands(p), Choking people with the force(v)" << endl;
		cin >> input;
		if (input == 'm')
			DarthMaul += 2;
		else if (input == 'p')
			Palpatine += 2;
		else if (input == 'v')
			DarthVader += 2;
		else if (input == 'g')
			Greivous += 2;
	}
	if (DarthMaul > Palpatine && DarthMaul > Greivous && DarthMaul > DarthVader)
		cout << "You are Darth Maul" << endl;
	else if (Palpatine > DarthMaul && Palpatine > Greivous && Palpatine > DarthVader)
		cout << "You are Emporer Palpatine" << endl;
	else if (Greivous > DarthMaul && Greivous > DarthVader && Palpatine < Greivous)
		cout << "You are General Greivous" << endl;
	else if (DarthVader > Greivous && Palpatine < DarthVader && DarthVader > DarthMaul)
		cout << "You are Darth Vader" << endl;
}
