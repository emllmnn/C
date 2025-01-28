/*
faça um programa que leia n nomes inserindo-os em uma lista de forma ordenada utilizando a ideia do algoritmo da inserção. No final, o programa deve mostrar todos os nomes ordenados alfabeticamente*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct lista{
  char nome[20];
  struct lista *prox;
}Lista;

void exibir(Lista *lista){
  printf("Lista:\n\n");
  while(lista){
    printf("%s\n", lista->nome);
    lista = lista-> prox;
  }
  printf("\n\n");
}

Lista *criaListaNomes(char *nome, Lista **lista){
  Lista *aux, *novoNome = malloc(sizeof(Lista));
  if(novoNome){
    strcpy(novoNome-> nome, nome);
    novoNome-> prox = NULL;
    if(*lista == NULL){
      *lista = novoNome;
    }else{
      aux = *lista;
      while(aux-> prox)
        aux = aux-> prox;
      aux-> prox = novoNome;
    }
  }
  return *lista;
}

void inserir(Lista **lista, Lista *novoElemento){
  Lista *atual;

  if(*lista == NULL || strcmp((*lista)->nome, novoElemento-> nome) >= 0){
    novoElemento-> prox = *lista;
    *lista = novoElemento;
  }else{
    atual = *lista;
    while(atual-> prox != NULL && strcmp(atual->prox->nome, novoElemento->nome) < 0){
      atual = atual-> prox;
    }
    novoElemento-> prox = atual-> prox;
    atual-> prox = novoElemento;
  }
}

void sort(Lista **lista){
  Lista *ordenada = NULL;
  Lista *atual = *lista;

  while(atual != NULL){
    Lista *prox = atual-> prox;
    inserir(&ordenada, atual);
    atual = prox;
  }
  *lista = ordenada;
}


void insertionSort(int n, Lista **lista){
  int k, j, aux, vetor[4];
  for(k=1; k<=n-1; k++){
    aux = vetor[k];
    j = k-1;
    while(j >= 0 && vetor[j] > aux){
      vetor[j+1] = vetor[j];
      j--;
    }
    vetor[j+1] = aux;
  }
}

int main(void){
  Lista *lista = NULL;
  criaListaNomes("edi", &lista);
  criaListaNomes("bea", &lista);
  criaListaNomes("sara", &lista);
  criaListaNomes("ameinda", &lista);
  criaListaNomes("rafa", &lista);

  exibir(lista);

  sort(&lista);

  exibir(lista);

  return 0;
} 