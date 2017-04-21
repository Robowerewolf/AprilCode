#include <iostream>
#include <ctime>
using namespace std;
void colorChange();
int num;
int main() {
	while (1) {
		srand(static_cast<unsigned int>(time(0)));
		colorChange();
		system("PAUSE");
	}
}
void colorChange(){
	num = rand() % 100;
	if (num >= 1 && num <= 25)
		system("color 1F");
	else if (num >= 26 && num <= 50)
		system("color 2F");
	else if (num >= 51 && num <= 100)
		system("color 4F");
}