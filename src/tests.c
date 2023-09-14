#include "binary_search.h"

/* ### NECESSÁRIAS NO USO DO UNITY ### */

void setUp() {}

void tearDown() {}


/* ### NECESSÁRIAS NA PREPARAÇÃO DOS DADOS E COMPARAÇÃO DOS ELEMENTOS ### */

basics set_basics(int is_notfound) {

	basics b;

	lli primos[] = {3, 5, 7, 11, 13, 17, 19, 21};

	for (int i = 0; i < 7; i++) {
		b.vector[i] = primos[i];
	}

	for (int i = 0; i < 8; i++) {
		if (!is_notfound)
			b.keys[i] = primos[i];
		else
			b.keys[i] = primos[i]-1;
	}

	for (int i = 0; i < 4; i++)
		b.path_retorned[i] = -1;

	return b;

}

void test_compare(int qtd, basics b, int len_path[], int path_expected[][4]) {

	lli *ret;
	char mensagem[200];

	for (int i = 0; i < qtd; i++) {

		sprintf(mensagem, "O erro ocorreu ao pesquisar o elemento %lld.", b.keys[i]);

		ret = binary_search(&b.keys[i], b.vector, qtd, sizeof(lli), cmp, b.path_retorned, 0);
		TEST_ASSERT_EQUAL_INT_MESSAGE(b.keys[i], *ret, mensagem);
		TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(path_expected[i], b.path_retorned, len_path[i], mensagem);
	}

}

void test_compare_not_found(int qtd, basics b, int len_path[], int path_expected[][4], int ifnotfound) {

	lli *ret;
	char mensagem[200];

	for (int i = 0; i < qtd+1; i++) {

		sprintf(mensagem, "O erro ocorreu ao pesquisar o elemento %lld.", b.keys[i]);

		ret = binary_search(&b.keys[i], b.vector, qtd, sizeof(lli), cmp, b.path_retorned, ifnotfound);
		if (ifnotfound == -1 && i > 0)
			TEST_ASSERT_EQUAL_INT_MESSAGE(b.vector[i-1], *ret, mensagem);
		else if (ifnotfound == 1 && i < qtd)
			TEST_ASSERT_EQUAL_INT_MESSAGE(b.vector[i], *ret, mensagem);
		else
			TEST_ASSERT_NULL_MESSAGE(ret, mensagem);
		TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(path_expected[i], b.path_retorned, len_path[i], mensagem);
	}

}


/* ### TESTES BUSCA BINÁRIA INDEPENDENTE DO ARRENDONDAMENTO ###*/

void test_empty() {

	basics b = set_basics(0);
	lli *ret;
	int qtd = 0;

	ret = binary_search(&b.keys[0], b.vector, qtd, sizeof(lli), cmp, b.path_retorned, 0);

	TEST_ASSERT_EACH_EQUAL_INT(-1, b.path_retorned, 4);
	TEST_ASSERT_NULL(ret);

}

void test_one() {

	basics b = set_basics(0);
	lli *ret;
	int qtd = 1;
	int path_expected[1] = {3};

	ret = binary_search(&b.keys[0], b.vector, qtd, sizeof(lli), cmp, b.path_retorned, 0);

	TEST_ASSERT_EACH_EQUAL_INT(path_expected[0], b.path_retorned, 1);
	TEST_ASSERT_EQUAL_INT(b.keys[0], *ret);

}

void test_one_nopath() {

	basics b = set_basics(0);
	lli *ret;
	int qtd = 1;

	ret = binary_search(&b.keys[0], b.vector, qtd, sizeof(lli), cmp, NULL, 0);

	TEST_ASSERT_EACH_EQUAL_INT(-1, b.path_retorned, 4);
	TEST_ASSERT_EQUAL_INT(b.keys[0], *ret);

}

void test_one_not_found() {

	basics b = set_basics(1);
	int qtd = 1;
	int len_path[] = {1, 1};
	int path_expected[2][4] = {
		{3},
		{3} };

	test_compare_not_found(qtd, b, len_path, path_expected, 0);

}

void test_one_not_found_bef() {

	basics b = set_basics(1);
	int qtd = 1;
	int len_path[] = {1, 1};
	int path_expected[2][4] = {
		{3},
		{3} };

	test_compare_not_found(qtd, b, len_path, path_expected, -1);

}

void test_one_not_found_next() {

	basics b = set_basics(1);
	int qtd = 1;
	int len_path[] = {1, 1};
	int path_expected[2][4] = {
		{3},
		{3} };

	test_compare_not_found(qtd, b, len_path, path_expected, 1);

}
