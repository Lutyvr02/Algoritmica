#include <bits/stdc++.h>
using namespace std;
int tenermitad(int s, int e) { 
    return s + (e -s)/2; 
} //usado para poder sacar la mitad de los datos usando sus extremos
 
// Esta funcion se enfoca en sumar datos
int sumatotalherra(int *puntador, int inicio, int final, int inicioq, int finalq, int dato) {
    if (inicioq <= inicio && finalq >= final)
        return puntador[dato];
    if (final < inicioq || inicio > finalq)
        return 0;
    int mitad = tenermitad(inicio, final);
    return sumatotalherra(puntador, inicio, mitad, inicioq, finalq, 2*dato+1) +
        sumatotalherra(puntador, mitad+1, final, inicioq, finalq, 2*dato+2);
}
 
// esta funcion facilita la actualizacion de los datos, parecido a la sumatotal, pero, i es el dato a acutalizar
// diff es la cantidad que se debe sumar a los datos despues de cambiar un dato
void updatevalorherra(int *puntero, int inicio, int final, int i, int diff, int dato) {
    if (i < inicio || i > final)
        return;
    puntero[dato] = puntero[dato] + diff;
    if (final != inicio) {
        int mid = tenermitad(inicio, final);
        updatevalorherra(puntero, inicio, mid, i, diff, 2*dato + 1);
        updatevalorherra(puntero, mid+1, final, i, diff, 2*dato + 2);
    }
}
 
// se actualiza el arbol aqui, usa  It uses updatevalorherra() para poder cambiar los datos del arbol
void updateValue(int array[], int *puntero, int n, int i, int valornuevo) {
    if (i < 0 || i > n-1) {
        cout<<"dato incorrecto";
        return;
    }
    int diff = valornuevo - array[i];
    array[i] = valornuevo;
    updatevalorherra(puntero, 0, n-1, i, diff, 0);
}
 
// se obtienen la suma de un dato fijo a otro
int sumatotal(int *puntero, int n, int inicioquery, int finalquery) {
    if (inicioquery < 0 || finalquery > n-1 || inicioquery > finalquery) {
        cout<<"Datos incorrectos";
        return -1;
    }
    return sumatotalherra(puntero, 0, n-1, inicioquery, finalquery, 0);
}

// esta funcion es una herramienta para poder armar un segment tree apartir de un arreglo
int conssegherr(int arreglo[], int inicio, int final, int *puntero, int ubicacion) {
    if (inicio == final) {
        puntero[ubicacion] = arreglo[inicio];
        return arreglo[inicio];
    }
    int mid = tenermitad(inicio, final);
    puntero[ubicacion] = conssegherr(arreglo, inicio, mid, puntero, ubicacion*2+1) +
            conssegherr(arreglo, mid+1, final, puntero, ubicacion*2+2);
    return puntero[ubicacion];
}
 
// se arma un segment tree a partir de un arreglo dado
int *consseg(int arr[], int n) {
    int x = (int)(ceil(log2(n)));
    int tamaximo = 2*(int)pow(2, x) - 1;
    int *puntero = new int[tamaximo];
    conssegherr(arr, 0, n-1, puntero, 0);
    return puntero;
}

// inicializacion
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *st = consseg(arr, n);
    updateValue(arr, st, n, 1, 10);
    return 0;
}
