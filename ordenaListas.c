/*
faça uma função que, dado um valor inteiro N positivo, aloque dinamicamente um vetor de Aluno, leia do teclado os N pares de valores (Matricula, Nota) e retorne o vetor alocado. Imprima, ao final do programa, duas listas: (1) alunos ordenados por nota final e (2) alunos ordenados por número de matrícula
*/
#include <stdio.h>
#include <malloc.h>

typedef struct _pessoa_{
  unsigned int Matricula;
  float Nota;
}Aluno;

Aluno _pessoa_;


void matriculaInsertion(Aluno *vetor, int n){
  for(int k = 1; k <= n-1; k++){
    Aluno aux = vetor[k];
    int j = k-1;
    while(j >= 0 && aux.Matricula < vetor[j].Matricula){
      vetor[j+1] = vetor[j];
      j--;
    }
    vetor[j+1] = aux;
  }
}

void notaInsertion(Aluno *vetor, int n){
  for(int k = 1; k <= n-1; k++){
    Aluno aux = vetor[k];
    int j = k-1;
    while(j >= 0 && aux.Nota < vetor[j].Nota){
      vetor[j+1] = vetor[j];
      j--;
    }
    vetor[j+1] = aux;
  }
}

Aluno *alocaVetor(int n){
  
  Aluno *vetor = (Aluno *)calloc(n, sizeof(Aluno));
  
  return vetor;
}


void *criaLista(Aluno *a, int n){
  for(int i=0; i<n; i++){
    printf("Digite a matrícula e o nome do aluno %d: \n", i+1);
    scanf("%d %f", &a[i].Matricula, &a[i].Nota);
  }
  printf("\n\nLista:\n\n");
  for(int count=0; count<n; count++){
    printf("%u\t", a[count].Matricula);
    printf("%.2f\n", a[count].Nota);
  }
}

void imprimeLista(Aluno *a, int n){
  for(int i = 0; i < n; i++){
    printf("%u\t", a[i].Matricula);
    printf("%.2f\n", a[i].Nota);
  }
}


int main(void){
  Aluno *aluno = NULL;
  int n;
  printf("Digite um valor inteiro:\n");
  scanf("%d", &n);
  aluno = alocaVetor(n);
  criaLista(aluno, n);
  matriculaInsertion(aluno, n);
  printf("\nLista ordenada pela matrícula:\n");
  imprimeLista(aluno, n);
  notaInsertion(aluno, n);
  printf("\nLista ordenada pela nota:\n");
  imprimeLista(aluno, n);
  
  return 0;
}