/*
tomar 20 numeros y separarlos en 2 de 10 teniendo en cuenta la mediana, separar los menores y mayores 
*/
#include <iostream>
#include "Funciones.h"
using namespace std;

void getGrades() {
    // Implementation for getting grades
    int grades[20]; 
    for (int i = 0; i < 20; i++) {
        cout << "Enter grade " << (i + 1) << ": ";
        cin >> grades[i];
    }

}

void separateGrades(int grades[], int lower[], int upper[], int size) {
    // Implementation for separating grades into lower and upper arrays
    int medianIndex = size / 2;
    for (int i = 0; i < size; i++) {
        if (grades[i] < grades[medianIndex]) {
            lower[i] = grades[i];
        } else {
            upper[i] = grades[i];
        }
    }
}
