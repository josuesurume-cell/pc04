/* Una planta produce envases de 3 tipos : 1 = vidrio, 2 = plástico y 3 = aluminio 
cada lote tiene una producciôn diaria que su registrará durante 10 días 
Por cada día, ingresar:
    Tipo de envase (1 - 3)
    Cantidad producida (entero > 0) */
#include <iostream>
#include <iomanip>

using namespace std;

const int T = 10; // Variable para el numero de dias

int main ()
{
    int produccion[T] = {0};
    int tipo;
    long long tip1 = 0, tip2 = 0, tip3 = 0;

    for (int i = 0; i < T; i++)
    {
        cout << "Ingrese el tipo de envase en el dia " << i + 1 << endl;
        cin >> tipo;
        while ((tipo != 1) && (tipo != 2) && (tipo != 3))
        {
            cout << "Tipos de envase validos 1,2 y 3\nReingrese el tipo de envase en el dia " << i + 1 << endl;
            cin >> tipo; 
        }
        cout << "Ingrese la cantidad producida en el dia " << i + 1 << endl;
        cin >> produccion[i];
        if (produccion[i] <= 0)
        {
            cout << "Ingrese una cantidad positiva:\n";
            cin >> produccion[i];
        }
        
        if (tipo == 1)
        {
            tip1 += produccion[i];
        }
        else if (tipo == 2)
        {
            tip2 += produccion[i];
        }
        else if(tipo == 3)
        {
            tip3 += produccion[i];
        }
    }

    int max = -100;
    int day;

    for (int i = 0; i < T; i++)
    {
        if (max < produccion[i])
        {
            max = produccion[i];
            day = i + 1;
        }
    }

    cout << "\n======== Reporte =========" << endl << endl;
    cout << "Porcentaje que representa cada tipo del total: " << endl;
    cout << fixed << setprecision(2);
    cout << "Tipo 1: " << (tip1 * 100.0)/(tip1 + tip2 + tip3) << "%" << endl;
    cout << "Tipo 2: " << (tip2 * 100.0)/(tip1 + tip2 + tip3) << "%" << endl;
    cout << "Tipo 3: " << (tip3 * 100.0)/(tip1 + tip2 + tip3) << "%" << endl;
    cout << "El dia " << day << " fue el dia con mayor producción con " << max << endl;
    for (int i = 0; i < T; i++)
    {
        if (produccion[i] < 500)
        {
            cout << "La producción el dia " << i + 1 << " fue baja" << endl;
        }
        else if ((500 <= produccion[i])&&(produccion[i] <= 1000))
        {
            cout << "La producción el dia " << i + 1 << " fue media" << endl;
        }
        else if (produccion[i] > 1000) 
        {
            cout << "La producción el dia " << i + 1 << " fue alta" << endl;
        }   
        /* Los else if son para condiciones mutuamente excluyentes ya que una vez que encuentran una condicion verdadera, deja de ejecutar el resto de else if*/
    }
    return 0;    
}