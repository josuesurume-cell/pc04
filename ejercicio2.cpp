/* 
2. Llenar un arreglo de 80 temperaturas (−5 °C a 45 °C). Calcular:
• La temperatura promedio
• Cuántas superan 30 °C• Cuál es la mínima
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int T = 80;

float suma (int arr[], int n)
{
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        a += arr[i];
    }
    
    return a;
}

int min (int arr[], int n)
{
    int min = -10;
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

int mayores (int arr[], int n, int m)
{
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > m)
        {
            a ++;
        }
    }
    
    return a;
}

int main()
{
    int arr [T], limite_inf, limite_max;
    srand(time(nullptr));
    limite_inf = -5;
    limite_max = 45;   

    for (int i = 0; i < T; i++)
    {
        arr[i] = limite_inf + rand()%(limite_max - limite_inf + 1);
        cout << arr [i] << endl;
    }

    cout << "====== RESULTADOS ======" << endl;
    cout << fixed << setprecision(2);
    cout << "La temperatura promedio es " << suma (arr, T)/T << endl;
    cout << "Las temperaturas que superan los 30 grados son " << mayores(arr, T, 30) << endl;
    cout << "La temperatura minima es " << min(arr, T) << endl;
    
    return 0;
}