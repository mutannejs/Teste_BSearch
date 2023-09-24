# Teste de Busca Binária

Esse programa foi criado com a intenção de ser uma base de testes para
 implementações da **_Busca Binária_** feitas utilizando a Linguagem C.

Quando o caminho até encontrar o elemento é importante, não só se ele
 está no vetor pesquisado ou não, a implementação da busca binária pode
 se tornar um tanto complexa. Não só isso, como a verificação se o
 código está executando como esperado pode não abranger todos os casos
 em que o algoritmo de fato será aplicado.

Os testes criados tentam englobar as diferentes possibilidades de
 execução da busca, verificando tanto se o elemento foi encontrado,
 quanto o caminho percorrido. Fornecendo uma interface simples e de
 fácil compreensão, para agilizar os testes e a validação da busca
 implementada.

:wrench: Esse projeto foi implementado utilizando o framework
 **[Unity](https://github.com/ThrowTheSwitch/Unity/tree/master)**, que
 auxilia na criação de testes unitários construídos em C.

:bangbang: _**Obs:**_ os testes criados consideram que o vetor
 processado é ordenado e não possui elementos repetidos.

## Preparando o código

Primeiramente faça um clone desse repositório em sua máquina. Utilizando
 o terminal essa operação pode ser feita executando o comando:

	git clone https://github.com/mutannejs/Teste_BSearch.git

Dentro da pasta do programa há um arquivo chamado **binary_search.c**, é
 neste arquivo que você deve escrever seu código da busca binária. Mais
 a frente há uma maior explicação sobre este processo, sobre o arquivo e
 a implementação do [algoritmo da busca](#o-algoritmo-da-busca-binária).

Após escrever o código da busca, ela já estará pronta para ser testada,
 mas antes é necessário se certificar de ter a ferramenta **make**
 instalada em seu sistema, ela será extremamente útil e necessária para
 agilizar a compilação do código e execução dos testes. Para saber se a
 ferramenta está presente no seu sistema você pode executar o comando a
 seguir em seu terminal:

	make -v

Outra ferramenta necessária é o **gcc**. Em sistemas Linux baseados em
 Debian esses dois programas podem ser instalados utilizando o comando:

	apt install build-essential

## O algoritmo da Busca Binária

Quando precisamos encontrar um dado específico dentro de um vetor,
 basicamente podemos realizar sua busca de duas maneiras diferentes, a
 partir de uma **busca linear** ou de uma **busca binária**.

Na busca linear, analisamos elemento por elemento, iniciando pelo
 primeiro índice do vetor, até encontrar o dado buscado, ou percorrer
 toda a estrutura. Essa abordagem pode não ser muito eficiente quando o
 vetor possui muitos elementos e aquele que está sendo buscado se
 encontra próximo ao último índice (ou está nesta posição).

Quando estamos trabalhando com um vetor ordenado, ao analisar um
 elemento qualquer sabemos de duas coisas: todos elementos em posições
 anteriores a ele são menores que ele (caso o vetor possa ter dados
 repetidos, os dados são menores ou iguais), e todos elementos em
 posições sucessoras são maiores que ele. A busca binária se aproveita
 desse fato e faz a busca pelo elemento apenas na parte do vetor que ele
 sabe que o dado está, analisando sempre o elemento que está na posição
 central daquele subconjunto (sendo o centro do vetor inicial a primeira
 posição analisada), para então continuar sua busca a partir dele. O
 algoritmo só para ao encontrar o dado buscado, ou quando não é
 possível dividir o subvetor em uma parte menor (o subconjunto é formado
 por apenas um elemento), ou seja, o dado não está no vetor.

Usando como exemplo um vetor de inteiro com 15 elementos, sendo o
 primeiro elemento igual a `0`, e os próximos elementos igual ao valor
 do elemento anterior incrementado em 1, se usássemos a busca binária
 para encontrar o elemento `13`, teríamos a seguinte execução:

![busca binária sem arredondamento](images/sem_arredondamento.jpg)

Se usássemos busca linear para encontrar o dado, teríamos que percorrer
 elemento por elemento até chegar naquele com valor `13`, sendo
 necessário extamente 14 passos para encontrá-lo (11 a mais se usado
 busca binária).

### Arredondamentos

No exemplo mostrado, tanto o vetor inicial quanto os subvetores
 analisados durante a busca possuíam um número ímpar de elementos. Esse
 fato implica em existir apenas **um elemento** central no subconjunto
 analisado, porém, se por acaso fosse encontrado um subvetor com uma
 quantidade par de elementos, não existiria um elemento central
 explícito para analisar. Neste caso, poderíamos analisar os dois
 elementos mais próximos ao centro, onde essa escolha nada mais é que o
 **arredondamento** impregado em nosso algoritmo da busca binária.
 Observe:

![busca binária com arredondamento](images/com_arredondamento.jpg)

No exemplo mostrado temos a representação da execução do algoritmo
 utilizando os dois tipos de arredondamento. Em ambas execuções a
 solução foi encontrada, porém, o caminho percorrido é diferente. Neste
 caso, o algoritmo com arredondamento para baixo chegou à solução em
 apenas dois passos, enquanto a outra implementação chegou à solução em
 três passos. Porém, isso não implica que utilizar arredondamento para
 baixo é a melhor escolha, em outros casos o arredondamento para cima
 poderia se sair melhor, não há uma escolha correta em qual
 arredondamento utilizar. Essa escolha pode depender da situação onde
 a busca binária será usada, ou apenas de qual é mais intuitiva de
 implementar.

### binary_search()

Dentro do arquivo **binary_search.c**, além da linha `#include
 "src/binary_search.h"`, existe apenas a declaração de uma função, sendo
 ela a função `binary_search()`, responsável pela lógica da
 _busca binária_. Seu protótipo é:

```
void* binary_search(const void *key, const void *base, size_t nintems, size_t size, int (*compar)(const void *, const void *), int *path, int ifnotfound);
```

A função `binary_search()` já possui sua interface definida, por tanto,
 é importante que o corpo da função obedeça a seus parâmetros para que
 os testes possam ser executados com êxito. Para isso, é importante
 entender o significado de cada parâmetro, como também de seu retorno.

Referente aos argumentos, comparando com a função **bsearch()**
 encontrada na biblioteca padrão C e outras implementações encontradas
 pela internet, a função binary_search() presente nesse programa, possui
 dois argumentos a mais, **\*path** e **\*ifnotfound**, os quais
 permitem visualizar o caminho percorrido e retornar elementos
 alternativos caso o procurado não tenha sido encontrado, ambas
 características que não estão presentes na bsearch().

Os argumentos da binary_search():

- **\*key** : esse ponteiro aponta para a chave usada na busca, ou seja,
 o elemento procurado deve possuir seu atributo chave igual ao valor de
 `*key`.

- **\*base** : esse ponteiro aponta para o vetor onde a busca será
 feita. Lembrando que esse vetor deve estar ordenado.

- **nitems** : esse inteiro informa a quantidade de elementos que o
 vetor possui.

- **size** : é o tamanho em memória que os dados indexados pelo vetor
 `base` ocupam, normalmente pode-se usar a função `sizeof()` para
 encontrar este valor.

- **\*compar** : esse ponteiro define a função que será usada para
 comparar os elementos do vetor. Essa função deve receber dois
 argumentos do tipo `const void *`, onde o primeiro argumento representa
 o ponteiro `key`, e o segundo receberá o endereço do elemento do vetor
 que será comparado. A função deve retornar um inteiro negativo caso
 `key` seja menor que o elemento passado no segundo argumento, um
 inteiro positivo caso `key` seja maior, ou zero caso eles sejam iguais.

- **\*path** : esse ponteiro representa o caminho processado pelo
 algoritmo até chegar na solução. Ele pode ser igual a `NULL`, indicando
 que o caminho para chegar à solução não é necessário (neste caso,
 `path` não deve ser manipulado), ou ser o endereço de um vetor de
 inteiros pré alocado, onde durante a busca, na primeira posição do
 vetor deve ser armazenado o valor do primeiro elemento processado na
 busca, na segunda posição do vetor armazenado o valor do segundo
 elemento processado na busca, e assim por diante.

- **ifnotfound** : esse inteiro informa qual deve ser o retorno da
 função caso o elemento buscado não seja encontrado. `ifnotfound` pode
 assumir os três valores:
 
	- -1 : deve ser retornado o maior elemento detre aqueles com o
	 atributo chave menores que o valor de `key`;
	- 0 : deve ser retornado `NULL`;
	- 1 : deve ser retornado o menor elemento detre aqueles com o
	 atributo chave maoires que o valor de `key`.

- o **retorno** da função, nada mais é que o endereço do elemento
 procurado. Porém, a função deve retornar `NULL` caso ocorra algum dos
 três casos:

	- o elemento não foi encontrado e `ifnotfound` é igual a 0;
	- o elemento não foi encontrado, `ifnotfound` é igual a -1 e o valor
	 de `*key` é menor que o valor do atributo chave do primeiro
	 elemento dentro do vetor;
	- o elemento não foi encontrado, `ifnotfound` é igual a 1 e o valor
	 de `*key` é maior que o valor do atributo chave do último elemento
	 dentro do vetor.

Um exemplo do uso dessa função seria:

```
/* consirando que a função de comparação possui o nome comp_int e já
 tenha sido implementada em outro local */

int v[] = {3, 5, 7, 11};
int caminho[4];
int chave = 4;

int *ret = binary_search(&chave, v, 4, sizoef(int), comp_int, caminho, 0);

if (ret == NULL) {
	printf("O elemento %d não está presente no vetor", chave);
}
else {
	printf("O elemento %d está no vetor", chave);
}

```

## Execução dos testes

Após escrever o código da busca binária, para compilar o programa e
 executar os testes básicos em seguida deve-se rodar o comando:

	make

![make sem parâmetros](images/make_01.jpg)

Na saída do comando podemos ter acesso aos erros encontrados durante a
 compilação, e logo em seguida o resultado da execução dos testes
 básicos.

Por padrão, a maioria dos testes executados consideram que o algoritmo
 da busca utiliza **arredondamento para cima** (mais a frente há uma
 explicação sobre os dois tipos de [arredondamentos](#arredondamentos)
 possíveis), por tanto, se seu código foi implementado utilizando
 arredondamento para baixo, não precisa se preocupar caso os testes
 retornem falha (mais a frente também há uma explicação de como
 [interpretar](#interpretando-as-saídas-dos-testes) o resultado dos
 testes). Além de considerar que foi utilizado arredondamento para cima,
 são executados apenas testes que encontram o elemento buscado, ou que
 retornam `NULL` por não encontrá-lo.

Após cada alteração no código é necessário utilizar o comando `make`
 novamente. Porém, se o teste que você deseja realizar não faz parte
 daqueles feitos ao rodar o comando, será necessário executar o arquivo
 `binary_search`, criado com a compilação do código. A escolha dos
 testes a realizar é feita a partir da combinação de argumentos passados
 na execução do programa, possuindo como possíveis valores as opções
 listadas a baixo:

- Referentes ao tipo de arredondamento utilizado (caso ambos valores
 sejam passados, o último será o considerado)
	- **t** : executa os testes com arredondamento para cima;
	- **d** : executa os testes com arredondamento para baixo.

- Referentes ao retorno da função caso o elemento buscado não seja
 encontrado (pode-se usar mais que um)
	- **-1** : executa os testes que retornam o maior elemento detre
	aqueles com o atributo chave menores que o valor de `key`;
	- **0** : executa os testes que retornam `NULL`;
	- **1** : executa os testes que retornam o menor elemento detre
	aqueles com o atributo chave maoires que o valor de `key`;
	- **2** : executa todos os três tipos de testes anteriores.

**Por exemplo:** caso você tenha implementado sua busca binária com
 arredondamento para baixo, e pretenda utilizá-la em duas situações
 diferentes, uma onde caso não encontrado o elemento buscado seja
 necessário retornar o maior elemento detre os menores que ele, e na
 outra onde caso o elemento buscado não seja encontrado não deva-se
 retornar nenhum outro em seu lugar, uma possível execução do programa
 para esse exemplo seria:

	./binary_search d -1 0

Assim, os testes para as situações consideradas, e apenas eles, seriam
 realizados.

### Dica

Se durante o desenvolvimento da busca binária, os testes que você queira
 que sejam realizados sejam sempre os mesmos, você pode alterar a
 segunda linha do arquivo `Makefile`, acrescentando a passagem de
 argumentos na execução do programa, assim, todos os testes (além da
 compilação do código há cada mudança nele) já serão executados ao
 utilizar o comando `make`.

Fazendo essa alteração a partir do editor de textos nano:

![alterando o arquivo Makefile](images/make_alterado.jpg)

Executando novamente o comando `make`:

![executando o Makefile alterado](images/make_02.jpg)

Na saída podemos ver que vários erros foram encontrados durante os
 testes, porém, isso já era esperado, pois o algoritmo que estava sendo
 usado ao executar o `make` utiliza arredondamento para cima. Também é
 importante mencionar que, embora a execução do `make` tenha
 retornado erros, esses 10 erros são referentes aos testes da busca
 binária que falharam.

## Interpretando as saídas dos testes

Primeiramente vamos utilizar como exemplo a saída a baixo, gerada a
 partir da execução do comando `make` com o arquivo `Makefile` alterado
 para realizar testes com arredondamento para baixo:

![teste com arredondamento para baixo](images/test_down.jpg)

Nessa saída não é possível ver os erros ou avisos de compilação, que
 são mostrados antes da primeira linha da imagem mostrada. Do que está
 presente na imagem, devemos dar atenção às seguintes informações:

![interpretando a saída](images/interpretando_01.jpg)

- Demarcado em amarelo, temos o comando usado para executar o
 `binary_search`, o mesmo comando presente na segunda linha do
 `Makefile`.

- Em vermelho temos toda a saída referente aos testes, gerada
 exclusivamente a partir do uso do framework
 [Unity](https://github.com/ThrowTheSwitch/Unity/tree/master), sendo o
 resultado dos testes cada uma das linhas começada com `src/main.c`,
 onde temos entre os caracteres `:` alguma informação sobre o teste
 específico. Usando como exemplo o primeiro resultado (demarcado em
 azul) temos:

	- `src/main.c` : é o arquivo onde a chamada do teste está, no caso,
	 todos os testes são chamados no arquivo main.c, dentro da pasta
	 src;
	- `28` : a linha onde o teste foi chamado;
	- `test_empty` : o nome do teste;
	- `PASS` : o resultado do teste, nesse caso significa que a busca
	 binária implementada passou no teste;

- Demarcado em roxo temos o total de testes realizados, seguido pelo
 total de testes que apresentaram falha e pelo total de testes que foram
 ignorados (na implementação desse projeto nenhum teste foi configurado
 para ser ignorado, independentemente dos argumentos passados na
 execução do `binary_search`).

- Por fim, tanto na imagem a cima, quanto na imagem a baixo temos linhas
 demarcadas em verde, esses são testes que falharam. Por tanto, no lugar
 de `PASS`, como na linha demarcada em azul, há a palavra `FAIL`, e após
 ela temos a descrição da falha.

![interpretando a saída](images/interpretando_02.jpg)

Ao combinar o **nome do teste** com a **descrição da falha**, obtemos a
 melhor indicação do motivo de seu ocorrimento. Mas antes, é necessário
 entender no que consiste um teste.

### O que os testes fazem

Os testes consistem na execução da busca binária em vários ambientes
 diferentes, onde sua solução já é conhecida, preparados para englobar
 todas as possibilidades na execução da busca, considerando:

- o dado procurado estar e não estar no vetor;
- o vetor possuir uma quantidade par ou uma quantidade ímpar de
 elementos;
- o vetor ser vazio;
- o vetor ter apenas um elemento;
- ocorrer arredondamentos consecutivos, não ocorrer arredondamentos, ou
 a intercalação dessas duas possibilidades;
- ser requisitado o caminho da busca ou não ser requisitado.

Em geral, o **ambiente do teste** é composto por um vetor com _n_
 números primos (a partir do 3) do tipo `typedef long long int lli` onde
 a busca ocorrerá, e um vetor de chaves a serem pesquisadas. Caso seja
 esperado que a `binary_search()` encontre o dado pesquisado, esse vetor
 será idêntico ao vetor onde a busca será feita, caso não seja esperado,
 o vetor será composto pelos _n_ números que antecedem os elementos do
 vetor de primos (o número que precede 3 é o número 2, assim por
 diante), mais um elemento igual ao antecessor do próximo primo
 referente ao último elemento.

**Por exemplo**, se _n_ for igual a 5, o vetor de primos será _{3, 5, 7,
 11, 13}_, e o vetor de chaves será _{2, 4, 6, 10, 12, 16}_. 

Na execução do teste, a busca binária será executada para cada uma das
 chaves utilizando o mesmo vetor de primos, assim, o teste só resultará
 em sucesso caso todos os retornos da busca estejam de acordo com as
 chaves passadas, considerando o valor de `ifnotfound`. Não só isso, mas
 o **ambiente do teste** também possui o caminho esperado que a busca
 percorra, o qual será comparado com o vetor **path** após a execução da
 busca.

Por tanto, o teste seguirá os passos:

- configurar o ambiente de teste;
- executar a busca das _n_ (ou _n+1_ caso seja testado o retorno quando
 o elemento buscado não está no vetor) chaves dentro do vetor de primos;
- comparar o retorno da função com o valor já esperado;
- comparar o caminho percorrido pela função com o caminho já esperado.

### Decrição da falha

A sua descrição será referente ao primeiro comportamento inesperado.
 Caso a primeira comparação do teste não esteja de acordo, a descrição
 da falha será semelhante à descrição da linha demarcada em verde na
 segunda imagem a cima. Essas saídas possuem o formato `Expected x Was
 y. Searching z`, onde:

- **x** : representa o retorno esperado que a função `binary_search()`
 devolvesse;
- **y** : representa o retorno que a busca de fato devolveu;
- **z** : representa a chave procurada na ocorrência da falha;

Se o retorno da função estiver de acordo, mas o caminho percorrido não
 esteja, a descrição da falha terá uma informação extra antes de
 `Expected x` com o formato `Element w`, onde **w** representa a
 primeira posição de **path** que não está de acordo com o esperado.


**Por exemplo**: a falha `Element 0 Expect 5 Was 7. Searching 3.`
 informa que ao passar a chave _3_ para a busca binária, embora o
 retorno da função tenha sido correto (essa informção é implicita, pois
 se não fosse verdade, a descrição da falha seria referente à essa
 informação, e não ao caminho percorrido), o primeiro elemento
 processado no caminho percorrido pela função possui valor _7_, porém
 era esperado que esse valor fosse _5_.

Já a falha `Expected 19 Was 2. Searching 20` informa que ao passar a
 chave _20_, o retorno da busca foi o valor _2_, quando na verdade
 deveria ser _19_.

:bangbang: _**Obs:**_ esses testes não possuem tratamento para
 _segmentation fault_ ou erros do tipo, por tanto, a única indicação da
 origem desse erro é o teste que estava sendo executado quando ele
 aconteceu. O nome do teste não estará presente na saída do programa,
 sendo necessário identificá-lo com base nos argumentos passados na
 execução do programa e no último teste executado até o fim (o último
 presente na saída). Para saber a sequência em que os testes são feitos
 acesse [doc/sequence.txt](doc/sequence.txt).

### Nome do teste

Todos os testes possuem a descrição do que fazem em seu nome. Em geral,
 todos os testes tem seu nome iniciado com a palavra `test` seguido da
 palavra `top` ou `down`, inidicando qual tipo de arredondamento será
 considerado, arredondamento para baixo (down) ou arredondamento para
 cima (top). Depois, temos no nome algum número em formato texto (one,
 four, five, six ou seven), indicando quantos elementos o vetor onde é
 feito a busca possui. Alguns testes tem seu nome terminado por esse
 número, sendo estes, testes onde o elemento procurado está presente no
 vetor e a busca deva encontrá-lo.

Os testes que possuem mais informação, ou seja, os testes onde o
 elemento procurado não está no vetor, possuem após a informação da
 quantidade de elementos, as palavras `not_found`, e após elas, podem ou
 não ter a palavra `bef` (de before) ou a palavra `next`.

- Caso o nome do teste termine em `not_found`, significa que na execução
 da função `binary_search()` será passado para o argumento `ifnotfound`
 o valor `0`;
- Caso o nome termine em `bef`, significa que foi passado para o
 argumento `ifnotfound` o valor `-1`;
- Caso o nome termine em `next`, significa que foi passado para o
 argumento `ifnotfound` o valor `1`,

Por fim, temos três testes que não seguem esse padrão, e que são
 sempre executados. São eles:

- **test_empty** : testa a busca para um vetor vazio;
- **test_one** : testa a busca para um vetor com apenas um elemento, o
 mesmo que está sendo procurado;
- **test_one_nopath** : igual ao de cima, mas na execução da
 `binary_search()` passa o valor `NULL` para o argumento `*path`,
 indicando que não deve-se retornar o caminho percorrido.

**Por exemplo**, o teste `test_top_five_not_found_bef` testa a busca
 binária implementada com arredondamento para cima utilizando um vetor
 de cinco elementos, onde o elemento procurado não está presente, sendo
 esperado que ao não encontrá-lo seja retornado o maior elemento detre
 aqueles com o atributo chave menores que o valor de `key`.

O teste `test_down_seven_not_found_next` por sua vez, testa a busca
 binária implementada com arredondamento para baixo ultilizando um vetor
 de sete elementos, onde o elemento procurado não está presente, sendo
 esperado que ao não encontrá-lo seja retornado o menor elemento detre
 aqueles com o atributo chave maoires que o valor de `key`.

### Motivo dos testes

Embora aqueles testes que não seguem o esquema padrão de nome tenham o
 motivo de sua criação explícitos em sua descrição, o motivo da criação
 dos testes onde seus vetores possuem diferentes quantidades de
 elementos não é tão clara. As diferentes quantidades de elementos estão
 relacionadas à necessidade de arredondamento na execução da busca e a
 não necessidade dele, considerando também a intercalação dessas duas
 possibilidade. Isso para chaves específicas que geram um processamento
 exclusivo da busca comparado com as outras quantidades de elementos.
 Assim, usando como exemplo arredondamento para cima, em testes com o
 vetor possuindo:

- **quatro elementos** : a busca realiza dois arredondamentos
 consecutivos. Ao passar as chaves _3_ e _5_;
- **cinco elementos** : a busca primeiramente compara o elemento no
 centro do vetor (não é necessário usar arredondamento nesse passo), e
 depois realiza um arredondamento. Ao passar as chaves _3, 5, 11_ e
 _13_;
- **seis elementos** : a busca primeiramente faz um arredondamento e em
 seguida compara apenas elementos que estão no centro dos subvetores
 encontrados. Ao passar as chaves _3, 5_ e _7_;
- **sete elementos** : a busca apenas compara elementos que estão no
 centro do conjunto analisado, para todas as chaves;

Assim, com todos os testes mencionado é possível saber se a busca está:

- se comportando corretamente para vetores:
	- vazios;
	- com apenas um elemento;
	- com vários elementos;
- se comportando corretamente quando:
	- é realizado dois ou mais arredondamentos em seguida;
	- é realizado um arredondamento logo após a comparação de um
	 elemento de centro;
	- é comparado um elemento de centro logo após a realização de um
	 arredondamento;
	- não ocorre arredondamentos, apenas é feita a comparação de vários
	 elementos de centro em seguida.

Embora os testes mencionados realizem apenas arredondamento para cima,
 os testes com arredondamento para baixo se comportaram de maneira
 igual. Também temos um comportamento semelhante para teste onde a chave
 pesquisada não está no vetor.

Para saber como um teste específico funciona, qual seu ambiente e outras
 informações mais detalhadas sobre ele, acesse
 [doc/tests.txt](doc/tests.txt).

## A fazer

- [X] testes padrões
- [X] testes com arredondamento para cima
	- [X] encontrados
	- [X] não encontrados retornando NULL
	- [X] não encontrados retornando o predecessor
	- [X] não encontrados retornando o sucessor
- [X] testes com arredondamento para baixo
	- [X] encontrados
	- [X] não encontrados retornando NULL
	- [X] não encontrados retornando o predecessor
	- [X] não encontrados retornando o sucessor
- [X] criar testes com mensagens
- [X] melhorar mensagens nos testes
- [X] permitir maior interação com o que o usuário deseja testar
- [X] facilitar interação com o usuário
- [X] escrever o readme
	- [X] descrever o funcionamento da busca binária
	- [X] descrever como executar o programa
	- [X] descrever como analisar os erros encontrados
	- [X] descrever o motivo de cada teste
- [X] corrigir erros no README
- [X] escrever arquivo tests.txt
- [X] escrever arquivo sequence.txt
- [ ] melhorar o README
