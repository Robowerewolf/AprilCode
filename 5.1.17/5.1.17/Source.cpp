#include <iostream>
#include <ctime>
using namespace std;
int arr[7];
int num;
int main() {
	srand(time(NULL)); 

	for (int i = 0; i < 7; i++){
		num = rand() % 10;
		arr[i] = num;
		cout << num << endl;
	}

	cout << "Strength:" << arr[0];
	cout << "Perception:" << arr[1];
	cout << "Endurance:" << arr[2];
	cout << "Charisma:" << arr[3];
	cout << "Intelligence:" << arr[4];
	cout << "Agility:" << arr[5];
	cout << "Luck:" << arr[6];
}


