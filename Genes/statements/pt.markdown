Anahita é uma geneticista de muito prestígio. Ela é a diretora de um grupo de cientistas que procuram descobrir uma forma barata de produzir certos compostos orgânicos.

Eles pretendem usar engenharia genética para modificar certa bactérias muito fáceis de cultivar, de modo a que produzam o composto desejado.
A quantidade de composto que uma bactéria em particular produz está determinada nos seus genes.

Mais especificamente, cada bactéria tem exatamente duas cópias de um gene produtor do composto.
Cada um destes genes pode ser um de $T$ tipos particulares de gene.
Cada tipo tem associado um número inteiro, denominado por _índice de produtividade_, e dizemos que o índice de produtividade de uma cópia particular do gene é igual ao índice correspondente ao seu tipo.
A quantidade de composto produzida por uma bactéria em particular é dada pela soma dos índices de produtividade das suas cópias do gene.

Assim, por exemplo, suponhamos que existem $T=5$ tipos de genes que têm os seguintes índices de produtividade:

$$
\begin{align*}
A &= 2\\\\
B &= 5\\\\
C &= 3\\\\
D &= 8\\\\
E &= -1.
\end{align*}$$ 

Uma bactéria que tenha uma cópia de um gene do tipo $B$ e uma cópia de um gene do tipo $C$ produzirá $5 + 3 = 8$ unidades do composto.
De maneira semelhante, bactérias que tenham genes $AD$, $DA$, $AB$ e $CC$ produzirão $10$, $10$, $7$ e $6$ unidades do composto, respetivamente.
Podemos ver que os índices de produtividade podem ser negativos. Por exemplo, bactérias que tenham genes $EE$ irão _absorver_ 2 unidades do composto provenientes do meio de cultivo, de tal forma que é psosível medir em laboratório tanto índices positivos como negativos.

O grupo de Anahita já conseguiu determinar todos os tipos diferentes de genes produtores do composto que existem, mas ainda não conseguiu determinar o índice de produtividade associado a cada um deles.

Infelizmente, a única forma confiável de medir o índice de produtividade é criando bactérias que tenham uma combinação específica de genes selecionados, sendo depois possível realizar experiências de laboratório que determinam a quantidade de composto que produzem (ou absorvem) essas mesmas bactérias. Isto não é muito prático, já que criar bactérias que tenham uma combinação selecionada de genes é um processo muito árduo e custoso.

Mais ainda, o custo de produzir bactérias com uma certa combinação não é sempre o mesmo, e depende da combinação de genes escolhida.
Podem inclusive existir combinações de genes tais que é impossível produzir bactérias com essa combinação em particular, mesmo quando se utilizam todas as técnicas de engenharia genética disponíveis na atualidade.

#Problema

Deves escrever um programa que, dados os custos de produzir bactérias que tenham cada uma das $C$ diferentes combinações de genes, ajude a Anahita a determinar o maior número de $T$ índices de produtividade possível, e de forma que minimize o custo total das experiências.
Anahita colocará o seu laboratório à tua disposição, para que o teu programa possa criar bactérias geneticamente modificadas e medir a quantidade de composto que produzem.

#Detalhes da implementação

Deves implementar uma função (método/procedimento)

`void tryScience(int T, int C, int[] cost, int[] gene1, int[] gene2)`

* `T`: A quantidade de tipos diferentes de genes.
* `C`: A quantidade de combinações de genes que podem ser produzidas de forma confiável mediante bactérias geneticamente modificadas.
* `cost`, `gene1`, `gene2`: arrays de cada um dos `C` elementos, indicando que para cada inteiro $\mathtt{i}$ tal que $0 \leq \mathtt{i} < \mathtt{C}$ (índice 0),
é possível criar bactérias do tipo `gene1[i]` y `gene2[i]`,
por meio de um processo com custo `cost[i]`.
* `gene1[i]` e `gene2[i]` estarão entre `1` e `T`, inclusive.
* `cost[i]` estará entre $0$ y $1000000000$ ($10^9$), inclusive.
* Não haverá nenhum par de valores $\mathtt{i} \neq \mathtt{j}$ tais que $\\{$ `gene1[i]`, `gene2[i]` $\\}$ = $\\{$ `gene1[j]`, `gene2[j]` $\\}$ (ou seja, a mesma combinação de genes não aparecerá duas vezes nos mesmos dados de entrada).

#Chamada a funções da biblioteca

Para interagir com o laborátório, o teu programa deve utilizar as seguintes funções (métodos/procedimentos):

* `int64 measureBacteria(int gene1, int gene2)`

Esta função é utilizada para criar bactérias que tenham cópias dos genes `gene1` e `gene2`, que devem estar ambos entre `1` e `T`, inclusive. 

Se o programa chama esta função com parâmetros fora do intervalo definido, ou com uma combinação de genes que é impossível de produzir, receberá zero pontos. Notem que as chamadas `measureBacteria(x,y)` e `measureBacteria(y,x)` irão sempre devolver resultados idênticos.

O valor devolvido por esta função representa a quantidade total de composto produzida pelas bactérias selecionadas (valores negativos indicam que a bactéria absorve o composto), e sempre terão um valor absoluto máximo de $10000000000$ ($10^{10}$).
            
* `void report(int K, int[] kind, int64[] idx)`

Deves chamar esta função exatamente *uma* vez antes de sair do procedimento `tryScience`. Esta função serve para que o teu programa informe a resposta ao avaliador.

Para isso, deves chamar a função com `K`, o número de índices de produtividade que conseguiste determinar, e dois arrays de tamanho `K`, representando que para todos os $0 \leq \mathtt{i} < \mathtt{K}$, o gene do tipo `kind[i]` tem índice de produtividade `idx[i]`.

Se não chamares a função `report`, se a chamas sem ter determinado a quantidade máxima de índices de produtividade possível, ou se colocas em `idx[i]` um valor que não corresponda com `kind[i]`, obterás zero pontos para esse caso de teste.

#Subtarefas

Cada uma das seguintes subtarefas representa uma coleção de casos de teste distintos dos demais.

* 10 pontos: (`gene1[i]` = `gene2[i]` ou 1 + `gene1[i]` = `gene2[i]`),  $1 \leq T \leq 1000, 0 \leq C \leq 5000$.
* 20 pontos: (`gene1[i]` = `gene2[i]` ou 1 + `gene1[i]` = `gene2[i]`), $1 \leq T \leq 50000, 0 \leq C \leq 200000$.
* 25 pontos: `cost[i]` = 0, $1 \leq T \leq 50000, 0 \leq C \leq 200000$.
* 20 pontos: $1 \leq T \leq 1000, 0 \leq C \leq 5000$.
* 25 pontos: $1 \leq T \leq 50000, 0 \leq C \leq 200000$.

#Pontuação

Para resolver corretamente um caso de teste, o teu programa deve reportar corretamente o índice de produtividade de __todos__ os genes para os quais é possível determinar com os dados disponíveis, e além disso deve fazê-lo com o menor custo possível.

Formalmente, se $M$ é o mínimo custo possível tal que, para todos os parâmetros particulares com os quais se chama `tryScience` no caso de teste, exista uma estratégia pela qual é garantido determinar todos os índices possíveis com um custo de no máximo $M$, então o teu programa será considerado correcto nesse caso de prova unicamente se determina corretamente todos os índices possíveis fazendo chamadas a  `measureBacteria` com um custo total de $M$ ou menos.

{{libinteractive:download}}
