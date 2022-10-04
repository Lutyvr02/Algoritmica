#include <bits/stdc++.h>
using namespace std;
 
// se usan los bordes de este grafo para poder armarlo
class borde {
public:
    int Buscar, destino;
};
 
// se representa el borde de este para ver el grafo y se crea el grafo apartir de los bordes
class grafo {
public:
    int Vertices, Bordes;
    borde* bardo;
};
// se instancia un nuevo grafo con una cantidad de vertices y de bordes definida
grafo* creargrafo(int Vertices, int Bordes) {
    grafo* grafus = new grafo();
    grafus->Vertices = Vertices;
    grafus->Bordes = Bordes;
    grafus->bardo = new borde[grafus->Bordes * sizeof(borde)];
    return grafus;
}
 
// Funcion para poder encontrar el subset de un numero i
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}
 
// Funcion de unir a 2 subsets
void Union(int parent[], int x, int y) { 
    parent[x] = y; 
}
  
// inicializacion
int main() {

    int V = 3, B = 3;
    grafo* grifo = creargrafo(V, B);
    grifo->bardo[0].Buscar = 0;
    grifo->bardo[0].destino = 1;
    grifo->bardo[1].Buscar = 1;
    grifo->bardo[1].destino = 2;
    grifo->bardo[2].Buscar = 0;
    grifo->bardo[2].destino = 2;
}
