#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
  
struct Trie { //cada nodo puede ser fina de una palabra por ello se inicializa en true, ademas se guarda el map en los nodos
    bool finalpalabra;
    unordered_map<char, Trie*> map;
};
  
//se crea un trie y se apunta al final de la palabra, poniendola en false
Trie* getNewTrieNode() {
    Trie* nodo = new Trie;
    nodo->finalpalabra = false;
    return nodo;
}
  
// poner una palabra al trie, tiene la raiz de esta y una palabra que no cambia
void insert(Trie*& raiz, const string& str) {
    if (raiz == nullptr)
        raiz = getNewTrieNode();
    Trie* tmpr = raiz;
    for (int i = 0; i < str.length(); i++) {
        char x = str[i];
        //el tmpr apunta al map y se escribe la letra
        if (tmpr->map.find(x) == tmpr->map.end())
            tmpr->map[x] = getNewTrieNode();
        tmpr = tmpr->map[x];
    }
    tmpr->finalpalabra = true;
}
  
// se busca la palabra en esta funcion, si la raiz es nula pues se regresa false, si no, pues se busca la palabra con punteros
bool search(Trie* raiz, const string& palabras) {
    if (raiz == nullptr)
        return false;
    Trie* temp = raiz;
    for (int i = 0; i < palabras.length(); i++) {
        temp = temp->map[palabras[i]];
        if (temp == nullptr)
            return false;
    }
    return temp->finalpalabra;
}
  
//main
int main() {
    Trie* root = nullptr;
    return 0;
}
