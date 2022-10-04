#include <bits/stdc++.h>
using namespace std;

//BIT usado para poder obtener la suma de valores hasta un punto 
int getSum(int BITree[], int index) {
    int sum = 0;
    index = index + 1;
    while (index>0) {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}
  
// se actualiza el bit, con un valor n, el cual se saca de la inicializacion, el index que representa el punto a cambiar y el valor
// nuevo, ademas, se mueven los datos que no se cambian y despues de añade el valor y al final se actualiza la vista del padre  
void updateBIT(int BITree[], int n, int index, int val) {
    index = index + 1;
    while (index <= n) {
    BITree[index] += val;
    index += index & (-index);
    }
}
  
// se empieza a construir el arbol del BIT, con datos binarios, para un array de tamaño n
// su valor predeterminado es 0 y se usa update para poder aplicar esos datos
int *constructBITree(int arr[], int n) {
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);

    return BITree;
}
  
// se inicializa todo el BIT  
int main() {
    int numeros[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(numeros)/sizeof(numeros[0]);
    int *BIT = constructBITree(numeros, n);
    numeros[3] += 6;
    updateBIT(BIT, n, 3, 6);
    return 0;
}
