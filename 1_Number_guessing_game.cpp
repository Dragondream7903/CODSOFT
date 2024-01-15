#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed for random number generation
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;

    // Variables to store user input and track guesses
    int guess, attempts = 0;

    // Game loop
    do {
        // Get user input
        std::cout << "Guess the number (between 1 and 100): ";
        std::cin >> guess;

        // Provide feedback
        if (guess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number in " << attempts + 1 << " attempts.\n";
        }

        // Increment attempts
        attempts++;

    } while (guess != secretNumber);

    return 0;
}
