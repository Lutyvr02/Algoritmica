// Forma recursiva del binary search
#include <bits/stdc++.h>
using namespace std;
//recibe una funcion, un arrary, el inicio, el final y el nuemro a buscar
int binarySearch(int arreglo[], int inicio, int final, int objetivo){
    if (final >= inicio) {
        int mid = inicio + (final - inicio) / 2;
        if (arreglo[mid] == objetivo)
            return mid;
 
        if (arreglo[mid] > objetivo)
            return binarySearch(arreglo, inicio, mid - 1, objetivo);

        return binarySearch(arreglo, mid + 1, final, objetivo);
    }
    return -1;
}
 
int main(void){
    int arreglo[] = { 2, 3, 4, 10, 40 };
    int objetivo = 10;
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    int resultado = binarySearch(arreglo, 0, n - 1, objetivo);
    (resultado == -1)
        ? cout << "El objetivo no esta en el arreglo"
        : cout << "El objetivo esta en: " << resultado;
    return 0;
}
