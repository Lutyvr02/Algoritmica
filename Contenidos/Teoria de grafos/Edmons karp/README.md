# Edmons Karp.

El algoritmo de Edmonds-Karp es solo una implementación del método Ford-Fulkerson que usa BFS para encontrar rutas de aumento.
La complejidad se puede dar independientemente del flujo máximo. El algoritmo se ejecuta en tiempo  O(V*E^2), incluso para capacidades irracionales. 
El objetico es de que cada vez que encontramos un camino de aumento uno de los bordes se satura, y la distancia del borde a  s será mayor si vuelve a a
parecer más tarde en un camino de aumento. La longitud de los caminos simples está limitada por  V .
* [Edmonst Karp](https://github.com/Lutyvr02/Algoritmica/blob/main/Contenidos/BinarySearch/binarysearch.cpp) en C++.

<img src="(https://user-images.githubusercontent.com/101956531/197396633-74dc974a-a03d-4f03-a567-0fe07c855713.png)" width="400">

## Referencias. 

* [Binary Search](https://www.geeksforgeeks.org/binary-search/).
