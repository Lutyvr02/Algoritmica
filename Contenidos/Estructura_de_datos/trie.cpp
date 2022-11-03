#include <bits/stdc++.h>
using namespace std;
 
const int alfabeto = 26; //un numero no cambiante, en si una constante
struct Nodos { // Se crea una estructura las cual se llamara trienode, dentro de esta 
//ademas se crean nodos dependiendo la cantidad de alfabeto y se les asigna un bool indicando si son palabras finales
    struct Nodos *hijos[alfabeto];
    bool finaldepalabra;
};
 
// Se inicializan nodos en null 
struct Nodos *getNode(void) {
    struct Nodos *nodoac =  new Nodos;
    nodoac->finaldepalabra = false;
    for (int i = 0; i < alfabeto; i++)
        nodoac->hijos[i] = NULL;
    return nodoac;
}
 
// Se inserta una palabra a el nodo
// por la logitud de la palabra, se crea un index que representa un int que es la palabra - a en ASCII
//el final de la palabra es true
void insert(struct Nodos *root, string key) {
    struct Nodos *ty = root;
    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (!ty->hijos[index]){
            ty->hijos[index] = getNode();
        }
        ty = ty->hijos[index];
    }
    ty->finaldepalabra = true;
}
 
// Se busca la palabra en el trie, si esta esta se devuelve true, en caso contrario da false
bool search(struct Nodos *root, string palabra){
    struct Nodos *gui = root;
    for (int i = 0; i < palabra.length(); i++){
        int index = palabra[i] - 'a';
        if (!gui->hijos[index])
            return false;
        gui = gui->hijos[index];
    }
    return (gui->finaldepalabra);
}
 
// main, en donde se inicializa todo y se empieza a crear los nodos
int main() {
    string keys[] = {"the", "a", "there","answer", "any", "by", "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
    struct Nodos *root = getNode();
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
    char salida[][32] = {"Not present in trie", "Present in trie"};
    return 0;
}
