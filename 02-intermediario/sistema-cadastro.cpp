#include <iostream>
#include <string>

using namespace std;

struct Pessoa {
    string nome;
    string cpf;
    float renda;
    int idade;
    string ir;
    string aposentadoria;
};

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

void cadastro(Pessoa pessoas[], int pos) {

    cout << "Nome: ";
    cin >> pessoas[pos].nome;

    cout << "CPF: ";
    cin >> pessoas[pos].cpf;

    cout << "Renda mensal: ";
    cin >> pessoas[pos].renda;

    cout << "Idade: ";
    cin >> pessoas[pos].idade;

    pessoas[pos].ir = funcaoir(pessoas[pos].renda);

    pessoas[pos].aposentadoria = funcaoapo(pessoas[pos].idade);
}

int main() {

    Pessoa pessoas[100];

    bool sair = false;
    int opcao;

    while (sair == false) {

        cout << "Digite 1 para Incluir" << endl;
        cout << "Digite 2 para Listar" << endl;
        cout << "Digite 3 para Sair" << endl;

        cin >> opcao;

        if (opcao == 1) {

            cadastro(pessoas, totalpessoas);

            totalpessoas++;
        }

        else if (opcao == 2) {

            for (int i = 0; i < totalpessoas; i++) {

                cout << endl;
                cout << "Nome: " << pessoas[i].nome << endl;
                cout << "Cpf: " << pessoas[i].cpf << endl;
                cout << "Renda: " << pessoas[i].renda << endl;
                cout << "Idade: " << pessoas[i].idade << endl;
                cout << "IR: " << pessoas[i].ir << endl;
                cout << "Aposentadoria: "
                    << pessoas[i].aposentadoria << endl;
                cout << endl;
            }
        }

        else if (opcao == 3) {
            sair = true;
        }
    }

    return 0;
}