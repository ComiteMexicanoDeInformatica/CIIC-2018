Estás a experimentar uma simulação de um novo tipo de rede neuronal artificial. A rede neuronal é formada por neurónios ligados entre eles por meio de axónios. Inicialmente, cada neurónio tem um importante pedaço de informação distinta.

Ao formar-se uma rede neuronal, os pedaços de informação são automaticamente partilhados. Quando se cria um novo axónio que liga dois neurónios, os seus pedaços de informação são automaticamente partilhados. É possível partilhar pedaços de informação de um neurónio para outro sempre e quando estiverem ligados por meio de uma sequência de axónios.

O sistema para partilhar informação é muito eficiente: se dois neurónios podem partilhar os seus pedaços de informação, então automaticamente sincronizam todas os seus pedaços de informação. Depois de uma sincronização entre um neurónio A e um neurónio B, ambos passam a conter todos os pedaços de informação que continham os neurónios A e B antes da sincronização.

Por uma questão de desempenho, pode ser criados no máximo $M$ axónios. Alguns axónios podem chegar a desaparecer depois de algum tempo. Se um axónio desaparece, não pode ser usado até que volte a ser criado.

A simulação dura $M$ segundos, e em cada segundo $j$, $1 \leq j \leq M$, o estado de um axónio muda (aparece ou desaparece). No início todos os neurónios não existe nenhum axónio, ou seja, todos os neurónios estão desligados.

#Problema 

Tens que encontrar a quantidade de pedaços de informação distintos que tem cada neurónio no segundo $M+1$.

# Input

A primeira linha contém dois inteiros $N$ e $M$: a quantidade de neurónios e a quantidade de segundos da simulação.

Cada uma das $M$ linhas seguintes contém dois inteiros que descrevem as trocas dos axónios. Em particular, a $í$-ésima linha contém dois inteiros $x_i$, $y_i$ $(x_i < y_i)$, descrevendo que no segundo $i$ houve uma troca
na ligação entre os neurónios $x_i$ e $y_i$. Se no segundo $i-1$ não existia o axónio, é então criado, caso contrário, é destruído. Todas as sincronizações do segundo $i$ são finalizadas antes do segundo $i+1$.

# Output

$N$ linhas com um inteiro não negativo cada uma, representando a quantidade de pedaços de informação distintos que tem um neurónio no segundo $M+1$.

O $i$-ésimo inteiro representa a quantidade de peças de informação do $i$-ésimo neurónio.

# Exemplo

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
No segundo 0, os três neurónios estão desligados.
No segundo 1, os neurónios 1 e 2 ligam-se e sincronizam. Agora ambos têm a informação um do outro.
No segundo 2, os neurónios 1 e 2 desligam-se.
No segundo 3, os neurónios 2 e 3 ligam-se e sincronizam-se.
No final, o neurónio 1 tem a informação dos neurónios 1 e 2, ao passo que os neurónios 2 e 3 têm a informação dos neurónios 1, 2 e 3.
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

# Subtarefas

* Para um conjunto de casos de teste valendo 21 pontos, cumpre-se que $x_i + 1 = y_i$ para todo o $i$.
* Para um outro conjunto separado do anterior com um valor de 43 pontos, cumpre-se que se não desaparecerem axónios, no segundo $M+1$ haveria no máximo um caminho entre um qualquer par de neurónios.
* No resto dos casos não há restrições adicionais.
