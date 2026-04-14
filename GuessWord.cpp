#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


//comment
void displayMenu() {
    cout << "========================\n";
    cout << "      GUESS A WORD      \n";
    cout << "========================\n";
    cout << "1. Start Game\n";
    cout << "2. View Rules\n";
    cout << "3. Exit\n";
    cout << "========================\n";
}

void viewRules() {

    cout << "\n========== RULES ==========\n";
    cout << "1. The game is played by two players.\n";
    cout << "2. Players take turns guessing the word.\n";
    cout << "3. A coin toss decides who goes first.\n";
    cout << "4. Each player gets 5 chances to guess.\n";
    cout << "5. The player with the most correct guesses wins.\n";
    cout << "6. In case of a tie, a sudden death round will be played.\n";
    cout << "7. Have fun and play fair!\n";
    cout << "==========================\n";
    system("read -p 'Press ENTER to return to the menu...' var");

}

void startGame() {
    string player01, player02;
    int player01Score = 0, player02Score = 0;
    bool coin, tossResult;

    const string words[] = {"apple", "banana", "cherry", "grape", "orange"};
    const int wordsSize = sizeof(words) / sizeof(words[0]);

    cout << "Please Enter Player01 Name : ";
    cin >> player01;


    cout << "Please Enter Player02 Name : ";
    cin >> player02;


    cout << "=============================" << endl;
    cout << player01 << ", please select 0 for Head & 1 for Tail: ";
    while (!(cin >> coin) || (coin != 0 && coin != 1)) {
        cout << "Invalid input. Please enter 0 for Head or 1 for Tail: ";

    }


    srand(time(0));
    tossResult = rand() % 2;

    cout << "Tossing the coin...\n";

    string currentPlayer="";
    if(coin == tossResult)
    currentPlayer=player01;
    else
    currentPlayer=player02;

    cout << "Congratulations, " << currentPlayer << "! You will start the game.\n";
    cout << "=============================" << endl;

    // Game logic
    for (int round = 0; round < 2; ++round) {
        cout << "It's " << currentPlayer << "'s turn!\n";
        string word = words[rand() % wordsSize];
        string guessedWord(word.length(), '_');
        int attempts = 5;

        cout << "The word has " << word.length() << " letters: " << guessedWord << "\n";

        while (attempts > 0) {
            char guess;
            cout << currentPlayer << ", enter a character: ";
            while (!(cin >> guess) || !isalpha(guess)) {
                cout << "Invalid input. Please enter a single alphabetic character: ";

            }

            guess = tolower(guess);
            bool correctGuess = false;
            for (int i = 0; i < word.length(); ++i) {
                if (word[i] == guess && guessedWord[i] == '_') {
                    guessedWord[i] = guess;
                    correctGuess = true;
                }
            }

            if (correctGuess) {
                cout << "Correct! The word now: " << guessedWord << "\n";
                if (guessedWord == word) {
                    cout << "Congratulations, " << currentPlayer << "! You guessed the word.\n";
                    if (currentPlayer == player01)
                        ++player01Score;
                    else
                        ++player02Score;
                    break;
                }
            } else {
                cout << "Incorrect guess. Try again!\n";
                --attempts;
            }
        }

        if (guessedWord != word) {
            cout << "Out of attempts! The word was: " << word << "\n";
        }

        if (currentPlayer == player01) {
            currentPlayer = player02;
        } else {
            currentPlayer = player01;
        }

    }

    cout << "\nFinal Scores:\n";
    cout << player01 << ": " << player01Score << "\n";
    cout << player02 << ": " << player02Score << "\n";

    if (player01Score > player02Score) {
        cout << "Congratulations, " << player01 << "! You are the winner!\n";
    } else if (player02Score > player01Score) {
        cout << "Congratulations, " << player02 << "! You are the winner!\n";
    } else {
        cout << "It's a tie! Great effort by both players!\n";
    }
}

int main() {
    int choice;
    while (true) {
        displayMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;


        switch (choice) {
        case 1:
            startGame();
            break;
        case 2:
            viewRules();
            break;
        case 3:
            cout << "Exiting the game. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 3.\n\n\n";
            break;
        }
    }
    return 0;
}
