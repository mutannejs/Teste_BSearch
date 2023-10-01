#include "binary_search.h"

/* ### TESTES USANDO BUSCA BINÁRIA COM ARREDONDAMENTO PARA CIMA
 * QUE RETORNA ELEMENTO ENCONTRADO ### */

void test_down_four() {

	basics b = set_basics(0);
	int qtd = 4;
	int len_path[] = {2, 1, 2, 3};
	int path_expected[4][4] = {
		{1, 0},
		{1},
		{1, 2},
		{1, 2, 3} };

	test_compare(qtd, b, len_path, path_expected);

}

void test_down_five() {

	basics b = set_basics(0);
	int qtd = 5;
	int len_path[] = {2, 3, 1, 2, 3};
	int path_expected[5][4] = {
		{2, 0},
		{2, 0, 1},
		{2},
		{2, 3},
		{2, 3, 4} };

	test_compare(qtd, b, len_path, path_expected);

}

void test_down_six() {

	basics b = set_basics(0);
	int qtd = 6;
	int len_path[] = {2, 3, 1, 3, 2, 3};
	int path_expected[6][4] = {
		{2, 0},
		{2, 0, 1},
		{2},
		{2, 4, 3},
		{2, 4},
		{2, 4, 5} };

	test_compare(qtd, b, len_path, path_expected);

}

void test_down_seven() {

	basics b = set_basics(0);
	int qtd = 7;
	int len_path[] = {3, 2, 3, 1, 3, 2, 3};
	int path_expected[7][4] = {
		{3, 1, 0},
		{3, 1},
		{3, 1, 2},
		{3},
		{3, 5, 4},
		{3, 5},
		{3, 5, 6} };

	test_compare(qtd, b, len_path, path_expected);

}


/* ### FUNÇÕES GENÉRICAS PARA REALIZAÇÃO DOS TESTES USANDO BUSCA BINÁRIA
 * COM ARREDONDAMENTO PARA CIMA ### */

void down_four_not_found(int ifnotfound) {

	basics b = set_basics(1);
	int qtd = 4;
	int len_path[] = {2, 2, 2, 3, 3};
	int path_expected[5][4] = {
		{1, 0},
		{1, 0},
		{1, 2},
		{1, 2, 3},
		{1, 2, 3} };

	test_compare_not_found(qtd, b, len_path, path_expected, ifnotfound);

}

void down_five_not_found(int ifnotfound) {

	basics b = set_basics(1);
	int qtd = 5;
	int len_path[] = {2, 3, 3, 2, 3, 3};
	int path_expected[6][4] = {
		{2, 0},
		{2, 0, 1},
		{2, 0, 1},
		{2, 3},
		{2, 3, 4},
		{2, 3, 4} };

	test_compare_not_found(qtd, b, len_path, path_expected, ifnotfound);

}

void down_six_not_found(int ifnotfound) {

	basics b = set_basics(1);
	int qtd = 6;
	int len_path[] = {2, 3, 3, 3, 3, 3, 3, };
	int path_expected[7][4] = {
		{2, 0},
		{2, 0, 1},
		{2, 0, 1},
		{2, 4, 3},
		{2, 4, 3},
		{2, 4, 5},
		{2, 4, 5} };

	test_compare_not_found(qtd, b, len_path, path_expected, ifnotfound);

}

void down_seven_not_found(int ifnotfound) {

	basics b = set_basics(1);
	int qtd = 7;
	int len_path[] = {3, 3, 3, 3, 3, 3, 3, 3};
	int path_expected[8][4] = {
		{3, 1, 0},
		{3, 1, 0},
		{3, 1, 2},
		{3, 1, 2},
		{3, 5, 4},
		{3, 5, 4},
		{3, 5, 6},
		{3, 5, 6} };

	test_compare_not_found(qtd, b, len_path, path_expected, ifnotfound);

}


/* ### TESTES USANDO BUSCA BINÁRIA COM ARREDONDAMENTO PARA CIMA
 * QUE RETORNA ELEMENTO NÃO ENCONTRADO ### */

void test_down_four_not_found() {
	down_four_not_found(0);
}

void test_down_five_not_found() {
	down_five_not_found(0);
}

void test_down_six_not_found() {
	down_six_not_found(0);
}

void test_down_seven_not_found() {
	down_seven_not_found(0);
}


/* ### TESTES USANDO BUSCA BINÁRIA COM ARREDONDAMENTO PARA CIMA
 * QUE RETORNA ELEMENTO PREDECESSOR ### */

void test_down_four_not_found_bef() {	
	down_four_not_found(-1);
}

void test_down_five_not_found_bef() {
	down_five_not_found(-1);
}

void test_down_six_not_found_bef() {	
	down_six_not_found(-1);
}

void test_down_seven_not_found_bef() {	
	down_seven_not_found(-1);
}


/* ### TESTES USANDO BUSCA BINÁRIA COM ARREDONDAMENTO PARA CIMA
 * QUE RETORNA ELEMENTO SUCESSOR ### */

void test_down_four_not_found_next() {
	down_four_not_found(1);
}

void test_down_five_not_found_next() {
	down_five_not_found(1);
}

void test_down_six_not_found_next() {
	down_six_not_found(1);
}

void test_down_seven_not_found_next() {
	down_seven_not_found(1);
}
