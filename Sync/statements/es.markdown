Estás experimentando con un nuevo tipo de red neuronal artificial. La red neuronal está formada por neuronas conectadas entre ellas por medio de axones. Inicialmente cada red neuronal tiene una importante pieza de información distinta.

Al formarse una red neuronal, las piezas de información de las neuronas se empiezan a compartir entre ellas. Cuando se crea un nuevo axón que conecta dos neuronas, sus piezas de información son automáticamente compartidas. Es posible compartir piezas de información de una neurona a otra siempre y cuando estén conectadas por medio de una linea de axones.

El sistema para compartir información es muy eficiente, si dos neuronas pueden compartir sus piezas de información entre ellas, entonces automáticamente sincronizan las piezas de información. Después de una sincronización entre una neurona A y una neurona B, ambas contendrán al menos las piezas de información que contenían las neuronas A y B antes de la sincronización.

Por detalles de desempeño, a lo más $M$ axones pueden ser creados. Al inicio, ningún axón existe. Algunos axones pueden llegar a desaparecer después de un tiempo. Si un axón desaparece, no puede ser usado hasta que vuelva a ser creado.

La simulación dura $M$ segundos y cada segundo $j$, $1 \leq j \leq M$, el estado de un axón cambia (aparece o desaparece).

#Problema 

Tienes que encontrar la cantidad de piezas de información distintas que tiene cada neurona en el segundo $M+1$.

# Entrada

La primera línea contiene los enteros $N$, $M$, la cantidad de neuronas y la cantidad de segundos.

En las siguientes M líneas cada una contendrá dos enteros que describen los cambios de axones. Particularmente la $i$-ésima línea describe el cambio en el segundo $i$ de la forma $x_i$ $y_i$ $(x_i < y_i)$ que significa que hubo un cambio en la conexión entre $x_i$ y $y_i$ en el segundo $i$. Si no existía el axón entonces es creado, de lo contrario es destruido. Toda la sincronización del segundo $i$ es finalizada antes del segundo $i+1$

# Salida

$N$ enteros no negativos que representan la cantidad de piezas de información distinta que tiene cada neurona en el segundo $M+1$. El $i$-ésimo entero representa la cantidad de piezas de información de la $i$-ésima neurona.

# Ejemplo

||input
1
2
||output
Case #1: 3
||description
Explicación
||input
5
10
||output
Case #2: 15
||end

# Límites

* $2 \leq N \leq 5000$
* $1 \leq M \leq 20000$
* $1 \leq x_i < y_i \leq N$


#Subproblemas
	* Aquí
* Van
* Los
* suproblemas