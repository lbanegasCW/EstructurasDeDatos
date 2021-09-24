/**
 * Archivo : hamilton.h      Fecha: 23/09/2021
 * Autores: Luis Gabriel Banegas
 *
 * UBP
 */

#include <vector>
#include <iostream>
#include <algorithm> 

using namespace std;

void caminoDelViajero(int origen, vector<vector<int>> matriz)
{
    // Guarda todos los vertices sin tener en cuenta el origen
    vector<int> vertices;
    for (int i = 0; i < V; i++)
        if (i != origen)
            vertices.push_back(i);

    // Inicializa las variables
    int pesoMinimo = INT_MAX;
    do {
        int pesoActual = 0;

        // Evalua el camino segun el orden 
        // almacenado en el array vertices
        int k = origen;
        for (int i = 0; i < vertices.size(); i++) {
            pesoActual += matriz[k][vertices[i]];
            k = vertices[i];
        }
        // Guarda el peso del camino actual
        pesoActual += matriz[k][origen];

        // Actualiza el peso del camino
        pesoMinimo = min(pesoMinimo, pesoActual);

    } while (
        // La funcion next_permutation funciona como combinatoria
        // Por lo que sera la estructura de control, finalizando 
        // Cuando todas las combinaciones de recorridos ya se dieron
        next_permutation(vertices.begin(), vertices.end()));

    cout << "El recorrido minimo es de: " << pesoMinimo;
}