Te encuentras jugando un juego donde hay un arreglo de $2\times n$ enteros. El objetivo del juego es maximizar la suma de los elementos del arreglo. Para jugar puedes realizar la cantidad que quieras de operaciones del siguiente tipo: para cada operación, puedes elegir un subarreglo contiguo de $n$ elementos y cambiar el signo de todos los elementos dentro de ese subarreglo.

# Entrada

En la primera línea el entero $n$, la mitad de la cantidad de elementos.

En la segunda línea los $2\times n$ enteros separados por un espacio.

# Salida

La suma máxima que se puede lograr.

# Ejemplo

||input
2
-1 2 -3 4
||output
10
||description
La primera operación se aplica en los primeros dos elementos, convirtiendo `[-1, 2, -3, 4]` en `[1, -2, -3, 4]`. La segunda operación se aplica en el segundo y tercer elemento, convirtiendo `[1, -2, -3, 4]` en `[1, 2, 3, 4]`.
||end

# Límites

* $1 \leq n \leq 10^5$.
* La suma de los valores absolutos de los enteros del arreglo caben en un entero signado de 32 bits.

# Subtareas

* Para un subconjunto de casos por valor de 7 puntos se cumple que todos los valores del arreglo tienen el mismo signo.
* Para un subconjunto de casos por valor de 43 puntos, se cumple que $1 \leq n \leq 20$.
