#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

// Funzione per stampare la scacchiera
void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Funzione per controllare se una mossa è valida
int isValidMove(char board[SIZE][SIZE], int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

// Funzione per controllare se qualcuno ha vinto
int checkWin(char board[SIZE][SIZE], char player) {
    // Controllo delle righe e delle colonne
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1; // Qualcuno ha vinto
        }
    }

    // Controllo delle diagonali
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1; // Qualcuno ha vinto
    }

    return 0; // Nessuno ha vinto ancora
}

// Funzione per far giocare il computer
void computerMove(char board[SIZE][SIZE]) {
    int row, col;
    do {
        // Genera mosse casuali finché non trova una mossa valida
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (!isValidMove(board, row, col));

    board[row][col] = 'O';
}

int main() {
    char board[SIZE][SIZE]; // Scacchiera del gioco
    int row, col;
    int currentPlayer = 1; // 1 per il giocatore, 2 per il computer

    // Inizializza la scacchiera
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Ciclo di gioco
    do {
        // Stampa la scacchiera
        printBoard(board);

        // Turno del giocatore umano
        if (currentPlayer == 1) {
            printf("Turno del giocatore (X)\nInserisci la tua mossa (riga colonna): ");
            scanf("%d %d", &row, &col);
        }
        // Turno del computer
        else {
            printf("Turno del computer (O)\n");
            computerMove(board);
            
        }

        // Verifica se la mossa è valida
        if (isValidMove(board, row, col)) {
            // Effettua la mossa
            board[row][col] = (currentPlayer == 1) ? 'X' : 'O';

            // Verifica se qualcuno ha vinto
            if (checkWin(board, (currentPlayer == 1) ? 'X' : 'O')) {
                printBoard(board);
                printf("Giocatore %c ha vinto!\n", (currentPlayer == 1) ? 'X' : 'O');
                break;
            }

            // Verifica se c'è un pareggio
            int movesLeft = 0;
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (board[i][j] == ' ') {
                        movesLeft = 1;
                        break;
                    }
                }
                if (movesLeft) {
                    break;
                }
            }

            if (!movesLeft) {
                printBoard(board);
                printf("Pareggio!\n");
                break;
            }

            // Cambia il turno
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        } else {
            printf("Mossa non valida. Riprova.\n");
        }

    } while (1);

    return 0;
}
