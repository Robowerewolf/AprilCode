#include <iostream>
using namespace std;
void show_menu();
//Print the help menu, as shown above.
void show_title_given_year(int year);
//Print the title for that year.Hint: Use a switch statement.
void show_age_given_index(int index);
//Print the age of the book for that index.Hint: Use an array.
char input;
int year;
int index;
int years;
int main() {
	while (input != 'q') {
		cout << "What do you want to do?" << endl;
		cin >> input;
		if (input == 'h') {
			cout << "h - help" << endl;
			cout << "i - show age of the Oz book for that index" << endl;
			cout << "y - show the Oz book for that year" << endl;
			cout << "q - quit" << endl;
		}
		if (input == 'i') {
			cout << "index" << endl;
			cin >> index;
			if (index == 1)
				cout << "Published 117 years ago" << endl;
			if (index == 2)
				cout << "Published 113 years ago" << endl;
			if (index == 3)
				cout << "Published 110 years ago" << endl;
			if (index == 4)
				cout << "Published 109 years ago" << endl;
			if (index == 5)
				cout << "Published 108 years ago" << endl;
			if (index == 6)
				cout << "Published 107 years ago" << endl;
			if (index == 7)
				cout << "Published 104 years ago" << endl;
			if (index == 8)
				cout << "Published 103 years ago" << endl;
			if (index == 9)
				cout << "Published 102 years ago" << endl;
			if (index == 10)
				cout << "Published 101 years ago" << endl;
			if (index == 11)
				cout << "Published 99 years ago" << endl;
			if (index == 12)
				cout << "Published 98 years ago" << endl;
			if (index == 13)
				cout << "Published 97 years ago" << endl;
			if (index == 14)
				cout << "Published 96 years ago" << endl;
			if(index > 14)
				cout << "Sorry, no such book" << endl;
		}

		if (input == 'y') {
			cout << "What year?" << endl;
			cin >> year;
			if (year == 1900)
				cout << "The Wonderful Wizard of oz" << endl;
			if (year == 1904)
				cout << "The Marvelous land of oz" << endl;
			if (year == 1907)
				cout << "Ozma of oz" << endl;
			if (year == 1908)
				cout << "Dorothy and the Wizard in oz" << endl;
			if (year == 1909)
				cout << "The Road to oz" << endl;
			if (year == 1910)
				cout << "The Emerald City of oz" << endl;
			if (year == 1913)
				cout << "The Patchwork Girl of oz" << endl;
			if (year == 1914)
				cout << "Tik-Tok of oz" << endl;
			if (year == 1915)
				cout << "The Scarecrow of oz" << endl;
			if (year == 1916)
				cout << "Rinkitink in oz" << endl;
			if (year == 1917)
				cout << "The Lost Princess of oz" << endl;
			if (year == 1918)
				cout << "The Tin Woodman of oz" << endl;
			if (year == 1919)
				cout << "The Magic of oz" << endl;
			if (year == 1920)
				cout << "Glinda of oz" << endl;
		}

	}
	}
void show_title_given_year(int year) {

}
void show_age_given_index(int index) {

}