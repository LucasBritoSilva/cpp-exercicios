#include <iostream>
using namespace std;
#define MAX 100
void dois_maiores(int n, int v[MAX], int* pr, int* seg){
    int i;

    *pr = v[0];
    *seg = 0;

    for (i = 1; i < n; i++)
    {
        if (v[i] > *pr) {
            *seg = *pr;
            * pr = v[i];
        }
        else {
            if (v[i] > *seg) {
                *seg = v[i];
            }
        }
    }
}
int main() {
    int i, n, v[MAX], primeiro, segundo;
    cout << "Digite a quantidade de numeros: " << endl;
    cin >> n;
    if (n < 2) {
        cout << "Quantidade invalida, digite novamente: " << endl;
        cin >> n;
    }
    for (i = 0;i < n;i++) {
        cin >> v[i];
    }
    dois_maiores(n, v, &primeiro, &segundo);
    cout << "O maior numero eh: " << primeiro << endl << "O segundo maior numero eh: " << segundo;
}