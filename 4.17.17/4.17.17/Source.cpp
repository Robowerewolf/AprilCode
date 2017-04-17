#include <iostream> 
#include <ctime>
#include <math.h>
using namespace std;  // For standard namespace 



int main() {
	srand(time(NULL));
	//int num = rand() % 20 - 10;
	//int num2 = rand() % 20 - 10;
	int num = 10;
	int num2 = -5;
	double x;
	double x2;
	double y;
	double y2;
	double sl;
	double sl2;
	double sl3;
	double perimeter;
	double s;
	double area; 

	do {

		// PART I: INSERT YOUR CODE BELOW HERE

		cout << "X = " << num << " Y = " << num2 << endl;
		cout << "Give me x" << endl;
		cin >> x;
		cout << "Give me y" << endl;
		cin >> y;
		cout << "Give me another x" << endl;
		cin >> x2;
		cout << "Give me another y" << endl;
		cin >> y2;

		// PART I INSERT YOUR CODE ABOVE HERE
		// PART II: INSERT YOUR CODE BELOW HERE

		sl = sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y));
		sl2 = sqrt((x - num)*(x - num) + (y - num2)*(y - num2));
		sl3 = sqrt((num - x2)*(num - x2) + (num2 - y2)*(num2 - y2));

		perimeter = sl + sl2 + sl;

		s = (sl + sl2 + sl3) / 2;

		area = sqrt(s*(s - sl)*(s - sl2)*(s - sl3));

		// PART II INSERT YOUR CODE ABOVE HERE
		// PART III INSERT YOUR CODE BELOW HERE

		cout << "Side Lengths Are: " << sl << " , " << sl2 << " , " << sl3 << endl;
		cout << endl;
		cout << "Perimeter Is: " << perimeter << endl;
		cout << endl;
		cout << "Area Is: " << area << endl;
		cout << endl;

		// PART III INSERT YOUR CODE ABOVE HERE

		// signals the operating system that our program ended OK.

	} while (1);

}