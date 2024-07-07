/*1. Criar um método que recebe um número N e remove os N últimos elementos da lista. 
Caso o tamanho da lista seja menor que N, esvaziar a lista.*/
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

    void removerElementos(int x){
        if (x == 0) return;
        if (n < x){
            while (inicio != NULL){
                No* aux02 = inicio;
                inicio = inicio->prox;
                delete(aux02);
                n--;
            }
        }
        if (n > x){
            while (x != 0){
                No* aux02 = inicio;
                while (aux02->prox != fim) {
                    aux02 = aux02->prox;
                }
                delete(fim);
                fim = aux02;
                aux02->prox = NULL;
                n--; 
                x--;                   
            }    
        }
    }

    void imprimir() {
        No* aux = inicio;
        if (inicio == NULL){
            printf("Lista vazia");
        }
        while (aux != NULL) {
            printf("%d\n", aux->valor);
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
    l.removerElementos(7);
    printf("Sobraram os seguintes elementos:\n");
    l.imprimir();

    return 0;
}