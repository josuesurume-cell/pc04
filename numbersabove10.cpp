/* Escriba un programa que ingrese elementos de un array
y luego imprima el recuento de elementos mayores a 10 */
#include <iostream>
using namespace std;
int main(){
    int A [10]; //Las celdas del array se empiezana a contar desde el 0
    int j=0; //contador para la cantidad de valores del array mayores a 10
    for (int i = 0; i < 10; i++)
    {
        cout << "Ingrese el valor de A"<<"["<<i<<"]"<<endl;
        cin >> A[i];
    }
    for (int i = 0; i < 10; i++)
    {
        if (A[i]>10) cout << A[i]<<" "; // agregar un espacio es importante porque sino los numeros aparecen pegados
    }
    
    return 0;
}