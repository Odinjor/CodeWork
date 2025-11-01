// Program: Guessing Minigame
// Author: Ugochukwu Odinjor
// Purpose: Replicate an RNG guessing game that resembles your standard RNG loot gussing game while givng users input on their 
// guesses, i.e. whether or not its too high or low, how many guesses they have left, and how many positios were right

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


#define TRIES 8 // Max number of guesses 
#define DIGITS 3 // 3 digit code
#define RANGE 10 // digits can range from 0 to RANGE - 1

// Function to check if input is valid
int isValidInput(const char *input) { 
	if (strlen(input) != DIGITS) return 0;
	for (int i = 0; i < DIGITS; ++i) { 
		if (!isdigit(input[i])) return 0;
	}
	return 1;
}

// Function to generate code
void generateCode(int codeArray[], int *codeValue) {
	*codeValue = 0;
 
	for (int i = 0; i < DIGITS; ++i) { 
		codeArray[i] = rand() % RANGE;
		*codeValue = *codeValue * 10 + codeArray[i];
	}
}

// Funtion to analyze the players guess 
void analyzeGuess(const char *guess, int codeArray[], int *correctPlace, int *correctDigitWrongPlace) {
	int guessDigits[DIGITS];
	int codeUsed[DIGITS] = {0}; // To mark mathced digits in code 
	int guessUsed[DIGITS] = {0}; // To mark matched digits in guess

	for (int i = 0; i < DIGITS; ++i) {
		guessDigits[i] = guess[i] - '0';
	}
	
	// Correct digit and position
	for (int i = 0; i < DIGITS; ++i) { 
		if (guessDigits[i] == codeArray[i]) {// Compares guess with actual code
			(*correctPlace)++;
			codeUsed[i] = 1;
			guessUsed[i] = 1;
		}
	}
	
	// Correct digit, wrong position 
	for (int i = 0; i < DIGITS; ++i) { 
		if (guessUsed[i]) continue;
		for (int j = 0; j < DIGITS; ++j) {
			if (!codeUsed[j] && guessDigits[i] == codeArray[j]) {
				(*correctDigitWrongPlace)++;
				codeUsed[j] = 1;
				break;
			}
		}
	}
}


int main() {
	srand(time(NULL)); // RNG

	int codeArray[DIGITS];
	int codeValue;
	generateCode(codeArray, &codeValue);

	char input[100];
	int attempts = TRIES;
	
	while (attempts > 0) {
		printf("%d tries remaining. What is the code? ", attempts);
        	fgets(input, sizeof(input), stdin);
        	input[strcspn(input, "\n")] = '\0';  // remove newline

        	if (input[0] == 'q' || input[0] == 'Q') {
            		printf("Quitting game. Goodbye!\n");
            		return 0;
        	}

		if (!isValidInput(input)) {
            		printf("Invalid input. Enter a %d-digit number.\n", DIGITS);
            		continue;
        	}

        	int guessValue = atoi(input);

        	if (guessValue == codeValue) {
            		printf("You opened the vault!\n");
            		return 0;
        	}

		if (guessValue > codeValue) {
            		printf("Too high, ");
        	} else {
            		printf("Too low, ");
        	}

        	int correctPlace = 0, correctDigitWrongPlace = 0;
        	analyzeGuess(input, codeArray, &correctPlace, &correctDigitWrongPlace);

        	printf("%d digit/digits are correct and in the right place, %d digit/digits are correct and in the wrong place.\n",
               	correctPlace, correctDigitWrongPlace);

        	attempts--;
    	}

    printf("You failed to open the vault. The correct code was: ");
    for (int i = 0; i < DIGITS; ++i) {
        printf("%d", codeArray[i]);
    }
    printf("\n");

    return 0;
}

