Anahita es una genetista muy prestigiosa. Es la directora de un grupo de cient�ficos que buscan encontrar una forma barata de producir ciertos compuestos org�nicos.

Tienen el plan de modificar mediante ingenier�a gen�tica ciertas bacterias muy f�ciles de cultivar, de modo que produzcan el compuesto deseado.
La cantidad de compuesto que produce una bacteria particular est� determinada por sus genes.

M�s espec�ficamente, cada bacteria posee exactamente dos copias de un gen productor del compuesto.
Cada uno de estos dos genes puede ser de uno de $T$ tipos particulares de gen.
Cada tipo tiene asociado un n�mero entero, denominado su _�ndice de productividad_, y decimos que el �ndice de productividad de una copia particular del gen es igual al �ndice correspondiente a su tipo.
La cantidad de compuesto producida por una bacteria particular est� dada por la suma de los �ndices de productividad de sus dos copias del gen.

As�, por ejemplo, si hay $T=5$ tipos de genes, que tienen los siguientes �ndices de productividad:

$A = 2$
 
$B = 5$
 
$C = 3$

$D = 8$

$E = -1$ 

Una bacteria que tenga una copia de un gen de tipo $B$ y una copia de un gen de tipo $C$, producir� $5 + 3 = 8$ unidades del compuesto.
De manera similar, bacterias que tengan genes $AD$, $DA$, $AB$ y $CC$ producir�n $10$, $10$, $7$ y $6$ unidades del compuesto, respectivamente.
Los �ndices de productividad pueden ser negativos. Bacterias que tengan genes $EE$ _absorber�n_ 2 unidades del compuesto provenientes del medio de cultivo,
de forma tal que es posible medir en el laboratorio tanto �ndices negativos como positivos.

El grupo de Anahita ya ha logrado determinar todos los tipos diferentes de genes productores del compuesto que existen, pero los cient�ficos a�n no han podido determinar el �ndice de productividad asociado a cada uno de ellos.

Desafortunadamente, la �nica forma confiable de medir el �ndice de productividad es creando bacterias que tengan una combinaci�n espec�fica de genes seleccionados, y luego
realizando experimentos de laboratorio que determinen la cantidad del compuesto que producen (o absorben) dichas bacterias. Esto es bastante impr�ctico, ya que crear bacterias que tengan
una combinaci�n seleccionada de genes es un proceso muy arduo y costoso.

M�s a�n, el costo de producir bacterias con una cierta combinaci�n de genes no es siempre el mismo, sino que depende de la combinaci�n particular de genes.
Podr�an incluso existir combinaciones de genes tales que sea imposible producir bacterias con dicha combinaci�n particular, a�n cuando se utilicen todas las t�cnicas de ingenier�a gen�tica disponibles en la actualidad.

#Problema

Debes escribir un programa que, dados los costos de producir bacterias que tengan cada una de $C$ diferentes combinaciones de genes,
ayude a Anahita a determinar tantos de los $T$ �ndices de productividad como sea posible, y de forma tal que se minimice el costo total de la experimentaci�n.
Anahita pondr� su laboratorio a tu disposici�n, para que tu programa pueda crear bacterias gen�ticamente modificadas y medir la cantidad de compuesto que producen.

#Detalles de implementaci�n

Debes implementar una funci�n (m�todo / procedimiento):

__void try_science(int T, int C, int [] cost, int [] gene1, int [] gene2)__

* __T__ : La cantidad de tipos diferentes de genes.
* __C__ : La cantidad de combinaciones de genes que pueden ser producidas en forma confiable mediante bacterias gen�ticamente modificadas.
* __cost__, __gene1__, __gene2__: Cada uno de $C$ elementos, indicando que para cada entero $i$ tal que $0 \leq i < C$ (�ndice 0),
                          es posible crear bacterias con genes de tipo __gene1$_i$__ y __gene2__$_i$,
                          por medio de un proceso de costo __cost__$_i$.
* __gene1__$_i$ y __gene2__$_i$ estar�n entre $1$ y $T$, inclusive.
                          
__cost__$_i$ estar� entre $0$ y $1000000000$ ($10^9$), inclusive.
                          
No habr� ning�n par de valores $i \neq j$ tales que \{ __gene1__$_i$, __gene2__$_i$ \} = \{ __gene1__$_j$, __gene2__$_j$ \} (la misma combinaci�n de genes no aparecer� dos veces en la entrada).

#Llamada a funciones de biblioteca

Para interactuar con el laboratorio, tu programa debe utilizar las siguientes dos funciones (m�todos / procedimientos):


* __int64 measure_bacteria(int gene1, int gene2)__

Esta funci�n se utiliza para crear bacterias que tengan copias de los genes __gene1__ y __gene2__, que deben estar ambos entre $1$ y $T$, inclusive. 

Si el programa llama a esta funci�n con par�metros ``fuera de rango'', o con una combinaci�n de genes que es imposible de producir, recibir� cero puntos. Notar que las llamadas __measure_bacteria(x,y)__ y __measure_bacteria(y,x)__ siempre devolver�n resultados id�nticos.

El valor devuelvo por esta funci�n representa la cantidad total de compuesto producida por las bacterias seleccionadas (valores negativos indican que la bacteria absorbe el compuesto), y siempre tendr�n un valor absoluto m�ximo de $10000000000$ ($10^{10}$).
            
* __void report_index(int i, int64 index)__

Esta funci�n se utiliza para informar que el gen de tipo _i_ tiene un �ndice de productividad __index__. __i__ debe estar entre $1$ y $T$, inclusive.

Si el programa llama a esta funci�n con par�metros ``fuera de rango'', o con un �ndice de productividad incorrecto, recibir� cero puntos. Llamar a esta funci�n m�s de una vez con los mismos par�metros no es necesario, pero est� permitido.

#Subtareas

* ($gene1_i=gene2{_i}$ o $1+gene1_i= gene2_i$),  $1 \leq T \leq 1000, 0 \leq C \leq 5000$
* ($gene1_i=gene2_i$ o $1 + gene1_i = gene2_i$),$1 \leq T \leq 500000, 0 \leq C \leq 1000000$
* __cost__$_i = 0$, $1 \leq T \leq 500000, 0 \leq C \leq 1000000$
* $1 \leq T \leq 1000, 0 \leq C \leq 5000$
* $1 \leq T \leq 500000, 0 \leq C \leq 1000000$

#Puntuaci�n

Para resolver correctamente un caso de prueba, tu programa debe reportar correctamente el �ndice de productividad de __todos__ los genes para los cuales esto se pueda determinar con los datos disponibles,
y adem�s debe hacerlo con el menor costo total posible.

Formalmente, si $M$ es el m�nimo costo posible tal que, para los par�metros particulares con los cuales se llama a __try_science__ en el caso de prueba, existe una estrategia
que garantiza determinar todos los �ndices posibles con un costo a lo sumo $M$, entonces tu programa se considerar� correcto en ese caso de prueba �nicamente si determina correctamente todos los �ndices posibles
con un costo total $M$ o menos.
