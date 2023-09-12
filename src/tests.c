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

	for (int i = 0; i < qtd; i++) {
		ret = binary_search(&b.keys[i], b.vector, qtd, sizeof(lli), cmp, b.path_retorned, 0);
		TEST_ASSERT_EQUAL_INT(b.keys[i], *ret);
		TEST_ASSERT_EQUAL_INT_ARRAY(path_expected[i], b.path_retorned, len_path[i]);
	}

}

void test_compare_not_found(int qtd, basics b, int len_path[], int path_expected[][4]) {

	lli *ret;

	for (int i = 0; i < qtd+1; i++) {
		ret = binary_search(&b.keys[i], b.vector, qtd, sizeof(lli), cmp, b.path_retorned, 0);
		TEST_ASSERT_NULL(ret);
		TEST_ASSERT_EQUAL_INT_ARRAY(path_expected[i], b.path_retorned, len_path[i]);
	}

}

void test_compare_bef(int qtd, basics b, int len_path[], int path_expected[][4]) {

	lli *ret;

	for (int i = 0; i < qtd+1; i++) {
		ret = binary_search(&b.keys[i], b.vector, qtd, sizeof(lli), cmp, b.path_retorned, -1);
		if (i > 0)
			TEST_ASSERT_EQUAL_INT(b.vector[i-1], *ret);
		else
			TEST_ASSERT_NULL(ret);
		TEST_ASSERT_EQUAL_INT_ARRAY(path_expected[i], b.path_retorned, len_path[i]);
	}

}

void test_compare_next(int qtd, basics b, int len_path[], int path_expected[][4]) {

	lli *ret;

	for (int i = 0; i < qtd+1; i++) {
		ret = binary_search(&b.keys[i], b.vector, qtd, sizeof(lli), cmp, b.path_retorned, 1);
		if (i < qtd)
			TEST_ASSERT_EQUAL_INT(b.vector[i], *ret);
		else
			TEST_ASSERT_NULL(ret);
		TEST_ASSERT_EQUAL_INT_ARRAY(path_expected[i], b.path_retorned, len_path[i]);
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
	lli *ret;
	int qtd = 1;
	int path_expected[1] = {3};

	ret = binary_search(&b.keys[0], b.vector, qtd, sizeof(lli), cmp, b.path_retorned, 0);

	TEST_ASSERT_EACH_EQUAL_INT(path_expected[0], b.path_retorned, 1);
	TEST_ASSERT_NULL(ret);

}

void test_one_not_found_bef() {

	basics b = set_basics(1);
	int qtd = 1;
	int len_path[] = {1, 1};
	int path_expected[2][4] = {
		{3},
		{3} };

	test_compare_bef(qtd, b, len_path, path_expected);

}

void test_one_not_found_next() {

	basics b = set_basics(1);
	int qtd = 1;
	int len_path[] = {1, 1};
	int path_expected[2][4] = {
		{3},
		{3} };

	test_compare_next(qtd, b, len_path, path_expected);

}


/* ### TESTES USANDO BUSCA BINÁRIA COM ARREDONDAMENTO PARA CIMA
 * QUE RETORNA ELEMENTO ENCONTRADO ### */

void test_top_four() {

	basics b = set_basics(0);
	int qtd = 4;
	int len_path[] = {3, 2, 1, 2};
	int path_expected[4][4] = {
		{7, 5, 3},
		{7, 5},
		{7},
		{7, 11} };

	test_compare(qtd, b, len_path, path_expected);

}

void test_top_five() {

	basics b = set_basics(0);
	int qtd = 5;
	int len_path[] = {3, 2, 1, 3, 2};
	int path_expected[5][4] = {
		{7, 5, 3},
		{7, 5},
		{7},
		{7, 13, 11},
		{7, 13} };

	test_compare(qtd, b, len_path, path_expected);

}

void test_top_six() {

	basics b = set_basics(0);
	int qtd = 6;
	int len_path[] = {3, 2, 3, 1, 3, 2};
	int path_expected[6][4] = {
		{11, 5, 3},
		{11, 5},
		{11, 5, 7},
		{11},
		{11, 17, 13},
		{11, 17} };

	test_compare(qtd, b, len_path, path_expected);

}

void test_top_seven() {

	basics b = set_basics(0);
	int qtd = 7;
	int len_path[] = {3, 2, 3, 1, 3, 2, 3};
	int path_expected[7][4] = {
		{11, 5, 3},
		{11, 5},
		{11, 5, 7},
		{11},
		{11, 17, 13},
		{11, 17},
		{11, 17, 19} };

	test_compare(qtd, b, len_path, path_expected);

}


/* ### TESTES USANDO BUSCA BINÁRIA COM ARREDONDAMENTO PARA CIMA
 * QUE RETORNA ELEMENTO NÃO ENCONTRADO ### */

void test_top_four_not_found() {

	basics b = set_basics(1);
	int qtd = 4;
	int len_path[] = {3, 3, 2, 2, 2};
	int path_expected[5][4] = {
		{7, 5, 3},
		{7, 5, 3},
		{7, 5},
		{7, 11},
		{7, 11} };

	test_compare_not_found(qtd, b, len_path, path_expected);

}

void test_top_five_not_found();

void test_top_six_not_found();


/* ### TESTES USANDO BUSCA BINÁRIA COM ARREDONDAMENTO PARA CIMA
 * QUE RETORNA ELEMENTO PREDECESSOR ### */

void test_top_five_not_found_bef();

void test_top_six_not_found_bef();


/* ### TESTES USANDO BUSCA BINÁRIA COM ARREDONDAMENTO PARA CIMA
 * QUE RETORNA ELEMENTO SUCESSOR ### */

void test_top_five_not_found_next();

void test_top_six_not_found_next();
