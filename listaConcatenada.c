#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

typedef struct lista{
  int conteudo;
  struct lista *prox;
}Lista;


int criaNumeros(int min, int max){
  return (rand()%(max-min+1)) + min;
}

Lista *criaLista(int cel, Lista **L){ 
  Lista *aux, *elemento = malloc(sizeof(Lista));
  if(elemento){
    elemento-> conteudo = cel;
    elemento-> prox = NULL;
  }
  if(*L){
    aux = *L;
    while(aux-> prox)
      aux = aux-> prox;
    aux -> prox = elemento;
  }else{
    *L = elemento;
  }
  return *L;
}

Lista *concatena(Lista *L1, Lista *L2){
  if(L1 == NULL) return L2;
  if(L2 == NULL) return L1; 
  
  Lista *atual = L1;
  while(atual-> prox)
    atual = atual-> prox;
  atual-> prox = L2;

  return L1; 
}

Lista *concatenaRecursivo(Lista *L1, Lista *L2){
  if(L1 == NULL){
    return L2;
  }
  L1-> prox = concatenaRecursivo(L1-> prox, L2);

  return L1; 
}

void mostraLista(Lista *lista){
  printf("\tLista:\t\n");
  while(lista){
    printf("%d -> ", lista-> conteudo);
    lista = lista-> prox;
  }
}

int main(void){
  Lista *Lista1, *Lista2 = NULL;
  Lista *L3 = NULL;

  srand((int)time(NULL));
  Lista1 = criaLista(criaNumeros(5, 50), &Lista1);
  Lista1 = criaLista(criaNumeros(5, 50), &Lista1);
  Lista1 = criaLista(criaNumeros(5, 50), &Lista1);

  Lista2 = criaLista(criaNumeros(4, 40), &Lista2);
  Lista2 = criaLista(criaNumeros(4, 40), &Lista2);
  Lista2 = criaLista(criaNumeros(4, 40), &Lista2);
 
  L3 = concatena(Lista1, Lista2);

  mostraLista(L3);
  return 0;
} 