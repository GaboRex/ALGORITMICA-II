

_El algoritmo de Kruskal, dado un grafo conexo, no dirigido y ponderado, encuentra un árbol de expansión mínima. Es decir, es capaz de encontrar un subconjunto de las aristas que formen un árbol que incluya todos los vértices del grafo inicial, donde el peso total de las aristas del árbol es el mínimo posible._

## Funcionamiento del algoritmo de Kruskal
- Se selecciona, de entre todas las aristas restantes, la de menor peso siempre que no cree ningún ciclo.
- Se repite el paso 1 hasta que se hayan seleccionado |V| - 1 aristas.