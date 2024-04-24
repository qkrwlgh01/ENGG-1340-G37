#include <iostream>
#include <string>
#include <cctype>
#include "header.h"
using namespace std;

void diff(string guess, string wordle) // find difference between guess and wordle
{
	for (int i = 0; i < guess.length(); i++) {
		if (guess[i] == wordle[i]) {
			cout << "letter " << itos(i + 1) << ": " << "right letter, right place." << endl;
		}
		else if (wordle.find(guess[i])) {
			cout << "letter " << itos(i + 1) << ": " << "right letter, wrong place." << endl;
		}
		else {
			cout << "letter " << itos(i + 1) << ": " << "wrong letter." << endl;
		}
	}
}
