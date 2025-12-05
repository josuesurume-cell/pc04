// un arreglo se incia con un valor fijo, no es dinamico como los vectores
// puedes recorrer un valor de filas a columas o de columnas a fijas cambiando el orden del for anidado
#include <iostream>
using namespace std;
const int T = 40;
int main (){
    int numero, limite_inferior, limite_superior;
    int NotasAlumnos[T];
    srand (time(nullptr));

    limite_inferior = 0;
    limite_superior = 20;
    int s = 0; // variable acumuladora para la suma
    int min = 100;
    int max = -100;

    for (int i = 0; i < T; i++){
        NotasAlumnos[i] = limite_inferior + rand()%(limite_superior + 1 - limite_inferior);
        s += NotasAlumnos[i];
        if (NotasAlumnos[i]<min){
            min = NotasAlumnos[i];
        }
        else if (NotasAlumnos[i]>max){
            max = NotasAlumnos[i];
        }        
    }
    int frecuencia[21] = {0}, i;
    for ( i = 0; i < 21; i++){
        for (int f = 0; f < T; f++){
            if (NotasAlumnos[f]==i){
                frecuencia[i] += 1;
            }
        }
    }

    int maxfrecuencia = -100,f;
    for (f = 0; f < 21;f++){
        if (maxfrecuencia < frecuencia[f]){
            maxfrecuencia = frecuencia[f];
        }
    }

    cout << "----------- Reporte -----------"<< endl;
    cout << "El promedio de notas es: " << s/40 << endl;
    cout << "La nota maxima es: " << max << endl;
    cout << "La nota minima es: " << min << endl;
    cout << "La nota más frecuente es: " << maxfrecuencia << " con una frecuencia de " << i << " veces." << endl;  
    return 0;
}
