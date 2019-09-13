#include <stdio.h>
#include <stdlib.h>

// função intercala para único vetor
// consideramos que o vetor tem duas metades ordenadas. do inico ao meio e o (meio+1) ao fim.
// ordenaramos esse vetor intercalando seus elementos
void intercala_1(int inicio, int meio, int fim, int* vetor) {
	int i, j, k;
	i = inicio;	// contador da primeira metade ordenada
	j = meio;	// contador da segunda metade ordenada
	k = 0;		// contador do vetor auxiliar
	int* aux = (int*) malloc(sizeof(int)*(fim-inicio));
	while(i < meio && j < fim) {		// enquanto não estivermos no fim de alguma das metades
		if(vetor[i] <= vetor[j]) aux[k++] = vetor[i++];
		else aux[k++] = vetor[j++];
	}
	while(i < meio) aux[k++] = vetor[i++];
	while(j < fim)	aux[k++] = vetor[j++];
	for(k=inicio ,i=0 ; k < fim ; k++, i++) vetor[k] = aux[i];
}

// intercala dois vetores disjuntos e ordenados. algoritmo iterativo
// recebe o tamanho do vetor 1, tamanho do vetor 2, vetor 1 e vetor 2, respectivamente.
// retorna um vetor ordenado;
int* intercala_2(int size_1, int size_2, int* v1, int* v2) {
	int i, j, k;
	i = j = k = 0;
	int* v3 = (int*) malloc(sizeof(int)*(size_1+size_2));
	while(i < size_1 && j < size_2) {
		if(v1[i] <= v2[j]) v3[k++] = v1[i++];
		else v3[k++] = v2[j++];
	}
	while(i < size_1) v3[k++] = v1[i++];
	while(j < size_2) v3[k++] = v2[j++];
	return v3;
}

void mergesort (int inicio, int fim, int v[]) {
   if (inicio < fim-1) {                 
      int meio = (inicio + fim)/2;          
      mergesort (inicio, meio, v);        
      mergesort (meio, fim, v);        
      intercala_1 (inicio, meio, fim, v);     
   }
}

int main() {
	int x = 0;
	int a[12] = {10,20,30,40,50,60, 1,2,3,4,5,6};
	mergesort(0,12,a);
	for(x=0;x<12;x++) printf("%i ",a[x]);
}
 
