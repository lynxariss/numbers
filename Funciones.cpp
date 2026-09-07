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

void separateGrades(int grades[], int lower[], int upper[]) {
    // Implementation for separating grades into lower and upper arrays
    int size = 20; // Assuming the size is 20
    int medianIndex = size / 2;
    medianIndex = (size % 2 == 0) ? (medianIndex - 1) : medianIndex; // Adjust for even size
    
    for (int i = 0; i < size; i++) {
        if (grades[i] < grades[medianIndex]) {
            lower[i] = grades[i];
        } else {
            upper[i] = grades[i];
        }
    }
}

void showGrades(int grades[], int size) {
    // Implementation for showing grades
    cout << "Grades: ";
    for (int i = 0; i < size; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;
}