
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Funciones.h"

using namespace std;

int main(int argc, const char* argv[]) {
    int option = 0;

    srand(time(NULL));

    do {
        cout << "Options Menu" << endl;
        cout << "1. Play against the computer." << endl;
        cout << "2. Play against another player." << endl;
        cout << "0. Exit the system." << endl;
        cout << "Select an option: ";

        cin >> option;

        switch (option) {
        case 1:
            playAgainstComputer();
            break;

        case 2:
            playAgainstUser();
            break;

        case 0:
            cout << "Closing system..." << endl;
            break;

        default:
            cout << "Invalid option. Please select another option from the menu." << endl;
            break;
        }

    } while (option != 0);

    return 0;
}