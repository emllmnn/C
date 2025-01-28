/*
crie um programa que dado uma string coloque as letras dela em ordem crescente pelo algortimo quick-sort 
*/
#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

int separacao(char palavra[20], int ini, int fim){
  int pivo = palavra[fim];
  int t, j = ini;
  for(int k = ini; k < fim; k++){
    if(palavra[k] <= pivo){
      t = palavra[j], palavra[j] = palavra[k], palavra[k] = t;
      j++;
    }
  }
  t = palavra[j], palavra[j] = palavra[fim], palavra[fim] = t;
  return j;
}

void quickSort(char palavra[20], int ini, int fim){
  if(ini < fim){
    int j = separacao(palavra, ini, fim);
    quickSort(palavra, ini, j-1);
    quickSort(palavra, j+1, fim);
  }
}


int main(void){
  char palavra[20] = "zwiera";
  quickSort(palavra, 0, 5);

  printf("Palavra ordenada:\n");
  printf("%s", palavra);
  
  return 0;
} 