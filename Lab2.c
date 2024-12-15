//********************************************************
// Lab2.c
// Author: Lorenzo Wyman
// UCFID: 5464079
// Class: COP 3223, Professor Parra
// Date: 9/10/24
// Purpose: This program is a randomized number game that randomizes a number and allows the user three (3) attempts at guessing the number before revealing the number at the end of their last attempt.
// Input: The only user input required are positive whole numbers, or integers.
//
// Output: (to the command line) A prompt asking the user to guess the randomized number three (3) times, prompts based on them guessing too high, low or guessing correctly.
// //********************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declares the function for the number generator before the rest of the program so there are no compiler errors

int numberGenerator() {

    return (rand() % 10) + 1;

}

// This function handles the loop with a if statement for the user's guess and depending on the guess, the appropiate output will be printed.
// After the loop runs 3 times, the program will stop; it is also increasing by 1 everytime the last loop was run.

int guessAttempt(int actualNum)
{
    int userGuess;
    int result;

    for (int i = 1; i <= 3; i++) {

        printf("Enter your guess: ");

        result = scanf("%d", &userGuess);

// If the user enters any character besides a number, the prompt will display a message and also have an offset to give them another try (line 45-47).

        if (result != 1){

            printf("The character types 'A' or '/' are not valid. Please enter a number. \n");

            while(getchar() != '\n');
            i--;
            continue;
        }

        if (userGuess == actualNum) {

            printf("Congratulations! You guessed the number.\n");

            return 0;

        }    

        if (userGuess < actualNum) {

            printf("Too low! Try again.\n");

        }

        else {

            printf("Too high! Try again.\n");
        }   
    }

         printf("Sorry, you've used all of your attempts. The number was: %d\n", actualNum);

    return 1;
}

// This function holds the srand() function to declare the time aswell declare the variable for the randomized number (actualNum).
// 

int main() 
{
    srand(time(0));

    int actualNum = numberGenerator();

    printf("Guess the number (between 1 and 10). You have 3 attempts.\n");

    guessAttempt(actualNum);

    return 0;
}

