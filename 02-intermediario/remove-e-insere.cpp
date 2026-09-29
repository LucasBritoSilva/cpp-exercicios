/*
    Funções para remoção e inserção de elementos em um vetor.
    
    A função remove() remove um elemento da posição informada utilizando um
    laço de repetição, enquanto remove_r() realiza a mesma operação de forma
    recursiva.

    A função insere() insere um novo elemento na posição informada utilizando
    um laço de repetição, enquanto insere_R() realiza a mesma operação de
    forma recursiva.

    As funções retornam o novo tamanho do vetor após a operação.
*/

#include <iostream>
using namespace std;
#define MAX 100

int remove(int n, int v[MAX], int k){
    for(k; k < n; k++){
        v[k] = v[k+1];
    }
    return n-1;
}

int remove_r(int n, int v[MAX], int k){
    if(k == n){
        return n-1;
    }
    v[k] = v[k+1];
    return remove_r(n, v, k+1);
}

int insere(int n,int v[MAX] , int k,int y){
    for(int i = n; i >= k; i--){
        v[i] = v[i-1];
    }
    v[k] = y;
    return n+1;
}

int insere_R(int n, int v[MAX], int k,int x) {
    if (n == k) {
        v[k] = x;
        return n + 1;
    }
    v[n] = v[n - 1];
    return insere_R(n - 1, v, k, x);
}

void mostrarVetor(int v[MAX], int n){
    cout << "Vetor: ";

    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }

    cout << endl;
}

int main(){

    int v[MAX];
    int n;

    cout << "Digite a quantidade de elementos do vetor: ";
    cin >> n;

    cout << "Digite os elementos do vetor:" << endl;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int opcao;

    do {
        cout << endl;
        cout << "========== MENU ==========" << endl;
        cout << "1 - Inserir elemento" << endl;
        cout << "2 - Remover elemento" << endl;
        cout << "3 - Inserir elemento (recursivo)" << endl;
        cout << "4 - Remover elemento (recursivo)" << endl;
        cout << "5 - Mostrar vetor" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if(opcao == 1){
            int posicao, valor;

            cout << "Digite a posicao onde deseja inserir: ";
            cin >> posicao;

            cout << "Digite o valor: ";
            cin >> valor;

            n = insere(n, v, posicao, valor);

            cout << "Elemento inserido!" << endl;
            mostrarVetor(v, n);
        }

        else if(opcao == 2){
            int posicao;

            cout << "Digite a posicao que deseja remover: ";
            cin >> posicao;

            n = remove(n, v, posicao);

            cout << "Elemento removido!" << endl;
            mostrarVetor(v, n);
        }

        else if(opcao == 3){
            int posicao, valor;

            cout << "Digite a posicao onde deseja inserir: ";
            cin >> posicao;

            cout << "Digite o valor: ";
            cin >> valor;

            n = insere_R(n, v, posicao, valor);

            cout << "Elemento inserido usando recursao!" << endl;
            mostrarVetor(v, n);
        }

        else if(opcao == 4){
            int posicao;

            cout << "Digite a posicao que deseja remover: ";
            cin >> posicao;

            n = remove_r(n, v, posicao);

            cout << "Elemento removido usando recursao!" << endl;
            mostrarVetor(v, n);
        }

        else if(opcao == 5){
            mostrarVetor(v, n);
        }

        else if(opcao != 0){
            cout << "Opcao invalida!" << endl;
        }

    } while(opcao != 0);

    cout << "Programa encerrado." << endl;

    return 0;
}