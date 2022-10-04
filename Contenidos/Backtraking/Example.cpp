#include <bits/stdc++.h>
using namespace std;
// se usara el ejemplo del un laberinto para ratas
#define N 4

// se hace un boolean para verificar si la rata soluciona el laberinto 
bool laberintoherra(int laberin[N][N], int x, int y,int solucion[N][N]);
 
// Se imprime la solucion
void mostrsolu(int solucion[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout<<" "<<solucion[i][j]<<" ";
        cout<<endl;
    }
}
 
// se verifica si las coordenadas x y y son validas para el laberinto
bool movseguro(int laberin[N][N], int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N && laberin[x][y] == 1)
        return true;
    return false;
}
 
// esta funcion se la usa para solucionar el laberinto usando backtraking, usa bool laberintoherra() parapoder hacerlo
bool resollab(int laberin[N][N]) {
    int solucion[N][N] = { { 0, 0, 0, 0 },
                           { 0, 0, 0, 0 },
                           { 0, 0, 0, 0 },
                           { 0, 0, 0, 0 } };
    if (laberintoherra(laberin, 0, 0, solucion) == false) {
        cout<<"La solucion no existe";
        return false;
    }
    mostrsolu(solucion);
    return true;
}
 
// la funcion es recursiva para poder solucionar el laberinto
bool laberintoherra(int laberin[N][N], int x, int y, int solucion[N][N]) {
    if (x == N - 1 && y == N - 1 && laberin[x][y] == 1) {
        solucion[x][y] = 1;
        return true;
    }
    if (movseguro(laberin, x, y) == true) {
        if (solucion[x][y] == 1)
            return false;
        solucion[x][y] = 1;
        if (laberintoherra(laberin, x + 1, y, solucion) == true)
            return true;
        if (laberintoherra(laberin, x, y + 1, solucion) == true)
            return true;
        // BACKTRACK: si moverse a x o a y es un movimiento invalido, entonces se retrocede
        solucion[x][y] = 0;
        return false;
    }
    return false;
}
 
// inicializacion
int main() {
    int laberin[N][N] = { { 1, 0, 0, 0 },
                          { 1, 1, 0, 1 },
                          { 0, 1, 0, 0 },
                          { 1, 1, 1, 1 } };
    resollab(laberin);
    return 0;
}
