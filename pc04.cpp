#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int T = 5;

int main ()
{
    // Arreglos con los tipos de eventos
/*
  =======================================================
  CATÁLOGO DE EVENTOS (PC04 - OBLIGATORIO)
  =======================================================
  | Código | Tipo de Evento                             |
  |--------|--------------------------------------------|
  | E001   | Incidente sin lesión                       |
  | E002   | Accidente leve                             |
  | E003   | Accidente incapacitante                    |
  | E004   | Accidente fatal                            |
  | E005   | Casi accidente                             |
  =======================================================
*/
    string codigos[T] = {"E001", "E002", "E003", "E004", "E005"};
    string descripciones[T] = {
        "Incidente sin lesión",
        "Accidente leve",
        "Accidente incapacitable",
        "Accidente fatal",
        "Casi accidente"
    };
    string areas[T] = {
        "Mina Subterránea", 
        "Planta", 
        "Mantenimiento", 
        "Logística", 
        "Geología"
    };

    int conteos[T] = {0}; // Contador por tipo de evento

    // Límites para generar número aleatorio de eventos
    int limite_inf = 80;
    int limite_sup = 100;

    srand(time(NULL)); // Semilla para números aleatorios

    // Número total de eventos entre 80 y 100
    int eventos = limite_inf + rand() % (limite_sup - limite_inf + 1);

    // Generación de eventos
    for (int i = 0; i < eventos; i++)
    {
        // Tipo de evento aleatorio
        int tipo = rand() % T;

        // Área aleatoria donde ocurrió el evento
        int areaAleatoria = rand() % T;

        cout << "Evento " << i + 1 << ": "
             << codigos[tipo] << " - "
             << descripciones[tipo] << " --> "
             << areas[areaAleatoria] << endl;

        // Se incrementa el conteo del tipo de evento
        conteos[tipo]++;
    }

    cout << "\n";

    // Mostrar alertas (si hay)
    cout << "Alertas detectadas:\n";
    for (int i = 0; i < T; i++)
    {
        if (conteos[i] >= 10)
        {
            cout << "⚠ " << codigos[i] << " - "
                 << descripciones[i] << " --> "
                 << conteos[i] << " casos" << endl;
        }
    }

    // Solicitud del número de trabajadores
    int trabajadores;
    do
    {
        cout << "\nIngrese el número de trabajadores: ";
        cin >> trabajadores;
    } while (trabajadores <= 0);

    // Cálculo de indicadores
    const int HORAS_MES = 160; // 8 horas x 20 días
    double HH = HORAS_MES * 12 * trabajadores; // Horas-hombre anuales

    // Índice de frecuencia: solo accidentes incapacitantes
    double TF = (conteos[2] * 1000000.0) / HH;

    // Tasa de severidad: ponderada (10 puntos por incapacitantes y 30 por fatales)
    double TS = ((conteos[2] * 10 + conteos[3] * 30) * 1000000.0) / HH;

    // Índice de incidentabilidad en porcentaje
    double II = (eventos * 100.0) / trabajadores;

    // Reporte final
    cout << "\n===== REPORTE FINAL DE SEGURIDAD =====\n\n";

    for (int i = 0; i < T; i++)
    {
        cout << codigos[i] << " - " << descripciones[i]
             << ": " << conteos[i] << endl;
    }

    cout << "\nIndicadores:\n";
    cout << fixed << setprecision(2); // Mostrar valores con dos decimales
    cout << "TF = " << TF << endl;
    cout << "TS = " << TS << endl;
    cout << "II = " << II << "%" << endl;

    // Recomendación final según indicadores
    cout << "\nRecomendación:\n";
    if (TF > 10 || TS > 20)
    {
        cout << "Reforzar capacitaciones y supervisiones.\n";
    }
    else
    {
        cout << "Mantener controles actuales.\n";
    }

    return 0;
}