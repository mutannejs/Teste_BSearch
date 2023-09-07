#include <stdlib.h>
#include <stdio.h>
#include "unity.h"

#ifndef _BINARYSEARCH_H_
#define _BINARYSEARCH_H_

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
 * @return	o elemento com a chave passada ou NULL caso ele não tenha sido encontrado.
 * */
void* binary_search(const void *key, const void *base, size_t nintems, size_t size, int (*compar)(const void *, const void *), int *path, int ifnotfound);


/* ### NECESSÁRIOS NO USO DO UNITY ### */

void setUp();

void tearDown();


/* ### TESTES USANDO BUSCA BINÁRIA COM ARREDONDAMENTO PARA CIMA ### */

/* ### TESTES USANDO BUSCA BINÁRIA COM ARREDONDAMENTO PARA CIMA ### */

#endif
