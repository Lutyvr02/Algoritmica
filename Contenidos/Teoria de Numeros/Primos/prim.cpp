#include <bits/stdc++.h>
using namespace std;
#define vertices 5
 
int minKey(int llave[], bool mrset[]){
    int minimo = INT_MAX, minindex;
 
    for (int v = 0; v < vertices; v++)
        if (mrset[v] == false && llave[v] < minimo)
            minimo = llave[v], minindex = v;
 
    return minindex;
}
void mostrar(int padre[], int grafo[vertices][vertices]){
    cout << "Esquina: \t Peso: \n";
    for (int i = 1; i < vertices; i++)
        cout << padre[i] << " - " << i << " \t"
             << grafo[i][padre[i]] << " \n";
}

void prim(int grafo[vertices][vertices]){
    int padre[vertices];
    int llave[vertices];
    bool mrset[vertices];

    for (int i = 0; i < vertices; i++)
        llave[i] = INT_MAX, mrset[i] = false;
 
    llave[0] = 0;
    padre[0] = -1;
 
    for (int i = 0; i < vertices - 1; i++) {
        int u = minKey(llave, mrset);
        mrset[u] = true;
        for (int v = 0; v < vertices; v++)
            if (grafo[u][v] && mrset[v] == false
                && grafo[u][v] < llave[v])
                padre[v] = u, llave[v] = grafo[u][v];
    }
    mostrar(padre, grafo);
}

int main(){
    int grafo[vertices][vertices] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    prim(grafo);
    return 0;
}
