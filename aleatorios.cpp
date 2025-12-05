#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main (){
    //declaramos la variable que recibira el numero aleatorio a generar
    int numero;
    // generamos la seilla para generar numeros aleatorios
    srand (time(nullptr));
    //generamos el numero aleatorio
    numero = rand();
    //mostramos el resultdo
    cout << numero;
    return 0;
    //obtenemos numeros muy grandes
}