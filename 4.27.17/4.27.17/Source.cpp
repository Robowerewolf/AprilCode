#include <iostream>
using namespace std;
double attack(double level,double a,double d,double power, double modifier);
int main() {
	double level = 0;
	double a = 0;
	double d = 0;
	double power = 0;
	double modifier;
	cout << "whats the level" << endl;
	cin >> level;
	cout << "attack?" << endl;
	cin >> a;
	cout << "power?" << endl;
	cin >> power;
	cout << "defence?" << endl;
	cin >> d;
	cout << "modifier?" << endl;
	cin >> modifier;
	
	cout << "you did " << attack(level, a, d, power, modifier) << " damage" << endl;
		
}
double attack(double level, double a, double d, double power, double modifier) {
	double damage = ((((2 * level / 5) + 2)*power*(a / d) / 50) + 2)*modifier;
	return damage;
}