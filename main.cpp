#include <iostream>
#include "Funciones.h"
using namespace std;

int main(){
    const int SIZE = 20;
    const int HALF = SIZE / 2;
    int grades[SIZE];
    int lower[HALF];
    int upper[HALF];

    getGrades(grades, SIZE);
    separateGrades(grades, SIZE, lower, upper);

    cout << "Lower half:" << endl;
    showGrades(lower, HALF);
    cout << "Upper half:" << endl;
    showGrades(upper, HALF);

    return 0;
}