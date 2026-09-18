#include <iostream>
#include <string>
using namespace std;

string nomes[100];
string cpfs[100];
float rendas[100];
int idades[100];
string ir[100];
string aposentadoria[100];
int totalpessoas = 0;

string funcaoir(float renda) {
    if (renda <= 5000) {
        return "Isento";
    }
    else {
        return "Contribuinte";
    }
}

string funcaoapo(int idade) {
    if (idade <= 65) {
        idade = 65 - idade;
        string idadeconvert = to_string(idade);
        return "Faltam " + idadeconvert + " anos para aposentar";
    }
    else {
        return "Aposentado";
    }
}

void cadastro(string nome[], string cpf[], float renda[], int idade[], int pos)
{
    cout << "Nome: ";
    cin >> nome[pos];

    cout << "CPF: ";
    cin >> cpf[pos];

    cout << "Renda mensal: ";
    cin >> renda[pos];

    cout << "Idade: ";
    cin >> idade[pos];

    ir[pos] = funcaoir(renda[pos]);

    aposentadoria[pos] = funcaoapo(idade[pos]);
}


int main() {
    bool sair = false;
    int opcao;

    while (sair == false) {
        cout << "Digite 1 para Incluir" << endl;
        cout << "Digite 2 para Listar" << endl;
        cout << "Digite 3 para Sair" << endl;
        cin >> opcao;

        if (opcao == 1) {
            cadastro(nomes, cpfs, rendas, idades, totalpessoas);
            totalpessoas++;
        }
        else if (opcao == 2) {
            int i = 0;
            for (i; i < totalpessoas; i++) {
                    cout << endl << "Nome: " << nomes[i] << endl << endl;
                    cout << "Cpf: " << cpfs[i] << endl;
                    cout << "Renda: " << rendas[i] << endl;
                    cout << "Idade: " << idades[i] << endl;
                    cout << "IR: " << ir[i] << endl;
                    cout << "Aposentadoria: " << aposentadoria[i] << endl << endl;
            }
        }
        else if (opcao == 3) {
            sair = true;
        }
    }
    

    return 0;
}