// Programm P8, das die Ziehung der Lottozahlen (6 aus 49) unter Verwendung von Feldern simuliert

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ANZAHL 6
#define MIN_ZAHL 6
#define MAX_ZAHL 49

void tastaturpuffer_leeren();

int main(void)
{
    int tippZahlen[MAX_ANZAHL];
    int lottoZahlen[MAX_ANZAHL];
    int versuch = 0;
    srand((unsigned int)time(0));
    int count = 0;
    int rest = MAX_ANZAHL;
    int gesamtErraten = 0;
    int result;

    // Berechnung der Lottozahlen
    // verhindern, dass eine der Lottozahlen doppelt existiert
    for (int i = 0; i < MAX_ANZAHL; i++)
    {
        lottoZahlen[i] = rand() % (MAX_ZAHL - MIN_ZAHL + 1) + MIN_ZAHL;
        for (int j = 0; j < i; j++)
        {
            if (lottoZahlen[i] == lottoZahlen[j])
            {
                i--;
                break;
            }
        }
    }

    printf("Bitte gebe %d Zahlen zwischen %d und %d als Tipp fuer die Lottozahlen ein.\nBeende jede Zahleingabe mit einem Enter.\n", MAX_ANZAHL, MIN_ZAHL, MAX_ZAHL);

    while (gesamtErraten < MAX_ANZAHL)
    {
        versuch++;
        count = 0;

        // Eingabe der fehlenden Zahlen
        for (int index = 0; index < rest; index++)
        {
            bool unique = false;
            while (!unique)
            {
                result = scanf("%d", &tippZahlen[index]);
                if (result == 0 || tippZahlen[index] < MIN_ZAHL || tippZahlen[index] > MAX_ZAHL)
                {
                    printf("Bitte gebe eine gueltige Zahl zwischen %d und %d ein.\n", MIN_ZAHL, MAX_ZAHL);
                }
                else
                {
                    bool duplicateFound = false;
                    for (int j = 0; j < index; j++)
                    {
                        if (tippZahlen[index] == tippZahlen[j])
                        {
                            printf("Diese Zahl wurde bereits eingegeben. Bitte gebe eine andere Zahl ein.\n");
                            duplicateFound = true;
                            break;
                        }
                    }
                    if (!duplicateFound)
                    {
                        unique = true;
                    }
                }
                if (!unique)
                {
                    tastaturpuffer_leeren();
                }
            }
        }

        // Ausgabe der Tippzahlen
        printf("Deine Lottozahlen lauten: ");
        for (int index = 0; index < rest; index++)
        {
            printf("[%d] ", tippZahlen[index]);
        }
        printf("\n");

        // Ausgabe Versuchsanzahl
        printf("Versuch: %d\n", versuch);

        // Abgleich welche Zahlen richtig getippt wurden
        for (int index = 0; index < MAX_ANZAHL; index++)
        {
            for (int i = 0; i < rest; i++)
            {
                if (lottoZahlen[index] == tippZahlen[i])
                {
                    printf("Folgende Zahl wurde richtig erraten: %d\n", lottoZahlen[index]);
                    count++;
                }
            }
        }

        // Ausgabe wie viele Zahlen richtig und wie viele noch fehlen
        printf("Es wurden %d Lottozahlen richtig erraten.\n", count);
        rest -= count;
        gesamtErraten += count;

        if (gesamtErraten == MAX_ANZAHL)
        {
            printf("Glueckwunsch! Es wurden alle Lottozahlen richtig erraten!!!\n");
            break;
        }
        else
        {
            printf("Es fehlen noch %d richtige Lottozahlen.\n", rest);
        }
    }

    // Ausgabe der Zufallszahlen
    printf("Die Lottozahlen lauten: ");
    for (int index = 0; index < MAX_ANZAHL; index++)
    {
        printf("[%d] ", lottoZahlen[index]);
    }
    printf("\n");
    return 0;
}

void tastaturpuffer_leeren()
{
    int tmp;
    do
    {
        tmp = getchar();
    } while (tmp != EOF && tmp != '\n');
}