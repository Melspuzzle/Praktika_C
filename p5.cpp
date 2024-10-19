#include <stdio.h>

int main(void)
{
    int eingabe;
    float preis;
    char *drink;
    printf("Moechtest du ein Getraenk mit Schaum? Tippe 1 fuer ja und 0 fuer nein \n");
    scanf("%d", &eingabe);
    if (eingabe == 1)
    {
        drink = "Bier";
        preis = 3.00;
        printf("Wir haben %s fuer %.2fEuro im Angebot.\n", drink, preis);
    }
    else
    {
        printf("Moechtest du ein Getraenk mit Kohlensaeure? Tippe 1 fuer ja und 0 fuer nein \n");
        scanf("%d", &eingabe);
        if (eingabe == 1)
        {
            printf("Moechtest du ein Getraenk mit Alkohol? Tippe 1 fuer ja und 0 fuer nein \n");
            scanf("%d", &eingabe);
            if (eingabe == 1)
            {
                drink = "Sekt";
                preis = 5.20;
                printf("Wir haben %s fuer %.2fEuro im Angebot.\n", drink, preis);
            }
            else
            {
                drink = "Limo";
                preis = 2.50;
                printf("Wir haben %s fuer %.2fEuro im Angebot.\n", drink, preis);
            }
        }
        else
        {
            printf("Moechtest du ein Getraenk mit Alkohol? Tippe 1 fuer ja und 0 fuer nein \n");
            scanf("%d", &eingabe);
            if (eingabe == 1)
            {
                drink = "Wein";
                preis = 5.20;
                printf("Wir haben %s fuer %.2fEuro im Angebot.\n", drink, preis);
            }
            else
            {
                drink = "Saft";
                preis = 3.50;
                printf("Wir haben %s fuer %.2fEuro im Angebot.\n", drink, preis);
            }
        }
    }
    printf("Wie viele Einheiten moechtest du von dem Getraenk haben? \n");
    scanf("%i", &eingabe);
    preis *= eingabe;
    printf("Der Gesamtpreis von %i mal %s lautet %.2fEuro. \n", eingabe, drink, preis);
    getchar();

    return (0);
}