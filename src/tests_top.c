#include "binary_search.h"

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


/* ### FUNÇÕES GENÉRICAS PARA REALIZAÇÃO DOS TESTES USANDO BUSCA BINÁRIA
 * COM ARREDONDAMENTO PARA CIMA ### */

void top_four_not_found(int ifnotfound) {

	basics b = set_basics(1);
	int qtd = 4;
	int len_path[] = {3, 3, 2, 2, 2};
	int path_expected[5][4] = {
		{7, 5, 3},
		{7, 5, 3},
		{7, 5},
		{7, 11},
		{7, 11} };

	test_compare_not_found(qtd, b, len_path, path_expected, ifnotfound);

}

void top_five_not_found(int ifnotfound) {

	basics b = set_basics(1);
	int qtd = 5;
	int len_path[] = {3, 3, 2, 3, 3, 2};
	int path_expected[6][4] = {
		{7, 5, 3},
		{7, 5, 3},
		{7, 5},
		{7, 13, 11},
		{7, 13, 11},
		{7, 13} };

	test_compare_not_found(qtd, b, len_path, path_expected, ifnotfound);

}

void top_six_not_found(int ifnotfound) {

	basics b = set_basics(1);
	int qtd = 6;
	int len_path[] = {3, 3, 3, 3, 3, 3, 2};
	int path_expected[7][4] = {
		{11, 5, 3},
		{11, 5, 3},
		{11, 5, 7},
		{11, 5, 7},
		{11, 17, 13},
		{11, 17, 13},
		{11, 17} };

	test_compare_not_found(qtd, b, len_path, path_expected, ifnotfound);

}

void top_seven_not_found(int ifnotfound) {

	basics b = set_basics(1);
	int qtd = 7;
	int len_path[] = {3, 3, 3, 3, 3, 3, 3, 3};
	int path_expected[8][4] = {
		{11, 5, 3},
		{11, 5, 3},
		{11, 5, 7},
		{11, 5, 7},
		{11, 17, 13},
		{11, 17, 13},
		{11, 17, 19},
		{11, 17, 19} };

	test_compare_not_found(qtd, b, len_path, path_expected, ifnotfound);

}


/* ### TESTES USANDO BUSCA BINÁRIA COM ARREDONDAMENTO PARA CIMA
 * QUE RETORNA ELEMENTO NÃO ENCONTRADO ### */

void test_top_four_not_found() {
	top_four_not_found(0);
}

void test_top_five_not_found() {
	top_five_not_found(0);
}

void test_top_six_not_found() {
	top_six_not_found(0);
}

void test_top_seven_not_found() {
	top_seven_not_found(0);
}


/* ### TESTES USANDO BUSCA BINÁRIA COM ARREDONDAMENTO PARA CIMA
 * QUE RETORNA ELEMENTO PREDECESSOR ### */

void test_top_four_not_found_bef() {	
	top_four_not_found(-1);
}

void test_top_five_not_found_bef() {
	top_five_not_found(-1);
}

void test_top_six_not_found_bef() {	
	top_six_not_found(-1);
}

void test_top_seven_not_found_bef() {	
	top_seven_not_found(-1);
}


/* ### TESTES USANDO BUSCA BINÁRIA COM ARREDONDAMENTO PARA CIMA
 * QUE RETORNA ELEMENTO SUCESSOR ### */

void test_top_four_not_found_next() {
	top_four_not_found(1);
}

void test_top_five_not_found_next() {
	top_five_not_found(1);
}

void test_top_six_not_found_next() {
	top_six_not_found(1);
}

void test_top_seven_not_found_next() {
	top_seven_not_found(1);
}
