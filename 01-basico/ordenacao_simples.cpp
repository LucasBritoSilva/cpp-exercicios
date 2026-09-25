/*
    Programa que recebe uma quantidade de números e armazena os valores em um vetor.
    A função verifica() percorre o vetor e verifica se os elementos estão em ordem crescente.
    Ao final, o programa informa se o vetor está ordenado ou não.
*/

#include <iostream>
using namespace std;

#define MAX 100

bool verifica(int v[MAX], int n){
    for(int i = 0; i < n-1; i++){
        if(v[i+1] < v[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int v[MAX];
    int n;
    cout << "Quantos numeros tem o vetor? ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    if(verifica(v, n) == true){
        cout << "ORDENADO";
    }
    else{
        cout << "NAO ORDENADO";
    }
}