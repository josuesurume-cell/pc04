#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main (){
    int matriz [5][5];
    int limite_inferior, limite_superior;
    srand (time(nullptr));

    limite_inferior = 1;
    limite_superior = 10;
    
    int s = 0;
    for (int i = 0; i<5; i++){
        for (int j=0;j<5;j++){
            matriz[i][j] = limite_inferior + rand()%(limite_superior + 1 - limite_inferior);
            if (j<4){
            cout << matriz[i][j] << "\t";
            }
            if (j == 4){
                cout << matriz[i][j] << "\n";
            }
            if ((i == j)||((i+j) == 4)){
                s += matriz [i][j];
            }

        }
    }
    cout << "\nLa suma de las diagonales de la matriz es: " << s << endl;
    return 0;
}