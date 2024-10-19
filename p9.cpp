#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 80

void readString(char *checkString);
void removeSpaces(char *checkString);
void reverseString(int *p_length, char *checkString, char *reversedString);
void palindromCheck(int *p_length, char *reversedString, char *checkString, bool *p_checkPalindrom);
void tastaturpuffer_leeren();

int main(void)
{
    // Variableninitialisierung
    int length, *p_length = &length;
    char checkString[MAX_LENGTH];
    char reversedString[MAX_LENGTH];
    bool checkPalindrom = true, *p_checkPalindrom = &checkPalindrom;
    bool nextRound = true;
    char playNextRound[2];

    while (nextRound = true)
    {
        // einlesen des Strings und Kontrollausgabe
        readString(checkString);

        // wenn Palindrom mehr als ein Wort Leerzeichen entfernen
        removeSpaces(checkString);

        // string umgedreht in neuen string kopieren
        reverseString(p_length, checkString, reversedString);

        // Ausgabe ob strings gleich oder ungleich bzw. Palindrom/nicht Palindrom
        palindromCheck(p_length, reversedString, checkString, p_checkPalindrom);

        printf("Moechtest du ein weiteres Wort oder einen Satz ueberpruefen?[y/n]\n");
        scanf("%s", playNextRound);

        if (playNextRound[0] == 'n' || playNextRound[1] == 'n')
        {
            nextRound = false;
            break;
        }
        tastaturpuffer_leeren();
    }

    return 0;
}

void readString(char *checkString)
{
    printf("Bitte gebe ein Wort oder kurzen Satz ohne Satzzeichen und ohne mehrfachen Leerzeichen ein.\n");
    scanf("%[^\n]", checkString);
    tastaturpuffer_leeren();
    //  gets_s(p_checkString); // im gegensatz zu scanf() werden auch Leerzeichen eingelesen
    //    Kontrollausgabe des eingegebenen Strings
    printf("Die Eingabe lautet: \"%s\"\n", checkString);
}
void removeSpaces(char *checkString)
{
    for (int index = 0; index < strlen(checkString); index++)
    {
        if (checkString[index] == ' ')
        {
            checkString[index] = checkString[index + 1];
            for (int x = index + 1; x < strlen(checkString); x++)
            {
                checkString[x] = checkString[x + 1];
            }
        }
    }
}

void reverseString(int *p_length, char *checkString, char *reversedString)
{
    //* um mit dem Inhalt vom pointer zu arbeiten
    *p_length = strlen(checkString) - 1;
    for (int index = 0; index <= *p_length; index++)
    {
        reversedString[*p_length - index] = checkString[index];
    }
}

void palindromCheck(int *p_length, char *reversedString, char *checkString, bool *p_checkPalindrom)
{
    // die beiden strings miteinander vergleichen
    for (int index = 0; index <= *p_length; index++)
    {
        if (reversedString[index] != checkString[index])
        {
            *p_checkPalindrom = false;
            break;
        }
    }
    if (*p_checkPalindrom == false)
    {
        printf("Es handelt sich nicht um ein Palindrom.\n");
    }
    else
    {
        printf("Es handelt sich um ein Palindrom.\n");
    }
}
void tastaturpuffer_leeren()
{
    int tmp;
    do
    {
        tmp = getchar();
    } while (tmp != EOF && tmp != '\n');
}