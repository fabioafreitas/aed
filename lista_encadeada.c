#include <stdio.h>
#include <stdlib.h>

/* também poderia ser:	typedef struct reg celula;
						struct reg{
							int conteudo;
							struct reg* prox;
						};*/

typedef struct reg {
   int         conteudo;
   struct reg *prox;
} celula;

celula* createList(celula* le) {
	celula* nova = (celula*) malloc(sizeof(celula));
	nova->prox = NULL;
	return nova;
} 

void printList(celula* le);

/*Escreva uma função que conte o número de células de uma lista encadeada.
 Faça duas versões: uma iterativa e uma recursiva.*/
int sizeList_R(celula* le);
int sizeList_I(celula* le);

/*Altura.  A altura de uma célula c em uma lista encadeada é a distância entre c e o fim da lista. Mais precisamente,
a altura de c é o número de passos do caminho que leva de c até a última célula da lista.  Escreva uma função que
calcule a altura de uma dada célula.*/
int heightList(celula* le, int valor);

/*Profundidade.  A profundidade de uma célula c em uma lista encadeada é o número de passos do único caminho que vai
da primeira célula da lista até c.  Escreva uma função que calcule a profundidade de uma dada célula.*/
int deepList(celula* begin,celula* end);

/*Escreva uma função que verifique se uma lista encadeada que contém números inteiros está em ordem crescente.*/
int checar_ordenada_R(celula* le);

/*Escreva uma função que faça uma busca em uma lista encadeada crescente. Faça versões recursiva e iterativa.*/
celula* buscaList_R(celula* le, int valor);
celula* buscaList_I(celula* le, int valor);

/*Escreva uma função que encontre uma célula com conteúdo mínimo. Faça duas versões: uma iterativa e uma recursiva.*/
celula* minList_R(celula* le);
celula* minList_I(celula* le);

/*Escreva uma função que verifique se duas listas encadeadas são iguais, ou melhor, se têm o mesmo conteúdo. Faça duas
versões: uma iterativa e uma recursiva.*/
int equalsList_I(celula* la, celula* lb);
int containsList(celula* la, int valor);

/*Ponto médio.  Escreva uma função que receba uma lista encadeada e devolva o endereço de uma célula que esteja o mais
próximo possível do meio da lista. Faça isso sem contar explicitamente o número de células da lista.*/
celula* middleList(celula* le);

/*Escreva versões das funções busca e busca_r para listas encadeadas com cabeça.*/
celula* buscaListHead_R(celula* le, int valor);

/*Escreva uma função que insira uma nova célula em uma lista encadeada sem cabeça. (Será preciso tomar algumas
decisões de projeto antes de começar a programar.)*/
// a lista precisa ter cabeça
void insertBegin(celula* le, int valor); 
void insertEnd(celula* le, int valor);

/*Escreva uma função que faça uma cópia de uma lista encadeada. Faça duas versões da função: uma iterativa e uma
recursiva.*/
void copyList_R(celula* le, celula* copy);

/*Escreva uma função que concatene duas listas encadeadas (isto é, engate a segunda no fim da primeira). Faça duas
versões: uma iterativa e uma recursiva.*/
void concList_R(celula* a, celula* b);
void concList_I(celula* a, celula* b);

/*Escreva uma função que insira uma nova célula com conteúdo x imediatamente depois da k-ésima célula de uma lista
encadeada. Faça duas versões: uma iterativa e uma recursiva.*/
void insertMiddle(celula* le, int posicao, int valor);

int tam(celula* a) {
	if(a->prox == NULL) return 0;
	else return 1+tam(a->prox);
}

int main() {
	celula* le = createList(le);
	celula* a = createList(a);
	insertEnd(le, 1);	insertEnd(le, 2);	insertEnd(le, 4);
	insertEnd(le, 5);	insertEnd(le, 6);	insertMiddle(le, 3, 3);
	printList(le->prox);
	printf("\n%i",tam(le));
}

void concList_R(celula* a, celula* b) {
	if(a->prox == NULL) {
		copyList_R(b, a);
	}
	else concList_R(a->prox, b);
}

void concList_I(celula* a, celula* b) {
	celula* x;
	for(x = a; x->prox != NULL ; x = x->prox);
	copyList_R(b, x);
	
}

void copyList_R(celula* le, celula* copy) {
	if(le->prox == NULL) copy->prox = le->prox;
	else {
		insertBegin(copy, le->prox->conteudo);
		copyList_R(le->prox, copy->prox);
	}
}

void insertMiddle(celula* le, int posicao, int valor) {
	if( !(posicao > 0 && le->prox == NULL)) {
		if(posicao == 1) {
			insertBegin(le, valor);
		}
		else insertMiddle(le->prox, --posicao, valor);
	} 
}

void insertEnd(celula* le, int valor) {
	if(le->prox == NULL) {
		celula *nova = createList(nova);
		nova->conteudo = valor;
		nova->prox = le->prox;
		le->prox = nova;
	}
	else insertEnd(le->prox, valor);
}

void insertBegin(celula* le, int valor) {
	celula *nova = createList(nova);
	nova->conteudo = valor;
	nova->prox = le->prox;
	le->prox = nova;
}

celula* buscaListHead_R(celula* le, int valor) {
	celula* x;
	for(x = le->prox; x != NULL ; x = x->prox)
		if(x->conteudo == valor) return x;
	return NULL;
}

int equalsList_I(celula* la, celula* lb) {
	if(la == NULL && lb == NULL) return 1;
	else {
		celula *x;
		for(x = lb; x != NULL ; x = x->prox) {
			if(containsList(la, x->conteudo) == 0) return 0;
		}
		return 1;
	}
}

int containsList(celula* la, int valor) {
	if(la != NULL) {
		if(la->conteudo == valor) return 1;
		else return containsList(la->prox, valor);
	}
	return 0;
}

celula* middleList(celula* le) {
	if(le == NULL) return le;
	else {
		int size = sizeList_I(le)/2;
		celula* test = le;
		while(test != NULL) {
			test = test->prox;
			if(--size == 0)
				return test; 
		}
	}
}

celula* minList_I(celula* le) {
	if(le != NULL) {
		celula* min = le;
		while(le != NULL) {
			if(le->conteudo < min->conteudo) min = le;
			le = le->prox;
		}
		return min;
	}
}

celula* minList_R(celula* le) {
	if(sizeList_R(le) == 1) return le;
	else {
		celula* x = minList_R(le->prox);
		if(le->conteudo < x->conteudo) return le; 
		else return x;
	}
}

int checar_ordenada_R(celula* le) {
	static int first = 0, count;
	if(le == NULL) return 1;
	else if(first == 0) {
		first = 1;
		count = le->conteudo;
		return checar_ordenada_R(le->prox);
	}
	else if(count <= le->conteudo) {
		count = le->conteudo;
		return 1 & checar_ordenada_R(le->prox);	
	}
	else return 0;
}

celula* buscaList_I(celula* le, int valor) {
	celula* x;
	for(x = le; le != NULL ; x = x->prox) 
		if(x->conteudo == valor) return x;
	return x;
}

celula* buscaList_R(celula* le, int valor) {
	if(le == NULL) return le;
	else if(le->conteudo == valor) return le;
	else return buscaList_R(le->prox,valor);
	
}

int deepList(celula* begin,celula* end) {
	if(begin == end) return 0;
	else return 1+deepList(begin->prox,end);
}

int heightList(celula* le, int valor) {
	static int x = 0;
	if(le == NULL) return 0;
	else if(le->conteudo == valor) x = 1;
	if(x == 1) return 1+heightList(le->prox, valor);
	else return 0+heightList(le->prox, valor);
}

int sizeList_R(celula* le) {
	if(le == NULL) return 0;
	else return 1+sizeList_R(le->prox);
}

int sizeList_I(celula* le) {
	int i = 0;
	celula* x;
	for(x = le; x!=NULL ; x = x->prox) i++;
	return i;
}

void printList(celula* le) {
	if(le != NULL) {
		printf("%i ",le->conteudo);
		printList(le->prox);
	}
}
