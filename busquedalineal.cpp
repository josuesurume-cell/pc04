#include <iostream>
using namespace std;
const int T = 5;
int main()
{
    int A [T];
    cout << "Ingrese " << T << " valores para cada celda:\n";
    for (int i = 0; i < T; i++)
    {
        cin >> A[i]; //si declaracemos una variable dentro del for, seria una variable local, esta naceria y moriria en cada iteracion
        // la variable es local en ese bucle, solo existe dentro del bucle. Para el resto del programa la variable no existe
    }
    int valor;
    bool hallado = false;
    int i; // declara la variable i fuera del for para que no se destruye una vez acabe la iteración, si no la declaramos, se destruye.
    // esto hace que sea local en toda la función (main) y pueda usarse en esta.
    cout << "Ingrese el valor a buscar:\n";
    cin >> valor;
    for (i = 0; i < T; i++)
    {
        if (valor == A [i])
        {
            hallado = true;
            break;
        }
    }
    if (hallado) // si hallado es verdadero entonces el programa ejecutara esta condición.
    {
        cout << "El numero " << valor << " se encuentra en la posicion " << i + 1 << "." << endl; 
        //como declaramos i antes, se puede usar pese a haber acabado la iteracion
    }
    else
    {
        cout << "El numero " << valor << " no se encuentra en el arreglo." << endl;
    }
    return 0;
}