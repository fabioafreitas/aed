#include <stdio.h>
#include <stdlib.h>
#define tam 10

int inicio = 0, final = 0;

// checa se a fila está vazia
int filavazia() {
	return inicio == final;
}

// checa se a fila está cheia
int filacheia() {
	return (final+1)%tam == inicio;
}

// retorna o coprimento da fila (número de elementos)
int comprimentoDaFila () {
	int n;
	int count = 0;
	if(inicio > final ) {
		for( n = inicio ; n < tam  ; n++ )
			count++;
		for( n = 0 ; n <= final  ; n++ )
			count++;
		return count;
	}
	for( n = inicio ; n <= final ; n++ )
		count++;
	return count;
}

// insere um elemento no final da fila
void colocanafila(int* fila, int conteudo) {
	if(!filacheia()) {
		fila[final++] = conteudo;
		if(final == tam) {
			final = 0;
		}
	}
}

// tira um elemento do inicio da fila
int tiradafila(int* fila) {
	if(!filavazia()) {
		int n = fila[inicio++];
		if(inicio == tam) {
			inicio = 0;
		}
		return n;
	}
}


int main() {
	int n, fila[tam];
	
	for(n = 0; n<tam ; n++) {
		fila[n] = -1;
	}
	
	colocanafila(fila, 1);
	colocanafila(fila, 2);
	colocanafila(fila, 3);
	colocanafila(fila, 4);
	colocanafila(fila, 5);
	colocanafila(fila, 6);
	colocanafila(fila, 7);
	colocanafila(fila, 8);
	colocanafila(fila, 9);
	colocanafila(fila, 10);
	
	tiradafila(fila);
	tiradafila(fila);
	tiradafila(fila);
	tiradafila(fila);
	tiradafila(fila);
	
	colocanafila(fila, 4);
	colocanafila(fila, 5);
	
	
	for(n = 0; n<tam ; n++) {
		printf("[%i]",fila[n]);
	}
	
	int k = comprimentoDaFila();
	
	printf("%i",k);
}
