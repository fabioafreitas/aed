/*
		Algoritmos e Estrutura de Dados
		Fábio Alves de Freitas
		14/07/2017
		EP2 - TREM BALA
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* estrutura que representa um ponto */
typedef struct {
	int x, y;
}Ponto;


/* estrutura que armazena um par de pontos, seus indices e a distancia entre eles */
typedef struct {
	int indice1, indice2;
	Ponto p1, p2;
	float dist;
}ParPontos;

static void intercala_indireto (int p, int q, int r, Ponto point[], int a[]) {
    int i, j, k;
    Ponto *w;
    w = (Ponto*) malloc ((r-p) * sizeof (Ponto));
    int* h = (int*) malloc ((r-p) * sizeof (int));
    
    i = p; j = q;
    k = 0;
	while (i < q && j < r) {
		if (point[i].x <= point[j].x) {
			h[k] = a[i];
			w[k++] = point[i++];	
		} 
        else  {
        	h[k] = a[j];
        	w[k++] = point[j++];
		}
    }
   	while (i < q) {
   		h[k] = a[i];
   		w[k++] = point[i++];
	}
   	while (j < r) {
   		h[k] = a[j];
		w[k++] = point[j++];
	}
	
    for (i = p; i < r; ++i) {
    	a[i] = h[i-p];
    	point[i] = w[i-p];
	}
	free(h);
    free (w);
}

void mergesort_indireto (int p, int r, Ponto point[], int a[]) {
	if (p < r-2) {
		int q = (p + r)/2;
        mergesort_indireto (p, q, point, a);
        mergesort_indireto (q, r, point, a);
        intercala_indireto (p, q, r, point, a);
	}
}
/* NÃO CONSEGUI IMPLEMENTAR A ORDENAÇÃO COM O MERGESORT */

void ordenacao_indireta (int n, Ponto p[], int a[]) {
	int i, j;
	for(i=0;i<n+1;i++) {
		for(j=i+1;j<n+1;j++) {
			if(p[i].y > p[j].y) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				Ponto aux = p[i];
				p[i] = p[j];
				p[j] = aux;
			}
		}
	}
}

/* tem a mesma utilidade do intercala de inteiros, mas nessa versão as validações são feitas
   com relação ao eixo X do array de pontos a fim de reordenar o array em ordem crescente. */

static void intercala (int p, int q, int r, Ponto point[]) {
    int i, j, k;
    Ponto *w;
    w = (Ponto*) malloc ((r-p) * sizeof (Ponto));
    i = p; j = q;
    k = 0;
	while (i < q && j < r) {
		if (point[i].x <= point[j].x)  w[k++] = point[i++];
        else  w[k++] = point[j++];
    }
   	while (i < q)
  	 	w[k++] = point[i++];
   	while (j < r)
		w[k++] = point[j++];
    for (i = p; i < r; ++i)
		point[i] = w[i-p];
    free (w);
}

/* mergesort obtido na página do prof. Feofiloff
 esta função foi alterada para ser adaptada a um array do tipo Ponto, que é uma estrutura. */

void mergesort (int p, int r, Ponto point[]) {
	if (p < r-2) {
		int q = (p + r)/2;
        mergesort (p, q, point);
        mergesort (q, r, point);
        intercala (p, q, r, point);
	}
}

/* calcula a distancia entre dois pontos, utilizando  o teorema de pitágoras. */

float distanciaPontos (Ponto esq, Ponto dir) {
	float a, b, c; 
	a = (esq.x-dir.x);
	b = (esq.y-dir.y);
	c = sqrt((a*a)+(b*b));
	return c;
}

/* é o caso base da função principal recursiva, na qual funciona com qualquer quantidade de pontos, porém
   como é utilizado apenas no caso base a quantidade de pontos sempre é dois ou três. */
ParPontos menorDistancia_Base (Ponto p[], int inicio, int final) {
	ParPontos teste;
	teste.indice1 = inicio;	teste.indice2 = final;
	teste.p1 = p[inicio];   teste.p2 = p[final];
	teste.dist = distanciaPontos(p[inicio], p[final]); 
	
	if(inicio+1 == final)  
		return teste;
	
	float a, b, min;
	a =  distanciaPontos(p[inicio], p[final-1]);
	b =  distanciaPontos(p[inicio+1], p[final]);
	min =  distanciaPontos(p[inicio], p[final]);
	
	if(min > a) {
		min = a;
		teste.indice1 = inicio;	teste.indice2 = final-1;
		teste.p1 = p[inicio];   teste.p2 = p[final-1];
		teste.dist = min; 
	}
	if(min > b) {
		min = b;
		teste.indice1 = inicio+1;	teste.indice2 = final;
		teste.p1 = p[inicio+1];   teste.p2 = p[final];
		teste.dist = min; 
	}
	return teste;
}

/* separa os pontos que se encontram dentro da fronteira (pontoMedio.x - min até pontoMedio.x + min)
   num outro array auxiliar e combina os pares para achar a distancia minima.
*/
ParPontos fronteira (Ponto p[], int a[], int inicio, int final, ParPontos min) {
	// seleção de candidatos
	int meio = (inicio+final)/2, i, k, j = 0;
	int frontE = p[meio].x - meio;
	int frontD = p[meio].x + meio;
	
	ParPontos candidatos[final+1];
	for( i=frontE ; i<=frontD ; i++) {
		if(p[i].x >= frontE && p[i].x <= frontD ) {
			candidatos[j].p1 = p[i];
			candidatos[j].indice1 = i;
			j++;
		}
			
	}
	
	// checar a distancia entre os pares dos candidatos
	float distFronteira; 
	ParPontos minFronteira;
	minFronteira.dist = min.dist;
	
	for( i=0 ; i < j ; i++ ) {
		int distVertical = candidatos[a[i]].p1.y + min.dist;
		
		// executa a quantidade de pontos do array candidatos, na qual pode existir um par cuja distancia seja menor que o min.dist
		for(k=i+1 ; (k < j) && (candidatos[a[k]].p1.y > distVertical) ; k++) {
			distFronteira = distanciaPontos(candidatos[a[i]].p1, candidatos[a[k]].p1);
			if(distFronteira < minFronteira.dist) {
				minFronteira.dist = distFronteira;
				minFronteira.p1 = candidatos[a[i]].p1;
				minFronteira.p2 = candidatos[a[j]].p1;
				minFronteira.indice1 = candidatos[a[i]].indice1;
				minFronteira.indice2 = candidatos[a[j]].indice1;
			}
		}
	}
	return minFronteira;
}


/*  função recursiva principal
	nesta função tem a divisão e conquista */

ParPontos menorDistancia_REC (Ponto p[], int a[], int inicio, int final) {
	// caso base, 2 ou 3 pontos
	if( (final-inicio) <= 3 ) {
		return menorDistancia_Base(p, inicio, final);
	}
	
	// divisão do array
	int meio = (inicio+final)/2;
	ParPontos dE = menorDistancia_REC (p, a, inicio,  meio);
	ParPontos dD = menorDistancia_REC (p, a, meio+1, final);
	ParPontos min;
	
	//minimo entre as distancias esquerda e direita.
	if(dE.dist < dD.dist) min = dE;
	else min = dD;
		
	// determina a fronteira.
	ParPontos f = fronteira(p, a, inicio, final, min);
	
	if(f.dist < min.dist)
		return f;
	return min;
}

// função principal, é a que deve ser chamada para resolver o problema

ParPontos menorDistancia (Ponto p[], int inicio, int final) {
	mergesort(0, final, p);
	int i;
	int a[final+1];
	for( i = 0 ; i <= final ; i++ ) {
		a[i] = i;
	}
	ordenacao_indireta (final+1, p, a);
	for( i = 0 ; i <= final ; i++ ) {
		printf("\nindice %i: x = %i, y = %i, a %i",i , p[i].x, p[i].y, a[i]);
	}
	return menorDistancia_REC(p, a, inicio, final);
}

// lê o arquivo de teste e passa as informações para um array

void lerArquivo (Ponto p[], int tam, FILE* arq) {
	int n = 0;
	while(n < tam) {
		fscanf(arq, "%d", &p[n].x);
		n++;
	}
	n = 0;
	while(n < tam) {
		if(n == 0) {
			fscanf(arq, "\n");
		}
		fscanf(arq, "%d", &p[n].y);
		n++;
	}
}

int main() {
	FILE* arq = fopen("trembala1.dat", "r");
	
	int tam, i;
	fscanf(arq, "%i", &tam);
	
	Ponto* p = (Ponto*) malloc(sizeof(Ponto)*tam);
	
	lerArquivo(p, tam, arq);

	ParPontos trembala = menorDistancia(p, 0, tam-1);
	
	printf("\n\ndistancia: %f\nindices: %i e %i", trembala.dist, trembala.indice1, trembala.indice2);
	printf("\ncoodenadas: (%i;%i) e (%i,%i)\n\n", trembala.p1.x, trembala.p1.y, trembala.p2.x, trembala.p2.y);
	
	fclose(arq);	
	free(p);
}
