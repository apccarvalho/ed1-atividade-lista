/*5. Crie um método que insere um elemento sempre na penúltima posição da lista. 
Se a lista tiver tamanho <= 1, seu método não deve fazer nada.*/
#include<stdio.h>

struct No {

    int valor;
    No* prox;

    No() {
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Lista {

    No* inicio;
    No* fim;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void inserirInicio(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            novo->prox = inicio;
            inicio = novo;
        }
        n++;
    }

    void inserirFinal(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void removerInicio() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    void removerFinal() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        delete(fim);
        fim = aux;
        aux->prox = NULL;
        n--;
    }

    void inserirPenultimo(int valor){
        No* aux = inicio;
        if (n <= 1) return;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        No* novo = new No(valor);
        novo->prox = fim;
        aux->prox = novo;            
        
    }

    void imprimir() {
        No* aux = inicio;
        //printf("%d %d\n", aux, aux->valor);
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            //printf("%d %d\n", aux->prox, aux->valor);
            aux = aux->prox;
        }
    }

};

int main() {

    Lista l;

    l.inserirInicio(10);
    l.inserirInicio(5);
    l.inserirInicio(1);
    l.inserirInicio(8);
    l.inserirFinal(7);
    l.inserirFinal(3);
    l.imprimir();
    l.inserirPenultimo(99);
    printf("Nova lista: \n");
    l.imprimir();


    return 0;
}