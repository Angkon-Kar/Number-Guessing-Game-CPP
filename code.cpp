#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1; 
    int choice;
    int chances = 0;
    string difficultyName;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I'm thinking of a number between 1 and 100.\n\n";

    cout << "Please select the difficulty level:\n";
    cout << "1. Easy (10 chances)\n";
    cout << "2. Medium (5 chances)\n";
    cout << "3. Hard (3 chances)\n\n";

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            chances = 10;
            difficultyName = "Easy";
            break;
        case 2:
            chances = 5;
            difficultyName = "Medium";
            break;
        case 3:
            chances = 3;
            difficultyName = "Hard";
            break;
        default:
            cout << "Invalid choice! Defaulting to Medium (5 chances).\n";
            chances = 5;
            difficultyName = "Medium";
    }

    cout << "\nGreat! You have selected the " << difficultyName << " difficulty level.\n";
    cout << "Let's start the game!\n\n";

    int guess;
    int attempts = 0;
    bool guessedCorrectly = false;

    while (chances > 0) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
            guessedCorrectly = true;
            break; // Thik guess korle loop theke ber hoye jabe
        } 
        else if (guess > secretNumber) {
            cout << "Incorrect! The number is less than " << guess << ".\n\n";
        } 
        else {
            cout << "Incorrect! The number is greater than " << guess << ".\n\n";
        }

        chances--;
    }

    if (!guessedCorrectly) {
        cout << "Game Over! You ran out of chances. The correct number was " << secretNumber << ".\n";
    }

    return 0;
}