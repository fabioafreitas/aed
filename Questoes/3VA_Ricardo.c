#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
	int value;
	struct Cell* prox;
}List;

void imprimir (List* a) {
	List* n;
	for( n = a->prox ; n != NULL ; n = n->prox ) {
		printf("(%i)",n->value);		
	}
}

// insere no fim de uma lista encadeada
void inserirFim(List *list, int value) {
	List *novo= (List*) malloc(sizeof(List));
	if(!novo){
		printf("\nSem memoria disponivel!\n");
		exit(1);
	}
	novo->value = value;
	novo->prox = NULL;

	if(list->prox == NULL)
		list->prox=novo;
	else{
		List *tmp = list->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
}

// recebe duas listas (a e b) a serem intercaladas numa terceira (c)
void intercalarListas (List* a, List* b, List* nova) {
	List *x = a->prox, *y = b->prox; // x compara a lista a, y compara a lista b
	// passamos apenas a cabeça das listas, logo nao há conteudo nas listas
	if(x == NULL || y == NULL) {
		if(x == NULL && y == NULL) {
			printf("Listas Vazias\n");
			exit(1);
		}
		if(x == NULL && y != NULL) {
			while(y != NULL) {
				inserirFim(nova, y->value);
				y = y->prox;
			}
		}
		if(y == NULL && x != NULL) {
			while(y != NULL) {
				inserirFim(nova, y->value);
				y = y->prox;
			}
		}
	}	
	else {
		// só paramos o laço quando chegarmos no NULL de ambas as listas
		while(x != NULL || y != NULL) {
			// se a primeira lista apontar para nulo, copiamos a segunda na nova lista
			if(x == NULL && y != NULL) {
				while(y != NULL) {
					inserirFim(nova, y->value);
					y = y->prox;
				}
				break;
			}
			// se a segunda lista apontar para nulo, copiamos a primeira na nova lista
			if(y == NULL && x != NULL) {
				while(x != NULL) {
					inserirFim(nova, x->value);
					x = x->prox;
				}
				break;
			}
			// nunhuma das listas apontam para nulo
			if(x != NULL && y != NULL) {
				if(x->value <= y->value) {
					inserirFim(nova, x->value);
					x = x->prox;
				}
				else {
					inserirFim(nova, y->value);
					y = y->prox;
				}
			}
		}
	}	
}
