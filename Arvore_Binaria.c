#include <stdio.h>
#include <stdlib.h>
 
typedef struct reg {
	int chave;
    char conteudo; // conteúdo
    struct reg *esq;
    struct reg *dir;
} Tree; // nó


Tree* create_tree(int chave, char conteudo) {
	Tree* tree = (Tree*) malloc(sizeof(Tree));
	tree->dir = tree->esq = NULL;
	tree->conteudo = conteudo;
	tree->chave = chave;
	return tree;
}

// esquerda raiz direita
void varredura_erd (Tree* r) {
   if (r != NULL) {
      varredura_erd (r->esq);
      printf ("chave: %i, conteudo: %c\n",r->chave, r->conteudo);
      varredura_erd (r->dir); 
   }
}

// consideranod que só existem chaves distintas
char buscar(Tree* t, int chave) {
	if(t == NULL) {
		printf("\ncelula nula\n");
		return;
	}
	if(t->chave == chave) return t->conteudo;
	if(chave >= t->chave) return buscar(t->dir, chave);
	else return buscar(t->esq, chave);
}


void inserir(Tree* t, int chave, char conteudo) {
	if(t == NULL) t = create_tree(chave, conteudo);
	else if(chave >= t->chave) inserir(t->dir, chave, conteudo);
	else inserir(t->esq, chave, conteudo);
}


int main() {
	Tree *t, *a, *b, *c;
	t = create_tree(2, 'a');
	a = create_tree(1, 'b');
	b = create_tree(4, 'c');
	c = create_tree(5, 'd');
//	t->esq = a;
//	t->dir = b;
//	t->dir->dir = c;

	inserir(t, 1, 'b');
	inserir(t, 4, 'a');
	inserir(t, 5, 'f');
	inserir(t, 2, 'd');
	inserir(t, 3, 'e');
	printf("%c", t->dir->conteudo);
}

