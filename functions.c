#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void Random(int* secretNumber)
{
    do {
        secretNumber[0] = rand() % 9 + 1;
        secretNumber[1] = rand() % 10;
        secretNumber[2] = rand() % 10;
        secretNumber[3] = rand() % 10;
    } while (secretNumber[0] == secretNumber[1] || secretNumber[0] == secretNumber[2] || secretNumber[0] == secretNumber[3] || secretNumber[1] == secretNumber[2] || secretNumber[1] == secretNumber[3] || secretNumber[2] == secretNumber[3]);

}

void BullsAndCows(int* guessNumber, int* secretNumber, int* bulls, int* cows)
{

    for (int i = 0; i < 4; i++) {
        if (guessNumber[i] == secretNumber[i]) {
            (*bulls)++;
        }
        else {
            for (int j = 0; j < 4; j++) {
                if (guessNumber[i] == secretNumber[j]) {
                    (*cows)++;
                    break;
                }
            }
        }
    }

}