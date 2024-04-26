#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
using namespace std;

void correct_position(char correct_character) //printing green characters
{
    printf("\033[32m[ "); 
    printf("\033[32m%c", correct_character);
    printf("\033[32m ]\033[0m");
}
void wrong_position(char wrong_position) //printing yellow characters
{
    printf("\033[33m[ ");
    printf("\033[33m%c", wrong_position);
    printf("\033[33m ]\033[0m");
}
void wrong_character(char wrong_character) // printing normal tries
{
    printf("\033[0m[ ");
    printf("\033[0m%c", wrong_character);
    printf("\033[0m ]\033[0m");
}

void printing_right_word(vector<char> right_word)
{
    for (int i = 0; i < right_word.size(); ++i)
    {
        if (right_word[i] == 'W')
        {
            correct_position(right_word[i]);
        }
        else if (right_word[i] == 'R')
        {
            wrong_position(right_word[i]);
        }
        else
        {
            wrong_character(right_word[i]);
        }
    }
}

void print_tries(vector<char> tries)
{
    for (int i = 0; i < tries.size(); ++i)
    {
        if (tries[i] == 'W')
        {
            correct_position(tries[i]);
        }
        else if (tries[i] == 'R')
        {
            wrong_position(tries[i]);
        }
        else
        {
            wrong_character(tries[i]);
        }
    }
    cout << "\n";
}

void printline()
{
    cout << "-------------------------" << endl;
}

int main() {
    while(decision == 'C') {
        vector<char> right_word_vec;
        vector<char> tries[5];
        string guess;
        string right_word;
        int guess_count = 1;
    
        system("clear");

        cin >> right_word;

        for (int i = 0; i < right_word.length(); ++i)
        {
            right_word_vec.push_back(right_word[i]);
        }

        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                tries[i].push_back(' ');
            }
        }

        system("clear");
    
        printing_right_word(right_word_vec);
        cout << "\n" << endl;
        for (int i = 0; i < 5; ++i)
        {
            print_tries(tries[i]);
            printline();
        }
        cout << "\n";
        cout << "Enter guess (" << guess_count << " of 5): ";
        cin >> guess;

        system("clear");

        while(guess != right_word && guess_count < 5)
        {
            system("clear");
            tries[guess_count-1].clear();
            for (int i = 0; i < 5; ++i)
            {
                tries[guess_count-1].push_back(guess[i]);
            }
            ++guess_count;
            printing_right_word(right_word_vec);
            cout << "\n" << endl;
            for (int i = 0; i < 5; ++i)
            {
                print_tries(tries[i]);
                printline();
            }
            cout << "\n";
            cout << "Enter guess (" << guess_count << " of 5): ";
            cin >> guess;
        }

        if (guess == right_word)
        {
            system("clear");

            tries[guess_count-1].clear();
            for (int i = 0; i < 5; ++i)
            {
                tries[guess_count-1].push_back(guess[i]);
            }
            printing_right_word(right_word_vec);
            cout << "\n" << endl;
            for (int i = 0; i < 5; ++i)
            {
                print_tries(tries[i]);
                printline();
            }
            cout << "\n";
            int Play_count = 1;
            if(Play_count != 99){
                char decision;
                cout << "YOU HAD GUESSED"<< Play_count <<"TIMES" << endl << endl;
                cout << "YOU GUESSED THE RIGHT WORD! NEXT LEVEL?" << endl << endl;
                cout << "Press C to continue / E to exit: ";
                cin >> decision;
                ++Play_count;
                else{
                    // Create an ifstream object and open the file
                    ifstream easter_egg_file("Easter_egg.txt");

                    // Check if the file was successfully opened
                    if (easter_egg_file.is_open()) {
                    // If yes, use a loop to read and print each line of the file
                        string line;
                        while (getline(easter_egg_file, line)) {
                        cout << line << endl;
                        }
                    // Close the file
                    easter_egg_file.close();
        }
    }                    

    return 0;
}
