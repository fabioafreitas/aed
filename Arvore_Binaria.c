#include <stdio.h>
#include <stdlib.h>
 
typedef struct reg {
	int conteudo;
    struct reg *esq;
    struct reg *dir;
} noh; // nó

typedef noh* arvore;

void esq_raiz_dir(arvore r) {
	if(r != NULL) {
		esq_raiz_dir(r->esq);
		printf("%i ",r->conteudo);
		esq_raiz_dir(r->dir);
	}
}

int main() {
	arvore a = (arvore) malloc(sizeof(arvore));
	int x ;
	x = 1;
	a->dir = a->esq = NULL;
	a->conteudo = x;
	printf("%i",x);	
	esq_raiz_dir(a);
}

