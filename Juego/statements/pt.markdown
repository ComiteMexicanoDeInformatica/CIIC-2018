Estás a jogar um jogo onde há um array de $2\times n$ inteiros. O objectivo do jogo é maximizar a soma dos elementos do array. Para jogar, podes realizar as operações que quiseres do seguinte tipo: para cada operação, podes eleger um subarray contíguo de $n$ elementos e trocar o sinal de todos os elementos dentro desse subarray.

# Input

Na primeira linha um inteiro $n$, que indica metade da quantidade de elementos do array.

Na segunda linha estão os $2\times n$ inteiros separados por um espaço.

# Output

A maior soma que é possível obter.

# Exemplo

||input
2
-1 2 -3 4
||output
10
||description
A primeira operação aplica-se nos dois primeiros elementos, convertendo `[-1, 2, -3, 4]` em `[1, -2, -3, 4]`. A segunda operação aplica-se ao segundo e terceiro elemento, convertendo `[1, -2, -3, 4]` em `[1, 2, 3, 4]`.
||end

# Limites

* $1 \leq n \leq 10^5$.
* A soma dos valores absolutos dos inteiros do array cabem num inteiro com sinal de 32 bits.

# Subtarefas

* Para um subconjunto de casos valendo 7 pontos, cumpre-se que todos os valores do array têm o mesmo sinal.
* Para um subconjunto de casos valendo 43 puntos, cumpre-se que $1 \leq n \leq 20$.
