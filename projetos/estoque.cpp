#include <iostream>
using namespace std;

struct Produto {
    string nome;
    float preco;
    int quantidade;
};

void cadastrarProdutos(Produto* estoque, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << "Nome do produto: " << endl;
        cin >> estoque[i].nome;
        cout << "Preco: " << endl;
        cin >> estoque[i].preco;
        cout << "Quantidade: " << endl;
        cin >> estoque[i].quantidade;
    }
}

void listarProdutos(Produto* estoque, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << endl << estoque[i].nome << " | Preco: " << estoque[i].preco << " | Quantidade: " << estoque[i].quantidade;
    }
    cout << endl;
}

float valorTotalEstoque(Produto* estoque, int tamanho) {
    float total = 0;
    for (int i = 0; i < tamanho; i++) {
        total += (estoque[i].preco * estoque[i].quantidade);
    }
    return total;
}

int buscarProdutoPorNome(Produto* estoque, int tamanho, string nome) {
    cout << endl;
    for (int i = 0; i < tamanho; i++) {
        if (nome == estoque[i].nome) {
            cout << "Produto Encontrado: " << estoque[i].nome << " | Preco: " << estoque[i].preco << " | Quantidade: " << estoque[i].quantidade << endl;
            return 0;
        }
    }
    cout << "Produto nao encontrado" << endl;
    return -1;
}

void aumentarPreco(Produto* estoque, int indice, float percentual) {
    estoque[indice].preco *= (1 + (percentual / 100));
}

int main() {
    Produto estoque[5];
    cadastrarProdutos(estoque, 3);
    listarProdutos(estoque, 3);
    cout << endl << "Valor total em estoque: " << valorTotalEstoque(estoque, 3) << endl;
    string nome;
    cout << endl << "Digite o nome do produto a buscar: ";
    cin >> nome;
    buscarProdutoPorNome(estoque, 3, nome);
    int indice, percentual;
    cout << endl << "Digite o indice do produto para reajustar o preco: ";
    cin >> indice;
    cout << "Digite o percentual de aumento: ";
    cin >> percentual;
    aumentarPreco(estoque, indice, percentual);
    cout << "Novo preco: " << estoque[indice].preco << endl;
    cout << endl << "Estoque atualizado:" << endl;
    listarProdutos(estoque, 3);
    return 0;
}