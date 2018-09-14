#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TAM 100

char pilhaAux[TAM], pilhaCounter = 0;

typedef struct celula {
	char dado;
	struct celula* prox;
}Lista;

// CRIA A LISTA ENCADEADA
Lista* createList() {
	Lista* le = (Lista*) malloc(sizeof(Lista));
	le->prox = NULL;
	return le;
}


// IMPRIME A LISTA ENCADEADA
void printList(Lista* le) {
	if(le != NULL) {
		printf("%c ",le->dado);
		printList(le->prox);
	}
}

// INSERE NO FIM DA LISTA ENCADEADA. USADO NA FILA, INSERE UM ITEM NA FILA.
void inserirFimList(Lista* le, char dado) {
	if(le->prox == NULL) {
		Lista *nova = createList();
		nova->dado = dado;
		nova->prox = le->prox;
		le->prox = nova;
	}
	else inserirFimList(le->prox, dado);
}

// RETORNA UM DADO DO INICIO DA LISTA ENCADEADA E O EXCLUI. REMOVE UM ITEM DA FILA.
char buscarInicioList(Lista* le) {
	Lista* aux = le->prox;
	le->prox = aux->prox;
	return aux->dado;
}

int pilhaVazia() {
	return pilhaCounter == 0;
}

int pilhaCheia() {
	return pilhaCounter == TAM;
}

void empilha(char c) {
	pilhaAux[pilhaCounter++] = c;
}

char desempilha() {
	return pilhaAux[--pilhaCounter];
}

int tamanhoLista(Lista* le) {
	if(le->prox == NULL) return 0;
	else return 1+tamanhoLista(le->prox);
}

// CHECA SE A EXPRESSÃO TEM OS PARÊNTESIS E CHAVES BEM FORMADOS. (1) BEM FORMADA, (0) MAL FORMADA
// algoritmo encontrado em https://www.ime.usp.br/~pf/algoritmos/aulas/pilha.html
int bemFormada(char expr[]) {
	char c;		int i;
	for(i = 0 ; expr[i] != '\0' ; i++) {
		switch(expr[i]) {
			case ')': if (pilhaVazia()) return 0;
                   	c = desempilha();
                   	if (c != '(') return 0;
                   	break;
			case '(': empilha(expr[i]);
					break;
		}
	}
	return pilhaVazia();
}

//	COPIA O CONTEÚDO DA LISTA PARA O VETOR
void copiaListaArray(char* vetor, int tamArray,Lista* lista) {
	int x;
	Lista* aux = lista->prox;
	for(x=0 ; x<tamArray ; x++) {
		vetor[x] = aux->dado;
		aux = aux->prox;
	}
}

// converte uma expressão infixa em posfixa
// algoritmo do professor feofiloff
// https://www.ime.usp.br/~pf/algoritmos/aulas/pilha.html#infixaParaPosfixa-pseudocode
char *infixaParaPosfixa (char *inf) {
   int n = strlen (inf);
   char *posf; 
   posf = malloc ((n+1) * sizeof (char));
   empilha(inf[0]);       // empilha '('

   int j = 0, i;
   for (i = 1; inf[i] != '\0'; ++i) {
      switch (inf[i]) {
         char x;
         case '(': empilha (inf[i]);
                   break;
         case ')': x = desempilha ();
                   while (x != '(') {
                      posf[j++] = x;
                      x = desempilha ();
                   }
                   break;
         case '+': 
         case '-': x = desempilha ();
                   while (x != '(') {
                      posf[j++] = x;
                      x = desempilha ();
                   }
                   empilha (x);
                   empilha (inf[i]);
                   break;
         case '*':
         case '/': x = desempilha ();
                   while (x != '(' && x != '+' && x != '-') {
                      posf[j++] = x;
                      x = desempilha ();
                   }
                   empilha (x);
                   empilha (inf[i]);
                   break;
         default:  posf[j++] = inf[i];
      }
   }
   posf[j] = '\0';      
   return posf;
}  

void calculadora(Lista* fila) {
	char c;
	int valor[4], i;
	while(fila->prox != NULL) {
		Lista* aux = createList();
		pilhaCounter = 0;
		
		// passa a expressao atual para a lista
		while(1) {
			c = buscarInicioList(fila);
			if(c == '\n' || c == -1) break;
			inserirFimList(aux, c);
		}
		
		// copiando o conteudo da lista para um array
		int tam = tamanhoLista(aux);
		char *expr = (char*) malloc( sizeof(char)*tam);
		copiaListaArray(expr, tam, aux);
		
		// imprime a expressão atual
		for(i=0 ; i<tam ; i++) {
			printf("%c",expr[i]);
		}
		printf("\n\n");
		
		// o usuario insere os valores
		for(i=0 ; i<4 ; i++) {
			printf("valor %i: ",i+1); 
			scanf("%i",&valor[i]);
		}
		
		
		if(bemFormada(expr)) {
			printf("\nOs parêntesis estão balanceados.\n");
			pilhaCounter = 0; // resetando a pilha 
			
			// parte meio bugada
			char* posfixa = infixaParaPosfixa(expr);
			for(i=0 ; i<strlen(posfixa) ; i++) {
				printf("%c",posfixa[i]);
			}
			
			
		}
		else printf("\nOs parêntesis não estão balanceados.\n");
		
		getchar();
		free(aux);
		printf("\n----------------\n");
	}
}



int main() {
	setlocale(LC_ALL, "Portuguese");
	FILE *arq = fopen("exp.dat","r");
	Lista* fila = createList();
	Lista* expr = createList();
	
	// PASSANDO O ARQUIVO PARA A FILA
	while(!feof(arq)) {			
		inserirFimList(fila, getc(arq));
	}

	calculadora(fila);
}
