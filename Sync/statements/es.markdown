Est�s experimentando con un nuevo tipo de red neuronal artificial. La red neuronal est� formada por neuronas conectadas entre ellas por medio de axones. Inicialmente cada red neuronal tiene una importante pieza de informaci�n distinta.

Al formarse una red neuronal, las piezas de informaci�n de las neuronas se empiezan a compartir entre ellas. Cuando se crea un nuevo ax�n que conecta dos neuronas, sus piezas de informaci�n son autom�ticamente compartidas. Es posible compartir piezas de informaci�n de una neurona a otra siempre y cuando est�n conectadas por medio de una linea de axones.

El sistema para compartir informaci�n es muy eficiente, si dos neuronas pueden compartir sus piezas de informaci�n entre ellas, entonces autom�ticamente sincronizan las piezas de informaci�n. Despu�s de una sincronizaci�n entre una neurona A y una neurona B, ambas contendr�n al menos las piezas de informaci�n que conten�an las neuronas A y B antes de la sincronizaci�n.

Por detalles de desempe�o, a lo m�s $M$ axones pueden ser creados. Al inicio, ning�n ax�n existe. Algunos axones pueden llegar a desaparecer despu�s de un tiempo. Si un ax�n desaparece, no puede ser usado hasta que vuelva a ser creado.

La simulaci�n dura $M$ segundos y cada segundo $j$, $1 \leq j \leq M$, el estado de un ax�n cambia (aparece o desaparece).

#Problema 

Tienes que encontrar la cantidad de piezas de informaci�n distintas que tiene cada neurona en el segundo $M+1$.

# Entrada

La primera l�nea contiene los enteros $N$, $M$, la cantidad de neuronas y la cantidad de segundos.

En las siguientes M l�neas cada una contendr� dos enteros que describen los cambios de axones. Particularmente la $i$-�sima l�nea describe el cambio en el segundo $i$ de la forma $x_i$ $y_i$ $(x_i < y_i)$ que significa que hubo un cambio en la conexi�n entre $x_i$ y $y_i$ en el segundo $i$. Si no exist�a el ax�n entonces es creado, de lo contrario es destruido. Toda la sincronizaci�n del segundo $i$ es finalizada antes del segundo $i+1$

# Salida

$N$ enteros no negativos que representan la cantidad de piezas de informaci�n distinta que tiene cada neurona en el segundo $M+1$. El $i$-�simo entero representa la cantidad de piezas de informaci�n de la $i$-�sima neurona.

# Ejemplo

||input
1
2
||output
Case #1: 3
||description
Explicaci�n
||input
5
10
||output
Case #2: 15
||end

# L�mites

* $2 \leq N \leq 5000$
* $1 \leq M \leq 20000$
* $1 \leq x_i < y_i \leq N$


#Subproblemas
	* Aqu�
* Van
* Los
* suproblemas