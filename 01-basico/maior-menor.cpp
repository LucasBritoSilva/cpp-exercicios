#include <iostream>
using namespace std;
#define MAX 100

void min_max(int n, int v[MAX], int* max, int* min)
{
    int i;

    *max = v[0];
    *min = v[0];

    for (i = 1; i < n; i++)
    {
        if (v[i] > *max)
            *max = v[i];

        if (v[i] < *min)
            *min = v[i];
    }
}
int main() {
    int i, n, v[MAX], maior, menor;
    cout << "Digite a quantidade de numeros: " << endl;
    cin >> n;
    while (n <= 0) {
        cout << "Quantidade invalida, digite novamente: ";
        cin >> n;
    }
    for (i = 0; i < n; i++) {
        cin >> v[i];
    }
    min_max(n, v, &maior, &menor);

    cout << "Maior elemento: " << maior << endl;
    cout << "Menor elemento: " << menor << endl;
}