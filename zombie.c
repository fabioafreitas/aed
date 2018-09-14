#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>

// proporções do tabuleiro
#define LINHA 	20
#define COLUNA 	30

// quantidades
#define	H_CARS 	20
#define V_CARS 	20
#define TREES 	0
#define MUNICAO 5 
#define ZUMBIS 	15
#define DISPAROS 1 // quantidade que uma munição recarrega

// caracteres
#define CHAR_WALL		219
#define CHAR_H_CAR 		176
#define CHAR_V_CAR 		178
#define CHAR_TREE 		'@'  // @
#define CHAR_MUNICAO 	'm'  // M 
#define CHAR_ZUMBI 		'Z'  // Z
#define CHAR_RICK 		'R'  // R
#define CHAR_EXIT		'#'  // #

typedef struct num{
	int coord_x, coord_y, num_municao, num_zumbis;
}Dados;

void preencher_tabuleiro(char tabuleiro[][COLUNA]) {
	int i,j;
	for(i=0;i<LINHA;i++) {
		for(j=0;j<COLUNA;j++) {
			if(i == 0 || j == 0 || i == (LINHA-1) || j == (COLUNA-1)) tabuleiro[i][j] = CHAR_WALL;
			else tabuleiro[i][j] = ' ';
		}
	}
}

void imprimir_tabuleiro(char tabuleiro[][COLUNA], Dados data) {
	int i,j;
	for(i=0;i<LINHA;i++) {
		for(j=0;j<COLUNA;j++)
			printf("%c",tabuleiro[i][j]);
		printf("\n");
	}
	printf("MUNICAO = %i	ZUMBIS = %i\n",data.num_municao, data.num_zumbis);
}

Dados posicionar_obstaculos(char tabuleiro[][COLUNA]) {
	int i,j,k;
	Dados data;
	// carros - 5 na horizontal
	k = 0;
	while(k < H_CARS) {
		i = (1 + rand()%( LINHA-3 ));
		j = (1 + rand()%( COLUNA-4 ));
		if(tabuleiro[i][j] == ' ' && tabuleiro[i][j+1] == ' ') {
			tabuleiro[i][j] = CHAR_H_CAR;
			tabuleiro[i][j+1] = CHAR_H_CAR;
			k++;
		}
	}
	// carros - 5 na vertical
	k = 0;
	while(k < V_CARS) {
		i = (1 + rand()%( LINHA-4 ));
		j = (1 + rand()%( COLUNA-3 ));
		if(tabuleiro[i][j] == ' ' && tabuleiro[i+1][j] == ' ') {
			tabuleiro[i][j] = CHAR_V_CAR;
			tabuleiro[i+1][j] = CHAR_V_CAR;
			k++;
		}
	}
	// árvores
	k = 0;
	while(k < TREES) {
		i = (1 + rand()%( LINHA-3 ));
		j = (1 + rand()%( COLUNA-3 ));
		if(tabuleiro[i][j] == ' ') {
			tabuleiro[i][j] = CHAR_TREE;
			k++;
		}
	}
	// munição
	k = 0;
	while(k < MUNICAO) {
		i = (1 + rand()%( LINHA-3 ));
		j = (1 + rand()%( COLUNA-3 ));
		if(tabuleiro[i][j] == ' ') {
			tabuleiro[i][j] = CHAR_MUNICAO;
			k++;
			data.num_municao = MUNICAO;
		}
	}
	// zumbis
	k = 0;
	while(k < ZUMBIS) {
		i = (1 + rand()%( LINHA-3 ));
		j = (1 + rand()%( COLUNA-3 ));
		if(tabuleiro[i][j] == ' ') {
			tabuleiro[i][j] = CHAR_ZUMBI;
			k++;
			data.num_zumbis = ZUMBIS;
		}
	}
	// saída
	k = 0;
	while(k < 1) {
		i = (1 + rand()%( LINHA-3 ));
		j = (1 + rand()%( COLUNA-3 ));
		if(tabuleiro[i][j] == ' ') {
			tabuleiro[i][j] = CHAR_EXIT;
			k++;
		}
	}
	// rick
	k = 0;
	while(k < 1) {
		i = (1 + rand()%( LINHA-3 ));
		j = (1 + rand()%( COLUNA-3 ));
		if(tabuleiro[i][j] == ' ') {
			tabuleiro[i][j] = CHAR_RICK;
			k++;
			data.coord_x = i;
			data.coord_y = j;
		}
	}
	return data;
}

void game(char tabuleiro[][COLUNA], Dados data) {
	int game_over = 0, i, j, disparos = DISPAROS;
	i = data.coord_x;
	j = data.coord_y;
	char c;
	while(!game_over) { // game loop
	
		// disparos do rick e condição de derrota
		int x,y,z = 0;
		for(x=(i-1) ; x<=(i+1) ; x++) {
			for(y=(j-1) ; y<=(j+1) ; y++) {
				if(z++ != 4) {
					if(tabuleiro[x][y] == CHAR_ZUMBI) {
						if(data.num_municao == 0) {
							game_over = 1;
							goto exit;
						}
						else {
							data.num_municao--;
							data.num_zumbis--;
							tabuleiro[x][y] = ' ';
						}
					}
				}
			}
		}
		exit:;
	
		// movimentação do rick
		c = getch();
		switch(c) {
			case 'w':
			case 'W': 
				c = tabuleiro[i-1][j];
				if(c == ' ' || c == CHAR_MUNICAO) {
					if(c == CHAR_MUNICAO) data.num_municao += disparos;
					tabuleiro[i][j] = ' ';
					tabuleiro[--i][j] = CHAR_RICK;
				}
				if(c == CHAR_EXIT) game_over = 2;
				break;
			case 'a':
			case 'A':
				c = tabuleiro[i][j-1];
				if(c == ' ' || c == CHAR_MUNICAO) {
					if(c == CHAR_MUNICAO) data.num_municao += disparos;
					tabuleiro[i][j] = ' ';
					tabuleiro[i][--j] = CHAR_RICK;
				}
				if(c == CHAR_EXIT) game_over = 2;
				break;
			case 's':
			case 'S':
				c = tabuleiro[i+1][j];
				if(c == ' ' || c == CHAR_MUNICAO) {
					if(c == CHAR_MUNICAO) data.num_municao += disparos;
					tabuleiro[i][j] = ' ';
					tabuleiro[++i][j] = CHAR_RICK;
				}
				if(c == CHAR_EXIT) game_over = 2;
				break;
			case 'd':
			case 'D':
				c = tabuleiro[i][j+1];
				if(c == ' ' || c == CHAR_MUNICAO) {
					if(c == CHAR_MUNICAO) data.num_municao += disparos;
					tabuleiro[i][j] = ' ';
					tabuleiro[i][++j] = CHAR_RICK;
				}
				if(c == CHAR_EXIT) game_over = 2;
				break;
		}
		system("cls");
		imprimir_tabuleiro(tabuleiro, data);
		if(game_over == 2) printf("\nVOCE VENCEU\n");
		if(game_over == 1) printf("\nVOCE PERDEU\n");
	}
}

int main() {
	srand(time(NULL));
	char tabuleiro[LINHA][COLUNA];
	preencher_tabuleiro(tabuleiro);
	Dados data = posicionar_obstaculos(tabuleiro);
	imprimir_tabuleiro(tabuleiro, data);
	game(tabuleiro, data);
}
