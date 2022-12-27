/* Nim Game -- Reese Chahal 2022 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pile1, pile2, pile3;

void startPiles() {
    pile1 = (rand() % 10) + 1;
    pile2 = (rand() % 10) + 1;
    pile3 = (rand() % 10) + 1;
}



void userMove() {
    int movePile, moveAmount;

    printf("Choose a pile: ");
    scanf("%d", &movePile);

    while (movePile <=0 || movePile>=4) {
        if (movePile >= 4 || movePile<= 0)
        {
            printf("Invalid pile !\n");
            printf("Choose a pile: ");
            scanf("%d", &movePile);


        } else if (moveAmount < 0 ) {
            printf("Invalid move !\n");
            printf("Choose another move: ");
            scanf("%d", &moveAmount);
        }
    }


    printf("How many to remove from pile %d: ", movePile);
    scanf("%d", &moveAmount);

    if (movePile < 1 || movePile > 3) {
        printf("invalid pile choice!\n");
        //repeat error check
    }

    else if (moveAmount < 1) {
        printf("you must take at least one.\n");
        userMove();
    }


    else if (movePile == 1 && moveAmount > pile1) {
        printf("Pile 1 doesn't have that many.\n");
        userMove();
    } else if (movePile == 2 && moveAmount > pile2) {
        printf("Pile 2 doesn't have that many.\n");
        userMove();
    } else if (movePile == 3 && moveAmount > pile3) {
        printf("Pile 3 doesn't have that many.\n");
        userMove();

    } else {
        if (movePile == 1) {
            pile1 -= moveAmount;
        } else if (movePile == 2) {
            pile2 -= moveAmount;
        } else if (movePile == 3) {
            pile3 -= moveAmount;
        }
    }
}



void computerMove() {
    int movePile = (rand() % 3) + 1;
    int moveAmount = (rand() % 3) + 1;

    if (movePile == 1 && moveAmount > pile1) {
        computerMove();
    } else if (movePile == 2 && moveAmount > pile2) {
        computerMove();
    } else if (movePile == 3 && moveAmount > pile3) {
        computerMove();
    } else {
        if (movePile == 1) {
            pile1 -= moveAmount;
        } else if (movePile == 2) {
            pile2 -= moveAmount;
        } else if (movePile == 3) {
            pile3 -= moveAmount;
        }
        printf("Computer took %d from pile %d.\n", moveAmount, movePile);
    }
}



int main()
{
    srand(time(NULL));

    startPiles();

    while (pile1 > 0 || pile2 > 0 || pile3 > 0)
    {
        printf("Pile 1: %d  Pile 2: %d  Pile 3: %d\n", pile1, pile2, pile3);
        userMove();

        if (pile1 <= 0 && pile2 <= 0 && pile3 <= 0)
        {
            printf("You lost.\n");
        } else {
            computerMove();
            if (pile1 <= 0 && pile2 <= 0 && pile3 <= 0)
            {
                printf("Computer lost, you win!\n");
            }
        }
    }

    return 0;
}



