/*
14. Matriz 6×4 con valores aleatorios 100–500. Determinar:
• Promedio por columna
• Promedio por fila
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    int matriz[6][4], limite_inf, limite_max;
    limite_inf = 100;
    limite_max = 500;
    srand(time(nullptr));

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matriz[i][j] = limite_inf + rand()%(limite_max - limite_inf + 1);
        }   
    }
     
    double filas [6] = {0};
    double columnas [4] = {0};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            filas[i] += matriz [i][j];
        }
    }
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            columnas[i] += matriz [i][j];
        }
    }
    cout << fixed << setprecision(2);
    for (int i = 0; i < 6; i++)
    {
        cout << "Promedio de la fila " << i + 1 << " es " << filas[i]/4 << endl;
    }
    for (int j = 0; j < 6; j++)
    {
        cout << "Promedio de la columna " << j + 1 << " es " << filas[j]/6 << endl;   
    }

  return 0;  
}