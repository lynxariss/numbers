/*
tomar 20 numeros y separarlos en 2 de 10 teniendo en cuenta la mediana, separar los menores y mayores 
*/
#include <iostream>
#include "Funciones.h"
#include <algorithm>
#include <vector>
using namespace std;

void getGrades(int grades[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter grade " << (i + 1) << ": ";
        cin >> grades[i];
    }
}

void separateGrades(int grades[], int size, int lower[], int upper[]) {
    // Sort a copy of the grades then split into lower and upper halves
    vector<int> temp(grades, grades + size);
    sort(temp.begin(), temp.end());
    int half = size / 2;
    for (int i = 0; i < half; i++) {
        lower[i] = temp[i];
        upper[i] = temp[i + half];
    }
}

void showGrades(int grades[], int size) {
    cout << "Grades: ";
    for (int i = 0; i < size; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;
}