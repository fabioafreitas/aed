#include <stdio.h>
#include <stdlib.h> 

typedef struct cell{
	int info;
	struct cell* prox;
}List;

typedef struct fila{
	int inicio, fim, size;
	int* fila;	
}Fila;

// fila com lista encadeada //
List* criar_lista() {
	List* node = (List*) malloc(sizeof(List));
	node->prox = NULL;
	return node;
}

void insere_fila_list(int info, List* fila) {
	if(fila->prox == NULL) {
		fila->prox = criar_lista();
		fila->prox->info = info;
	}
	else insere_fila_list(info, fila->prox);
}

int remove_fila_list(List* fila) {
	if(!fila_vazia_list(fila)) {
		int info = fila->prox->info;
		fila = fila->prox->prox;
		return info;
	}
}

int fila_vazia_list(List* fila) {
	return fila->prox == NULL;
} 

void print_fila_list(List* le) {
	if(le->prox != NULL) {
		printf("%i ",le->info);
		print_fila_list(le->prox);
	}
}

// fila com vetor //

Fila criar_fila(int size) {
	Fila f;
	f.inicio = f.fim = 0;
	f.size = size;
	f.fila = (int*) malloc(sizeof(int)*size);
	return f;
}

int fila_vazia(Fila* f) {
	return (*f).inicio == (*f).fim;
}

int fila_cheia(Fila* f) {
	return (*f).fim == (*f).size;
}

void insere_fila(Fila* f, int info) {
	if(!fila_cheia(f))  (*f).fila[ (*f).fim++ ] = info;
}

int remove_fila(Fila* f) {
	if(!fila_vazia(f)) return (*f).fila[ (*f).inicio++ ];
}

void print_fila(Fila f) {
	while(f.inicio < f.fim) printf("%i ",f.fila[f.inicio++]);
}

// fila circular com vetor //
/*cria fila é a mesma da fila simples*/

int fila_circular_vazia(Fila* f) {
	return ( (*f).fim % (*f).size ) == (*f).inicio; 
}

int fila_circular_cheia(Fila* f) {
	return ( ((*f).fim+1) % (*f).size ) == (*f).inicio;
}

void insere_fila_circular(Fila* f, int info) {
	if(!fila_circular_cheia(f)) (*f).fila[ ((*f).fim++ % (*f).size) ] = info;
}

int remove_fila_circular(Fila* f) {
	if(!fila_circular_vazia(f)) return (*f).fila[ ((*f).inicio++ % (*f).size) ];
}


int main() {
}

