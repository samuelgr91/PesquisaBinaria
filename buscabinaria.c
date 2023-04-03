#include "buscabinaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TDicionario* TDicionarioInicia (int tamanho){
  TDicionario *t=malloc(sizeof(TDicionario));
  t->max = tamanho;
  t->cont=0;//a cada iteracao o contador é zerado
  t->v=malloc(t->max * sizeof(TRegistro));
  return t;
}

void TDicionariolibera (TDicionario **t){
  free((*t)->v);
  (*t)->max = 0;
  (*t)->cont=0;
  free(*t);
}

void lerMalha (TDicionario *t,int tamanho){
  for(int i=0;i<tamanho;i++){
    scanf("%d",&t->v[i].chave);
  }
}

//Manter como especificado
int TDicionario_Binario(TDicionario *t,int esq,int dir,int x){
  int meio=(int)(esq+dir)/2;
  t->cont++;//a cada chamada(divisao) o contador soma mais um
  if(x < t->v[meio].chave)
    return TDicionario_Binario(t, esq,meio-1, x);
  else if(x > t->v[meio].chave)
    return TDicionario_Binario(t, meio+1,dir, x);
  else
    return meio;
}

int TDicionario_Find(TDicionario *t,int codigo){//verifica se a embarcacao procurada esta presente no vetor
  for(int i=0;i<t->max;i++)
    if(codigo == t->v[i].chave)
        return 1; 
  return 0;  
}


void mensagem(TDicionario *t,int codigo,int resultado,int posicao){
  if(resultado != posicao){//se nao encontra na posicao que o usuario jogou
    if((codigo % 10) == 1)//em cada condicao verifica o ultimo numero da embarcacao para saber seu tipo  
        printf("Disparo impreciso: %d divisoes para conquistar o porta avioes %03d!\n",t->cont,codigo);
    else if((codigo % 10) == 2)  
        printf("Disparo impreciso: %d divisoes para conquistar o encouracado %03d!\n",t->cont,codigo);
    else if((codigo % 10) == 3)  
        printf("Disparo impreciso: %d divisoes para conquistar o cruzador %03d!\n",t->cont,codigo);
    else if((codigo % 10) == 4)  
        printf("Disparo impreciso: %d divisoes para conquistar o fragata %03d!\n",t->cont,codigo);
    else if((codigo % 10) == 5)  
        printf("Disparo impreciso: %d divisoes para conquistar o submarino %03d!\n",t->cont,codigo);
  }
  else if(resultado == posicao){//caso o usuario acertou de primeira
    if((codigo % 10) == 1)  
        printf("Disparo certeiro: O porta avioes %03d afundou!\n",codigo);
    else if((codigo % 10) == 2)  
        printf("Disparo certeiro: O encouracado %03d afundou!\n",codigo);
    else if((codigo % 10) == 3)  
        printf("Disparo certeiro: O cruzador %03d afundou!\n",codigo);
    else if((codigo % 10) == 4)  
        printf("Disparo certeiro: O fragata %03d afundou!\n",codigo);
    else if((codigo % 10) == 5)  
        printf("Disparo certeiro: O submarino %03d afundou!\n",codigo);
  }
    
}

void naoexiste(int codigo){
    if((codigo % 10) == 1)  
        printf("Disparo incorreto: Malha sem o porta avioes %03d!\n",codigo);
    else if((codigo % 10) == 2)  
        printf("Disparo incorreto: Malha sem o encouracado %03d!\n",codigo);
    else if((codigo % 10) == 3)  
        printf("Disparo incorreto: Malha sem o cruzador %03d!\n",codigo);
    else if((codigo % 10) == 4)  
        printf("Disparo incorreto: Malha sem o fragata %03d!\n",codigo);
    else if((codigo % 10) == 5)  
        printf("Disparo incorreto: Malha sem o submarino %03d!\n",codigo);

}