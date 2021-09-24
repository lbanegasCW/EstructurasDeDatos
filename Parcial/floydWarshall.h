/**
 * Archivo : floydWarshall.h      Fecha: 23/09/2021
 * Autores: Luis Gabriel Banegas
 *
 * UBP
 */

#include <vector>
#include <iostream>
using namespace std;

// Valor utilizado para vertices sin conexion
#define INF 99999
int matrizFloydWarshall[V][V];

// Funcion que adapta la matriz de adyacencia al formato
// utilizado por Floyd-Warshall
void transformMatriz(vector<vector<int>> matriz){
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j && matriz[i][j] == 0) {
                matrizFloydWarshall[i][j] = INF;
            } else {
                matrizFloydWarshall[i][j] = matriz[i][j];
            }
        }
    }
}

// Imprime en pantalla los caminos de Floyd-Warshall
void showMatrizFW(int matriz[V][V], vector<string> vertices)
{
    for (int i = 0; i < V; i++) {
        cout << "   " << vertices[i] << "  ";
    }
    cout << endl;
    for (int i = 0; i < V; i++) {
        cout << vertices[i];
        for (int j = 0; j < V; j++) {
            printf("  %02d  ", matriz[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

void floydWarshall(vector<vector<int>> matrizOrigen, vector<string> vertices) {
    transformMatriz(matrizOrigen);

    int i, j, k;

    /* Esta rutina va seleccionando uno a uno los elementos de una fila y los elementos de una columna 
    *  de la matriz. En esa comparacion, evalua que ambos elementos sean distintos de el valor maximo (INF)
    *  en el caso que se cumpla esto, evalua con el elemento que forma la interseccion de la fila y columna 
    *  seleccionada. Si este es mayor a la suma del elemento de la fila y el elemento de la columna, 
    *  se sobreescribira el valor.
    */
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (matrizFloydWarshall[i][j] > (matrizFloydWarshall[i][k] + matrizFloydWarshall[k][j])
                    && (matrizFloydWarshall[k][j] != INF
                        && matrizFloydWarshall[i][k] != INF))
                    matrizFloydWarshall[i][j] = matrizFloydWarshall[i][k] + matrizFloydWarshall[k][j];
            }
        }
    }
    showMatrizFW(matrizFloydWarshall, vertices);
}