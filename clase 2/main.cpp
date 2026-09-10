#include <iostream>
using namespace std;

int llenarmatriz(int matriz[7][4], int i, int j); 
void leermatriz(int matriz[7][4]);
void ingresardato(int matriz[7][4]);
void leerDatosMatriz(int matriz[7][4], int i);




int llenarmatriz(int matriz[7][4], int i, int j){
    for (i = 0; i < 7; i++){
        for(j = 0; j < 4; j++){
            cout<<"ingrese el dato de la posicion ("<<i+1<<","<<j+1<<"): ";
            cin>>matriz[i][j];

        }
    }
    cout<<"tablero de lleno\n"<<endl;

    return i;

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
        int l = 0, m = 0;
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
        cout<<" el dato almacenado en la posicion ("<<l<<","<<m<<") es: "<<matriz[l-1][m-1]<<endl;
    }
    else{
        cout<<"no hay datos almacenados en la matriz"<<endl;
    }

}
    int main(){
        int matriz[7][4];
        int i = 0, j = 0;
        int op = 0;
        do{ 
            cout <<"ingrese la opcion que desea realizar: "<<endl;
            cout <<"1. llenar matriz"<<endl;
            cout <<"2. leer matriz"<<endl;
            cout <<"3. ingresar dato"<<endl;
            cout <<"4. leer dato de la matriz"<<endl;
            cout <<"5. salir"<<endl;
            cin>>op;
            if(op == 1){
                i = llenarmatriz(matriz, i, j);
            }
            else if(op == 2){
                leermatriz(matriz);
            }
            else if(op == 3){
                ingresardato(matriz);
            }
            else if(op == 4){
                leerDatosMatriz(matriz, i);
            }
            else if(op == 5){
                cout<<"saliendo del programa"<<endl;
                return true;
            }
            else{
                cout<<"la opcion ingresada no es valida"<<endl;
            }
        }
        while(true);
}