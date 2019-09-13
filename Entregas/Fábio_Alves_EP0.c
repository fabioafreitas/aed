/*  
	Fábio Alves de Freitas
	EP0-Recursão 
	14/05/2017 
	Algoritmos e Estrutura de Dados	
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int global = 1;

//1º Versão Interativa - Busca o maior valor do array e o retorna

int maximoInterativo(int tamanho, int vetor[]) {
	
	int n;
	int maior = vetor[0];
	
	for( n=1 ; n<tamanho; n++) {
		global++;                  // variavel global para contar as interações
		if( vetor[0] < vetor[n] ) {
			maior = vetor[n];
		}
	}
	
	return maior;
}

//1º Versão Recursiva - Busca o maior valor do array e o retorna
// Utilizei o código do professor Feofillof- https://www.ime.usp.br/~pf/algoritmos/aulas/recu.html

int maximoRecursivo(int n, int v[]) { 
	global++;
    if (n == 1) {
    	return v[0];
    }
   	
    else {
		int x;
        x = maximoRecursivo(n-1, v);  
        // x é o máximo de v[0..n-2] 
        if (x > v[n-1])
           return x;
        else
           return v[n-1]; 
    }
}

//2º Versão Interativa - Testa se um vetor está em ordem crescente, 0 - falso, 1 - verdadeiro

int crescenteInterativo(int tamanho, int vetor[]) {
	int n;
	int pikachu=1;

	for( n=1 ; n<tamanho ; n++) {  // variavel global para contar as interações
		global++;
		if(vetor[n-1] > vetor[n]) {
			pikachu = 0;
			break;
		}
	}
	
	return pikachu;
}

//2º Versão Recursiva - Testa se um vetor está em ordem crescente

int crescenteRecursivo(int tamanho, int vetor[]) { // 1 verdadeiro, 0 falso
	global++;
	if(tamanho == 1){
		return 1;
	}
	
	int x; 	
	
	if(vetor[tamanho-2] <= vetor[tamanho-1]){
		x = crescenteRecursivo(tamanho-1,vetor);	
	} else {
		x = 0;
	}
	
	return x;
}

//3º Versão Interativa - Calcula o valor de 2^n 

int potenciaDois_interativa(int n) {
	int x;
	int resultado=2;
	
	if(n<0)
		n*=-1;
		
	if(n==0)
		return 1;
		
	for( x=0 ; x<(n-1); x++) {
		global++;
		resultado*=2;
	}

	return resultado;
}

//3º Versão Recursiva - Calcula o valor de 2^n

int potenciaDois_recursiva(int n) {
	global++;
	if(n==0)
		return 1;
		
	if(n<0)
		n*=-1;
		
	return 2*potenciaDois_recursiva(n-1);
}

//4º Versão Interativa - Busca um valor num vetor crescente e retorna um j tal que v[j-1] < x <= v[j]
// Utilizei o código do professor Feofillof - https://www.ime.usp.br/~pf/algoritmos/aulas/bubi.html

int buscaSequencial(int x, int n, int v[]) {
	global=0;
    int j = 0;
    while (j < n && v[j] < x  ) {                  // variavel global para contar as interações
   		global++;
		++j;
    }
   
   return j;
}

//4º Versao Recursiva - Busca um valor num vetor crescente e retorna um j tal que v[j-1] < x <= v[j]
// Utilizei o código do professor Feofillof - https://www.ime.usp.br/~pf/algoritmos/aulas/bubi2.html

int buscaBinaria (int x, int n, int v[]) { 
	global++;
    int e, m, d; 
    e = -1; d = n;
    while (e < d-1) {  
    	m = (e + d)/2;
        if (v[m] < x) {
    		e = m;
	  	}
        else {
      		d = m;
	    } 
    }
   	return d;
}

// implementei o main de maneira mais elaborada para facilitar na hora dos testes!

int main() {
	setlocale(LC_ALL,"Portuguese");
	int n;
	int parar=1;
	do {

		global = 0;  // reseto a variavel global para outra contagem
		
		printf("\n\tquestao 1:\n\t1 - recursivo\n\t2 - interativa\n\n");
		printf("\n\tquestao 2:\n\t3 - recursivo\n\t4 - interativa\n\n");
		printf("\n\tquestao 3:\n\t5 - recursivo\n\t6 - interativa\n\n");
		printf("\n\tquestao 4:\n\t7 - recursivo\n\t8 - interativa\n\n\t9 - Sair\n\n\t-->");
		scanf("%i",&n);
		fflush(stdin);
		
		switch(n) {
			case 1: {  // questao 1 recursivo
				system("cls");
				int tamanho;
				do {
					printf("\n\n\tinsira o tamanho do vetor: ");
					scanf("%i",&tamanho);
					fflush(stdin);
					if(tamanho<0) {
						printf("\n\n\tinsira um valor maior que 0;");
					}
				}while(tamanho<0);
				
				int v[tamanho];
				
				for(n=0 ; n<tamanho ; n++) {
					printf("\n\tv[%i] valor: ",n);
					scanf("%i",&v[n]);
				}
				
				int valor = maximoRecursivo(tamanho,v);
				printf("\n\n\tO maior valor deste vetor é %i\n\n",valor);
				printf("\n\n\tNº interações: %i\n\n\n",global);
				system("pause");
				break;
			}
			case 2: { // questao 1 interativa
				system("cls");
				int tamanho;
				do {
					printf("\n\n\tinsira o tamanho do vetor: ");
					scanf("%i",&tamanho);
					fflush(stdin);
					if(tamanho<0) {
						printf("\n\n\tinsira um valor maior que 0;");
					}
				}while(tamanho<0);
				
				int v[tamanho];
				
				for(n=0 ; n<tamanho ; n++) {
					printf("\n\tv[%i] valor: ",n);
					scanf("%i",&v[n]);
				}
				
				int valor = maximoInterativo(tamanho,v);
				printf("\n\n\tO maior valor deste vetor é %i\n\n",valor);
				printf("\n\n\tNº interações: %i\n\n\n",global);
				system("pause");
				break;
			}
			case 3: { // questao 2 recursivo
				system("cls");
				int tamanho;
				do {
					printf("\n\n\tinsira o tamanho do vetor: ");
					scanf("%i",&tamanho);
					fflush(stdin);
					if(tamanho<0) {
						printf("\n\n\tinsira um valor maior que 0;");
					}
				}while(tamanho<0);
				
				int v[tamanho];
				
				for(n=0 ; n<tamanho ; n++) {
					printf("\n\tv[%i] valor: ",n);
					scanf("%i",&v[n]);
				}
				
				int valor = crescenteRecursivo(tamanho,v);
				printf("%i",valor);
				if(valor==1) {
					printf("\n\n\tEstá crescente!\n\n");
				} else {
					printf("\n\n\tNão está crescente!\n\n");
				}
				printf("\n\n\tNº interações: %i\n\n\n",global);
				system("pause");
				break;
			}
			case 4: { // questao 2 interativa
				system("cls");
				int tamanho;
				do {
					printf("\n\n\tinsira o tamanho do vetor: ");
					scanf("%i",&tamanho);
					fflush(stdin);
					if(tamanho<0) {
						printf("\n\n\tinsira um valor maior que 0;");
					}
				}while(tamanho<0);
				
				int v[tamanho];
				
				for(n=0 ; n<tamanho ; n++) {
					printf("\n\tv[%i] valor: ",n);
					scanf("%i",&v[n]);
				}
				
				int valor = crescenteInterativo(tamanho,v);
				if(valor==1) {
					printf("\n\n\tEstá crescente!\n\n");
				} else {
					printf("\n\n\tNão está crescente!\n\n");
				}
				printf("\n\n\tNº interações: %i\n\n\n",global);
				system("pause");
				break;
			}
			case 5: { // questao 3 recursivo
				system("cls");
				printf("\n\n\tInsira um valor Inteiro: ");
				scanf("%i",&n);
				
				if(n<0) 
					printf("\n\n\t2^%i = 1/%i\n\n",n,potenciaDois_recursiva(n));
				
				if(n>=0)
					printf("\n\n\t2^%i = %i\n\n",n,potenciaDois_recursiva(n));
				printf("\n\n\tNº interações: %i\n\n\n",global);
				system("pause");
				break;
			}
			case 6: { // questao 3 interativa
				system("cls");
				printf("\n\n\tInsira um valor Inteiro: ");
				scanf("%i",&n);
				
				if(n<0) {
					printf("\n\n\t2^%i = 1/%i\n\n",n,potenciaDois_interativa(n));
				}
					
				if(n>=0) {
					printf("\n\n\t2^%i = %i\n\n",n,potenciaDois_interativa(n));
				}
					
					
				printf("\n\n\tinteraçoes do laço: %i",global);
				printf("\n\n\tNº interações: %i\n\n\n",global);
				system("pause");
				break;
			}
			case 7: { // questao 4 recursivo
				system("cls");
				int tamanho;
				do {
					printf("\n\n\tinsira o tamanho do vetor: ");
					scanf("%i",&tamanho);
					fflush(stdin);
					if(tamanho<0) {
						printf("\n\n\tinsira um valor maior que 0;");
					}
				}while(tamanho<0);
				
				int v[tamanho];
				
				printf("\n\n\tpreencha o vetor em ordem crescente!\n\n");
					
				for(n=0 ; n<tamanho ; n++) {
					do {
						printf("\n\tv[%i] valor: ",n);
						scanf("%i",&v[n]);
						fflush(stdin);
						if(v[n-1]>v[n]) {
							printf("\n\n\tinsira um valor maior ou igual que o anterior(%i)!\n",v[n-1]);
						}
					}while(v[n-1]>v[n]);
				}
				
				int buscar;
				
				printf("\n\n\tDigite o valor a ser procurado no array: ");
				scanf("%i",&buscar);
				fflush(stdin);
				
				int resultado = buscaBinaria(buscar,tamanho,v);
				
				printf("\n\n\tO valor encontrado está em v[%i] e vale %i\n\n",resultado,v[resultado]);
				printf("\n\n\tNº interações: %i\n\n\n",global);
				system("pause");
				break;
			}
			case 8: { // questao 4 interativa
				system("cls");
				int tamanho;
				do {
					printf("\n\n\tinsira o tamanho do vetor: ");
					scanf("%i",&tamanho);
					fflush(stdin);
					if(tamanho<0) {
						printf("\n\n\tinsira um valor maior que 0;");
					}
				}while(tamanho<0);
				
				int v[tamanho];
				
				printf("\n\n\tpreencha o vetor em ordem crescente!\n\n");
					
				for(n=0 ; n<tamanho ; n++) {
					do {
						printf("\n\tv[%i] valor: ",n);
						scanf("%i",&v[n]);
						fflush(stdin);
						if(v[n-1]>v[n]) {
							printf("\n\n\tinsira um valor maior ou igual que o anterior(%i)!\n",v[n-1]);
						}
					}while(v[n-1]>v[n]);
				}
				
				int buscar;
				
				printf("\n\n\tDigite o valor a ser procurado no array: ");
				scanf("%i",&buscar);
				fflush(stdin);
				
				int resultado = buscaSequencial(buscar,tamanho,v);
				
				printf("\n\n\tO valor encontrado está em v[%i] e vale %i\n\n",resultado,v[resultado]);
				printf("\n\n\tNº interações: %i\n\n\n",global);
				system("pause");
				break;
			}
			case 9: {
				parar = 0;
				break;
			}
			default:
				printf("\n\t opcao invalida! ");
		}
		system("cls");
	}while(parar!=0);
}
