# README.md for ENGG1340 Group Project - Group 37

## Team Members
- **Chan Shun Hei**
- **Cheung Man Hin**
- **Park Ji Ho**
- **Wong Hei Long**
- **Yik Yu Hang**

## Description of the Game: Wordle
Wordle is a word puzzle game where players have six attempts to guess a target word. Each guess provides feedback in the form of colored tiles, indicating when letters match or occupy the correct position.

## introduce the game rules of our own wordle.
In Wordle, players receive three types of feedback after each guess: a letter in the correct position indicates that the letter is both correct and properly placed; a "+" sign means the letter is correct but in the wrong spot; and no feedback signifies an incorrect letter. Players win by correctly guessing the word.

After playing, participants can view their scores and streaks by selecting option 2 from the menu. Each correct guess awards 10 points. Successive correct guesses contribute to a winning streak. Upon achieving five consecutive wins, players will see a special gift. However, failing to guess the word within six attempts resets the streak to zero, though the overall score remains unaffected. You can exit the code wile gameplay by pressing "0" and you can completely terminate the game by selecting option 4 from the menu.

## Implemented Features
1. **Generation of Random Game Sets or Events**
   - The game randomly selects a target word from a predefined list each time a new game starts. This feature is crucial for keeping the gameplay experience fresh and engaging.

2. **Data Structures for Storing Game Status**
   - We use STL containers such as `std::vector` to store the list of words and `std::array` or `std::string` for the current game state and guesses. This helps in efficiently managing the game’s state and operations on guesses.

3. **Dynamic Memory Management**
   - Dynamic arrays and STL containers like `std::vector` are used to handle varying amounts of game data (e.g., user guesses, word lists). This allows the game to scale well with different word list sizes and number of user attempts.

4. **File Input/Output**
   - The game includes functionality to load the word list from a file and save game statistics to a file. This feature enhances user experience by allowing persistent data storage across sessions.

5. **Program Codes in Multiple Files (Separate Compilation)**
   - Our project is structured into multiple source files (e.g., `main.cpp`, `difference.cpp`, `select_words.cpp`), each handling a specific aspect of the game. This modular approach aids in maintainability and scalability of the code.

## Support from Coding Elements
- **Proper Indentation and Naming Styles**: All source files use consistent indentation and descriptive naming conventions to enhance readability and ease of maintenance.
- **In-Code Documentation**: Each function and critical section of the codebase is accompanied by comments that explain the purpose and logic, aiding future developers or contributors in understanding the code quickly.

## Non-Standard C/C++ Libraries Used
In your our function and throughout the code, we have not used any non-standard C/C++ libraries. All the libraries we've included are part of the C++ Standard Library, which is a collection of classes and functions, written in the core language. 

## Features Supported by These Libraries
Here are the standard libraries we've used:

iostream: This is a standard header in the C++ Standard Library that provides functionalities for input-output operations. We've used this for standard console I/O operations like std::cout for displaying output to the console and std::cin for reading input from the user.

vector: This is part of the C++ Standard Template Library (STL) and is used to store dynamically resizable arrays. We've used std::vector to manage collections of words and player scores.

string: This standard library provides support for manipulating strings. We've used std::string extensively for handling text data throughout our game.

algorithm: This includes a set of functions especially designed to be used on ranges of elements. We've used functions like std::sort and std::find_if to manipulate data structures for purposes like sorting the scoreboard and finding specific players.

limits: Provides information about the properties of arithmetic types. In our code, it's used with std::numeric_limits<std::streamsize>::max() to handle input errors and clear the input buffer.

fstream: Provides facilities for file handling. We've used std::ifstream to read from files, which is crucial for loading external resources like game instructions, winning messages, and so forth.

cstdlib: This is a standard library in C++ which provides functionality for general purposes including dynamic memory management, random number generation, and system functions. Here, we use it for the rand() function to generate random numbers.

ctime: Also part of the C++ Standard Library, this includes functions and types that provide standardized access to time and date. It is used here for time(NULL) to get the current time, which we then use to seed the random number generator with srand().

cctype: This includes the Standard Library's <cctype> header, which provides functions for character classification and conversion. The function std::tolower used in our code is provided by this header and is used to convert characters to their lowercase equivalents.

sstream: This includes the C++ Standard Library's <sstream> header, which provides string stream classes such as std::stringstream. String streams can be used for reading/writing data from/to strings in memory, similar to how file streams read/write data from/to files.

The ANSI color codes (#define ANSI_COLOR_RED "\x1b[31m", etc.) we've defined simply macro definitions for escape sequences that are widely supported by many terminal emulators to provide colored text output. These are used directly in our code to enhance the visual appeal of the game's console output.

## Compilation and execution instructions
1. g++ -o wordle main.cpp import_words.cpp select_words.cpp to_lower_case.cpp print_char.cpp difference.cpp file_read_until.cpp
2. ./wordle

## Video link

