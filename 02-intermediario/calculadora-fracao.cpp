/*
    Programa para realizar operações matemáticas com duas frações.
    A estrutura "fracao" armazena o numerador e o denominador.
    O programa possui funções para somar, subtrair, multiplicar e dividir
    frações, permitindo que o usuário escolha qual operação deseja realizar.
    Também verifica se os denominadores informados são diferentes de zero.
*/

#include <iostream>
#include <string>

using namespace std;

int a;
int b;
int c;
int d;
int operacao;

struct fracao {
    int numerador;
    int denominador;
};

fracao fracao1;
fracao fracao2;

fracao somar(fracao fracao1, fracao fracao2) {
    fracao resultado;
    
    if (fracao1.denominador == fracao2.denominador){
        resultado.numerador = fracao1.numerador + fracao2.numerador;
        resultado.denominador = fracao2.denominador;
    }
    else {
        resultado.numerador = fracao1.numerador * fracao2.denominador + fracao1.denominador * fracao2.numerador;
        resultado.denominador = fracao1.denominador * fracao2.denominador;
    }
    return resultado;
}

fracao subtrair(fracao fracao1, fracao fracao2) {
    fracao resultado;

    if (fracao1.denominador == fracao2.denominador) {
        resultado.numerador = fracao1.numerador - fracao2.numerador;
        resultado.denominador = fracao2.denominador;
    }
    else {
        resultado.numerador = fracao1.numerador * fracao2.denominador - fracao1.denominador * fracao2.numerador;
        resultado.denominador = fracao1.denominador * fracao2.denominador;
    }
    return resultado;
}

fracao multiplicar(fracao fracao1, fracao fracao2) {
    fracao resultado;
    resultado.numerador = fracao1.numerador * fracao2.numerador;
    resultado.denominador = fracao1.denominador * fracao2.denominador;
    return resultado;
}

fracao dividir(fracao fracao1, fracao fracao2) {
    fracao resultado;
    resultado.numerador = fracao1.numerador * fracao2.denominador;
    resultado.denominador = fracao1.denominador * fracao2.numerador;
    return resultado;
}

int main() {
    cout << "Digite o numerador da sua primeira fracao" << endl;
    cin >> fracao1.numerador;
    cout << "Digite o denominador da sua primeira fracao" << endl;
    cin >> fracao1.denominador;
    if (fracao1.denominador == 0) {
        while (fracao1.denominador == 0) {
            cout << "O denominador nao pode ser '0', por favor, digite outro numero" << endl;
            cin >> fracao1.denominador;
        }
    }
    cout << "Digite o numerador da sua segunda fracao" << endl;
    cin >> fracao2.numerador;
    cout << "Digite o denominador da sua segunda fracao" << endl;
    cin >> fracao2.denominador;
    if (fracao2.denominador == 0) {
        while (fracao2.denominador == 0) {
            cout << "O denominador nao pode ser '0', por favor, digite outro numero" << endl;
            cin >> fracao2.denominador;
        }
    }
    cout << "Digite 1 para Somar" << endl << "Digite 2 para Subtrair" << endl << "Digite 3 para Multiplicar" << endl << "Digite 4 para Dividir" << endl;
    cin >> operacao;
    cout << endl << "O resultado eh ";

    if (operacao == 1) {
        fracao resultado = somar (fracao1, fracao2);
        cout << resultado.numerador << "/" << resultado.denominador << endl;
    }
    else if (operacao == 2) {
        fracao resultado = subtrair (fracao1, fracao2);
        cout << resultado.numerador << "/" << resultado.denominador << endl;
    }
    else if (operacao == 3) {
        fracao resultado = multiplicar (fracao1, fracao2);
        cout << resultado.numerador << "/" << resultado.denominador << endl;
    }
    else if (operacao == 4) {
        fracao resultado = dividir (fracao1, fracao2);
        cout << resultado.numerador << "/" << resultado.denominador << endl;
    }
    return 0;
}