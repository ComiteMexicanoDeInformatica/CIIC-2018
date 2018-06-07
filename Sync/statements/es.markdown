Estás experimentando con una simulación de un nuevo tipo de red neuronal artificial. La red neuronal está formada por neuronas conectadas entre ellas por medio de axones. Inicialmente cada red neuronal tiene una importante pieza de información distinta.

Al formarse una red neuronal, las piezas de información de las neuronas se empiezan a compartir entre ellas. Cuando se crea un nuevo axón que conecta dos neuronas, sus piezas de información son automáticamente compartidas. Es posible compartir piezas de información de una neurona a otra siempre y cuando estén conectadas por medio de una secuencia de axones.

El sistema para compartir información es muy eficiente: si dos neuronas pueden compartir sus piezas de información entre ellas, entonces automáticamente sincronizan todas las piezas de información. Después de una sincronización entre una neurona A y una neurona B, ambas contendrán todas las piezas de información que contenían las neuronas A y B antes de la sincronización.

Por detalles de desempeño, a lo más $M$ axones pueden ser creados. Al inicio, ningún axón existe. Algunos axones pueden llegar a desaparecer después de un tiempo. Si un axón desaparece, no puede ser usado hasta que vuelva a ser creado.

La simulación dura $M$ segundos y cada segundo $j$, $1 \leq j \leq M$, el estado de un axón cambia (aparece o desaparece).

#Problema 

Tienes que encontrar la cantidad de piezas de información distintas que tiene cada neurona en el segundo $M+1$.

# Entrada

La primera línea contiene los enteros $N$ y $M$: la cantidad de neuronas y la cantidad de segundos de la simulación.

En las siguientes M líneas, cada una contendrá dos enteros que describen los cambios de los axones. Particularmente, la $i$-ésima línea contiene dos enteros $x_i$, $y_i$ $(x_i < y_i)$, describiendo que en el segundo $i$ hubo un cambio en la conexión entre las neuronas $x_i$ y $y_i$. Si en el segundo $i-1$ no existía el axón entonces es creado, de lo contrario es destruido. Todas las sincronizaciones del segundo $i$ son finalizadas antes del segundo $i+1$.

# Salida

$N$ líneas con un entero no negativo en cada una, representando la cantidad de piezas de información distinta que tiene cada neurona en el segundo $M+1$.

El $i$-ésimo entero representa la cantidad de piezas de información de la $i$-ésima neurona.

# Ejemplo

||input
3 3
1 2
1 2
2 3
||output
2
3
3
||description
En el segundo 0, las tres neuronas están desconectadas.  
En el segundo 1, la neuronas 1 y 2 se conectan y sincronizan. Ahora ambas tienen la información de la otra.  
En el segundo 2, la neuronas 1 y 2 se desconectan.  
En el segundo 3, las neuronas 2 y 3 se conectan y sincronizan.  
Al final, la neurona 1 tiene la información de las
neuronas 1 y 2, mientras que las neuronas 2 y 3
tienen la información de las neuronas 1, 2 y 3.
||input
5 3
1 2
3 4
1 4
||output
4
4
4
4
1
||end

# Límites

* $2 \leq N \leq 5000$
* $1 \leq M \leq 20000$
* $1 \leq x_i < y_i \leq N$

# Subtareas

* En un conjunto de casos con valor de 21 puntos, se cumple que $x_i + 1 = y_i$ para toda $i$.
* En otro conjunto separado del anterior con valor de 43 puntos, se cumple que si no desaparecieran axones, en el segundo $M+1$ habría a lo más un camino entre cualquier par de neuronas.
* En el resto de los casos no hay restricciones adicionales.
