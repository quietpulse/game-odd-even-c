#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Calling functions on top to remove warnings!
// This is just a testing comment
void aiFunction(int randomNum, int choice, char* name, int aiScore, int userScore);
void userFunction(int randomNum, int choice, char* name, int userScore, int aiScore);
void displayInstructions();

int main() {
    srand(time(0)); // Using time to generate random values.
    char name[100];
    int startChoice;
    int randomNumMain = (rand() % 2) + 1; // Saving random value for choice 1 or 2 on main menu.
    int choice;
    int userScore = 0;
    int aiScore = 0;
    int randomNum; // This value is used in aiFunction and userFunction.

    printf("\nWelcome to the Number Guessing Game Main Menu!\n");
    printf("I am Ai, your opponent in this game.\n\n");
    printf("Please enter your first name: ");
    scanf("%s", name);
    printf("\n\nOkay, %s, shall we start the game?\n", name);
    printf("1: Start\n2: No, I want to exit!\n3: Help, I don't know how to play.\n");
    printf("\nEnter your choice: ");
    scanf("%d", &startChoice);

    // Choosing main menu options.
    if (startChoice == 1) {
        // Start statement
        printf("\nGreat! Let's begin.\n\n");

        switch (randomNumMain) {
            case 1:
                printf("%s is the main player.\n", name);
                // Calling user input and output function.
                userFunction(randomNum, choice, name, userScore, aiScore);
                break;
            case 2:
                // Calling Ai's output function.
                printf("\nAi is the main player.\n");
                aiFunction(randomNum, choice, name, aiScore, userScore);
                break;
            default:
                printf("Error: Random value generated incorrectly!\nExiting the game.\n");
        }
    }
    else if (startChoice == 2) {
        // Exit statement
        printf("Okay, maybe next time. Goodbye!\n");
    }
    else if (startChoice == 3) {
        // Help statement
        printf("\n\nGame Instructions:\n");
        displayInstructions();
    }
    else {
        // Error statement
        printf("Invalid choice. Exiting the game.\n");
    }
    return 0;
}

// User input and output function
void userFunction(int randomNum, int choice, char* name, int userScore, int aiScore) {
    // User's turn.
    do {
        randomNum = (rand() % 10) + 1;
        printf("\nEnter your number: ");
        scanf("%d", &choice);
        printf("\nAi = %d\n", randomNum);
        printf("%s = %d\n", name, choice);
        userScore = userScore + (randomNum + choice);
    } while (randomNum != choice);

    printf("\n\n%s's total score is \"%d\".\n", name, userScore);

    // Ai's turn.
    do {
        printf("\n\n\nNow Ai is the main player.");
        randomNum = (rand() % 10) + 1;
        printf("\nEnter your number: ");
        scanf("%d", &choice);
        printf("\nAi = %d\n", randomNum);
        printf("%s = %d\n", name, choice);
        aiScore = aiScore + (randomNum + choice);
    } while (randomNum != choice);

    printf("\n\nAi's total score is \"%d\".\n", aiScore);

    // Result if user wins.
    if (aiScore < userScore) {
        printf("\n\n\n/==========================================================/");
        printf("\n\nAi loses!\n");
        printf("%s wins! :)\n", name);
        printf("\nTotal score of Ai: %d", aiScore);
        printf("\nTotal score of %s: %d\n\n", name, userScore);
    }
    // Result if Ai wins.
    else if (aiScore > userScore) {
        printf("\n\n\n/==========================================================/");
        printf("\n\nAi Wins!!\n");
        printf("%s loses! :(\n", name);
        printf("\nTotal score of Ai: %d", aiScore);
        printf("\nTotal score of %s: %d\n\n", name, userScore);
    }
    else {
        // Error statement
        printf("Error: Exiting the game.\n");
    }
}

// Ai's generated outputs function
void aiFunction(int randomNum, int choice, char* name, int aiScore, int userScore) {
    // Ai's turn.
    do {
        randomNum = (rand() % 10) + 1;
        printf("\nEnter your number: ");
        scanf("%d", &choice);
        printf("\nAi = %d\n", randomNum);
        printf("%s = %d\n", name, choice);
        aiScore = aiScore + (randomNum + choice);
    } while (randomNum != choice);

    printf("\n\nAi's total score is %d.\n", aiScore);
    printf("\n\n\nNow %s is the main player.", name);

    // User's turn.
    do {
        randomNum = (rand() % 10) + 1;
        printf("\nEnter your number: ");
        scanf("%d", &choice);
        printf("\nAi = %d\n", randomNum);
        printf("%s = %d\n", name, choice);
        userScore = userScore + (randomNum + choice);
    } while (randomNum != choice);

    printf("\n\n%s's total score is %d.\n", name, userScore);

    // Result if Ai wins.
    if (aiScore < userScore) {
        printf("\n/==========================================================/");
        printf("\nAi loses!\n");
        printf("%s wins! :)\n", name);
        printf("\nTotal score of Ai: %d", aiScore);
        printf("\nTotal score of %s: %d\n\n", name, userScore);
    }
    // Result if user wins.
    else if (aiScore > userScore) {
        printf("\n/==========================================================/");
        printf("\nAi Wins!!\n");
        printf("%s loses! :(\n", name);
        printf("\nTotal score of Ai: %d", aiScore);
        printf("\nTotal score of %s: %d\n\n", name, userScore);
    }
    else {
        // Error statement
        printf("Error: Exiting the game.\n");
    }
}

// Display game instructions.
void displayInstructions() {
    printf("1. The game is played between You and Ai.\n");
    printf("2. You and Ai take turns entering a number.\n");
    printf("3. A random number will also be generated by the computer for each turn.\n");
    printf("4. If your number matches the computer's number, you score a point.\n");
    printf("5. The game continues until you or Ai matches the computer's number.\n");
    printf("6. The player with the highest score wins.\n");
}
