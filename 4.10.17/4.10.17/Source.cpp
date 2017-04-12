#include <iostream>
#include <iomanip>
using namespace std;
double temp,C=0,F=0,K=0;
char type;
void k(), f(), c(),ts();
int main() {
	cout << "Enter temp." << endl;
	cin >> temp;
	cout << "Enter type." << endl;
	cin >> type;

	if (type == 'k')
		k();
	if (type == 'c')
		c();
	if (type == 'f')
		f();
	ts();

}
void ts() {
	if (F < 32)
		cout << "Brrrrrrrrrrr!" << endl;

	if (F > 212)
		cout << "Pant Pant!" << endl;

	else
		cout << "You are a fugitive from the law of averages" << endl;

}

void f() {

	F = temp;


	C = (temp - 32) * 5 / 9;
	K = (temp - 32) * 5 / 9 + 273.15;
	cout << fixed << setprecision(2) << F << "F" << endl << C << "C" << endl << K << "K" << endl;
}
void c() {

	C = temp;
	F = (temp* 9 / 5) + 32;
	K = temp + 273.15;
	cout << fixed << setprecision(2) << C << "C" << endl << F << "F" << endl << K << "K" << endl;
}
void k() {
	K = temp;
	C = temp - 273.15;
	F = (temp - 273.15) * 9 / 5 + 32;
	cout << fixed << setprecision(2) << K << "K" << endl << F << "F" << endl << C << "C" << endl;
}