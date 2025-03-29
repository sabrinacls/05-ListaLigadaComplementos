#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
//NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada Ordenada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{

	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else {

		NO* atual = primeiro;
		NO* antes = NULL;


		while (atual != NULL && atual->valor < novo->valor) {
			antes = atual;
			atual = atual->prox;
		}

		if (atual != NULL && atual->valor == novo->valor) {
			cout << "Elemento já existe na lista\n";
			free(novo);
			return;
		}

		if (antes == NULL) {
			novo->prox = primeiro;
			primeiro = novo;
		}

		else {
			antes->prox = novo;
			novo->prox = atual;
		}

		if (novo->prox == NULL) {
			ultimo = novo;
		}
	}
}

void excluirElemento()
{
	int excluir;
	bool encontrei = false;
	NO* aux;
	NO* antes;

	aux = primeiro;
	antes = primeiro;

	if (aux == NULL) {
		cout << "Lista vazia\n";
		return;
	}
	else {
		cout << "Digite o elemento que deseja excluir: ";
		cin >> excluir;

		while (aux != NULL) {
			if (aux->valor == excluir) {
				encontrei = true;
				if (aux == primeiro) {
					primeiro = aux->prox;

				}
				else {
					antes->prox = aux->prox;

				}

				free(aux);
				cout << "\n elemento excluido\n";
				return;
			}

			antes = aux;
			aux = aux->prox;
		}
	}

	if (!encontrei) {
		cout << "Elemento não encontrado\n";
	}

}

void buscarElemento()
{
	int pos = 0;
	int busca = 0;
	cout << "Digite o elemento que deseja buscar; ";
	cin >> busca;

	NO* aux = primeiro;

	while (aux != NULL) {
		if (aux->valor == busca) {
			break;
		}
		aux = aux->prox;
		pos++;
	}


	if (aux == NULL) {
		cout << "Elemento nao encontrado" << endl;
	}
	else {
		cout << "O elemento " << aux->valor << " foi encontrado na posição: " << pos << endl;
	}

}