/**
 * Archivo : grafo.h      Fecha: 23/09/2021
 * Autores: Luis Gabriel Banegas
 *
 * UBP
 */

#include <vector>
#include <iostream>
using namespace std;

 // Metodo para agregar aristas
void addArista(vector<pair<int, int>> aristas[], int verticeUno, int verticeDos, int peso)
{
    aristas[verticeUno].push_back(make_pair(verticeDos, peso));
    aristas[verticeDos].push_back(make_pair(verticeUno, peso));
}

// Convertimos la lista en una matriz de adyacencia
vector<vector<int> > listaToMatriz(vector<pair<int, int>> aristas[])
{
    // Inicializo la matriz
    vector<vector<int> > matriz(V, vector<int>(V, 0));

    // Voy recorriendo y armando la matriz, utilizando el peso para indicar adyacencia
    for (int i = 0; i < V; i++) {
        for (auto j = aristas[i].begin(); j != aristas[i].end(); j++)
            matriz[i][j->first] = j->second;
    }
    return matriz;
}

// Imprime en pantalla los nodos como una lista de adyacencia
void showLista(vector<string> vertices, vector<pair<int, int>> aristas[])
{
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Vertice " << vertices[u] << " forma una arista con: \n";
        for (auto it = aristas[u].begin(); it != aristas[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tVertice " << vertices[v] << " con peso: "
                << w << "\n";
        }
        cout << "\n";
    }
}

// Imprime en pantalla los nodos como una matriz de adyacencia
void showMatriz(vector<vector<int>> matriz, vector<string> vertices)
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

// Segun nombre de vertice devuelve el indice del mismo
int indexarVertice(string vertice, vector<string> vertices)
{
    for (int i = 0; i < V; i++) {
        if (vertice.compare(vertices[i]) == 0) {
            return i;
        }
    }
}
