/*
		Algoritmos e Estrutura de Dados
		Fabio Alves de Freitas
		14/07/2017
		EP3 - LEP (Linguagem de estruturas posfixas)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// estrutura da lista encadeada
typedef struct Lista {
	char conteudo;
	struct Lista* prox;
}Celula;

// struct auxiliar que ajuda na conversao de uma string para inteiro
typedef struct {
	float value;
	int size;
}Backup;

// struct que representa um contexto recursivo
typedef struct {
    int entrada;
    int indice;
}Contexto;

// insere conteudo no inicio da lista encadeada
Celula* insereInicio (Celula *plst, char pn) {
    Celula *nova;
    nova = (Celula*)malloc(sizeof(Celula));
    nova -> conteudo = pn;
	nova -> prox = plst;
    return nova;
}

// imprime a lista encadeada
void imprimirLista (Celula* c) {
	int n = 0;
	Celula *x;
	for(x = c ; x != NULL ; x = x->prox)
		printf("[%c]", x->conteudo);
}

// retorna o tamanho da lista encadeada
int tamanhoLista (Celula *c) {
	int n = 0;
	Celula *x;
	for(x = c ; x != NULL ; x = x->prox)
		n++;
	return n;
}

// funcao auxiliar que imprime as informacoes do arquivo
void imprimirInfo(int num, int base[], char exp[]) {
	printf("%i\n",num);
	int x;
	for(x=0;x<=num;x++)
		printf("%i\n",base[x]);
	int y = strlen(exp);
	for(x=0;x<y;x++)
		printf("%c",exp[x]);
}

// copia os dados de uma lista encadeada para um array
void copiarDados(char c[], int tam, Celula* le) {
	Celula* aux;
	int count = tam;
	for(aux = le ; aux != NULL ; aux = aux->prox) {
		c[--tam] = aux->conteudo;
	}
}

// empilha um elemento na pilha
void empilha(float valor, float pilha[], int* count, int tam) {
    if(!pilhaCheia(count, tam)) {
        pilha[(*count)++] = valor;
        printf("empilha: %.3f\n", valor);
    }
}

// retorna o elementos do topo da pilha
float desempilha(float pilha[], int* count) {
	if(!pilhaVazia(count)) {
        return pilha[--(*count)];
	}
	return 0;
}

void empilhaContexto (Contexto novoContexto, Contexto pilhaContexto[], int* count, int tam) {
    if(!pilhaCheia(count, tam)) {
         pilhaContexto[(*count)++] = novoContexto;
    }
}

Contexto desempilhaContexto (Contexto pilhaContexto[], int* count) {
    if(!pilhaVazia(count)) {
        return pilhaContexto[--(*count)];
    }
    return pilhaContexto[0];
}

// checa se uma pilha esta cheia
int pilhaCheia(int* count, int tam) {
	return (tam == (*count));
}

// checa se uma pilha est√° vazia
int pilhaVazia(int* count) {
    return ((*count) == 0);
}

// converte um caracter de n„mero em um numero inteiro
int converter (char c) {
	return  c - 48;
}

// imprime a opera„„o do desempilha
void imprimirOperacao (float a, float b, char c) {
	printf("desempilha: %.3f %c %.3f\n", b, c, a);
}

// converte uma sequencia de numeros seguidos de uma string para seu respectivo inteiro
Backup converterStringInteiro (char posf[], int inicio) {
	int contador = 0, aux = 0, n;  float resultado;  int tamanho = strlen(posf);
	for( n=inicio ; n<tamanho ; n++ ) {
		if(n != tamanho-1) {
			if(posf[n] != ' ') {
				contador++;
				if(posf[n+1] == ' ') {
					break;
				}
				if(n+1 == tamanho-1) {
					if(posf[n+1] != ' ')
						contador++;
					break;
				}
			}
		}
	}
	int* valores = (int*)malloc(sizeof(int)*contador);
	for( n=inicio ; n<tamanho ; n++ ) {
		if(posf[n] != ' ') {
			valores[aux++] = converter(posf[n]);
			if(aux == contador) {
				break;
			}
		}
	}
	int expoente = contador-1;
	for( n=0 ; n<contador ; n++ ) {
		aux = valores[n]*(pow(10, expoente--));
		resultado += aux;
	}
	free(valores);
	Backup novo;
	novo.size  = contador;
	novo.value = resultado;
	return novo;
}

// checa se o caracter em questao „ um inteiro
int checarInteiro (char posf[], int count) {
	if(posf[count] >= '0' && posf[count]<= '9')
        return 1;
	return 0;
}

// calcula o valor de uma expressao posffixa
float calculadora (char posf[], int bases[], int numBases, int entrada) {
	int tamanho = strlen(posf), countPilha = 0, j, n, aux;
	Backup backup;
	float* pilha = (float*)malloc(sizeof(float)*tamanho);
	float num1, num2;
	printf("=============== inicio e(%i) ===============\n", entrada);
	for(n=0 ; n<tamanho ; n++) {
		// diferencia o menos da recurs„o da operacao
		if(posf[n] == '-') {
			if(n == (tamanho-1)) { // o - eh um operador e esta na ultima posicao
				num1 = desempilha(pilha, &countPilha);
				num2 = desempilha(pilha, &countPilha);
				imprimirOperacao(num1, num2, posf[n]);
				empilha( num2 - num1 , pilha, &countPilha, tamanho);
			}
			else {// o - poder ser chamada recursiva ou um operador, pois nao estao no fim do array
				if(posf[n+1] == ' ') { // o - eh um operador e n„o esta no fim do array
					num1 = desempilha(pilha, &countPilha);
					num2 = desempilha(pilha, &countPilha);
					imprimirOperacao(num1, num2, posf[n]);
					empilha( num2 - num1 , pilha, &countPilha, tamanho);
				}
				// LOGICA DAS CHAMADAS RECURSIVAS
				else { // o - faz parte de uma chamada recursiva
					// se na posicao n+2 for diferente de vazio, a chamada recursiva eh de um valor maior que 9
					if(posf[n+2] != ' ') {
						backup = converterStringInteiro(posf, n+1);
						j = entrada - backup.value;
						n += (backup.size+1);
					}
					else {
						j = entrada - converter(posf[n+1]);
						// se a recursao for do tipo -n, entao j = entrada - entrada vale zero
						if(posf[n+1] == 'n') {
							j = 0;
						}
						n += 2;
					}
					// 0 <= j <= (numBases-1) e por isso o valor recursivo esta contido no array de bases
					if(j <= numBases) {
						// j eh menor ou igual a 0, empilhamos base[0]
						if(j <= 0) {
							printf("base da recursao e(%i): %i\n", j, bases[0]);
							empilha(bases[0], pilha, &countPilha, tamanho);
						}
						// 0 < j < (numBases), empilhamos base[j]
						else {
							printf("base da recursao e(%i): %i\n", j, bases[j]);
							empilha(bases[j], pilha, &countPilha, tamanho);
						}
					}
					else { // o valor recursivo eh desconhecido e deve ser ocorrida uma chama recursiva;
						//CHAMADA RECURSIVA
						float numRecursivo = calculadora(posf, bases, numBases, j);
						printf("chamada recursiva e(%i): %.3f\n", j, numRecursivo);
						empilha(numRecursivo, pilha, &countPilha, tamanho);
					}
				}
			}
		}
		// checa se eh um valor inteiro
		if(checarInteiro(posf, n)) {
			// quantidade de algarismo igual a 1
			if(posf[n+1] == ' ') {
				empilha(converter(posf[n]), pilha, &countPilha, tamanho);
			}
			// quantidade de algarismo maior que 1
			else {
				// converte as posicoes na string que representam o inteiro
				backup = converterStringInteiro(posf, n);
				// passa o contador para o proximo espaÁo vazio
				n += backup.size;
				// empilha o valor do inteiro da string apos a concersao
				empilha(backup.value, pilha, &countPilha, tamanho);
			}
		}
		// checa se eh uma operacao ou a entrada (n)
		switch(posf[n]) {
			// entrada n
			case 'n':
				empilha(entrada, pilha, &countPilha, tamanho);
				break;
			case '+':
				num1 = desempilha(pilha, &countPilha);
				num2 = desempilha(pilha, &countPilha);
				imprimirOperacao(num1, num2, posf[n]);
				empilha( num2 + num1 , pilha, &countPilha, tamanho);
				break;
			case '*':
				num1 = desempilha(pilha, &countPilha);
				num2 = desempilha(pilha, &countPilha);
				imprimirOperacao(num1, num2, posf[n]);
				empilha( num2 * num1 , pilha, &countPilha, tamanho);
				break;
			case '/':
				num1 = desempilha(pilha, &countPilha);
				num2 = desempilha(pilha, &countPilha);
				// checa a operacao de divisao por zero
				if(num1 == 0) {
					printf("\nencerrando o programa! divisao por zero.\n");
					return desempilha(pilha, &countPilha);
				}
				imprimirOperacao(num1, num2, posf[n]);
				empilha( num2 / num1 , pilha, &countPilha, tamanho);
				break;
		}
		// checa se a pilha esta cheia, se sim para a execucao
		if(pilhaCheia(&countPilha, tamanho)) {
			printf("\n\nestouro de pilha!\n\n");
			break;
		}
	}
	printf("===============  final e(%i) ===============\n", entrada);
	float retorno = pilha[--countPilha];
	free(pilha);
	return retorno;
}



int main() {
	FILE* arq = fopen("lep0.in","r");
	int linha1, n;
	fscanf(arq, "%i", &linha1);
	int* base = (int*)malloc(sizeof(int)*(linha1+1));
	for(n=0;n<=linha1;n++) {
		fscanf(arq, "%i", &base[n]);
		fscanf(arq, "\n");
	}
	Celula* lista1 = NULL;
	Celula* lista2 = NULL;
	int tam1 = 0, tam2 = 0;
	char c;
	do {
		fscanf(arq, "%c", &c);
		if(c == '\n')
			break;
		tam1++;
		lista1 =  insereInicio(lista1, c);
	}while(1);
	char* posf = (char*)malloc(sizeof(char)*tam1);
	copiarDados(posf, tam1, lista1);
	do {
		fscanf(arq, "%c", &c);
		if(feof(arq))
			break;
			tam2++;
		lista2 = insereInicio(lista2, c);
	}while(1);
	char* aux = (char*)malloc(sizeof(char)*tam2);
	Backup b;
	float resultado;
	imprimirInfo(linha1, base, posf);
	// entrada possui apenas 1 algarismo
	if(tam2 == 1) {
		int entrada = converter(lista2->conteudo);
		printf("\n%i\n\n",entrada);
		resultado = calculadora(posf, base, linha1, entrada);
	}

	// entrada possui mais de 1 algarismo
	else {
		// se entradar possuir 2 algarismos
		if(tam2 == 2) {
			aux[0] = lista2->prox->conteudo;
			aux[1] = lista2->conteudo;
			int entrada;
			entrada = (converter(aux[0])*10) + converter(aux[1]);
			printf("\n%i\n\n",entrada);
			resultado = calculadora(posf, base, linha1, entrada);
		}
		// se possuir 3 ou mais
		else {
			copiarDados(aux, tam2, lista2);
			b = converterStringInteiro(aux, 0);
			printf("\n%.2f\n\n",b.value);
			resultado = calculadora(posf, base, linha1, b.value);
		}

	}
	printf("\nResultado: %.3f\n\n",resultado);
	fclose(arq);
	free(base);
	free(posf);
	free(aux);;
}
