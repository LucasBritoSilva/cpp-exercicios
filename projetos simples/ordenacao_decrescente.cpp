#include <iostream>
using namespace std;
#define MAX 100

void troca(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void ordenar_b(int v[MAX], int n){
    for(int i = n - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(v[j] < v[j+1]){
                troca(&v[j], &v[j+1]);
            }
        }
    }
}

void ordenar_s(int v[MAX], int n){
    for(int i = 0; i < n - 1; i++){
        int maior = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] > v[maior]){
                maior = j;
            }
        }
        troca(&v[i], &v[maior]);
    }
}

void ordenar_i(int v[MAX], int n){
    for(int i = 1; i < n; i++){
        int j = i;
        while(j > 0 && v[j] > v[j-1]){
            troca(&v[j], &v[j-1]);
            j--;
        }
    }
}

int main(){
    int algoritmo, n;
    int v[MAX];

    cout << "Escolha o algoritmo de ordenacao:" << endl;
    cout << "1 - Bubble Sort" << endl;
    cout << "2 - Selection Sort" << endl;
    cout << "3 - Insertion Sort" << endl;
    cout << "Opcao: ";
    cin >> algoritmo;

    cout << "Digite a quantidade de elementos do vetor: ";
    cin >> n;

    cout << "Digite os " << n << " elementos do vetor:" << endl;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    cout << "Vetor lido: ";
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    if(algoritmo == 1){
        ordenar_b(v, n);
    }
    else if(algoritmo == 2){
        ordenar_s(v, n);
    }
    else if(algoritmo == 3){
        ordenar_i(v, n);
    }

    cout << "Vetor ordenado de forma decrescente: ";
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}