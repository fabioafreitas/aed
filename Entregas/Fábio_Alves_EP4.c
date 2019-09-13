/*
		Algoritmos e Estrutura de Dados
		Fábio Alves de Freitas
		05/09/2017
		EP4 - Sistema de Processamento de Textos


		obs: considerei textos que nao possuem acentuação
		nem caracteres mais espeficicos, como: Ø, ƒ, « e ®
		
		fiz as implementações de todas as funções necessarias para 
		a seleção das palavras na tabela, porém tive dificuldade na
		impressao delas!
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 100   // tamanho da tabela
#define PRIMO 31  // primo utilizado na conversao do hash

// a lista representa uma palavra, pois nao sabenos inicialmente o tamanho da palavra
typedef struct Lista {
	char caracter;
	struct Lista* prox;
}List;

// essa lista que armazena uma palavra do tipo List
typedef struct Node {
    List palavra;
    int contador;
    struct Node* prox;
}Conjunto;

// essa struct representa a tabela hash, e armazena Listas do tipo Conjunto
typedef struct {
	Conjunto conjunto; // conjunto de palavras
	int chave; // inicializado com -1
}HashTable;


// imprime o conteudo de uma lista encadeada
void imprimeLista(List* lista) {
	List* n;
	for(n=lista;n!=NULL;n = n->prox) {
		printf("%c",n->caracter);
	}
}

// insere caracteres no final de uma lista encadeada do tipo List
void inserirFim(List *list, char conteudo) {
	List *novo= (List*) malloc(sizeof(List));
	if(!novo){
		printf("\nSem memoria disponivel!\n");
		exit(1);
	}
	novo->caracter = conteudo;
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

// insere uma lista encadeada do tipo List no fim de uma lista do tipo Conjunto
void novaPalavra(Conjunto *conjunto, List* palavra) {
    Conjunto *novo= (Conjunto*) malloc(sizeof(Conjunto));
	if(!novo){
		printf("\nSem memoria disponivel!\n");
		exit(1);
	}
	novo->contador = 1; // a nova palavra inicia com quantidade 1
	novo->palavra.prox = NULL;
	novo->palavra.caracter = ' ';
	novo->prox = NULL;
	
	
    // copiando a palavra numa lista List
    List* n; // contador

    for(n = palavra ; n != NULL ; n = n->prox) {
        inserirFim(&novo->palavra, n->caracter);// copiando a palavra para uma lista auxiliar
    }
	
	imprimeLista(&novo->palavra);
	
    // inserindo esta palavra no fim da lista Conjunto
	if(conjunto->prox == NULL)
		conjunto->prox=novo;
	else{
		Conjunto *tmp = conjunto->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
}

// calcula o hash de uma lista encadeada do tipo List
int calcular_Hash (List* string, int tamTabela) {
   unsigned h = 0;
   List* n;
   for(n = string ; n != NULL ; n = n->prox) {
   		h = (h * PRIMO + n->caracter) % tamTabela;
   }
   return h;
}


// retorna o tamanho de uma lista encadeada do tipo List
int tamanho_Lista (List* a) {
	List* n;
	int count = 0;
	for(n = a; n != NULL ; n = n->prox)
		count++;
	return count;
}

// insere o conteudo de uma lista List A no fim de uma lista List B
// a lista do primeiro paremetro recebe o conteudo da segunda
void concatenar_Lista (List* list, List* add) {
	List *a;
	for(a = add ; a != NULL ; a = a->prox) {
		inserirFim(list, a->caracter);
	}
}


// checa se duas listas encadeadas do tipo List possuem o mesmo conteudo
// retorna 1 se sim, 0 se nao
int equals (List* a, List* b) {
	int tam1 = tamanho_Lista(a);
	int tam2 = tamanho_Lista(b);
	int count = 0;
	List *x = a, *y = b;
	if(tam1 == tam2) {
		while(x != NULL) {
			if(x->caracter == y->caracter) {
				count++;
			}
			if(count == tam1) {
				return 1;
			}
			x = x->prox;
			y = y->prox;
		}
	}
	return 0;
}

// checa se determinada palavra está contida no conjunto
// se sim retorna 1, se nao retorna 0
int contains (Conjunto* conjunto, List* palavra) {
    Conjunto* n;
    for(n = conjunto ; n != NULL ; n = n->prox) {
        if(equals(&n->palavra, palavra)) {
            return 1;
        }
    }
    return 0;
}

// busca uma palavra na lista encadeada, e se acha-la incrementa seu contador em 1
void incrementar_Contador (Conjunto* conjunto, List* palavra) {
    Conjunto* n;
    for(n = conjunto ; n != NULL ; n = n->prox) {
        if(equals(&n->palavra, palavra)) {
        	imprimeLista(&n->palavra);
            n->contador++;
            break;
        }
    }
    printf("Erro, a palavra nao existe no conjunto");
    exit(EXIT_FAILURE);
}

// checa se o caracter lido no arquivo faz parte de uma palavra
// return 1 se sim, 0 se nao
int validar_Caracter (char c) {
	if(c >= 65 || c <= 90 || c >= 97 || c <= 122)
		return 1;
	return 0;
}


// lista as palavras que ocorrem exatamente N vezes
// o N é um valor de entrada maior que 0 selecionado pelo usuario
void Listar_Por_Ocorrencia (HashTable *tabelaHash) {
	int num = -1;
	while(num <= 0) {
		printf("\nNumero de ocorrencias: ");
		scanf("%i",&num);
		fflush(stdin);
		if(num <= 0) {
			printf("Valor invalido!\n");
		}
	}
	// laço que busca pela quantidade de ocorrencias
	int n; 
	Conjunto* cj;
	// tabela
	for( n = 0 ; n < TAM ; n++ ) {
		// lista de conjuntos
		if(tabelaHash[n].chave != -1) {
			for(cj = &tabelaHash[n].conjunto ; cj != NULL ; cj = cj->prox) {
				if( cj->contador == num ) {
					imprimeLista(&cj->palavra);
				}
			}
		}
	}
	system("pause");
}

// lista todas as palavras já armazenadas numa tabela hash
void Listar_Palavras_Armazenadas (HashTable *tabelaHash) {
	int n; 
	Conjunto* cj;
	// tabela
	for( n = 0 ; n < TAM ; n++ ) {
		// lista de conjuntos
		if(tabelaHash[n].chave != -1) {
			for(cj = &tabelaHash[n].conjunto ; cj != NULL ; cj = cj->prox) {
				imprimeLista(&cj->palavra);
				printf("Ocorrencias: %i",cj->contador);
			}
		}
		
	}
	system("pause");
}

// Funcao principal do sistema
// ela recebe um arquivo de texto e armazena suas palavras numa tabela hash
// contabilizando suas repeticoes
void ler_Arquivo(FILE* arq, HashTable *tabelaHash) {
    // LISTA AUXILIAR
    List palavra;
    palavra.prox = NULL;
    palavra.caracter = ' ';


    int comparador = 0;// checa se na ultima iteração ocorreu a leitura de palavra
    int indice; // valor auxiliar para receber o hash de uma palavra
    char c, menu;
    while(1) {
        c = getc(arq);

        // se for o fim do arquivo paramos o laço
        if(feof(arq)) {
            break;
        }

        // se for um caracter válido para uma palavra
        if(validar_Caracter(c) || c == '-' || c == 39) {
            inserirFim(&palavra, c);
            comparador = 1; // se for 1 está tendo a leitura de uma palavra
        }

        // a leitura de uma palavra acabou
        if(c == '\n' || c == ' ') {
            // se comparador for 1 ocorreu uma leitura de palavra
            if(comparador == 1) {
                indice = calcular_Hash(&palavra, TAM);
				
                // posicao ainda nao ocupada (sem colisao)
                if(tabelaHash[indice].chave == -1) {
                    // add a palavra no inicio da variavel conjunto dessa posisao da tabela
                    novaPalavra(&tabelaHash[indice].conjunto, &palavra);
                }

                // posicao ja ocupada (houve colisao)
                else {
                    // checa se a palavra já esta contida no conjunto
                    if(contains(&tabelaHash[indice].conjunto, &palavra)) {
                        incrementar_Contador(&tabelaHash[indice].conjunto, &palavra);
                    }
                    // se nao estiver contida inclui a palavra na tabela
                    else {
                        novaPalavra(&tabelaHash[indice].conjunto, &palavra);
                    }
                }

                // SWITCH
				
				printf("\nUltima Palavra: ");
				imprimeLista(&palavra);
				printf("\n<ENTER> Continuar Leitura\n<1> Buscar por numero do ocorrencia\n<2> Listar palavas armazenadas\n\n");
				scanf("%c",&menu);
				fflush(stdin);
				switch(menu) {
					case '1':
						Listar_Por_Ocorrencia(tabelaHash);
						break;
					case '2':
						Listar_Palavras_Armazenadas(tabelaHash);
						break;
				}
				system("cls");
				
                // RESETAR A LISTA AUXILIAR
                palavra.prox = NULL;
                palavra.caracter = ' ';
            }
            // se for 0 nao ocorreu leitura de palavra continuamos o codigo normalmente
        }
    }
}

int main() {
    FILE* arq = fopen("Texto2.txt","r");
    //TABELA HASH
    HashTable *tabelaHash = (HashTable*) malloc(sizeof(HashTable)*TAM);
    int n;
    for( n = 0 ; n<TAM ; n++ ) {
        tabelaHash[n].chave = -1; // inicializando co -1
        tabelaHash[n].conjunto.prox = NULL; // cabeça da lista de conjunto
    }

	ler_Arquivo(arq, tabelaHash);
	
	printf("\nFim do arquivo\n");
	system("pause");

    fclose(arq);
}
