#include <stdio.h>
#include <stdlib.h>
 
typedef struct reg {
	int conteudo;
    struct reg *esq;
    struct reg *dir;
} noh; // nó

typedef noh* node;

void esq_raiz_dir(node r) {
	if(r != NULL) {
		esq_raiz_dir(r->esq);
		printf("%i ",r->conteudo);
		esq_raiz_dir(r->dir);
	}
}

int main() {
	node a = (node) malloc(sizeof(node));
	int x ;
	x = 1;
	a->dir = a->esq = NULL;
	a->conteudo = x;
	printf("%i",x);	
	esq_raiz_dir(a);
}

