#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

char board[3][3]; // Griglia di gioco 3x3

void inizializzaGriglia() {
    // Inizializza la griglia vuota
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void stampaGriglia() {
       // Stampa la griglia di gioco con bordi speciali | * + 
    printf("*****************\n");
    for(int i = 0; i < 3; i++) {
        printf("* %c | %c | %c *\n", board[i][0], board[i][1], board[i][2]);
        if(i < 2) {
            printf("*---+---+---*\n");
        }
    }
    printf("*****************\n");

}

int controllaVittoria() {
    // Controlla se c'è una combinazione vincente
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1; // Vittoria nella riga i
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1; // Vittoria nella colonna i
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1; // Diagonale principale
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1; // Diagonale secondaria

    return 0; // Nessuna vittoria
}

int verificaPareggio() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // La griglia non è piena
            }
        }
    }
    return 1; // La griglia è piena (pareggio)
}
// Funzione per controllare se una mossa è valida
int isValidMove(char board[3][3], int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}
void computerMove(char board[3][3]) {
    int row, col;
    do {
        // Genera mosse casuali finché non trova una mossa valida
        row = rand() % 3;
        col = rand() % 3;
    } while (!isValidMove(board, row, col));

    board[row][col] = 'O';
}

int main() {
    system("clear");
    
    int riga, colonna;
    int giocaAncora = 1; // 1 per continuare a giocare

    while (giocaAncora) {
        int turno; // 0 per X, 1 per O
        printf("scegli se vuoi giocare tu, inserendo 0, o il PC, inserdendo 1: ");
        scanf("%d", &turno);
        inizializzaGriglia();

        while (1) {
            printf("Turno del giocatore %c\n", (turno == 0) ? 'X' : 'O');
            system("clear");
            stampaGriglia();

            if(turno==0){
                // Input della mossa del giocatore
                printf("Inserisci la riga e la colonna (0-2) separate da uno spazio: ");
                scanf("%d %d", &riga, &colonna);
                if(riga>=3 || colonna>=3){
                    continue;
                }else{
                    if(isValidMove(board, riga, colonna)){
                        board[riga][colonna] = 'X';
                    }

                    if(controllaVittoria()) {
                        printf("Giocatore X ha vinto!\n");
                        break;
                    } else if (verificaPareggio()) {
                        printf("La partita è finita in pareggio!\n");
                        break;
                    }
                    ++turno;
                }
                
            }else{
                //turo del pc
                printf("Turno del computer (O)\n");
                computerMove(board);
                if(controllaVittoria()) {
                        printf("Giocatore O ha vinto!\n");
                        break;
                    } else if (verificaPareggio()) {
                        printf("La partita è finita in pareggio!\n");
                        break;
                    }
                --turno;
            }
        }

        // Richiedi all'utente se vuole giocare ancora
        printf("Vuoi giocare ancora? (1 per sì, 0 per no): ");
        scanf("%d", &giocaAncora);
    }

    printf("Grazie per aver giocato!\n");
    return 0;
}
