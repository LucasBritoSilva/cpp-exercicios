#include <iostream>
using namespace std;

#define MAX 100

void troca(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

bool verifica(int v[MAX], int n){
    for(int i = 0; i < n - 1; i++){
        if(v[i+1] < v[i]){
            return false;
        }
    }
    return true;
}

void ordenar_b(int v[MAX], int n){
    for(int i = n - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(v[j] > v[j+1]){
                troca(&v[j], &v[j+1]);
            }
        }
    }
}

void ordenar_s(int v[MAX], int n){
    for(int i = 0; i < n - 1; i++){
        int menor = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        troca(&v[i], &v[menor]);
    }
}

void ordenar_i(int v[MAX], int n){
    for(int i = 1; i < n; i++){
        int x = v[i];
        int j = i - 1;

        while(j >= 0 && v[j] > x){
            v[j+1] = v[j];
            j--;
        }

        v[j+1] = x;
    }
}

int busca(int v[MAX], int n, int x){
    int inicio = 0;
    int fim = n - 1;

    while(inicio <= fim){
        int meio = (inicio + fim) / 2;

        if(v[meio] == x){
            return meio;
        }
        else if(x < v[meio]){
            fim = meio - 1;
        }
        else{
            inicio = meio + 1;
        }
    }

    return -1;
}

int main(){
    int algoritmo, n, x;
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

    if(!verifica(v, n)){
        if(algoritmo == 1){
            ordenar_b(v, n);
        }
        else if(algoritmo == 2){
            ordenar_s(v, n);
        }
        else if(algoritmo == 3){
            ordenar_i(v, n);
        }
    }

    cout << "Vetor ordenado: ";
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Digite o numero que deseja buscar: ";
    cin >> x;

    int posicao = busca(v, n, x);

    cout << "Posicao: " << posicao << endl;

    return 0;
}