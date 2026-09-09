#include <iostream>
using namespace std;

void llenarmatriz(int matriz[7][4], int i, int j); 
void  leermatriz(int matriz[7][4]);
void ingresardato(int matriz[7][4]);
void leerDatosMatriz(int matriz[7][4], int i);




void llenarmatriz(int matriz[7][4], int i, int j){
    for (int i = 0; i < 7; i++){
        for(int j = 0; j < 4; j++){
            cout<<"ingrese el dato de la posicion ("<<i+1<<","<<j+1<<"): ";
            cin>>matriz[i][j];

        }
    }
    cout<<"tablero de lleno\n"<<endl;

} 
void leermatriz(int matriz[7][4]){
    cout<<"tablero de numeros\n"<<endl;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 4; j++){
            cout<<" | "<<matriz[i][j];
        }
        cout<<" | "<<endl;
    }
}
void ingresardato(int matriz[7][4]){
    int l = 0, m = 0, n = 0;
    do{ 
        cout<<"ingrese la posicion donde desea ingresar el dato (1 - 7); ";
        cin>>l;
        cout<<endl;
        if (l < 1 || l > 7){
            cout<<"la posicion ingresada no es valida, ingrese un numero entre 1 y 7"<<endl;
            
        }

    }
    while(l < 1 || l > 7);
    do{
        cout<<"ingrese la posicion donde desea ingresar el dato (1 - 4); ";
        cin>>m;
        cout<<endl; 
        if (m < 1 || m > 4){
            cout<<"la posicion ingresada no es valida, ingrese un numero entre 1 y 4"<<endl;
        }
        
    }
    while(m < 1 || m > 4);
    cout<<"ingresa el numero para almacear. "<< endl;
    cin>>n;
    matriz[l-1][m-1] = n;

}

void leerDatosMatriz(int matriz[7][4], int i){
    if(i > 0){
        int l = 0, m = 0, n = 0;
        do{ 
            cout<<"ingrese la posicion donde desea ingresar el dato (1 - 7); ";
            cin>>l;
            cout<<endl;
            if (l < 1 || l > 7){
                cout<<"la posicion ingresada no es valida, ingrese un numero entre 1 y 7"<<endl;
            
            }

        }
        while(l < 1 || l > 7);
        do{
            cout<<"ingrese la posicion donde desea ingresar el dato (1 - 4); ";
            cin>>m;
            cout<<endl; 
            if (m < 1 || m > 4){
                cout<<"la posicion ingresada no es valida, ingrese un numero entre 1 y 4"<<endl;
            }
        
        }
        while(m < 1 || m > 4);
    }
}