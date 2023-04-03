#include "buscabinaria.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
	TDicionario *t;
	int c,m,posicao,codigo,resultado;
    scanf("%d%d",&c,&m);
	
    for(int i = 0;i < c;i++){
        t=TDicionarioInicia(m);
        lerMalha(t,m);
        scanf("%d%d",&posicao,&codigo);
        int procura=TDicionario_Find(t,codigo);
        if(procura == 0)//caso nao exista a embarcacao na matriz
            naoexiste(codigo);
        else{//caso exista ele verifica em qual indice a embarcacao se encontra
            resultado=TDicionario_Binario(t,0,t->max-1,codigo);
            mensagem(t,codigo,resultado,posicao);//produz a mensagem esperada
        }
        TDicionariolibera(&t);
    }
	

	return 0;
}
