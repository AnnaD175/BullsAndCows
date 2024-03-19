#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    int ch;
    int secretNumber[4], secretNumber1[4], secretNumber2[4];
    int guessNumber[4], guessNumber1[4], guessNumber2[4];
    int bulls, cows, attempts, bulls1, bulls2, cows1, cows2;
    printf("���� -���� � ������-\n");
    do
    {
        printf_s("�������� ������� ����:\n1 - ������ ����������\n2 - ���� ����� ������ �������\n");
        scanf_s("%d", &ch);
        printf("-------------------------------\n");
        switch (ch)
        {
        case 1:
            srand(time(0));
            Random(secretNumber);

            printf("��������� ������� �����. ���������� �������� ��� (�������������� ����� � ������� �������).\n");

            attempts = 0;
            do {
                bulls = 0;
                cows = 0;

                printf("������� ���� �������������: ");
                scanf_s("%1d%1d%1d%1d", &guessNumber[0], &guessNumber[1], &guessNumber[2], &guessNumber[3]);

                BullsAndCows(guessNumber, secretNumber, &bulls, &cows);


                attempts++;
                printf("�����: %d, �����: %d\n", bulls, cows);
                printf("-------------------------------\n");

            } while (bulls < 4);

            printf("�����������! �� �������� ����� �� %d �������.\n", attempts);

            break;
        case 2:
            srand(time(0));
            Random(secretNumber1);

            Random(secretNumber2);
            attempts = 0;
            do {
                bulls1 = 0;
                cows1 = 0;

                printf("��� ������ 1\n");
                printf("������� ���� �������������: ");
                scanf_s("%1d%1d%1d%1d", &guessNumber1[0], &guessNumber1[1], &guessNumber1[2], &guessNumber1[3]);

                BullsAndCows(guessNumber1, secretNumber1, &bulls1, &cows1);

                printf("�����: %d, �����: %d\n", bulls1, cows1);
                printf("-------------------------------\n");

                bulls2 = 0;
                cows2 = 0;

                printf("��� ������ 2\n");
                printf("������� ���� �������������: ");
                scanf_s("%1d%1d%1d%1d", &guessNumber2[0], &guessNumber2[1], &guessNumber2[2], &guessNumber2[3]);

                BullsAndCows(guessNumber2, secretNumber2, &bulls2, &cows2);

                printf("�����: %d, �����: %d\n", bulls2, cows2);
                printf("-------------------------------\n");
                attempts++;

            } while (bulls1 < 4 && bulls2 < 4);

            if ((bulls1 + bulls2) == 8)
            {
                printf("�����, ��� ������ �������� ����� �� %d �������", attempts);
            }
            else {
                if (bulls1 == 4)
                {
                    printf("������� 1 ����� �� %d �������", attempts);
                }
                if (bulls2 == 4)
                {
                    printf("������� 2 ����� �� %d �������", attempts);
                }
            }
            break;
        default: printf("error");
        }
    } while (0 >= ch || ch > 2);

    return 0;
}