#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Returns: -1 = draw, 1 = user wins, 0 = computer wins
int playRound(char user, char comp) {
    if (user == comp) return -1;
    if ((user == 'r' && comp == 's') ||
        (user == 'p' && comp == 'r') ||
        (user == 's' && comp == 'p'))
        return 1;
    return 0;
}

int main() {
    srand((unsigned)time(NULL));
    char user;
    do {
        // Ask user
        printf("Enter r = Rock, p = Paper, s = Scissors (q to quit): ");
        if (scanf(" %c", &user) != 1) break;
        user = tolower(user);
        if (user == 'q') break;
        if (user != 'r' && user != 'p' && user != 's') {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        // Computer picks
        char options[] = {'r', 'p', 's'};
        char comp = options[rand() % 3];

        // Play
        int res = playRound(user, comp);
        const char *names = "RockPaperScissors"; // mapping indexwise
        printf("You chose: %c, Computer chose: %c — ", user, comp);
        if (res == -1)       printf("It's a draw!\n");
        else if (res == 1)   printf("You win!\n");
        else                 printf("Computer wins!\n");

    } while (1);

    printf("Thanks for playing!\n");
    return 0;
}
