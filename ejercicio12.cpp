/* 
12. Matriz 5×5 con valores 10–60. Determinar:
• Suma del triángulo superior
• Suma del triángulo inferior
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int matriz[5][5], limite_inf, limite_max;
    limite_inf = 10;
    limite_max = 60;
    srand (time(nullptr));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz[i][j] = limite_inf + rand()%(limite_max - limite_inf + 1);
        }
    }

    int tsup = 0, tinf = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j < i) {tsup += matriz[i][j];}
            else if (j > i) {tinf += matriz[i][j];}
        }
    }

    cout << "La suma del triangulo superior es " << tsup << endl;
    cout << "La suma del triangulo inferior es " << tinf << endl;

   return 0; 
}