#include <iostream>
#include <windows.h>
using namespace std;
int shute;
int input;
bool horoscope(int input);
int main() {
	cout << "Enter number for your horoscope" << endl;
	cin >> input;
	horoscope(input);
	if (horoscope(input) == true)
		cout << "congradualtions you closer to dying!" << endl;
}
 bool horoscope(int input) {
	 if (input == 3) {
		 cout << "You are aries, and you will slay the god of war and gain freedom soon" << endl;
		 return 0;
	 }
	 else if (input == 2) {
		 cout << "you are Picies. inescapable death lies in your future." << endl;
		 return 0;
	 }
	 else if (input == 1) {
		 cout << "You are aquarius. Fortune and good apples await you in your future." << endl;
		 return 0;
	 }
	 else if (input == 4) {
		 return 1;
		 cout << "you are Taurus. you may find the truth about your god soon." << endl;
	 }
	 else if (input == 5) {
		 cout << "you are Gemini. you will find that everything changes." << endl;
		 return 0;
	 }
	 else if (input == 6) {
		 cout << "you are Cancer. you are a crab." << endl;
		 return 0;
	 }
	 else if (input == 7) {
		 cout << "you are leo. Unleash your charm, and you will be the life of the party. " << endl;
		 return 0;
	 }
	 else if (input == 8) {
		 cout << "you are virgo. Trial and error is a very effective way to learn, so remember that if a few of your experiments go awry today, These aren't failures -- they are wonderful learning opportunities!" << endl;
		 return 0;
	 }
	 else if (input == 9) {
		 cout << "you are Libra. Hang on tight, because your creativity is about to skyrocket! Today you'll be able to find multiple ways to add more fun, color, music and beauty to your life with little (if any) effort." << endl;
		 return 0;
	 }
	 else if (input == 11) {
		 cout << "you are Sagittarius. you will achive your goals with incredible accuracy" << endl;
		 return 0;
	 }
	 else if (input == 10) {
		 cout << "you are scorpio. An idea you used to think of as quite radical will be proved to be the right strategy today -- and you might be served up a piece of humble pie for doubting it." << endl;
		 return 0;
	 }
	 else if (input == 12) {
		 cout << "you are capricorn. Your actions will impress people today, even though you may not completely understand why." << endl;\
			 return 0;
	 }
}