Tens uma árvore com $N$ nós e dois inteiros positivos $P$ e $K$. Os nós estão indexados de $1$ a $N$ e cada nó $i$ tem um valor $e_i$ atribuído. Cumpre-se que nenhum $e_i$ é igul a $P$.

Para cada par de nós com índices $u$ e $v$, ($u \leq v$), existe um único caminho de nós ($u, a_1, a_2, ..., v$) que ligam $u$ a $v$. Se tomarmos os valores $e_i$ do caminho, ou seja, o array ($e_u, e_{a_1}, e_{a_2}, ..., e_v$), inserirmos o valor $P$, e ordenarmos, o valor $P$ fica na posição $K$ do array ordenado?

#Problema

Tens que encontrar a quantidade de pares de nós $u$ e $v$ tal que ao aplicar as operações anteriores, o valor de $P$ termina na posição $K$.

# Input

Na primeira linha os valores $N$, $P$ e $K$.

Na segunda linha os $N$ valores de $e_i$.

As $N-1$ linhas seguintes contêm dois inteiros $x_j$ e $y_j$ que descrevem uma aresta (ligação) da árvore.

# Output

A quantidade de pares distintos $u$ e $v$ que cumprem as condições do problema.

# Exemplo

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
Os pares de nós que cumprem com o que o problema pede são:
(1,3), (2,3), (3,4), (3,5), (3,6), (4,7), (5,7) e (6,7).
||end

# Limites

* $1 \leq N \leq 500,000$
* $1 \leq K \leq N+1$
* $1 \leq P, e_i \leq 10^9$
* $P \neq e_i$ para todo o $i$.

# Subtarefas

* 10 pontos: Cada nó será conectado a no máximo 2 nós e $1 \leq N \leq 1000$.
* 14 pontos: $1 \leq N \leq 1000$.
* 15 pontos: $1 \leq K \leq \min(10, N+1)$ e para tudo $i$, $e_i < P$.
* 15 pontos: $1 \leq K \leq \min(10, N+1)$.
* 20 pontos: Cada nó será conectado a no máximo 2 nós.
* 26 pontos: Sem restrições adicionais.
