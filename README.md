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

## Execução dos testes

Após escrever o código da busca binária, para compilar o programa e
 executar os testes básicos em seguida deve-se rodar o comando:

	make

Por padrão, a maioria dos testes executados consideram que o algoritmo
 da busca utiliza **arredondamento para cima** (mais a frente há uma
 explicação sobre os dois tipos de arredondamentos possíveis), por
 tanto, se seu código foi implementado utilizando arredondamento para
 baixo, não precisa se preocupar caso os testes retornem falha (mais a
 frente também há uma explicação de como interpretar o resultado dos
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
 argumentos na execução do programa, assim, todo os testes (além da
 compilação do código há cada mudança nele) já serão executados ao
 utilizar o comando `make`.

## O algoritmo da Busca Binária

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

### \*key

O ponteiro `key` é o endereço da chave a ser pesquisada, ou seja, o
 elemento procurado possui seu atributo chave igual ao valor de
 `\*key`.

### \*base

O ponteiro `base` é o endereço do vetor onde a busca será feita.
 Lembrando que é esse vetor deve estar ordenado.

### nitems

`nitems` é a quantidade de elementos que o vetor possui.

### size

`size` é o tamanho em memória que os dados indexados pelo vetor
 `base` ocupam, normalmente pode-se usar a função `sizeof()` para
 encontrar este valor.

### \*compar

O ponteiro `compar` define a função que será usada para comparar os
 elementos do vetor.

### \*path

O ponteiro `path` representa o caminho processado pelo algoritmo até
 chegar na solução. Ele pode ser igual a `NULL`, indicando que o
 caminho para chegar à solução não é necessário (neste caso, `path`
 não deve ser manipulado), ou ser o endereço de um vetor de inteiros pré
 alocado, onde na primeira posição do vetor deve ser armazenado o valor
 do primeiro elemento processado na busca, na segunda posição do vetor
 armazenado o valor do segundo elemento processado na busca, e assim por
 diante.

### ifnotfound

O inteiro `ifnotfound` informa qual deve ser o retorno da função caso
 o elemento buscado não seja encontrado. `ifnotfound` pode assumir os
 três valores:
 
- -1 : deve ser retornado o maior elemento detre aqueles com o atributo
 chave menores que o valor de `key`;
- 0 : deve ser retornado `NULL`;
- 1 : deve ser retornado o menor elemento detre aqueles com o atributo
 chave maoires que o valor de `key`.

### retorno

O **retorno** da função nada mais é que o endereço do elemento
 procurado. Porém a função deve retornar `NULL` caso ocorra algum dos
 três casos:

- o elemento não foi encontrado e `ifnotfound` é igual a 0;
- o elemento não foi encontrado, `ifnotfound` é igual a -1 e o valor
 de `\*key` é menor que o valor do atributo chave do primeiro elemento
 dentro do vetor;
- o elemento não foi encontrado, `ifnotfound` é igual a 1 e o valor
 de `\*key` é maior que o valor do atributo chave do último elemento
 dentro do vetor.

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
- [ ] melhorar mensagens nos testes
- [X] permitir maior interação com o que o usuário deseja testar
- [X] facilitar interação com o usuário
- [ ] escrever o readme
	- [ ] descrever o funcionamento da busca binária
	- [ ] descrever o motivo de cada teste
	- [ ] descrever como executar o programa
	- [ ] descrever como analisar os erros encontrados
- [ ] criar arquivo explicando como cada teste funciona
