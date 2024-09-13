#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
    int valor;
    NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
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
        cout << "Menu Lista Ligada";
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

    if (primeiro == NULL || primeiro->valor > novo->valor) {
        novo->prox = primeiro;
        primeiro = novo;
        return;
    }

    NO* aux = primeiro;
    while (aux->prox != NULL && aux->prox->valor < novo->valor) {
        aux = aux->prox;
    }

    if (aux->prox != NULL && aux->prox->valor == novo->valor) {
        free(novo);
        cout << "Elemento já existe \n";
        return;
    }

    novo->prox = aux->prox;
    aux->prox = novo;
}

void excluirElemento()
{
    if (primeiro == NULL) {
        cout << "Lista vazia \n";
        return;
    }

    int valor;
    cout << "Digite o valor do elemento a ser excluído: ";
    cin >> valor;

    if (primeiro->valor == valor) {
        NO* paraExcluir = primeiro;
        primeiro = primeiro->prox;
        free(paraExcluir);
        cout << "Elemento excluído \n";
        return;
    }

    NO* aux = primeiro;
    while (aux->prox != NULL && aux->prox->valor < valor) {
        aux = aux->prox;
    }

    if (aux->prox == NULL || aux->prox->valor != valor) {
        cout << "Elemento não encontrado \n";
        return;
    }

    NO* paraExcluir = aux->prox;
    aux->prox = aux->prox->prox;
    free(paraExcluir);
    cout << "Elemento excluído \n";
}

void buscarElemento()
{
    int valor;
    cout << "Digite o valor do elemento a ser buscado: ";
    cin >> valor;

    NO* aux = primeiro;
    while (aux != NULL && aux->valor < valor) {
        aux = aux->prox;
    }

    if (aux != NULL && aux->valor == valor) {
        cout << "Elemento " << valor << " encontrado \n";
    }
    else {
        cout << "Elemento " << valor << " não encontrado \n";
    }
}

// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
NO* posicaoElemento(int numero)
{
    NO* aux = primeiro;
    while (aux != NULL) {
        if (aux->valor == numero)
        {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}



