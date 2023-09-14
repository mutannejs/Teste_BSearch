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

## Como usar

Primeiramente faça um clone do repositório em sua máquina. Utilizando o
 terminal essa operação pode ser feita executando o comando:

```
git clone https://github.com/mutannejs/Teste_BSearch.git
```

Dentro da pasta do programa há um arquivo chamado **binary_search.c**, é
 neste arquivo que você deve escrever seu código da busca binária.
 Dentro do arquivo existe apenas uma função, além da linha `#include
 "src/binary_search.h"`, sendo a função `binary_search()` responsável
 pela lógica da _busca binária_. Seu protótipo é:

```
void* binary_search(const void *key, const void *base, size_t nintems, size_t size, int (*compar)(const void *, const void *), int *path, int ifnotfound);
```
 
A função binary_search() já possui sua interface definida, por tanto, é
 importante que o corpo da função obedeça a seus parâmetros para que os
 testes possam ser executados com êxito. Para isso, é importante
 entender o significado de cada parâmetro, como também de seu retorno.

- o ponteiro **\*key** é o endereço da chave a ser pesquisada, ou seja,
 o elemento procurado possui seu atributo chave igual ao valor de
 **\*key**
- o ponteiro **\*base** é o endereço do vetor onde a busca será feita
- **nitems** é a quantidade de elementos que o vetor possui
- **size** é o tamanho em memória que os dados indexados pelo vetor
 **base** ocupam, normalmente pode-se usar a função `sizeof()` para
 encontrar este valor
- o ponteiro **\*compar** define a função que será usada para comparar
 os elementos do vetor
- o ponteiro **\*path** representa o caminho processado pelo algoritmo
 até chegar na solução. Ele pode ser igual a `NULL`, indicando que o
 caminho para chegar à solução não é necessário (neste caso, **path**
 não deve ser manipulado), ou ser o endereço de um vetor de inteiros pré
 alocado, onde na primeira posição do vetor deve ser armazenado o valor
 do primeiro elemento processado na busca, na segunda posição do vetor
 deve ser armazenado o valor do segundo elemento processado na busca, e
 assim por diante.
- o inteiro **ifnotfound** informa qual deve ser o retorno da função
 caso não haja nenhum elemento com a chave pesquisada dentro do vetor,
 ou seja, o elemento não foi encontrado. **ifnotfound** pode assumir os
 três valores:
	- -1 : deve ser retornado o maior elemento detre aqueles com o
	atributo chave menores que o valor de **key**
	- 0 : deve ser retornado NULL
	- 1 : deve ser retornado o menor elemento detre aqueles com o
	atributo chave maoires que o valor de **key**
- o **retorno** da função nada mais é que o endereço do elemento
 procurado, ou `NULL` caso ocorra algum dos três casos seguintes:
	- o elemento não foi encontrado e **ifnotfound** é igual a 0
	- o elemento não foi encontrado, **ifnotfound** é igual a -1 e o
	valor de **key** é menor que o valor do atributo chave do primeiro
	elemento dentro do vetor
	- o elemento não foi encontrado, **ifnotfound** é igual a 1 e o
	valor de **key** é maior que o valor do atributo chave do último
	elemento dentro do vetor

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
