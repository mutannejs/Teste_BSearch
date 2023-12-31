#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../unity/unity.h"

#ifndef _BINARYSEARCH_H_
#define _BINARYSEARCH_H_

/* ### TIPO DOS ELEMENTOS ### */

typedef long long int lli;

typedef struct {
	lli vector[7];
	lli keys[8];
	int path_retorned[4];
} basics;


/* ### BUSCA BINÁRIA ### */

/**
 * @param key			a chave do elemento que será pesquisado.
 * @param base			o vetor onde a busca será feita.
 * @param nitems		a quantidade de elementos alocados no vetor.
 * @param size			o tamanho dos elementos envolvidos na busca.
 * @param compar		a função usada para comparar os elementos do vetor.
 * @param path			vetor com o índice de todos elementos processados na busca até finalizá-la.
 * @param ifnotfound	informa qual elemento deve ser retornado caso não haja nenhum elemento com a chave informada.
 * 
 * @return o elemento com a chave passada ou NULL caso ele não tenha sido encontrado.
 * */
void* binary_search(const void *key, const void *base, size_t nintems, size_t size, int (*compar)(const void *, const void *), int *path, int ifnotfound);


/* ### NECESSÁRIAS NO USO DO UNITY ### */

void setUp();

void tearDown();


/* ### NECESSÁRIAS NA PREPARAÇÃO DOS DADOS E COMPARAÇÃO DOS ELEMENTOS ### */

int cmp();

basics set_basics(int is_notfound);

void test_compare(int qtd, basics b, int len_path[], int path_expected[][4]);

void test_compare_not_found(int qtd, basics b, int len_path[], int path_expected[][4], int ifnotfound);


/* ### TESTES BUSCA BINÁRIA INDEPENDENTE DO ARRENDONDAMENTO ###*/

void test_empty();

void test_one();

void test_one_nopath();

void test_one_not_found();

void test_one_not_found_bef();

void test_one_not_found_next();


/* ### TESTES USANDO BUSCA BINÁRIA COM ARREDONDAMENTO PARA CIMA ### */

void test_ceil_four();

void test_ceil_five();

void test_ceil_six();

void test_ceil_seven();

void ceil_four_not_found(int ifnotfound);

void ceil_five_not_found(int ifnotfound);

void ceil_six_not_found(int ifnotfound);

void ceil_seven_not_found(int ifnotfound);

void test_ceil_four_not_found();

void test_ceil_five_not_found();

void test_ceil_six_not_found();

void test_ceil_seven_not_found();

void test_ceil_four_not_found_bef();

void test_ceil_five_not_found_bef();

void test_ceil_six_not_found_bef();

void test_ceil_seven_not_found_bef();

void test_ceil_four_not_found_next();

void test_ceil_five_not_found_next();

void test_ceil_six_not_found_next();

void test_ceil_seven_not_found_next();


/* ### TESTES USANDO BUSCA BINÁRIA COM ARREDONDAMENTO PARA BAIXO ### */

void test_floor_four();

void test_floor_five();

void test_floor_six();

void test_floor_seven();

void test_floor_four_not_found();

void test_floor_five_not_found();

void test_floor_six_not_found();

void test_floor_seven_not_found();

void test_floor_four_not_found_bef();

void test_floor_five_not_found_bef();

void test_floor_six_not_found_bef();

void test_floor_seven_not_found_bef();

void test_floor_four_not_found_next();

void test_floor_five_not_found_next();

void test_floor_six_not_found_next();

void test_floor_seven_not_found_next();

#endif
