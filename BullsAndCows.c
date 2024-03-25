#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>

int main() 
{
    setlocale(LC_ALL, "Russian");
    char Ch[10];
    int ch;
    int guessNum, guessNum1, guessNum2;
    char GuessNum[10], GuessNum1[10], GuessNum2[10];
    int secretNumber[4], secretNumber1[4], secretNumber2[4];
    int guessNumber[4], guessNumber1[4], guessNumber2[4];
    int bulls, cows, attempts, bulls1, bulls2, cows1, cows2;
    printf("Игра -Быки и коровы-\n");
    do
    {
        printf_s("Выберите вариант игры:\n1 - против компьютера\n2 - один игрок против другого\n");
        ch = Inputt();
        printf("-------------------------------\n");
        switch (ch)
        {
        case 1:
            srand(time(0));
            Random(secretNumber);

            printf("Компьютер задумал число. Попробуйте отгадать его (четырехзначное число с разными цифрами).\n");

            attempts = 0;
            do {
                bulls = 0;
                cows = 0;

                printf("Введите ваше предположение: ");

                guessNum = Inputt();
                TrueNum(guessNum, &guessNumber);

                BullsAndCows(guessNumber, secretNumber, &bulls, &cows);

                attempts++;
                printf("Быков: %d, коров: %d\n", bulls, cows);
                printf("-------------------------------\n");

            } while (bulls < 4);

            printf("Поздравляем! Вы отгадали число за %d попыток.\n", attempts);

            break;
        case 2:
            srand(time(0));
            Random(secretNumber1);

            Random(secretNumber2);

            printf("Компьютер задумал числа для двух игроков. Попробуйте отгадать их (четырехзначные числа с разными цифрами).\n");

            attempts = 0;
            do {
                bulls1 = 0;
                cows1 = 0;

                printf("Ход игрока 1\n");
                printf("Введите ваше предположение: ");

                guessNum1 = Inputt();
                TrueNum(guessNum1, &guessNumber1);

                BullsAndCows(guessNumber1, secretNumber1, &bulls1, &cows1);

                printf("Быков: %d, коров: %d\n", bulls1, cows1);
                printf("-------------------------------\n");

                bulls2 = 0;
                cows2 = 0;

                printf("Ход игрока 2\n");
                printf("Введите ваше предположение: ");

                guessNum2 = Inputt();

                TrueNum(guessNum2, &guessNumber2);

                BullsAndCows(guessNumber2, secretNumber2, &bulls2, &cows2);

                printf("Быков: %d, коров: %d\n", bulls2, cows2);
                printf("-------------------------------\n");
                attempts++;

            } while (bulls1 < 4 && bulls2 < 4);

            if ((bulls1 + bulls2) == 8)
            {
                printf("Ничья, оба игрока отгадали слова за %d попыток", attempts);
            }
            else {
                if (bulls1 == 4)
                {
                    printf("Выиграл 1 игрок за %d попыток", attempts);
                }
                if (bulls2 == 4)
                {
                    printf("Выиграл 2 игрок за %d попыток", attempts);
                }
            }
            break;
        default: printf("error\n");
        }
    } while (0 >= ch || ch > 2);

    return 0;
}