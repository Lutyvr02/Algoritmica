# Edmonds Karp.

El algoritmo de Edmonds-Karp es solo una implementación del método Ford-Fulkerson que usa BFS para encontrar rutas de aumento.
La complejidad se puede dar independientemente del flujo máximo. El algoritmo se ejecuta en tiempo  O(V*E^2), incluso para capacidades irracionales. 
El objetico es de que cada vez que encontramos un camino de aumento uno de los bordes se satura, y la distancia del borde a  s será mayor si vuelve a a
parecer más tarde en un camino de aumento. La longitud de los caminos simples está limitada por  V .
* [Edmonds Karp](https://github.com/Lutyvr02/Algoritmica/blob/main/Contenidos/Teoria%20de%20grafos/Edmons%20karp/edmos.cpp) en C++.

![300px-Edmonds-Karp_flow_example_0 svg](https://user-images.githubusercontent.com/101956531/199821200-91bea6de-cf64-4e4d-a3c5-61fcb44b0d67.png)

## Referencias. 

* [Edmonds Karp](https://www.geeksforgeeks.org/binary-search/).
* [Video de Edmonds Karp](https://www.youtube.com/watch?v=RppuJYwlcI8).

## Problema relacionado al algoritmo.
* [Banda ancha](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&category=685&page=show_problem&problem=761).

## Su Tiempo algoritmico es: O(VE^2) donde V son los vertices y E son los nodos.


