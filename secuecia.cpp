#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//funcion de pares
int pares (int arr[], int n)
{
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]%2 == 0)
        {
            a += 1;
        }      
    }
    return a;   
}

//funcion para hallar el minimo
int min (int arr[], int n){
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

// funcion para hallar el maximo de los valores del array
int max (int arr[], int n){
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
// función para la suma de los elementos del array
int suma (int array[], int n)
{
    int a = 0;
    for (int i = 0; i < n; i ++)
    {
        a += array[i];
    }
    return a;
}
// función para hallar la cantidad de primos del array
int primos (int arr[], int n)
{
    int noprimo = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 1)
        {
            noprimo ++;
            continue;
        }

        for (int j = 2; j <= sqrt(arr[i]); j++)
        {
            if (arr[i]%j == 0)
            {
                noprimo ++;
                break;
            }
        }
    }
    return n - noprimo;
}

int main()
{
    int N;
    cout << "Ingrese el valor de N" << endl;
    cin >> N;
    while (N <= 0)
    {
        cout << "Ingrese un valor entero positivo" << endl;
        cin >> N;
    }
    int* vector = new int [N];
    for (int i = 0; i < N; i++)
    {
        cout << "Ingrese el valor " << i + 1 << " del array" << endl;
        cin >> vector[i];
    }
    cout << "======= Reporte =======" << endl;
    cout << fixed << setprecision(2);
    cout << "La suma de los elementos del array es " << suma(vector,N) << endl;
    cout << "El promedio es " << suma(vector,N)/N << endl;
    cout << "El mayor de los elementos es " << max(vector, N) << endl;
    cout << "El menor de los elementos es " << min(vector, N) << endl;
    cout << "El numero de pares es " << pares (vector, N) << endl;
    cout << "El numero de impares es " << N - pares (vector, N) << endl;
    cout << "El numero de valores primos es " << primos(vector, N) << endl;

    return 0;
}