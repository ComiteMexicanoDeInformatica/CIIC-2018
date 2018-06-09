Tienes un árbol con $N$ nodos numerados de $1$ a $N$ y dos enteros positivos $P$ y $K$. Los nodos están indexados de $1$ a $N$ y cada nodo $i$ tiene un valor $e_i$ asignado. Se cumple que ningún $e_i$ es igual a $P$.

Para cada par de nodos con índice $u$ e índice $v$,  ($u \leq v$), existe un único camino de nodos ($u,a_1, a_2, ...,v$) tal que conectan $u$ y $v$. Si tomamos los valores $e_i$ del camino, es decir el arreglo ($e_u, e_{a_1}, e_{a_2}, ..., e_v$), le insertamos el valor $P$ y lo ordenamos, ¿Queda el valor $P$ en la posición $K$ del arreglo ordenado?

#Problema

Tienes que encontrar la cantidad de pares de nodos $u$ y $v$ tal que al aplicar las operaciones anteriores, el valor $P$ termina en la posición $K$.

# Entrada

En la primera línea los valores $N$, $K$ y $P$.

En la segunda línea, los $N$ valores $e_i$.

Las siguientes $N-1$ líneas contiene cada una dos enteros $x_j$ y $y_j$ que describen una arísta del árbol.


# Salida

La cantidad de pares distintos $u$ y $v$ que cumplen con las condiciones del problema.

# Ejemplo

||input
7 4 3
2 2 3 3 7 9 1
1 3
2 3
3 4
4 5
5 6
4 7
||output
8
||description
Los pares de nodos que cumplen con lo que pide el problema son:
(1,3), (2,3), (3,4), (3,5), (3,6), (4,7), (5,7) y (6,7).
||end

# Límites

* $1 \leq N \leq 500,000$
* $1 \leq K \leq N+1$
* $1 \leq P, e_i \leq 10^9$
* $P \neq e_i$ para toda $i$.


# Subproblemas

* 10 puntos: cada nodo estará conectado con a lo más 2 nodos y $1 \leq N \leq 1000$ .
* 14 puntos: $1 \leq N \leq 1000$ .
* 15 puntos: $1 \leq K \leq min(10, N+1)$ y para todo $i$, $e_i < P$ .
* 15 puntos: $1 \leq K \leq min(10, N+1)$ .
* 20 puntos: cada nodo estará conectado con a lo más 2 nodos.


