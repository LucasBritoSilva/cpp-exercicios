/*
    Programa que recebe uma quantidade de números e armazena os valores em um vetor.
    A função maximo() percorre o vetor e identifica o maior elemento,
    retornando o endereço de memória onde esse elemento está armazenado.
    Ao final, o programa exibe o endereço retornado pela função.
*/

#include <iostream>
using namespace std;
#define MAX 100
int i;
int* maximo(int n, int v[MAX]) {
	int* endereco = &v[0];
	for (i = 0;i < n;i++) {
		if (v[i] > *endereco) {
			endereco = &v[i];
		}
	}
	return endereco;
}
int main() {
	int i, v[MAX], n;
	int* endereco;
	cout << "Digite a quantidade de numeros: " << endl;
	cin >> n;
	while (n <= 0) {
		cout << "Digite um numero maior que 0: " << endl;
		cin >> n;
	}
	cout << "Digite os numeros: " << endl;
	for (i = 0; i < n;i++) {
		cin >> v[i];
	}
	
	endereco = maximo(n, v);
	cout << endl << endereco << endl;
	return 0;
}