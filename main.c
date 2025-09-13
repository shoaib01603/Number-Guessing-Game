#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int number, guess, attempts, max_attempts, play = 1;
    char name[50];
    int difficulty;
    char choice;

    srand(time(0));

    printf("🎮 Welcome to the Number Guessing Game!\n");
    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    while (play) {
        printf("\nHello %s! Choose a difficulty level:\n", name);
        printf("1. Easy   (15 attempts)\n");
        printf("2. Medium (10 attempts)\n");
        printf("3. Hard   (5 attempts)\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &difficulty);

        while ((getchar()) != '\n');

        if (difficulty == 1)
            max_attempts = 15;
        else if (difficulty == 2)
            max_attempts = 10;
        else
            max_attempts = 5;

        number = rand() % 100 + 1;
        attempts = 0;

        printf("\nGuess a number between 1 and 100.\n");
        printf("You have a maximum of %d attempts.\n\n", max_attempts);

        do {
            printf("Enter your guess: ");
            scanf("%d", &guess);
            attempts++;

            if (guess > number) {
                printf("Too high! Try again.\n");
            } else if (guess < number) {
                printf("Too low! Try again.\n");
            } else {
                printf("\n🎉 Congratulations %s! You guessed the number in %d attempts!\n", name, attempts);
                break;
            }

            if (attempts == max_attempts) {
                printf("\n❌ You've used all your attempts. The number was %d.\n", number);
                break;
            }

        } while (1);

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &choice);

        while ((getchar()) != '\n');

        if (choice != 'y' && choice != 'Y') {
            play = 0;
            printf("\nThanks for playing, %s! Goodbye!\n", name);
        }
    }

    return 0;
}
