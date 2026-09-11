#include <iostream>
#include <cstdlib>
#include <string>
#include "Funciones.h"

using namespace std;

// ---------- Llenado de tableros ----------

bool repeatedNumber(int matrix[4][4], int number) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] == number) {
                return true;
            }
        }
    }
    return false;
}

bool hasDuplicates(int matrix[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int count = 0;
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 4; y++) {
                    if (matrix[x][y] == matrix[i][j]) {
                        count++;
                    }
                }
            }
            if (count > 1) {
                return true;
            }
        }
    }
    return false;
}

void fillMatrixManually(int matrix[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int number;
            bool valid = false;

            do {
                cout << "Enter number for position [" << i << "][" << j << "] (1-100): ";
                cin >> number;

                if (number < 1 || number > 100) {
                    cout << "Invalid number. It must be between 1 and 100." << endl;
                } else if (repeatedNumber(matrix, number)) {
                    cout << "That number is already on the board. Choose another one." << endl;
                } else {
                    valid = true;
                }
            } while (!valid);

            matrix[i][j] = number;
        }
    }
}

void fillMatrixRandomly(int matrix[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int number;
            do {
                number = (rand() % 100) + 1;
            } while (repeatedNumber(matrix, number));

            matrix[i][j] = number;
        }
    }
}

void displayMatrix(int matrix[4][4], bool marked[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (marked[i][j]) {
                cout << "[X]\t";
            } else {
                cout << "[" << matrix[i][j] << "]\t";
            }
        }
        cout << endl;
    }
}

// ---------- Logica del juego ----------

bool checkWinner(bool marked[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!marked[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int checkNumber(int matrix[4][4], bool marked[4][4], int number) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] == number && !marked[i][j]) {
                marked[i][j] = true;
                return 1;
            }
        }
    }
    return 0;
}

int generateNumber(bool drawnNumbers[101]) {
    int number;
    do {
        number = (rand() % 100) + 1;
    } while (drawnNumbers[number]);

    drawnNumbers[number] = true;
    return number;
}

// ---------- Configuracion de tableros ----------

void chooseBoard(int matrix[4][4], int player) {
    int option = 0;

    cout << "\n--- Board setup for player " << player << " ---" << endl;
    cout << "1. Fill the board manually." << endl;
    cout << "2. Fill the board randomly." << endl;
    cout << "Select an option: ";
    cin >> option;

    while (option != 1 && option != 2) {
        cout << "Invalid option. Please select 1 or 2: ";
        cin >> option;
    }

    if (option == 1) {
        fillMatrixManually(matrix);
    } else {
        fillMatrixRandomly(matrix);
    }
}

// ---------- Ciclo principal del juego ----------

void startGame(int board1[4][4], int board2[4][4], bool againstComputer) {
    bool marked1[4][4] = {};
    bool marked2[4][4] = {};
    bool drawnNumbers[101] = {};

    int score1 = 0;
    int score2 = 0;
    int turn = 0;

    string player2Name = againstComputer ? "Computer" : "Player 2";

    cout << "\nInitial boards:" << endl;
    cout << "Player 1:" << endl;
    displayMatrix(board1, marked1);
    cout << player2Name << ":" << endl;
    displayMatrix(board2, marked2);

    while (score1 < 16 && score2 < 16) {
        int number = generateNumber(drawnNumbers);
        turn++;

        cout << "\nTurn " << turn << " - Number drawn: " << number << endl;

        if (checkNumber(board1, marked1, number)) {
            score1++;
        }

        if (checkNumber(board2, marked2, number)) {
            score2++;
        }

        cout << "Player 1 (" << score1 << " points):" << endl;
        displayMatrix(board1, marked1);
        cout << player2Name << " (" << score2 << " points):" << endl;
        displayMatrix(board2, marked2);
    }

    cout << "\n--- Game over ---" << endl;

    if (score1 == 16 && score2 == 16) {
        cout << "It's a tie! Both boards were completed on the same turn." << endl;
    } else if (score1 == 16) {
        cout << "Player 1 wins!" << endl;
    } else {
        cout << player2Name << " wins!" << endl;
    }
}

// ---------- Modos de juego ----------

void playAgainstComputer() {
    int board1[4][4];
    int board2[4][4];

    cout << "\n=== Player vs Computer ===" << endl;
    chooseBoard(board1, 1);

    cout << "\nGenerating the computer's board..." << endl;
    fillMatrixRandomly(board2);

    startGame(board1, board2, true);
}

void playAgainstUser() {
    int board1[4][4];
    int board2[4][4];

    cout << "\n=== Player 1 vs Player 2 ===" << endl;
    chooseBoard(board1, 1);
    chooseBoard(board2, 2);

    startGame(board1, board2, false);
}