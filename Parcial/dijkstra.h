/**
 * Archivo : dijkstra.h      Fecha: 23/09/2021
 * Autores: Luis Gabriel Banegas
 *
 * UBP
 */

#include <vector>
#include <iostream>
using namespace std;

// Esta función retorna el vertice del camino mas corto evitando los vertices ya procesados
int distanciaMinima(int distancias[], bool verticeMarcado[])
{
    // Inicializa variables
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (verticeMarcado[v] == false && distancias[v] <= min) {
            min = distancias[v];
            min_index = v;
        }
    }
    return min_index;
}

// Muestra por pantalla las distancias almacenadas en el vector
void mostrarCaminos(int distancias[], vector<string> vertices)
{
    cout << "Vertice  |  Distancia desde el origen" << endl;
    for (int i = 0; i < V; i++)
        cout << vertices[i] << " \t\t" << distancias[i] << endl;
}

// Implementacion de algoritmo de Dijkstra para buscar el camino mas corto
// Utilizando una matriz de adyacencia
void dijkstra(vector<vector<int>> matriz, int origen, vector<string> vertices)
{
    // Array que contiene las distancias al origen
    int distancias[V];

    // Array de booleanos que marcara los vertices como visitados
    bool verticeMarcado[V]; 

    // Inicializa todas las distancias como infinito y los vertices como no marcado
    for (int i = 0; i < V; i++)
        distancias[i] = INT_MAX,
        verticeMarcado[i] = false;

    // La distancia del origen al origen es 0
    distancias[origen] = 0;

    // Busca el camino mas corto en todos los vertices
    for (int count = 0; count < V - 1; count++) {
        // Devuelve el vertice actual, evaluando el camino mas corto para llegar a este
        int u = distanciaMinima(distancias, verticeMarcado);

        // Marca el vertice como procesado
        verticeMarcado[u] = true;

        for (int v = 0; v < V; v++)
            // Se actualiza la distancia si el vertice actual (u) no esta marcado,
            // y el peso total del camino desde el origen a v pasando por u 
            // es menor al calculado anteriormente
            if (!verticeMarcado[v] && matriz[u][v] && distancias[u] != INT_MAX
                && distancias[u] + matriz[u][v] < distancias[v])
                distancias[v] = distancias[u] + matriz[u][v];
    }

    mostrarCaminos(distancias, vertices);
}
