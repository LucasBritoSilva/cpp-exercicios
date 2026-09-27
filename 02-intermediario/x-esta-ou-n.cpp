/*
    Programa que verifica se um determinado número está presente em um vetor.
    A função decide() realiza a busca de forma recursiva, verificando os elementos
    do vetor um por um até encontrar o valor procurado ou chegar ao final do vetor.
    Ao final, o programa informa se o número está ou não presente no vetor.
*/

#include <iostream>
using namespace std;

#define MAX 100

bool decide(int a[], int n, int x) {
    if (n == 0) {
        return false;
    }
    if (a[n - 1] == x) {
        return true;
    }
    return decide(a, n - 1, x);
}

int main() {
    int n, x;
    cin >> n;
    cin >> x;
    int a[MAX];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (decide(a, n, x)) {
        cout << "x esta no vetor" << endl;
    }
    else {
        cout << "x nao esta no vetor" << endl;
    }
    return 0;
}