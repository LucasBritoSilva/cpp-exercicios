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