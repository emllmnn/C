#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct lista{
  char nome[10];
  struct lista *prox;
  struct lista *ant;
}Lista;

void criaLista(Lista **list, char *nm){
  Lista *no = malloc(sizeof(Lista));
  if(no){
    strcpy(no-> nome, nm);
    no-> prox = *list;
    no-> ant = NULL;
    if(*list)
      (*list)-> ant = no;
    *list = no;
  }
}

Lista *ultimoNo(Lista **list){
  Lista *aux = *list;
  while(aux-> prox)
    aux = aux-> prox;
  return aux;
}

void inverteLista(Lista *list){
  printf("\n\nLista invertida:");
  while(list){
    printf(" -> %s ", list-> nome);
    list = list-> ant;
  }
  printf("\n");
}

void mostraLista(Lista *lista){
  printf("\nLista original:");
  while(lista){
    printf("%s -> ", lista-> nome);
    lista = lista-> prox;
  }
}

int main(void){
  Lista *lista = NULL;
  
  criaLista(&lista, "edu");
  criaLista(&lista, "eulora");
  criaLista(&lista, "julio");
  criaLista(&lista, "ed");

  mostraLista(lista);

  inverteLista(ultimoNo(&lista));
  
  return 0;
}
