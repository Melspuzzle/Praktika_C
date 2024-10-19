#include <stdio.h>
#define _USE_MATH_DEFINES
#include <cmath>

tastaturpuffer_leeren() float eingabe_pruefen(const char *prompt);

int main(void)
{
    // Variablendeklaration
    int result;
    float durchmesser_unten, durchmesser_oben, durchmesser_mitte, hoehe;
    float grundf, mantelf, oberf, volumen;

    // Eingabe best. Groeßen durch Nutzer & Tastaturpuffer anschließend leeren
    // abfangen von Fehleingaben

    // Kontrolle einbauen, damit keine Buchstaben oder negativen Zahlen eingegeben werden
    durchmesser_unten = eingabe_pruefen("Bitte gebe den Durchmesser fuer unten ein: ");
    tastaturpuffer_leeren();

    durchmesser_oben = eingabe_pruefen("Bitte gebe den Durchmesser fuer oben ein: ");
    tastaturpuffer_leeren();

    durchmesser_mitte = eingabe_pruefen("Bitte gebe den Durchmesser fuer mitte ein: ");
    tastaturpuffer_leeren();

    hoehe = eingabe_pruefen("Bitte gebe die Hoehe ein: ");
    tastaturpuffer_leeren();

    getchar();
    // Ausgabe der eingegebenen Groeßen
    printf("Folgende Durchmesser wurden eingegeben: \n unten: %.f \n oben: %.f \n mitte: %.f \nDie eingegebene Hoehe lautet: %.f\n", durchmesser_unten, durchmesser_oben, durchmesser_mitte, hoehe);

    grundf = 4 * M_PI * pow(durchmesser_unten, 2);
    mantelf = 4 * M_PI * pow(durchmesser_mitte, 2);
    oberf = 4 * M_PI * pow(durchmesser_oben, 2);
    volumen = (4.0 / 3.0) * M_PI * pow(hoehe, 3);
    getchar();
    // Ausgabe der Berechneten Groeßen
    printf("Die Grundflaeche/Deckelflaeche ist: %.2fm^2\n", grundf);
    printf("Die Mantelflaeche ist: %.2fm^2\n", mantelf);
    printf("Die Oberflaeche ist: %.2fm^2\n", oberf);
    printf("Das Volumen ist: %.2fm^3\n", volumen);

    getchar();
    return (0);
}

// Funktion zur Eingabeprüfung von Gleitkommazahlen
float eingabe_pruefen(const char *prompt)
{
    float zahl;
    int result;

    while (1)
    {
        printf("%s", prompt); // Ausgabe des Eingabeaufforderungstextes

        result = scanf("%f", &zahl); // Eingabe der Zahl

        if (result == 1 && zahl > 0)
        {
            // Gültige Eingabe, Schleife verlassen
            break;
        }
        else
        {
            // Fehlermeldung, falls keine Zahl eingegeben wurde
            printf("Fehler: Bitte gebe eine gueltige Zahl ein!\n");
            // Buffer leeren, um ungültige Eingaben zu entfernen
            while (getchar() != '\n')
                ; // Alle Zeichen bis zum Zeilenende verwerfen
        }
    }
    return zahl; // Die gültige Zahl zurückgeben
}
void tastaturpuffer_leeren()
{
    int tmp;

    do
    {
        tmp = getchar();
    } while (tmp != EOF && tmp != '\n');
}