#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Constante global para el tamaño de los arreglos (T = 5 tipos de eventos)
const int T = 5;

// =========================================================
// 1. PROTOTIPOS DE FUNCIONES (Funciones obligatorias)
// =========================================================

// Inicializa el arreglo de contadores a cero.
void inicializarContadores(int conteos[]);

// Ejecuta la simulación de eventos, llena el arreglo conteos y retorna N_eventos.
void simularRegistros(const string codigos[], const string descripciones[], const string areas[], 
                      int conteos[], int &eventos);

// Calcula los indicadores TF, TS, II y los devuelve por referencia (&).
void calcularIndicadores(int N_eventos, int N_incapacitantes, int N_fatales, int trabajadores, 
                          double &TF, double &TS, double &II);

// Muestra el reporte final consolidado, las alertas y la recomendación.
void mostrarReporte(const string codigos[], const string descripciones[], const int conteos[], 
                    double TF, double TS, double II);

// =========================================================
// 2. FUNCIÓN PRINCIPAL (MAIN) - Control del Flujo
// =========================================================

int main() {
    // DECLARACIÓN DE VARIABLES Y ARREGLOS BASE
    string codigos[T] = {"E001", "E002", "E003", "E004", "E005"};
    string descripciones[T] = {"Incidente sin lesión", "Accidente leve", "Accidente incapacitante", "Accidente fatal", "Casi accidente"};
    string areas[T] = {"Mina Subterránea", "Planta", "Mantenimiento", "Logística", "Geología"};
    int conteos[T]; // Array de contadores.
    int eventos;    // Número total de eventos simulados (80-100).
    int trabajadores; // Número de trabajadores ingresado por el usuario.
    
    // Variables de salida de la función calcularIndicadores (Parámetros por Referencia)
    double TF, TS, II; 
    
    // CONFIGURACIÓN INICIAL
    srand(time(nullptr)); // Seed the generator ONCE.

    // 1. INICIALIZAR
    inicializarContadores(conteos);

    // 2. SIMULACIÓN Y REGISTRO (Llena conteos[] y eventos)
    simularRegistros(codigos, descripciones, areas, conteos, eventos);

    // 3. ENTRADA DE TRABAJADORES (Punto C: Solicitud al usuario)
    cout << "\n-----------------------------------------------------" << endl;
    cout << "Ingrese el numero total de trabajadores para el calculo: " << endl;
    cin >> trabajadores;
    while (trabajadores <= 0) {
        cout << "Valor invalido. Ingrese un numero de trabajadores mayor a 0: " << endl;
        cin >> trabajadores;
    }

    // 4. CÁLCULO DE INDICADORES
    // Se extraen conteos[2] y conteos[3] para la función
    calcularIndicadores(eventos, conteos[2], conteos[3], trabajadores, TF, TS, II);

    // 5. REPORTE FINAL Y ALERTAS
    mostrarReporte(codigos, descripciones, conteos, TF, TS, II);

    return 0;
}

// =========================================================
// 3. DEFINICIONES DE FUNCIONES
// =========================================================

// Inicializa todos los elementos del arreglo conteos a 0.
void inicializarContadores(int conteos[]) {
    for (int i = 0; i < T; i++) {
        conteos[i] = 0;
    }
}

// Ejecuta la simulación de eventos, llena el arreglo conteos y devuelve N_eventos.
void simularRegistros(const string codigos[], const string descripciones[], const string areas[], 
                      int conteos[], int &eventos) {
    
    int limite_inf = 80;
    int limite_sup = 100;
    int indice_evento; // Guarda el índice aleatorio del tipo de evento (0-4)
    int indice_area;   // Guarda el índice aleatorio del área (0-4)

    // Genera N_eventos entre 80 y 100
    eventos = limite_inf + rand() % (limite_sup - limite_inf + 1);

    cout << "\n===== SIMULACION: Generando " << eventos << " eventos aleatorios =====" << endl;

    for (int i = 0; i < eventos; i++) {
        // Genera el índice aleatorio del evento y del área
        indice_evento = rand() % T;
        indice_area = rand() % T; 
        
        // Imprime el registro del evento
        cout << "Evento " << i + 1 << ": " << codigos[indice_evento] << " - " 
             << descripciones[indice_evento] << " -> Area: " 
             << areas[indice_area] << endl;
        
        // Incrementa el contador correspondiente
        conteos[indice_evento] += 1;
    }
}

// Calcula los indicadores TF, TS, II y los devuelve por referencia (&).
void calcularIndicadores(int N_eventos, int N_incapacitantes, int N_fatales, int trabajadores, 
                          double &TF, double &TS, double &II) {
    
    // 1. Horas-Hombre (HH)
    // Se usa double para asegurar la precisión del resultado
    double HH = 160.0 * 12 * trabajadores; 

    // 2. Tasa de Frecuencia (TF)
    // N_incapacitantes es conteos[2]
    TF = (N_incapacitantes * 1000000.0) / HH;

    // 3. Tasa de Severidad (TS)
    // N_fatales es conteos[3]
    TS = ((N_incapacitantes * 10.0 + N_fatales * 30.0) * 1000000.0) / HH;

    // 4. Índice de Incidentabilidad (II)
    // Se usa static_cast<double> para evitar la división entera (II siempre sería 0)
    II = (static_cast<double>(N_eventos) / trabajadores) * 100.0; 
}


// Muestra el reporte final consolidado, las alertas y la recomendación.
void mostrarReporte(const string codigos[], const string descripciones[], const int conteos[], 
                    double TF, double TS, double II) {

    // --- REPORTE FINAL ---
    cout << "\n\n===== REPORTE FINAL DE SEGURIDAD =====" << endl;
    cout << "\n--- Conteo Total de Eventos ---\n";

    for (int i = 0; i < T; i++) {
        cout << codigos[i] << " - " << descripciones[i] << ": " << conteos[i] << endl;
    }
    
    // --- ALERTAS (Punto B) ---
    cout << "\n--- Alertas Activas (>= 10 casos) ---\n";
    bool alerta_activa = false;
    for (int i = 0; i < T; i++) {
        if (conteos[i] >= 10) {
            cout << "⚠ ALERTA: "<< codigos[i]<< " - " << descripciones[i] << " --> " << conteos[i] <<" casos" << endl;
            alerta_activa = true;
        }
    }
    if (!alerta_activa) {
        cout << "No se registraron alertas críticas." << endl;
    }

    // --- INDICADORES (Punto C/D) ---
    cout << "\n--- Indicadores de Seguridad ---\n";
    // Muestra los resultados con dos decimales
    cout << fixed << setprecision(2); 
    
    cout << "Tasa de Frecuencia (TF) = " << TF << endl;
    cout << "Tasa de Severidad (TS)  = " << TS << endl;
    cout << "Indice de Incidentabilidad (II) = " << II << " %" << endl;

    // --- RECOMENDACIÓN (Punto D) ---
    cout << "\n--- Recomendación Automática ---\n";
    if ((TF > 10.0) || (TS > 20.0)) { // Se usan 10.0 y 20.0 para comparar con double
        cout << "Reforzar capacitaciones y supervisiones" << endl;
    } else {
        cout << "Mantener controles actuales" << endl;
    }
}