Um dos teus hobbies é realizar experiências químicas. Inicialmente tens $R$ recipientes com compostos numa fila. Cada composto é representado por um inteiro positivo, sendo os _compostos originais_ $(r_1, r_2, ..., r_{R})$.

Como parte das tuas experiências, pegaste num novo recipiente, selecionaste um intervalo contíguo de recipientes da fila original e deitaste um pouco de cada _composto original_ desse intervalo no novo recipiente. Os compostos têm a propriedade de que se forem combinados num recipiente compostos tal que o valor de cada um é  $(c_1,...,c_n)$, o valor do novo composto formado será $c_1 \times \ldots \times c_n$.

No total chegaste a criar $M$ novos compostos. Para ter um relatório das tuas experiências, colocaste os novos recipientes numa nova fila e anotaste em cada recipience o intervalo da fila original que foi usado para criar o novo composto. Dito de outro modo, para cada novo composto $m_i$, anotaste $L_i$ e $D_i$, que significa que usaste os compostos $(r_{L_i},r_{L_i+1}, \ldots ,r_{D_i} )$ para criar o composto $m_i$.

Infelizmente, um dia o laboratório foi remodelado e a fila original de compostos perdeu-se completamente. Por sorte, os novos compostos sobreviveram à remodelação, juntamente com os seus valores de $L_i$ e $D_i$.

#Problema

Dados os intervalos $L_i$, $D_i$ e os valores $m_i$ dos novos compostos, encontra o valor e posição de cada um dos _compostos originais_.

# Input

A primeira linha contém os inteiros $R$ e $M$, a quantidade de _compostos originais_ e a quantidade de compostos novos.

Cada uma das $M$ linhas seguintes contém os inteiros $L_i$, $D_i$ e $m_i$.

# Output

Deves imprimir $R$ inteiros positivos que representam o valor de cada _composo original_ na sua posição da fila de tal forma que todos os $m_i$ possam ser formados. Se algum _composto original_ não foi usado em nenhum dos compostos novos, imprime $1$ como o seu valor.

Se existir mais do que uma solução, podes imprimr qualquer solução válida.

# Exemplo

||input
5 2
1 2 6
4 5 10
||output
6 1 1 2 5
||description
O produto das posições 1 e 2 deve ser 6, e o das posições 4 e 5 deve ser 10. Já que não sabemos nada da posição 3, colocamos um 1.
||input
4 3
1 2 4
2 2 2
2 4 12
||output
2 2 2 3
||end

# Limites

* $1 \leq R \leq 10^5$.
* $1 \leq M \leq R$.
* $1 \leq L_i \leq D_i \leq R$.
* $1 \leq m_i \leq 10^{11}$.
* Não existem $i,j$ tais que $L_i < L_j \leq D_j < D_i$, ou seja, nenhum intervalo $[L_i, D_i]$ contém estritamente um outro intervalo $[L_j, D_j]$.

#Subtarefas

* Para um subconjunto de casos valendo 7 pontos, cumpre-se que não existem $i,j$ tais que $L_i \leq L_j \leq D_i$, ou seja, nenhum intervalo $[L_i, D_i]$ interseta um outro intervalo $[L_j, D_j]$.
* Para um subconjunto de casos valendo 13 pontos, cumpre-se que $1 \le R \le 20$ e que $1 \le M \le 20$.
* Para um subconjunto de casos valendo 13 pontos, cumpre-se que $L_i = L_1$ o $D_i = D_1$ para todo $i$ tal que $2 \le i \le M$.
* Para um subconjunto de casos valendo 20 pontos, cumpre-se que $1 \le M \le 1000$.
* Para um subconjunto de casos valendo 17 pontos, cumpre-se que cada *composto original* foi utilizado para fazer no máximo 2 dos novos compostos.
