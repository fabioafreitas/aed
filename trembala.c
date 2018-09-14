#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct par {
	int x,y;
}Ponto;

Ponto* readFile(int* lenght) {
	FILE* arq = fopen("trembala1.dat", "r");
	int size, i = 0;
	fscanf(arq, "%i", &size);
	Ponto* pontos = (Ponto*) malloc(sizeof(Ponto)*size); 
	while(i < size) fscanf(arq, "%i", &pontos[i++].x);
	i = 0;
	while(!feof(arq)) fscanf(arq, "%i", &pontos[i++].y);
	fclose(arq);
	*lenght = size;
	return pontos;
}

void intercala_eixo_X(int inicio, int meio, int fim, Ponto* vetor) {
	int i, j, k;
	i = inicio;	// contador da primeira metade ordenada
	j = meio;	// contador da segunda metade ordenada
	k = 0;		// contador do vetor auxiliar
	Ponto* aux = (Ponto*) malloc(sizeof(Ponto)*(fim-inicio));
	while(i < meio && j < fim) {		// enquanto não estivermos no fim de alguma das metades
		if(vetor[i].x <= vetor[j].x) aux[k++] = vetor[i++];
		else aux[k++] = vetor[j++];
	}
	while(i < meio) aux[k++] = vetor[i++];
	while(j < fim)	aux[k++] = vetor[j++];
	for(k=inicio ,i=0 ; k < fim ; k++, i++) vetor[k] = aux[i];
}

void intercala_eixo_Y(int inicio, int meio, int fim, Ponto* vetor) {
	int i, j, k;
	i = inicio;	// contador da primeira metade ordenada
	j = meio;	// contador da segunda metade ordenada
	k = 0;		// contador do vetor auxiliar
	Ponto* aux = (Ponto*) malloc(sizeof(Ponto)*(fim-inicio));
	while(i < meio && j < fim) {		// enquanto não estivermos no fim de alguma das metades
		if(vetor[i].y <= vetor[j].y) aux[k++] = vetor[i++];
		else aux[k++] = vetor[j++];
	}
	while(i < meio) aux[k++] = vetor[i++];
	while(j < fim)	aux[k++] = vetor[j++];
	for(k=inicio ,i=0 ; k < fim ; k++, i++) vetor[k] = aux[i];
}

void mergesort_eixo_X (int inicio, int fim, Ponto v[]) {
   if (inicio < fim-1) {                 
      int meio = (inicio + fim)/2;          
      mergesort_eixo_X (inicio, meio, v);        
      mergesort_eixo_X (meio, fim, v);        
      intercala_eixo_X (inicio, meio, fim, v);     
   }
}

void mergesort_eixo_Y (int inicio, int fim, Ponto v[]) {
   if (inicio < fim-1) {                 
      int meio = (inicio + fim)/2;          
      mergesort_eixo_Y (inicio, meio, v);        
      mergesort_eixo_Y (meio, fim, v);        
      intercala_eixo_Y (inicio, meio, fim, v);     
   }
}

float distEuclidiana(Ponto a, Ponto b) {
	return sqrt( pow(a.x-b.x,2) + pow(a.y-b.y,2) );
}

// indice inicio, indice final+1, dist min, pontos mais proximos, todos os pontos.
void fronteira(int inicio, int fim, float min_dist, Ponto* min, Ponto* pontos) {
	float centro = pontos[fim-1].x/2, min_dist_front;
	Ponto* front =  (Ponto*) malloc(sizeof(Ponto)*(fim-inicio));
	Ponto* min_front = (Ponto*) malloc(sizeof(Ponto)*2);
	int i, j, k;
	for( i=inicio, k=0 ; i<fim ; i++ ) {	// separando os pontos que estão na fronteira
		if(pontos[i].x >= (centro-min_dist) && pontos[i].x <= (centro+min_dist)) 
			front[k++] = pontos[i];
	}
	mergesort_eixo_Y(0, k, front);
	for(i=0 ; i<k ; i++) {
		for(j=i+1 ; j<k ; j++) {
			if((front[j].y - front[i].y) <= min_dist) {
				min_dist_front = distEuclidiana(front[i], front[j]);
				if(min_dist_front < min_dist) {
					min_dist = min_dist_front;
					min[0] = front[i];
					min[1] = front[j];
				}
			}
		}
	}
}

Ponto* distanciaMinima(int inicio, int fim, Ponto* pontos) {
	if(fim <= inicio+3) {
		int i, j;
		float min_dist = INT_MAX, aux;
		Ponto* par = (Ponto*) malloc(sizeof(Ponto)*2);
		for( i=inicio ; i<fim ; i++ ) {
			for( j=i+1 ; j<fim ; j++) {
				aux = distEuclidiana(pontos[i],pontos[j]);
				if(aux < min_dist) {
					min_dist = aux;
					par[0] = pontos[i];
					par[1] = pontos[j];
				}
			}
		}	
		return par;
	}
	else {
		int meio = (inicio+fim)/2; 
		Ponto *esq, *dir, *min, *aux;
		min = (Ponto*) malloc(sizeof(Ponto)*2);
		esq = distanciaMinima(inicio, meio, pontos);
		dir = distanciaMinima(meio, fim, pontos);
		float dist_esq = distEuclidiana(esq[0], esq[1]);
		float dist_dir = distEuclidiana(dir[0], dir[1]);
		float min_dist;
		
		if(dist_dir < dist_esq) {
			min_dist = dist_dir;
			min[0] = dir[0];
			min[1] = dir[1];
		}
		else {
			min_dist = dist_esq;
			min[0] = esq[0];
			min[1] = esq[1];
		}
		
		fronteira(inicio, fim, min_dist, min, pontos);
		
		return min;
	}
}

Ponto* trembala(Ponto* pontos, int lenght) {
	mergesort_eixo_X(0, lenght, pontos);
	return distanciaMinima(0, lenght, pontos);
}

int main() {
	int lenght;
	Ponto* pontos = readFile(&lenght);
	Ponto* min = trembala(pontos, lenght);
	printf("par: (%i,%i) (%i,%i)\tdistancia: %f",min[0].x,min[0].y,min[1].x,min[1].y,distEuclidiana(min[0],min[1]));
}



