/**
 * Archivo : recorridos.h      Fecha: 23/09/2021
 * Autores: Luis Gabriel Banegas
 *
 * UBP
 */

#include <vector>
#include <iostream>
#include <list>
using namespace std;

bool verticesVisitados[V]; 

void clearVisitados() {
    for (int i = 0; i < V; i++) {
        verticesVisitados[i] = false;
    }
}

void recursiveDFS(int origen, vector<pair<int, int>> aristas[], vector<string> vertices)
{
    // Marca un vertice como visitado e imprime en pantalla
    verticesVisitados[origen] = true;
    cout << vertices[origen] << " ";

    // De forma recursiva para los vertices adyacentes no visitados
    for (auto i = aristas[origen].begin(); i != aristas[origen].end(); i++)
        if (!verticesVisitados[i->first])
            cout << "-> ", 
            recursiveDFS(i->first, aristas, vertices);
}

void DFS(int origen, vector<pair<int, int>> aristas[], vector<string> vertices) {
    clearVisitados();
    recursiveDFS(origen, aristas, vertices);
}

void BFS(int origen, vector<pair<int, int>> aristas[], vector<string> vertices)
{
    // Marca todos los vertices como no visitados
    clearVisitados();

    // Create a queue for BFS
    list<int> colaVertices;

    // Marca el vertice como visitado y lo agrega a la cola
    int verticeActual = origen;
    verticesVisitados[verticeActual] = true;
    colaVertices.push_back(verticeActual);

    while (!colaVertices.empty())
    {
        // Saca de la cola el vertice y lo imprime
        verticeActual = colaVertices.front();
        cout << " -> " << vertices[verticeActual] ;
        colaVertices.pop_front();

        // Toma todos los vertices adyacentes del que quito de la cola
        // si algun adyacente no fue visitado lo marca como visitado 
        // y lo ingresa a la cola
        for (auto i = aristas[verticeActual].begin(); i != aristas[verticeActual].end(); i++)
        {
            if (!verticesVisitados[i->first])
            {
                verticesVisitados[i->first] = true;
                colaVertices.push_back(i->first);
            }
        }
    }
}
