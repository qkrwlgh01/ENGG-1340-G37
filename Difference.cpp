#include "header.h" //header file

void diff(string guess, string wordle) // indicate differences between guess and wordle
{
	for (int i = 0; i < guess.length(); i++) {
		if (guess[i] == wordle[i]) {
			correct_position(guess[i]);
		}
		else if (wordle.find(guess[i])) {
			wrong_position(guess[i]);
		}
		else {
			wrong_character(guess[i]);
		}
	}
}
