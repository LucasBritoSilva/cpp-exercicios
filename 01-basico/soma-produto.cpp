/*
    Programa que recebe uma quantidade par de números e os analisa em pares.
    A função soma_prod() calcula a soma e o produto de cada par de números.
    O programa conta quantas vezes a soma é maior que o produto e quantas vezes
    o produto é maior que a soma.
*/

#include <iostream>
using namespace std;

void soma_prod(int a, int b, int* som, int* prod) {
	*som = a + b;
	*prod = a * b;
}
int main() {
	int somas = 0;
	int produtos = 0;
	int i, n, a, b, soma, produto;
	cout << "Digite a quantidade de numeros (lembrando que deve ser par): " << endl;
	cin >> n;
	while(n %2 != 0){
		cout << "Digite uma quantidade par: " << endl;
		cin >> n;
	}
	cout << "Digite " << n << " numeros" << endl;
	n = n / 2;
	for(i = 0; i < n; i++) {
		cin >> a;
		cin >> b;
		soma_prod(a, b, &soma, &produto);
		if (soma > produto) {
			somas++;
		}
		else if (produto > soma) {
			produtos++;
		}
	}
	cout << "A quantidade de vezes que a soma eh maior que o prduto eh: " << somas << endl << "A quantidade de vezes que o produto eh maior que a soma eh: " << produtos;
}