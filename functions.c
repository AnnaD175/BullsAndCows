#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>

void Random(int* secretNumber) 
{
    do {
        secretNumber[0] = rand() % 9 + 1;
        secretNumber[1] = rand() % 10;
        secretNumber[2] = rand() % 10;
        secretNumber[3] = rand() % 10;
    } while (secretNumber[0] == secretNumber[1] || secretNumber[0] == secretNumber[2] || secretNumber[0] == secretNumber[3] || secretNumber[1] == secretNumber[2] || secretNumber[1] == secretNumber[3] || secretNumber[2] == secretNumber[3]);

}


int TTrueNum(char GuessNum[]) 
{
    int i;
    for (i = 0; i < strlen(GuessNum); i++) {
        if (!isdigit(GuessNum[i])) {
            printf("Ошибка: введенное значение не является числом.\n");
            return 0;
        }
    }
    return 1;
}

int Inputt()
{
    char GuessNum[10];
    scanf_s("%s", &GuessNum, sizeof(GuessNum));
    while (!(TTrueNum(GuessNum)))
    {
        printf("Повторите ввод: ");
        scanf_s("%s", &GuessNum, sizeof(GuessNum));
    }
    return atoi(GuessNum);
}


int TrueNum(int guessNum, int guess[], char GuessNum[])
{

    while (!(guessNum >= 1000 && guessNum <= 9999))
    {
        printf("Вы ввели не четырехзначное число, повторите ввод: ");
        guessNum = Inputt();
    }
    if (guessNum >= 1000 && guessNum <= 9999)
    {
        guess[0] = guessNum / 1000; guess[1] = (guessNum % 1000) / 100; guess[2] = (guessNum % 100) / 10; guess[3] = guessNum % 10;
        while (guess[0] == guess[1] || guess[0] == guess[2] || guess[0] == guess[3] || guess[1] == guess[2] || guess[1] == guess[3] || guess[2] == guess[3])
        {
            printf("Вы ввели некорректное число, все цифры в числе должны быть различны, повторите ввод: ");
            guessNum = Inputt();
            while (!(guessNum >= 1000 && guessNum <= 9999))
            {
                printf("Вы ввели не четырехзначное число, повторите ввод: ");
                guessNum = Inputt();
            }
            guess[0] = guessNum / 1000; guess[1] = guessNum % 1000 / 100; guess[2] = guessNum % 100 / 10; guess[3] = guessNum % 10;
        }
    }
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