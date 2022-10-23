#include <bits/stdc++.h>
using namespace std;
  
bool isSubsetSum(int arreglo[], int nro, int numero){
    bool subset[nro + 1][numero + 1];
    for (int i = 0; i <= nro; i++)
        subset[i][0] = true;
  
    for (int i = 1; i <= numero; i++)
        subset[0][i] = false;
  
    for (int i = 1; i <= nro; i++) {
        for (int j = 1; j <= numero; j++) {
            if (j < arreglo[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= arreglo[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - arreglo[i - 1]];
        }
    }
    return subset[nro][numero];
}
  
int main(){
    int arreglo[] = { 3, 34, 4, 12, 5, 2 };
    int numero = 9;
    int nro = sizeof(arreglo) / sizeof(arreglo[0]);
    if (isSubsetSum(arreglo, nro, numero) == true)
        cout <<"Se encontro el numero";
    else
        cout <<"No se encontro el numero";
    return 0;
}
