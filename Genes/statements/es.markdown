Anahita es una genetista muy prestigiosa. Es la directora de un grupo de científicos que buscan encontrar una forma barata de producir ciertos compuestos orgánicos.

Tienen el plan de modificar mediante ingeniería genética ciertas bacterias muy fáciles de cultivar, de modo que produzcan el compuesto deseado.
La cantidad de compuesto que produce una bacteria particular está determinada por sus genes.

Más específicamente, cada bacteria posee exactamente dos copias de un gen productor del compuesto.
Cada uno de estos dos genes puede ser de uno de $T$ tipos particulares de gen.
Cada tipo tiene asociado un número entero, denominado su _índice de productividad_, y decimos que el índice de productividad de una copia particular del gen es igual al índice correspondiente a su tipo.
La cantidad de compuesto producida por una bacteria particular está dada por la suma de los índices de productividad de sus dos copias del gen.

Así, por ejemplo, si hay $T=5$ tipos de genes, que tienen los siguientes índices de productividad:

$A = 2$
 
$B = 5$
 
$C = 3$

$D = 8$

$E = -1$ 

Una bacteria que tenga una copia de un gen de tipo $B$ y una copia de un gen de tipo $C$, producirá $5 + 3 = 8$ unidades del compuesto.
De manera similar, bacterias que tengan genes $AD$, $DA$, $AB$ y $CC$ producirán $10$, $10$, $7$ y $6$ unidades del compuesto, respectivamente.
Los índices de productividad pueden ser negativos. Bacterias que tengan genes $EE$ _absorberán_ 2 unidades del compuesto provenientes del medio de cultivo,
de forma tal que es posible medir en el laboratorio tanto índices negativos como positivos.

El grupo de Anahita ya ha logrado determinar todos los tipos diferentes de genes productores del compuesto que existen, pero los científicos aún no han podido determinar el índice de productividad asociado a cada uno de ellos.

Desafortunadamente, la única forma confiable de medir el índice de productividad es creando bacterias que tengan una combinación específica de genes seleccionados, y luego
realizando experimentos de laboratorio que determinen la cantidad del compuesto que producen (o absorben) dichas bacterias. Esto es bastante impráctico, ya que crear bacterias que tengan
una combinación seleccionada de genes es un proceso muy arduo y costoso.

Más aún, el costo de producir bacterias con una cierta combinación de genes no es siempre el mismo, sino que depende de la combinación particular de genes.
Podrían incluso existir combinaciones de genes tales que sea imposible producir bacterias con dicha combinación particular, aún cuando se utilicen todas las técnicas de ingeniería genética disponibles en la actualidad.

#Problema

Debes escribir un programa que, dados los costos de producir bacterias que tengan cada una de $C$ diferentes combinaciones de genes,
ayude a Anahita a determinar tantos de los $T$ índices de productividad como sea posible, y de forma tal que se minimice el costo total de la experimentación.
Anahita pondrá su laboratorio a tu disposición, para que tu programa pueda crear bacterias genéticamente modificadas y medir la cantidad de compuesto que producen.

#Detalles de implementación

Debes implementar una función (método / procedimiento):

__void try_science(int T, int C, int [] cost, int [] gene1, int [] gene2)__

* __T__ : La cantidad de tipos diferentes de genes.
* __C__ : La cantidad de combinaciones de genes que pueden ser producidas en forma confiable mediante bacterias genéticamente modificadas.
* __cost__, __gene1__, __gene2__: Cada uno de $C$ elementos, indicando que para cada entero $i$ tal que $0 \leq i < C$ (índice 0),
                          es posible crear bacterias con genes de tipo __gene1$_i$__ y __gene2__$_i$,
                          por medio de un proceso de costo __cost__$_i$.
* __gene1__$_i$ y __gene2__$_i$ estarán entre $1$ y $T$, inclusive.
                          
__cost__$_i$ estará entre $0$ y $1000000000$ ($10^9$), inclusive.
                          
No habrá ningún par de valores $i \neq j$ tales que \{ __gene1__$_i$, __gene2__$_i$ \} = \{ __gene1__$_j$, __gene2__$_j$ \} (la misma combinación de genes no aparecerá dos veces en la entrada).

#Llamada a funciones de biblioteca

Para interactuar con el laboratorio, tu programa debe utilizar las siguientes dos funciones (métodos / procedimientos):


* __int64 measure_bacteria(int gene1, int gene2)__

Esta función se utiliza para crear bacterias que tengan copias de los genes __gene1__ y __gene2__, que deben estar ambos entre $1$ y $T$, inclusive. 

Si el programa llama a esta función con parámetros ``fuera de rango'', o con una combinación de genes que es imposible de producir, recibirá cero puntos. Notar que las llamadas __measure_bacteria(x,y)__ y __measure_bacteria(y,x)__ siempre devolverán resultados idénticos.

El valor devuelvo por esta función representa la cantidad total de compuesto producida por las bacterias seleccionadas (valores negativos indican que la bacteria absorbe el compuesto), y siempre tendrán un valor absoluto máximo de $10000000000$ ($10^{10}$).
            
* __void report_index(int i, int64 index)__

Esta función se utiliza para informar que el gen de tipo _i_ tiene un índice de productividad __index__. __i__ debe estar entre $1$ y $T$, inclusive.

Si el programa llama a esta función con parámetros ``fuera de rango'', o con un índice de productividad incorrecto, recibirá cero puntos. Llamar a esta función más de una vez con los mismos parámetros no es necesario, pero está permitido.

#Subtareas

* ($gene1_i=gene2{_i}$ o $1+gene1_i= gene2_i$),  $1 \leq T \leq 1000, 0 \leq C \leq 5000$
* ($gene1_i=gene2_i$ o $1 + gene1_i = gene2_i$),$1 \leq T \leq 500000, 0 \leq C \leq 1000000$
* __cost__$_i = 0$, $1 \leq T \leq 500000, 0 \leq C \leq 1000000$
* $1 \leq T \leq 1000, 0 \leq C \leq 5000$
* $1 \leq T \leq 500000, 0 \leq C \leq 1000000$

#Puntuación

Para resolver correctamente un caso de prueba, tu programa debe reportar correctamente el índice de productividad de __todos__ los genes para los cuales esto se pueda determinar con los datos disponibles,
y además debe hacerlo con el menor costo total posible.

Formalmente, si $M$ es el mínimo costo posible tal que, para los parámetros particulares con los cuales se llama a __try_science__ en el caso de prueba, existe una estrategia
que garantiza determinar todos los índices posibles con un costo a lo sumo $M$, entonces tu programa se considerará correcto en ese caso de prueba únicamente si determina correctamente todos los índices posibles
con un costo total $M$ o menos.
