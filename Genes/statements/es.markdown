Anahita es una genetista muy prestigiosa. Es la directora de un grupo de científicos que buscan encontrar una forma barata de producir ciertos compuestos orgánicos.

Tienen el plan de modificar mediante ingeniería genética ciertas bacterias muy fáciles de cultivar, de modo que produzcan el compuesto deseado.
La cantidad de compuesto que produce una bacteria particular está determinada por sus genes.

Más específicamente, cada bacteria posee exactamente dos copias de un gen productor del compuesto.
Cada uno de estos dos genes puede ser de uno de $T$ tipos particulares de gen.
Cada tipo tiene asociado un número entero, denominado su _índice de productividad_, y decimos que el índice de productividad de una copia particular del gen es igual al índice correspondiente a su tipo.
La cantidad de compuesto producida por una bacteria particular está dada por la suma de los índices de productividad de sus dos copias del gen.

Así, por ejemplo, supongamos que hay $T=5$ tipos de genes que tienen los siguientes índices de productividad:

$$
\begin{align*}
A &= 2\\\\
B &= 5\\\\
C &= 3\\\\
D &= 8\\\\
E &= -1.
\end{align*}$$ 

Una bacteria que tenga una copia de un gen de tipo $B$ y una copia de un gen de tipo $C$ producirá $5 + 3 = 8$ unidades del compuesto.
De manera similar, bacterias que tengan genes $AD$, $DA$, $AB$ y $CC$ producirán $10$, $10$, $7$ y $6$ unidades del compuesto, respectivamente.
Podemos ver que los índices de productividad pueden ser negativos. Por ejemplo, bacterias que tengan genes $EE$ _absorberán_ 2 unidades del compuesto provenientes del medio de cultivo,
de forma tal que es posible medir en el laboratorio tanto índices negativos como positivos.

El grupo de Anahita ya ha logrado determinar todos los tipos diferentes de genes productores del compuesto que existen, pero aún no han podido determinar el índice de productividad asociado a cada uno de ellos.

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

`void tryScience(int T, int C, int[] cost, int[] gene1, int[] gene2)`

* `T`: La cantidad de tipos diferentes de genes.
* `C`: La cantidad de combinaciones de genes que pueden ser producidas en forma confiable mediante bacterias genéticamente modificadas.
* `cost`, `gene1`, `gene2`: Arreglos cada uno de `C` elementos, indicando que para cada entero $\mathtt{i}$ tal que $0 \leq \mathtt{i} < \mathtt{C}$ (índice 0),
es posible crear bacterias con genes de tipo `gene1[i]` y `gene2[i]`,
por medio de un proceso de costo `cost[i]`.
* `gene1[i]` y `gene2[i]` estarán entre `1` y `T`, inclusive.
* `cost[i]` estará entre $0$ y $1000000000$ ($10^9$), inclusive.
* No habrá ningún par de valores $\mathtt{i} \neq \mathtt{j}$ tales que $\\{$ `gene1[i]`, `gene2[i]` $\\}$ = $\\{$ `gene1[j]`, `gene2[j]` $\\}$ (es decir, la misma combinación de genes no aparecerá dos veces en la entrada).

#Llamada a funciones de biblioteca

Para interactuar con el laboratorio, tu programa debe utilizar las siguientes dos funciones (métodos / procedimientos):

* `int64 measureBacteria(int gene1, int gene2)`

Esta función se utiliza para crear bacterias que tengan copias de los genes `gene1` y `gene2`, que deben estar ambos entre `1` y `T`, inclusive. 

Si el programa llama a esta función con parámetros fuera de rango, o con una combinación de genes que es imposible de producir, recibirá cero puntos. Notar que las llamadas `measureBacteria(x,y)` y `measureBacteria(y,x)` siempre devolverán resultados idénticos.

El valor devuelto por esta función representa la cantidad total de compuesto producida por las bacterias seleccionadas (valores negativos indican que la bacteria absorbe el compuesto), y siempre tendrá un valor absoluto máximo de $10000000000$ ($10^{10}$).
            
* `void report(int K, int[] kind, int64[] idx)`

Debes llamar esta función exactamente *una* vez antes de que `tryScience` regrese. Esta función sirve para que tu programa informe la respuesta al evaluador.

Para eso, debes llamar la función con `K`, el número de índices de productividad que lograste determinar,
y dos arreglos de longitud `K`, representando que
para toda $0 \leq \mathtt{i} < \mathtt{K}$, el gen
de tipo `kind[i]` tiene índice de productividad
`idx[i]`.

Si no llamas a la función `report`, si la llamas
sin haber determinado la cantidad máxima de índices
de productividad posible, o si mandas un valor de
`idx[i]` que no corresponda con `kind[i]`, obtendrás
cero puntos en ese caso de prueba.

#Subtareas

Cada una de las siguientes subtareas representa
una colección de casos de prueba disjunto de
los demás.

* 10 puntos: (`gene1[i]` = `gene2[i]` o 1 + `gene1[i]` = `gene2[i]`),  $1 \leq T \leq 1000, 0 \leq C \leq 5000$.
* 20 puntos: (`gene1[i]` = `gene2[i]` o 1 + `gene1[i]` = `gene2[i]`), $1 \leq T \leq 50000, 0 \leq C \leq 200000$.
* 25 puntos: `cost[i]` = 0, $1 \leq T \leq 50000, 0 \leq C \leq 200000$.
* 20 puntos: $1 \leq T \leq 1000, 0 \leq C \leq 5000$.
* 25 puntos: $1 \leq T \leq 50000, 0 \leq C \leq 200000$.

#Puntuación

Para resolver correctamente un caso de prueba, tu programa debe reportar correctamente el índice de productividad de __todos__ los genes para los cuales esto se pueda determinar con los datos disponibles,
y además debe hacerlo con el menor costo total posible.

Formalmente, si $M$ es el mínimo costo posible tal que, para los parámetros particulares con los cuales se llama a `tryScience` en el caso de prueba, existe una estrategia
que garantiza determinar todos los índices posibles con un costo a lo sumo $M$, entonces tu programa se considerará correcto en ese caso de prueba únicamente si determina correctamente todos los índices posibles
haciendo llamadas a `measureBacteria` con un costo total $M$ o menos.

{{libinteractive:download}}
