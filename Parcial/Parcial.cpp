/**
 * Archivo : Parcial.cpp      Fecha: 23/09/2021
 * Autores: Luis Gabriel Banegas
 *
 * UBP
 */

#define V 5
#include <vector>
#include <iostream>
#include "grafo.h"
#include "dijkstra.h"
#include "hamilton.h"
#include "recorridos.h"
#include "floydWarshall.h"
using namespace std;

// Driver code
int main()
{    
    // Vector de referencia para utilizar nombres en vertices
    vector<string> vertices;

    // Vector que almacena las aristas y el peso
    vector<pair<int, int> > aristas[V];

    // Funcion que convierte lista a matriz
    vector<vector<int> > matrizAdyacencia;
    
    int menuOption;
    do {
        cout << endl << endl;
        cout << "1. Ingresar Vertices" << endl;
        cout << "2. Ingresar Aristas" << endl;
        cout << "3. Lista de adyacencia" << endl;
        cout << "4. Matriz de adyacencia" << endl;
        cout << "5. Camino mas corto con Dijkstra" << endl;
        cout << "6. Camino por Floyd-Warshall" << endl;
        cout << "7. Recorrido en profundidad" << endl;
        cout << "8. Recorrido en anchura" << endl;
        cout << "9. Camino del viajero" << endl;
        cout << "0. Salir" << endl;
        cout << endl << "Elija una opcion: ";
        cin >> menuOption;
        switch (menuOption) {
              case 1: {
                  system("cls");
                  for (int i = 0; i < V; i++) {
                      cout << endl << "Ingrese nombre de vertice " << i+1 << ": " << endl;
                      string nombre;
                      cin >> nombre;
                      vertices.push_back(nombre);
                  }
                  break;
            } case 2: {
                  char aristOption = 'n';
                  do {
                      system("cls");
                      string verticeUno, verticeDos;
                      int peso;

                      cout << endl << "Ingrese primer vertice: ";
                      cin >> verticeUno;
                      cout << endl << "Ingrese segundo vertice: ";
                      cin >> verticeDos;
                      cout << endl << "Ingrese peso: ";
                      cin >> peso;

                      addArista(aristas, indexarVertice(verticeUno, vertices), indexarVertice(verticeDos, vertices), peso);

                      cout << endl << "Desea agregar otra? (s/n): ";
                      cin >> aristOption;
                  }
                  while (tolower(aristOption) == 's');
                  break;
            } case 3: {
                system("cls");
                cout << "Lista de adyacencia: \n";
                showLista(vertices, aristas);
                break;
            } case 4: {
                system("cls");
                cout << "Matriz de adyacencia: \n";
                matrizAdyacencia = listaToMatriz(aristas);
                showMatriz(matrizAdyacencia, vertices);
                break;
            } case 5: {
                system("cls");
                matrizAdyacencia = listaToMatriz(aristas);
                cout << endl << "Ingrese vertice de origen: ";
                string origen;
                cin >> origen;
                dijkstra(matrizAdyacencia, indexarVertice(origen, vertices), vertices);
                break;
            } case 6: {
                system("cls");
                matrizAdyacencia = listaToMatriz(aristas);
                floydWarshall(matrizAdyacencia, vertices);
                break;
            } case 7: {
                system("cls");
                cout << endl << "Ingrese vertice de origen: ";
                string origen;
                cin >> origen;
                cout << endl << "Recorrido en profundidad: " << endl;
                DFS(indexarVertice(origen, vertices), aristas, vertices);
                break;
            } case 8: {
                system("cls");
                cout << endl << "Ingrese vertice de origen: ";
                string origen;
                cin >> origen;
                cout << endl << "Recorrido en anchura: " << endl;
                BFS(indexarVertice(origen, vertices), aristas, vertices);
                break;
            } case 9: {
                system("cls");
                matrizAdyacencia = listaToMatriz(aristas);
                cout << endl << "Ingrese vertice de origen: ";
                string origen;
                cin >> origen;
                cout << endl << "Camino del viajero: " << endl;
                caminoDelViajero(indexarVertice(origen, vertices), matrizAdyacencia);
                break;
            } default: {
                cout << "Elija una opcion valida" << endl;
            }
        }
    }
    while (menuOption != 0);

    return 0;
}