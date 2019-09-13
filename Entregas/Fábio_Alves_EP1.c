/*
		Algoritmos e Estrutura de Dados
		Fábio Alves de Freitas
		11/06/2017
		EP1 - Sorting
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define TAM ;
int contadorGlobal;

/*====================================================================================================================================================================================*/

/*
	Algoritmo de Inserção
 	Copiei o código do professor Feofiloff!
 	https://www.ime.usp.br/~pf/algoritmos/aulas/ordena.html
*/

//	Esta função rearranja o vetor v[0..n-1]
//	em ordem crescente.

void insercao_Iterativo (int n, int v[])
{
	int i, j, x;
    for (j = 1; j < n; ++j) {
       	x = v[j];
      	for (i = j-1; i >= 0 && v[i] > x; --i) {
      		v[i+1] = v[i];
      		contadorGlobal++;
	  	}
      	v[i+1] = x;
   	}
}
/*
insertion sort recursivo
https://cboard.cprogramming.com/c-programming/37188-recursive-insertion-sort.html
*/
void insercao_Recursivo (int i, int array[], int size) {
    contadorGlobal++;
    if (i < size)
    {
        int j;
        int temp = array[i];

        for (j = i; j > 0 && array[j-1] > temp; j--) {
            contadorGlobal++;
            array[j] = array[j-1];
        }

        array[j] = temp;

        insercao_Recursivo(++i, array, size);
    }
}

/*====================================================================================================================================================================================*/

/*
	Algoritmo de Seleção
 	Copiei o código do professor Feofiloff!
 	https://www.ime.usp.br/~pf/algoritmos/aulas/ordena.html
*/

//	Esta função rearranja o vetor v[0..n-1]
//	em ordem crescente.

void selectionSort (int n, int v[])
{
	int i, j, min, x;
   	for (i = 0; i < n-1; ++i) {
   		contadorGlobal++;
    	min = i;
      	for (j = i+1; j < n; ++j) {
      		contadorGlobal++;
      		if (v[j] < v[min])  min = j;
	  	}
		x = v[i]; v[i] = v[min]; v[min] = x;
   	}
}


/*====================================================================================================================================================================================*/

/*
	HeapSort
 	Copiei o código do professor Feofiloff!
 	https://www.ime.usp.br/~pf/algoritmos/aulas/hpsrt.html
*/

// Troca os valores das variáveis na qual os ponteiros a e b apontam;

static void troca (int *a, int *b) {
	int t = (*a);
	(*a) = (*b);
	(*b) = t;
}

// Rearranja um vetor v[1..m] de modo a
// transformá-lo em heap.

static void constroiHeap (int m, int v[])
{
	int k;
   	for (k = 1; k < m; ++k) {
   		contadorGlobal++;
      	// v[1..k] é um heap
      	int f = k+1;
      	while (f > 1 && v[f/2] < v[f]) {
	 		contadorGlobal++;
			troca (&v[f/2], &v[f]);
         	f /= 2;
      	}
   	}
}

// Recebe um vetor v[1..m] que é um heap
// exceto talvez pelos índices 2 e 3 e
// rearranja o vetor de modo a
// transformá-lo em heap.

static void peneira_Iterativo (int m, int v[])
{
	int p = 1, f = 2, t = v[1];
   	while (f <= m) {
   		contadorGlobal++;
      	if (f < m && v[f] < v[f+1])  ++f;
      	if (t >= v[f]) break;
      	v[p] = v[f];
      	p = f, f = 2*p;
   	}
   	v[p] = t;
}

// Recebe um vetor v[1..m] que é um heap
// exceto talvez pelos índices 2 e 3 e
// rearranja de maneira recursiva o vetor de modo a
// transformá-lo em heap.

void peneira_Recursivo (int m, int v[]) {
	contadorGlobal++;
	if(m==1) {
		return;
	}
	
	int f = m;
	
	peneira_Recursivo(m-1,v);
	
	if( f<m && v[f] < v[f+1] ) {
		f++;
	}
	
	if( v[f/2] >= v[f] ) {
		return;
	}
	
	troca(&v[f/2],&v[f]);
	f = f/2;
}

// Rearranja os elementos do vetor v[1..n]
// de modo que fiquem em ordem crescente.

void heapsort_Peneira_Iterativo (int n, int v[]) {
	int m;
    constroiHeap (n, v);
    for (m = n; m >= 2; --m) {
		contadorGlobal++;
        troca (&v[1], &v[m]);
        peneira_Iterativo (m-1, v);
	}
}



void heapsort_Peneira_Recursivo (int n, int v[]) {
	int m;
    constroiHeap (n, v);
    for (m = n; m >= 2; --m) {
		contadorGlobal++;
        troca (&v[1], &v[m]);
        peneira_Recursivo (m-1, v);
	}
}

/*====================================================================================================================================================================================*/

/*
	MergeSort
	Esta função rearranja o vetor v[0..n-1]
	em ordem crescente.
 	Copiei o código do professor Feofiloff!
 	https://www.ime.usp.br/~pf/algoritmos/aulas/mrgsrt.html
*/

// A função recebe vetores crescentes v[p..q-1] e
// v[q..r-1] e rearranja v[p..r-1] em ordem crescente.

static void intercala (int p, int q, int r, int v[])
{
	int i, j, k;
    int *w;
    w = (int*) malloc ((r-p) * sizeof (int));
    i = p; j = q;
    k = 0;
	while (i < q && j < r) {
   		contadorGlobal++;
		if (v[i] <= v[j])  w[k++] = v[i++];
        else  w[k++] = v[j++];
    }
   	while (i < q) {
  	 	w[k++] = v[i++];
   		contadorGlobal++;
   	}
   	while (j < r) {
   		contadorGlobal++;
		w[k++] = v[j++];
	}
    for (i = p; i < r; ++i) {
		contadorGlobal++;
		v[i] = w[i-p];
    }
    free (w);
}

// A função mergesort rearranja o vetor
// v[p..r-1] em ordem crescente.

void mergesort_Recursivo (int p, int r, int v[]) {
	contadorGlobal++;
	if (p < r-1) {                 // 1
		int q = (p + r)/2;          // 2
        mergesort_Recursivo (p, q, v);        // 3
        mergesort_Recursivo (q, r, v);        // 4
        intercala (p, q, r, v);     // 5
	}
}

// Esta função rearranja o vetor v[0..n-1]
// em ordem crescente.

void mergesort_Iterativo (int n, int v[]) {
	int p, r;
   	int b = 1;
   	while (b < n) {
   		contadorGlobal++;
    	p = 0;
		while (p + b < n) {
        	contadorGlobal++;
			r = p + 2*b;
         	if (r > n) r = n;
         	intercala (p, p+b, r, v);
         	p = p + 2*b;
      	}
      	b = 2*b;
   	}
}

/*====================================================================================================================================================================================*/

/*
	QuickSort
	Esta função rearranja o vetor v[0..n-1]
	em ordem crescente.
 	Copiei o código do professor Feofiloff!
 	https://www.ime.usp.br/~pf/algoritmos/aulas/quick.html
*/

// Recebe vetor v[p..r] com p <= r. Rearranja
// os elementos do vetor e devolve j em p..r
// tal que v[p..j-1] <= v[j] < v[j+1..r].

static int separa (int v[], int p, int r) {
	int c = v[p], i = p+1, j = r, t;
   	while (/*A*/ i <= j) {
   		contadorGlobal++;
    	if (v[i] <= c) ++i;
      	else if (c < v[j]) --j;
      	else {
        	t = v[i], v[i] = v[j], v[j] = t;
         	++i; --j;
      	}
   	}
   	// agora i == j+1
   	v[p] = v[j], v[j] = c;
   	return j;
}

// A função rearranja o vetor v[p..r]
// em ordem crescente.

void quicksort (int v[], int p, int r) {
	int j;
	contadorGlobal++;
	if (p < r) {
    	j = separa (v, p, r);
		quicksort (v, p, j-1);
      	quicksort (v, j+1, r);
   	}
}
/*====================================================================================================================================================================================*/

// imprime o array randomico atual

void imprimeArray(int tam, int vetor[]) {
	printf("\n\n\t\t\tVETOR RANDOMICO ATUAL\n\n");
    int p;
    int jump = 0;
    for( p = 0 ; p < tam ; p++ , jump++ ) {
        if( jump == 15 ) {
			printf("\n");
			jump = 0;
		}
		if( jump == 0) {
			printf("\t");
		}
        if(p == tam-1) {
   			printf("%i. ",vetor[p]);
		}
		else {
			printf("%i, ",vetor[p]);
		}
	}
    printf("\n\n\n");
}

// tem a funçao de resetar o array de teste para sua forma antes da ordenação

void resetarArrayTeste(int arrayAuxiliar[], int array[], int tamanho) {
	int n;
	for( n = 0 ; n < tamanho ; n++ ) {
		array[n] = arrayAuxiliar[n];
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	int opcoes, tam, parar = 1;
	int primeiroVetor = 0; // validações
    int* vetor; // vetor teste
	int* vetorAuxiliar; // reseta o array teste ao seu original
	do{
		resetarArrayTeste(vetorAuxiliar, vetor, tam);
		fflush(stdin);
		if(primeiroVetor == 1) {
			system("cls");
			printf("Tamanho do Array = %i\n\n\t\tInsira a opção:",tam);
			printf("\n\n\t\t1 = Inserção;\n\t\t2 = Seleção;");
			printf("\n\t\t3 = Mergesort;\n\t\t4 = Heapsort;\n\t\t5 = Quicksort;");
			printf("\n\n\t\t6 = Criar ARRAY de teste;\n\t\t");
			printf("7 = Imprimir Array Atual;\n\n\t\t0 = sair;\n\n\t\t==> ");
			scanf("%i",&opcoes);
			
			if(opcoes == 0) { // parar o programa
				return 0;
			}
		}
		if(primeiroVetor == 0) {
			opcoes = 6;
			primeiroVetor = 1;
		}
		switch(opcoes) {
			case 1: {
				system("cls");
				printf("\n\n\t\tInserção\n\n");
				printf("\t\t1 = Iterativo;\n\n\t\t2 = Recursivo;\n\n\t\t==> ");
				scanf("%i",&opcoes);
				switch(opcoes) {
				    case 1: {
				        printf("\n\n\t\tInserção Iterativo\n\n");
				        insercao_Iterativo(tam, vetor);
                        printf("\n\n\t\tArray foi ordenado!\n\n\t\tNúmero de interações = %i\n\n\n",contadorGlobal);
                        system("pause");
                        contadorGlobal = 0;
                        break;
				    }
				    case 2: {

                        printf("\n\n\t\tInserção Recursivo\n\n");
                        insercao_Recursivo(0, vetor, tam);
                        printf("\n\n\t\tArray foi ordenado!\n\n\t\tNúmero de interações = %i\n\n\n",contadorGlobal);
                        system("pause");
                        contadorGlobal = 0;
                        break;
				    }
				}
				break;
			}
			case 2: {
				selectionSort(tam,vetor);
                system("cls");
                printf("\n\n\t\tSeleção\n\n");
                printf("\n\n\t\tArray foi ordenado!\n\n\t\tNúmero de interações = %i\n\n\n",contadorGlobal);
                system("pause");
                contadorGlobal = 0;
                break;
			}
			case 3: {
			    system("cls");
				printf("\n\n\t\tMergesort;\n\n");
				printf("\t\t1 = Iterativo;\n\n\t\t2 = Recursivo;\n\n\t\t==> ");
				scanf("%i",&opcoes);
				switch(opcoes) {
				    case 1: {
				        printf("\n\n\t\tMergesort Iterativo\n\n");
				        mergesort_Iterativo(tam,vetor);
                        printf("\n\n\t\tArray foi ordenado!\n\n\t\tNúmero de interações = %i\n\n\n",contadorGlobal);
                        system("pause");
                        contadorGlobal = 0;
                        break;
				    }
				    case 2: {

                        printf("\n\n\t\tMergesort Recursivo\n\n");
                        mergesort_Recursivo(0,tam,vetor);
                        printf("\n\n\t\tArray foi ordenado!\n\n\t\tNúmero de interações = %i\n\n\n",contadorGlobal);
                        system("pause");
                        contadorGlobal = 0;
                        break;
				    }
				}
				break;
			}
			case 4: {
			    system("cls");
				printf("\n\n\t\tHeapSort Peneira;\n\n");
				printf("\t\t1 = Iterativo;\n\n\t\t2 = Recursivo;\n\n\t\t==> ");
				scanf("%i",&opcoes);
				switch(opcoes) {
				    case 1: {
				        printf("\n\n\t\tHeapSort Peneira Iterativo\n\n");
				        heapsort_Peneira_Iterativo(tam,vetor);
                        printf("\n\n\t\tArray foi ordenado!\n\n\t\tNúmero de interações = %i\n\n\n",contadorGlobal);
                        system("pause");
                        contadorGlobal = 0;
                        break;
				    }
				    case 2: {
                        printf("\n\n\t\tHeapSort Peneira Recursivo\n\n");
				        heapsort_Peneira_Recursivo(tam,vetor);
                        printf("\n\n\t\tArray foi ordenado!\n\n\t\tNúmero de interações = %i\n\n\n",contadorGlobal);
                        system("pause");
                        contadorGlobal = 0;
                        break;
				    }
				}
				break;
			}
			case 5: {
				quicksort(vetor,0,tam);
				system("cls");
				printf("\n\n\t\t\tQuicksort\n\n");
				printf("\n\n\t\tArray foi ordenado!\n\n\t\tNúmero de interações = %i\n\n\n",contadorGlobal);
				system("pause");
				contadorGlobal = 0;
				break;
			}
			case 6: {
				system("cls");
				tam = TAM;
                vetor = (int*) malloc (tam*sizeof(int)); // vetor de teste
                vetorAuxiliar = (int*) malloc (tam*sizeof(int)); // vetor auxiliar para resetar o vetor de teste
				int a;
                for(a = 0 ; a < tam ; a++ ) {
                    vetor[a] = rand()%tam;
                    vetorAuxiliar[a] = vetor[a];
                }
				break;
			}
			case 7: {
				system("cls");
				imprimeArray(tam, vetor);
                system("pause");
        	}
		}
	}while(parar);
	return 0;
}
