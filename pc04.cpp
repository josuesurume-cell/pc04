#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int T = 5;

<<<<<<< HEAD
=======
void indicadores(int); // prototipo de funciones

>>>>>>> 6e9d78d0a94395fb06bb435b5d47d2983c5b4a6e
int main ()
{
    string codigos[T] = {"E001", "E002", "E003", "E004", "E005"};
    string descripciones[T] = {"Incidente sin lesión", "Accidente leve", "Accidente incapacitable", "Accidente fatal", "Casi accidente"}; // esto indica el tipo de evento
    string areas[T] = {"Mina Subterránea", "Planta", "Mantenimiento", "Logística", "Geología"};
    int conteos[T] = {0};
    int limite_inf, limite_sup;
    srand (time(nullptr));
    limite_inf = 80;
    limite_sup = 100;
    int eventos; //Indica el numero de eventos que se van a realizar
    int a; // variable que guardara el codigo aleatorio
    eventos = limite_inf + rand()%(limite_sup - limite_inf + 1);
    for (int i = 0; i < eventos; i++)
    {
        a = rand()%(T);
        cout << "Evento " << i + 1 << ": " << codigos[a] << " - " << descripciones[a] << " --> " << areas[rand()%(T)] << endl;
        conteos[a] += 1;
    }
    cout << "\n";
    for (int i = 0; i < T; i++) // condiciones para la alerta
    {
        if (conteos[i] >= 10)
        {
            cout << "⚠ Alerta: "<< codigos[i]<< " - " << descripciones[i] << " --> " << conteos[i] <<" casos" << endl;
        }
    }
    int trabajadores;
    double HH; // horas-hombre al año 
    double TF; // tasa de frecuencia
    double TS; //tasa de severidad
    double II; // Índice de incidentabilidad (%)
    cout << "\nIngrese el numero de trabajadores: " << endl;
    cin >> trabajadores;
    while (trabajadores <= 0)
    {
        cout << "Ingrese el numero de trabajadores: " << endl;
        cin >> trabajadores;
    }
    
    HH = 160.0 * 12 * trabajadores;

    TF = (conteos[2]*1000000.0)/HH;

    TS = ((conteos[2]*10 + conteos[3]*30)*1000000.0)/HH;

    II = ((eventos * 100.0)/trabajadores); //multiplicamos por 100.0 para evitar el truncamiento de los decimales int/int
    
    cout << "\n===== REPORTE FINAL DE SEGURIDAD =====" << endl;
    cout << "\n";
    for (int i = 0; i < T; i++)
    {
        cout << codigos[i] << " - " << descripciones[i] << ": " << conteos[i] << endl;
    }
    cout << "\n";
    cout << "Alertas: " << endl;
    for (int i = 0; i < T; i++)
    {
        if (conteos[i] >= 10)
        {
            cout << "⚠ "<< codigos[i]<< " - " << conteos[i] <<" casos" << endl;
        }
    }
    cout << "\n";
    cout << "Indicadores: " << endl;
    cout << fixed << setprecision(2); //muestra los resultados con 2 decimales
    cout << "TF = " << TF << endl;
    cout << "TS = " << TS << endl;
    cout << "II = " << II << " %" << endl;
    cout << "\n";

    cout << "Recomendación: " << endl;
    if ((TF > 10)||(TS > 20))
    {
        cout << "Reforzar capacitaciones y supervisiones" << endl;
    }
    else
    {
        cout << "Mantener controles actuales" << endl;
    }
    return 0;
}