#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Calling functions on top to remove warnings!
void amanFunction(int rendomNum,int choise,char* name,int amanScore, int userScore);
void userFunction(int rendomNum,int choise,char* name,int userScore,int amanScore);
void displayInstructions();

int main() {
    srand(time(0));// Using time to make random values.
    char name[100];
    int startChoice;
    int randomNumMain = (rand() % 2) + 1;// Saving rendom value fro choise 1, 2 or 3 On main menu.
    int choise;
    int userScore = 0;
    int amanScore = 0;
    int rendomNum;// This value i gona use on amanFunction and userFunction.

    printf("\nWelcome main menu for the Odd-Even Game!\n");
    printf("I am Aman, I am you opponent in this game.\n\n");
    printf("Please enter your fist name: ");
    scanf("%s", name);
    printf("\n\nOk, %s, Shall we start the game?\n", name);
    printf("1: Start\n2: No, I want to exit!\n3: Help, I don't know how to play.\n");
    printf("\nEnter your choice: ");
    scanf("%d", &startChoice);

    // Choising Main menu options.
    if (startChoice == 1) {
        // Start statement
        printf("\nGreat! Let's begin.\n\n");

        switch (randomNumMain) {
            case 1:
            printf("%s is the main player.", name);
            // Colling user input and output function.
            userFunction(rendomNum, choise, name, userScore, amanScore);
            break;
            case 2:
            // Colling Aman output function.
            printf("\nAman is the main player.");
            amanFunction(rendomNum, choise, name, amanScore, userScore);
            break;
            default:
                printf("Error : Random value generated wrong!\nExiting game.");
        }

    }
    else if (startChoice == 2) {
        // Exit statement
        printf("Okay, maybe next time. Goodbye!\n");
    }
    else if (startChoice == 3) {
        // Help statement
        printf("\n\nGame's instructions\n");
        displayInstructions();
    }
    else {
        // Error statement
        printf("Invalid choice. Exiting the game.\n");
    }
    return 0;
}


// User input and output function
void userFunction(int rendomNum,int choise,char* name,int userScore,int amanScore) {

     // User's turn.
    do {
        rendomNum = (rand() % 10) + 1;
        printf("\nEnter you number : ");
        scanf("%d", &choise);
        printf("\nAman = %d\n", rendomNum);
        printf("%s = %d\n", name, choise);
        userScore = userScore+(rendomNum+choise);
    } while (rendomNum != choise);

    printf("\n\n%s's totale score is \"%d\".\n", name, userScore);

    // Aman's turn.
    do {
        printf("\n\n\nNow Aman is the main player.");
        rendomNum = (rand() % 10) + 1;
        printf("\nEnter you number : ");
        scanf("%d", &choise);
        printf("\nAman = %d\n", rendomNum);
        printf("%s = %d\n", name, choise);
        amanScore = amanScore+(rendomNum+choise);
    } while (rendomNum != choise);

        printf("\n\nAman's totale score is \"%d\".\n", amanScore);

    // Result if user's win.
    if (amanScore < userScore) {
        printf("\n\n\n/==========================================================/");
        printf("\n\nAman loose! With\n");
        printf("%s's loose! :(\n", name);
        printf("\nTotal score of Aman : %d", amanScore);
        printf("\nTotal score of %s : %d\n\n", name, userScore);

    // Result if Aman's win.
    } else if (amanScore > userScore) {
        printf("\n\n\n/==========================================================/");
        printf("\n\nAman Win!!\n");
        printf("%s's loose! :(\n", name);
        printf("\nTotal score of Aman : %d", amanScore);
        printf("\nTotal score of %s : %d\n\n", name, userScore);

    } else {
        // Error statement
        printf("Error : Exiting game.");
    }
}


// Aman generated outputs function
void amanFunction(int rendomNum,int choise,char* name,int amanScore, int userScore) {

    // Aman's turn.
    do {
        rendomNum = (rand() % 10) + 1;
        printf("\nEnter you number : ");
        scanf("%d", &choise);
        printf("\nAman = %d\n", rendomNum);
        printf("%s = %d\n", name, choise);
        amanScore = amanScore+(rendomNum+choise);
    } while (rendomNum != choise);

        printf("\n\naman's totale score is %d\n", amanScore);
        printf("\n\n\nNow %s is the main player.", name);

    // User's turn.
    do {
        rendomNum = (rand() % 10) + 1;
        printf("\nEnter you number : ");
        scanf("%d", &choise);
        printf("\nAman = %d\n", rendomNum);
        printf("%s = %d\n", name, choise);
        userScore = userScore+(rendomNum+choise);
    } while (rendomNum != choise);
    
    printf("\n\n%s's totale = %d\n", name, userScore);

    // Result if Aman's win.    
    if (amanScore < userScore) {
        printf("\n/==========================================================/");
        printf("\nAman's loose! With\n");
        printf("%s's loose! :(\n", name);
        printf("\nTotal score of Aman : %d", amanScore);
        printf("\nTotal score of %s : %d\n\n", name, userScore);
    }
    // Result if user's win.
    else if (amanScore > userScore) {
        printf("\n/==========================================================/");
        printf("\nAman's Win!!\n");
        printf("%s's loose! :(\n", name);
        printf("\nTotal score of Aman : %d", amanScore);
        printf("\nTotal score of %s : %d\n\n", name, userScore);
    }
    else {
        // Error statement
        printf("Error : Exiting game.");
    }

}


// Display game instructions.
void displayInstructions() {
    printf("\nGame Instructions:\n");
    printf("1. The game is played between You and Aman.\n");
    printf("2. You and Aman take turns entering a number.\n");
    printf("3. A random number will also be generated by the computer for each turn.\n");
    printf("4. If your number matches the computer's number, you score a point.\n");
    printf("5. The game continues until you or Aman matches the computer's number.\n");
    printf("6. The player with the highest score wins.\n");
}
