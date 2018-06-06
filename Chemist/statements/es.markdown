Uno de tus hobbies es realizar experimentos químicos. Originalmente tenías $R$ recipientes con compuestos acomodados en una hilera. Cada compuesto es representado por un entero positivo, siendo los _compuestos originales_ $(r_0, r_1, ..., r_{R-1})$.

Como parte de tus experimentos, tomabas un nuevo recipiente, seleccionabas un intervalo contiguo de recipientes de la hilera original y vertías un poco de cada _compuesto original_ de ese intervalo sobre el nuevo recipiente. Los compuestos tienen la propiedad que si combinas en un recipiente compuestos tal que el valor de cada uno es $(c_1,...,c_n)$, el valor del nuevo compuesto formado será $c_1 \times \ldots \times c_n$.

En total llegaste a crear $M$ nuevos compuestos y para tener reporte de tus experimentos, colocabas los nuevos recipientes en una nueva hilera y anotabas en cada recipiente el intervalo de la hilera original que fue usado para crear el nuevo compuesto. Es decir, para cada nuevo compuesto $m_i$, anotabas $L_i$ y $D_i$ que significa que usaste los compuestos $(r_{L_i},r_{L_i+1}, \ldots ,r_{D_i} )$ para crear el compuesto $m_i$.

Desafortunadamente un día remodelaron tu laboratorio y la hilera original de compuestos se perdió completamente. Por suerte, los nuevos compuestos sobrevivieron la remodelación, junto con sus valores de $L_i$ y $D_i$.

#Problema

Dado los rangos $L_i$, $D_i$ y valores $m_i$ de los nuevos compuestos, encuentra el valor y posición de los _compuestos originales_.

# Entrada

La primera línea contiene los enteros $R$ y $M$, la cantidad de _compuestos originales_ y la cantidad de compuestos nuevos.

Cada una de las siguientes $M$ líneas contiene los enteros $L_i$, $D_i$ y $m_i$.

# Salida

Debes imprimir $R$ enteros positivos que representan el valor de cada _compuesto original_ en su posición de la hilera de tal forma que todos los $m_i$ puedan ser formados. Si algún _compuesto original_ no fue usado en ninguno de los compuestos nuevos, imprime $1$ como su valor.

Si existe más de una solución, puedes imprimir cualquier solución válida.

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

* $1 \leq R \leq 10^5$.
* $1 \leq M \leq R$.
* $1 \leq L_i \leq D_i \leq R$.
* $1 \leq m_i \leq 10^{11}$.
* No existen $i,j$ tales que $L_i < L_j \leq D_j < D_i$. Es decir, ningún rango $[L_i, D_i]$ contiene estrictamente a otro rango $[L_j, D_j]$.
