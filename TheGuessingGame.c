#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void displayRules();
int getValidAmount(int balance, char playerName[]);
int getValidGuess();
void clearScreen();

int main() {
    char playerName[50];    // Increased size to handle longer names
    int balance;            // Player's balance
    int placingAmount;      // Bet amount
    int guess;              // Player's guess
    int dice;               // Randomly generated number
    char choice;

    // Seed the random number generator
    srand(time(0));

    printf("\n\t\t======== WELCOME TO THE GUESSING GAME ========\n\n");
    printf("What's your Name: ");
    fgets(playerName, sizeof(playerName), stdin);
    playerName[strcspn(playerName, "\n")] = '\0'; // Remove trailing newline

    // Get initial balance
    do {
        printf("Enter the starting balance to play the game (must be greater than 0): Cr ");
        if (scanf("%d", &balance) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n'); // clear input buffer
            balance = 0; // force re-entry
        }
        if (balance <= 0)
            printf("Starting balance must be greater than 0!\n");
    } while (balance <= 0);

    do {
        clearScreen();
        displayRules();
        printf("\nYour current balance: %d Cr\n", balance);

        // Get valid placing amount from the user
        placingAmount = getValidAmount(balance, playerName);

        // Get valid guess from the user
        guess = getValidGuess();

        // Generate random dice number between 1 and 10
        dice = rand() % 10 + 1;

        // Check if the player guessed correctly
        if (dice == guess) {
            printf("\nYou are in luck!! You won %d Cr\n", placingAmount * 10);
            balance += placingAmount * 10;
        } else {
            printf("Oops, better luck next time! You lost %d Cr\n", placingAmount);
            balance -= placingAmount;
        }

        printf("The winning number was: %d\n", dice);
        printf("%s, your current balance is: %d Cr\n", playerName, balance);

        // Check if player still has balance to play
        if (balance == 0) {
            printf("You have no credits left to play.\n");
            break;
        }

        // Ask if the player wants to play again
        do {
            printf("\nDo you want to play again? (y/n): ");
            scanf(" %c", &choice);
            if (choice != 'y' && choice != 'n') {
                printf("Invalid choice! Please enter 'y' or 'n'.\n");
            }
        } while (choice != 'y' && choice != 'n');

    } while (choice == 'y');

    printf("\nThanks for playing, %s! Your final balance is %d Cr\n", playerName, balance);
    return 0;
}

// Function to display the game rules
void displayRules() {
    printf("\n================== RULES ==================\n");
    printf("1. Choose any number between 1 to 10.\n");
    printf("2. If you guess correctly, you'll win 10 times your placing amount.\n");
    printf("3. If you guess incorrectly, you'll lose your placing amount.\n");
    printf("4. You can quit anytime if you wish to stop playing.\n");
    printf("===========================================\n");
}

// Function to get a valid placing amount from the player
int getValidAmount(int balance, char playerName[]) {
    int placingAmount;
    do {
        printf("Hey, %s, enter the credits you would like to place: Cr ", playerName);
        if (scanf("%d", &placingAmount) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n'); // clear input buffer
            placingAmount = 0; // force re-entry
        }
        if (placingAmount <= 0) {
            printf("Placing amount must be greater than 0!\n");
        } else if (placingAmount > balance) {
            printf("Placing amount cannot be more than your current balance!\n");
        }
    } while (placingAmount <= 0 || placingAmount > balance);
    return placingAmount;
}

// Function to get a valid guess from the player
int getValidGuess() {
    int guess;
    do {
        printf("Guess a number between 1 and 10: ");
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter a valid number between 1 and 10.\n");
            while (getchar() != '\n'); // clear input buffer
            guess = 0; // force re-entry
        }
        if (guess < 1 || guess > 10) {
            printf("Invalid guess! Number should be between 1 and 10.\n");
        }
    } while (guess < 1 || guess > 10);
    return guess;
}

// Function to clear the screen
void clearScreen() {
    // Clear screen command for different operating systems
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}
