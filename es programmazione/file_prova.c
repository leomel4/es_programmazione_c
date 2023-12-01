#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Cambia il colore del testo a rosso
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("Testo rosso\n");

    // Cambia il colore del testo a verde
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("Testo verde\n");

    // Ripristina il colore predefinito del testo
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("Testo predefinito\n");

    return 0;
}