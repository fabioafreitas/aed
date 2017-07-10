#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int x;
	int y;	
}Ponto;

// par de indices mais proximos
typedef struct {
	int a;
	int b;
}Par;

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

static void intercalaIndireto (int p, int q, int r, Ponto point[]) {
	int i, j, k;
    Ponto *w;
    w = (Ponto*) malloc ((r-p) * sizeof (Ponto));
    i = p; j = q;
    k = 0;
	while (i < q && j < r) {
		if (point[i].y <= point[j].y)  w[k++] = point[i++];
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

// Ordena o o array pelo eixo X
void mergesort (int p, int r, Ponto point[]) {
	if (p < r-2) {
		int q = (p + r)/2;
        mergesort (p, q, point);
        mergesort (q, r, point);
        intercala (p, q, r, point);
	}
}

// Ordena o o array pelo eixo Y
void mergesortIndireto (int p, int r, Ponto point[]) {
	if (p < r-2) {
		int q = (p + r)/2;
        mergesort (p, q, point);
        mergesort (q, r, point);
        intercala (p, q, r, point);
	}
}
// Lê o arquivo que contém as cidades
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

// calcula a distancia de um par de pontos
float distancia (Ponto a, Ponto b) {
	float n,m; 
	n = b.x - a.x;
	m = b.y-a.y;

	return sqrt(n*n + m*m);
}

// recebe um array de pontos e retorna o par mais proximo
// checar se funciona
Par minDistBruto (Ponto p[], int i, int f) {
	int n,m;
	Par par;
	par.a = i;
	par.b = i+1;
	float min = distancia(p[i],p[i+1]);
	for(n = i ; n < f ; n++ ) {
		for( m = n+1 ; m < f ; m++ ) {
			if(distancia(p[n],p[m]) < min) {
				min = distancia(p[n],p[m]);
				par.a = n;
				par.b = m;
			}
		}
	}
	return par;
}

// Calcula a distancia entre todos os pontos e retorna o par com distancia mínima
Par minDist (Ponto p[], int tam) {
	if(tam <= 3)
		return minDistBruto(p, 0, tam);
		
	// falta implementar o resto
}

int main() {
	int t, num;
	FILE* arq = fopen("trembala.dat","r");
	
	// Lê o número de cidades
	fscanf(arq, "%i", &num);
	Ponto p[num];
	// função que lê o arquivo
	lerArquivo(p, num, arq);
	fclose(arq);

	mergesort(0, num, p);
	
	//Par oi = minDist(p, num);
	
//	printf("\n\nindices mais proximos: %i, %i %i\n\n", oi.a, oi.b, num);
//	for(t = 0;t<num;t++) {
//		printf("x %i, y %i\n", p[t].x, p[t].y);
//	}
}







