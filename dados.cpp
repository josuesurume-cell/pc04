#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main (){
    int numero, limite_inferior, limite_superior;
    srand (time(nullptr)); // se genera la semilla con la que se va a generar el numero aleatorio

    limite_inferior = 1;
    limite_superior = 6;
    
    int s = 0;
    for (int i = 0; i < 2; i++)
    {
        numero = limite_inferior + rand()%(limite_superior + 1 - limite_inferior);
        s += numero;
        cout << numero << endl;
    }
    cout << "La suma de los dados es " << s << endl;
    if (s==9)
    {
        cout << "Ha ganado" << endl;
    }
    else 
    {
        cout << "Ha perdido" << endl;
    }
    return 0;
}