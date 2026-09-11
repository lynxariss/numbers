#ifndef Funciones_H
#define Funciones_H 

void fillMatrixManually(int matrix[4][4]);
void fillMatrixRandomly(int matrix[4][4]);
void displayMatrix(int matrix[4][4], bool marked[4][4]);

bool repeatedNumber(int matrix[4][4], int number);

int checkNumber(
    int matrix[4][4],
    bool marked[4][4],
    int number
);

int generateNumber(bool drawnNumbers[101]);

void chooseBoard(
    int matrix[4][4],
    int player
);

void startGame(
    int board1[4][4],
    int board2[4][4],
    bool againstComputer
);

void playAgainstComputer();
void playAgainstUser();

#endif 