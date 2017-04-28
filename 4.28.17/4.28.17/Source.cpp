#include <iostream>
using namespace std;
double nuke(double attack, double orb);
int main() {
	double attack;
	double orb;
	double nukePower;
	cout << "What is the base attack?" << endl;
	cin >> attack;
	cout << "power of the orb?" << endl;
	cin >> orb;
	cout << "your orb did " << nuke(attack, orb) << " damage" << endl;
}
double nuke(double attack, double orb) {
	double nukePower = (attack * (1 + (0.3 * orb))) + 3000;
	return nukePower;
}