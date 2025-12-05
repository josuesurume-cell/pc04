// hallar el maximo valor de un conjunto de numeros
#include <iostream>
using namespace std;
const int T = 5;  /* Es bueno definir una constante para declara el tamaño
del array, y ya no es necesario tener que definir T en las demás funciones*/
int main ()
{
    int A [T];
    int maxVal;
    cout << "Ingrese " << T << " valores para cada celda:\n";
    for (int i = 0; i < T; i++) 
    {
        cin >> A[i]; 
    }
    int position = 0; // variable a la cual le asignaremos la ubicacion del valor máximo
    maxVal = A[0]; // se le asigna a una variable un valor de una celda
    for (int i = 1; i < T; i++)
    {
        if (maxVal < A[i]) // se compara con cada una de las celdas
        {
            maxVal = A[i]; // si es mayor, se le asigna el nuevo valor de la celda
            position = i;
        }
    }
    cout << "El valor máximo es "<< maxVal << " en la posición " << position << endl;
    return 0;
}