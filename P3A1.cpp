#include <stdio.h>
#define _USE_MATH_DEFINES
#include <cmath>

int main(void)
{
    // Variablendeklaration
    int durchmesser;
    float volumen;
    float oberflaeche;

    // Eingabe Durchmesser über Tastatur
    printf("Bitte gebe den Durchmesser einer Kugel an, dessen Volumen und Oberflaeche du berechnen moechtest.");
    scanf("%i", &durchmesser);

    volumen = (4.0 / 3.0) * M_PI * pow(durchmesser, 3);
    oberflaeche = 4 * M_PI * pow(durchmesser, 2);
    printf("Das Volumen der Kugel betraegt: %.2f m^3\n", volumen);
    printf("Die Oberflaeche der Kugel betraegt: %.2f m^2\n", oberflaeche);

    getchar();
    return 0;
}