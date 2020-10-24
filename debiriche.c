//////////////////////////////////////////////////////////
//														//
//														//
//		    	DEBIRICHE 1.0 , 23/07/2016 				//
//														//
//														//
//			Fábio Alves de Freitas , for fun :p			//
//														//
//				  1º periodo BCC UFRPE                  //
//														//
//			  							 			    //
//														//
//														//		
//														//				
//////////////////////////////////////////////////////////



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char checar_local(char a, char jogada, int* turn)
{
	a = jogada;
	if( a == ' ' )
	{
		if(*turn==1)
		{
			*turn=2;
		}
		else if((*turn)==2)
		{
			*turn=1;
		}
	}
	else 
	{
		if(*turn==1)
		{
			*turn = 1;
		}
		else
		{
			*turn = 2;
		}
	}
	return a;
}

void fechar()
{
	system("cls");
	printf("\n\n\n\n\n\n\n\t\t\tFECHANDO 1%%\n\n\n\n");
	usleep(200000);
	system("cls");
	printf("\n\n\n\n\n\n\n\t\t\tFECHANDO 5%%\n\n\n\n");
	usleep(200000);
	system("cls");
	printf("\n\n\n\n\n\n\n\t\t\tFECHANDO 23%%\n\n\n\n");
	usleep(200000);
	system("cls");
	printf("\n\n\n\n\n\n\n\t\t\tFECHANDO 72%%\n\n\n\n");
	usleep(200000);
	system("cls");
	printf("\n\n\n\n\n\n\n\t\t\tFECHANDO 95%%\n\n\n\n");
	usleep(200000);
	system("cls");
	printf("\n\n\n\n\n\n\n\t\t\tFECHANDO 100%%\n\n\n\n");
	usleep(200000);
}

void instrucoes()
{
	char matriz[13][13];
	char a=205,b=186;
	int l,j,aux=1,linha=7;
	for(l=0;l<13;l++)
	{
		for(j=0;j<13;j++)
		{
			 if(l%2==0&&j%2==0)
			 {
			 	matriz[l][j] = 'O';
			 }
			 else
			 {
			 	matriz[l][j] = ' ';
			 }
		}
	}
	system("cls");
	printf("\n\n\t\t\tGUIA");
	printf("\n\n\t\tTurno de jogo onde o jogador deve desenhar\n\t\tuma  linha  para  conectar  dois  pontos,");
	printf("\n\t\thorizontalmente    ou    verticalmente.\n\n\t\tSe o jogador forma um quadrado com linhas,");
	printf("\n\t\tele ganha um ponto, e voce pode criar uma\n\t\toutra linha.\n\n\t\tGANHA Quem Desenha mais quadrados.");
	printf("\n\n\n");
	printf("\n\n\t\t\tTABULEIRO\n\n");
	for(l=0;l<13;l++)
	{
		if(l%2==0)
		{
			printf("\n\t\t\t%i %c%c  ",linha,a,a);
			linha--;
		}
		else
		{
			printf("\n\t\t\t  ");
		}
		for(j=0;j<13;j++)
		{
			 printf("%c",matriz[l][j]);
		}
	}
	printf("\n\n\t\t\t      ");
	for(l=1;l<8;l++)
	{
		printf("%c ",b);
	}
	printf("\n\n\t\t\t      ");
	for(l=1;l<8;l++)
	{
		printf("%i ",l);
	}
	printf("\n\n");
	printf("\n\n\n");
	printf("\n\n\t\tDigite as coordenadas dos dois pontos\n\t\tque representam a linha desejada!\n\n\n\t\tpara desenhar uma linha imagine o tabuleiro como\n\t\tuma batalha naval.");
	printf(" Sendo assim digite os dois \n\t\tpontos q representam uma linha e o local entre \n\t\tessas duas coordenadas sera \n\t\tpreenchido com a linha!\n");
	printf("\t\tnao eh permitido criar uma linha com dimensao\n\t\tmaior que duasunidades, pois esta sera considerada\n\t\tinvalida !!!\n\n");
	printf("\t\tOBS: ao selecionar a coordenada lembre-se de digitar\n\t\tuma linha ,'-', entre os numeros como no exemplo abaixo !!!\n\n");
	printf("\t\tEX: Coordenada X (1-1) , e Coordenada Y (1-2)\n\n");
	linha=7;
	matriz[11][0]='|';
	for(l=0;l<13;l++)
	{
		if(l%2==0)
		{
			printf("\n\t\t\t%i %c%c  ",linha,a,a);
			linha--;
		}
		else
		{
			printf("\n\t\t\t      ");
		}
		for(j=0;j<13;j++)
		{
			 printf("%c",matriz[l][j]);
		}
	}
	printf("\n\n\t\t\t      ");
	for(l=1;l<8;l++)
	{
		printf("%c ",b);
	}
	printf("\n\n\t\t\t      ");
	for(l=1;l<8;l++)
	{
		printf("%i ",l);
	}
	printf("\n\n");
	system("pause");
}

void jogar()
{
	int turn = rand()%2+1;
	int l, j ,linha=7 ,x ,y ,x2 ,y2;
	int pontos_1=0,pontos_2=0;
	char a=205, b=186, m[13][13], aux;
	for(l=0;l<13;l++)
	{
		for(j=0;j<13;j++)
		{
			 if(l%2==0&&j%2==0)
			 {
			 	m[l][j] = 'O';
			 }
			 else
			 {
			 	m[l][j] = ' ';
			 }
		}
	}
	while(1)
	{
		if(turn == 1)
		{
			linha=7;
			turn = 2;
			system("cls");
			printf("\n\n\t\t\tPRIMEIRO JOGADOR\n\n\n");
			printf("\t\t\tJOGADOR 1 = %i  PONTOS\n\n\t\t\tJOGADOR 2 = %i  PONTOS\n\n",pontos_1,pontos_2);
			for(l=0;l<13;l++)
			{
				if(l%2==0)
				{
					printf("\n\t\t\t%i %c%c  ",linha,a,a);
					linha--;
				}
				else
				{
					printf("\n\t\t\t      ");
				}
				for(j=0;j<13;j++)
				{
					printf("%c",m[l][j]);
				}
			}
			printf("\n\n\t\t\t      ");
			for(l=1;l<8;l++)
			{
				printf("%c ",b);
			}
			printf("\n\n\t\t\t      ");
			for(l=1;l<8;l++)
			{
				printf("%i ",l);
			}
			printf("\n\n");
			printf("\t\tCoordenada X: ");
			scanf("%i-%i",&x,&y);
			fflush(stdin);
			printf("\t\tCoordenada y: ");
			scanf("%i-%i",&x2,&y2);
			fflush(stdin);

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  LINHA        1        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											if( ( x==1 && y==1 && x2==2 && y2==1 ) || ( x==2 && y==1 && x2==1 && y2==1 ) )
											{
												if( m[ 12 ][ 1 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 12 ][ 1 ] = checar_local(m[ 12 ][ 1 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==1 && x2==3 && y2==1 ) || ( x==3 && y==1 && x2==2 && y2==1 ) )
											{
												if( m[ 12 ][ 3 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 12 ][ 3 ] = checar_local(m[ 12 ][ 3 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==1 && x2==4 && y2==1 ) || ( x==4 && y==1 && x2==3 && y2==1 ) )
											{
												if( m[ 12 ][ 5 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 12 ][ 5 ] = checar_local(m[ 12 ][ 5 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==1 && x2==5 && y2==1 ) || ( x==5 && y==1 && x2==4 && y2==1 ) )
											{
												if( m[ 12 ][ 7 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 12 ][ 7 ] = checar_local(m[ 12 ][ 7 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==1 && x2==6 && y2==1 ) || ( x==6 && y==1 && x2==5 && y2==1 ) )
											{
												if( m[ 12 ][ 9 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 12 ][ 9 ] = checar_local(m[ 12 ][ 9 ] ,aux ,&turn);
												}
											}
											else if( ( x==7 && y==1 && x2==6 && y2==1 ) || ( x==6 && y==1 && x2==7 && y2==1 ) )
											{
												if( m[ 12 ][ 11 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 12 ][ 11 ] = checar_local(m[ 12 ][ 11 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  LINHA        2        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==1 && y==2 && x2==2 && y2==2 ) || ( x==2 && y==2 && x2==1 && y2==2 ) )
											{
												if( m[ 10 ][ 1 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 10 ][ 1 ] = checar_local(m[ 10 ][ 1 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==2 && x2==3 && y2==2 ) || ( x==3 && y==2 && x2==2 && y2==2 ) )
											{
												if( m[ 10 ][ 3 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 10 ][ 3 ] = checar_local(m[ 10 ][ 3 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==2 && x2==4 && y2==2 ) || ( x==4 && y==2 && x2==3 && y2==2 ) )
											{
												if( m[ 10 ][ 5 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 10 ][ 5 ] = checar_local(m[ 10 ][ 5 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==2 && x2==5 && y2==2 ) || ( x==5 && y==2 && x2==4 && y2==2 ) )
											{
												if( m[ 10 ][ 7 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 10 ][ 7 ] = checar_local(m[ 10 ][ 7 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==2 && x2==6 && y2==2 ) || ( x==6 && y==2 && x2==5 && y2==2 ) )
											{
												if( m[ 10 ][ 9 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 10 ][ 9 ] = checar_local(m[ 10 ][ 9 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==2 && x2==7 && y2==2 ) || ( x==7 && y==2 && x2==6 && y2==2 ) )
											{
												if( m[ 10 ][ 11 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 10 ][ 11 ] = checar_local(m[ 10 ][ 11 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  LINHA        3        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==1 && y==3 && x2==2 && y2==3 ) || ( x==2 && y==3 && x2==1 && y2==3 ) )
											{
												if( m[ 8 ][ 1 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 8 ][ 1 ] = checar_local(m[ 8 ][ 1 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==3 && x2==3 && y2==3 ) || ( x==3 && y==3 && x2==2 && y2==3 ) )
											{
												if( m[ 8 ][ 3 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 8 ][ 3 ] = checar_local(m[ 8 ][ 3 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==3 && x2==4 && y2==3 ) || ( x==4 && y==3 && x2==3 && y2==3 ) )
											{
												if( m[ 8 ][ 5 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 8 ][ 5 ] = checar_local(m[ 8 ][ 5 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==3 && x2==5 && y2==3 ) || ( x==5 && y==3 && x2==4 && y2==3 ) )
											{
												if( m[ 8 ][ 7 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 8 ][ 7 ] = checar_local(m[ 8 ][ 7 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==3 && x2==6 && y2==3 ) || ( x==6 && y==3 && x2==5 && y2==3 ) )
											{
												if( m[ 8 ][ 9 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 8 ][ 9 ] = checar_local(m[ 8 ][ 9 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==3 && x2==7 && y2==3 ) || ( x==7 && y==3 && x2==6 && y2==3 ) )
											{
												if( m[ 8 ][ 11 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 8 ][ 11 ] = checar_local(m[ 8 ][ 11 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  LINHA        4        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==1 && y==4 && x2==2 && y2==4 ) || ( x==2 && y==4 && x2==1 && y2==4 ) )
											{
												if( m[ 6 ][ 1 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 6 ][ 1 ] = checar_local(m[ 6 ][ 1 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==4 && x2==3 && y2==4 ) || ( x==3 && y==4 && x2==2 && y2==4 ) )
											{
												if( m[ 6 ][ 3 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 6 ][ 3 ] = checar_local(m[ 6 ][ 3 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==4 && x2==4 && y2==4 ) || ( x==4 && y==4 && x2==3 && y2==4 ) )
											{
												if( m[ 6 ][ 5 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 6 ][ 5 ] = checar_local(m[ 6 ][ 5 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==4 && x2==5 && y2==4 ) || ( x==5 && y==4 && x2==4 && y2==4 ) )
											{
												if( m[ 6 ][ 7 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 6 ][ 7 ] = checar_local(m[ 6 ][ 7 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==4 && x2==6 && y2==4 ) || ( x==6 && y==4 && x2==5 && y2==4 ) )
											{
												if( m[ 6 ][ 9 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 6 ][ 9 ] = checar_local(m[ 6 ][ 9 ] ,aux ,&turn);
												}
											}
											else if( ( x==7 && y==4 && x2==6 && y2==4 ) || ( x==6 && y==4 && x2==7 && y2==4 ) )
											{
												if( m[ 6 ][ 11 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 6 ][ 11 ] = checar_local(m[ 6 ][ 11 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  LINHA        5        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==1 && y==5 && x2==2 && y2==5 ) || ( x==2 && y==5 && x2==1 && y2==5 ) )
											{
												if( m[ 4 ][ 1 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 4 ][ 1 ] = checar_local(m[ 4 ][ 1 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==5 && x2==3 && y2==5 ) || ( x==3 && y==5 && x2==2 && y2==5 ) )
											{
												if( m[ 4 ][ 3 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 4 ][ 3 ] = checar_local(m[ 4 ][ 3 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==5 && x2==4 && y2==5 ) || ( x==4 && y==5 && x2==3 && y2==5 ) )
											{
												if( m[ 4 ][ 5 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 4 ][ 5 ] = checar_local(m[ 4 ][ 5 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==5 && x2==5 && y2==5 ) || ( x==5 && y==5 && x2==4 && y2==5 ) )
											{
												if( m[ 4 ][ 7 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 4 ][ 7 ] = checar_local(m[ 4 ][ 7 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==5 && x2==6 && y2==5 ) || ( x==6 && y==5 && x2==5 && y2==5 ) )
											{
												if( m[ 4 ][ 9 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 4 ][ 9 ] = checar_local(m[ 4 ][ 9 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==5 && x2==7 && y2==5 ) || ( x==7 && y==5 && x2==6 && y2==5 ) )
											{
												if( m[ 4 ][ 11 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 4 ][ 11 ] = checar_local(m[ 4 ][ 11 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  LINHA        6        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==1 && y==6 && x2==2 && y2==6 ) || ( x==2 && y==6 && x2==1 && y2==6 ) )
											{
												if( m[ 2 ][ 1 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 2 ][ 1 ] = checar_local(m[ 2 ][ 1 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==6 && x2==3 && y2==6 ) || ( x==3 && y==6 && x2==2 && y2==6 ) )
											{
												if( m[ 2 ][ 3 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 2 ][ 3 ] = checar_local(m[ 2 ][ 3 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==6 && x2==4 && y2==6 ) || ( x==4 && y==6 && x2==3 && y2==6 ) )
											{
												if( m[ 2 ][ 5 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 2 ][ 5 ] = checar_local(m[ 2 ][ 5 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==6 && x2==5 && y2==6 ) || ( x==5 && y==6 && x2==4 && y2==6 ) )
											{
												if( m[ 2 ][ 7 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 2 ][ 7 ] = checar_local(m[ 2 ][ 7 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==6 && x2==6 && y2==6 ) || ( x==6 && y==6 && x2==5 && y2==6 ) )
											{
												if( m[ 2 ][ 9 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 2 ][ 9 ] = checar_local(m[ 2 ][ 9 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==6 && x2==7 && y2==6 ) || ( x==7 && y==6 && x2==6 && y2==6 ) )
											{
												if( m[ 2 ][ 11 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 2 ][ 11 ] = checar_local(m[ 2 ][ 11 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  LINHA        7        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==1 && y==7 && x2==2 && y2==7 ) || ( x==2 && y==7 && x2==1 && y2==7 ) )
											{
												if( m[ 0 ][ 1 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 0 ][ 1 ] = checar_local(m[ 0 ][ 1 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==7 && x2==3 && y2==7 ) || ( x==3 && y==7 && x2==2 && y2==7 ) )
											{
												if( m[ 0 ][ 3 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 0 ][ 3 ] = checar_local(m[ 0 ][ 3 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==7 && x2==4 && y2==7 ) || ( x==4 && y==7 && x2==3 && y2==7 ) )
											{
												if( m[ 0 ][ 5 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 0 ][ 5 ] = checar_local(m[ 0 ][ 5 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==7 && x2==5 && y2==7 ) || ( x==5 && y==7 && x2==4 && y2==7 ) )
											{
												if( m[ 0 ][ 7 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 0 ][ 7 ] = checar_local(m[ 0 ][ 7 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==7 && x2==6 && y2==7 ) || ( x==6 && y==7 && x2==5 && y2==7 ) )
											{
												if( m[ 0 ][ 9 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 0 ][ 9 ] = checar_local(m[ 0 ][ 9 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==7 && x2==7 && y2==7 ) || ( x==7 && y==7 && x2==6 && y2==7 ) )
											{
												if( m[ 0 ][ 11 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 0 ][ 11 ] = checar_local(m[ 0 ][ 11 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  COLUNA       1        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==1 && y==1 && x2==1 && y2==2 ) || ( x==1 && y==2 && x2==1 && y2==1 ) )
											{
												if( m[ 11 ][ 0 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 11 ][ 0 ] = checar_local(m[ 11 ][ 0 ] ,aux ,&turn);
												}
											}
											else if( ( x==1 && y==2 && x2==1 && y2==3 ) || ( x==1 && y==3 && x2==1 && y2==2 ) )
											{
												if( m[ 9 ][ 0 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 9 ][ 0 ] = checar_local(m[ 9 ][ 0 ] ,aux ,&turn);
												}
											}
											else if( ( x==1 && y==3 && x2==1 && y2==4 ) || ( x==1 && y==4 && x2==1 && y2==3 ) )
											{
												if( m[ 7 ][ 0 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 7 ][ 0 ] = checar_local(m[ 7 ][ 0 ] ,aux ,&turn);
												}
											}
											else if( ( x==1 && y==5 && x2==1 && y2==4 ) || ( x==1 && y==4 && x2==1 && y2==5 ) )
											{
												if( m[ 5 ][ 0 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 5 ][ 0 ] = checar_local(m[ 5 ][ 0 ] ,aux ,&turn);
												}
											}
											else if( ( x==1 && y==5 && x2==1 && y2==6 ) || ( x==1 && y==6 && x2==1 && y2==5 ) )
											{
												if( m[ 3 ][ 0 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 3 ][ 0 ] = checar_local(m[ 3 ][ 0 ] ,aux ,&turn);
												}
											}
											else if( ( x==1 && y==6 && x2==1 && y2==7 ) || ( x==1 && y==7 && x2==1 && y2==6 ) )
											{
												if( m[ 1 ][ 0 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 1 ][ 0 ] = checar_local(m[ 1 ][ 0 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  COLUNA       2        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==2 && y==1 && x2==2 && y2==2 ) || ( x==2 && y==2 && x2==2 && y2==1 ) )
											{
												if( m[ 11 ][ 2 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 11 ][ 2 ] = checar_local(m[ 11 ][ 2 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==2 && x2==2 && y2==3 ) || ( x==2 && y==3 && x2==2 && y2==2 ) )
											{
												if( m[ 9 ][ 2 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 9 ][ 2 ] = checar_local(m[ 9 ][ 2 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==3 && x2==2 && y2==4 ) || ( x==2 && y==4 && x2==2 && y2==3 ) )
											{
												if( m[ 7 ][ 2 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 7 ][ 2 ] = checar_local(m[ 7 ][ 2 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==5 && x2==2 && y2==4 ) || ( x==2 && y==4 && x2==2 && y2==5 ) )
											{
												if( m[ 5 ][ 2 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 5 ][ 2 ] = checar_local(m[ 5 ][ 2 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==5 && x2==2 && y2==6 ) || ( x==2 && y==6 && x2==2 && y2==5 ) )
											{
												if( m[ 3 ][ 2 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 3 ][ 2 ] = checar_local(m[ 3 ][ 2 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==6 && x2==2 && y2==7 ) || ( x==2 && y==7 && x2==2 && y2==6 ) )
											{
												if( m[ 1 ][ 2 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 1 ][ 2 ] = checar_local(m[ 1 ][ 2 ] ,aux ,&turn);
												}
											}	
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  COLUNA       3        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==3 && y==1 && x2==3 && y2==2 ) || ( x==3 && y==2 && x2==3 && y2==1 ) )
											{
												if( m[ 11 ][ 4 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 11 ][ 4 ] = checar_local(m[ 11 ][ 4 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==2 && x2==3 && y2==3 ) || ( x==3 && y==3 && x2==3 && y2==2 ) )
											{
												if( m[ 9 ][ 4 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 9 ][ 4 ] = checar_local(m[ 9 ][ 4 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==3 && x2==3 && y2==4 ) || ( x==3 && y==4 && x2==3 && y2==3 ) )
											{
												if( m[ 7 ][ 4 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 7 ][ 4 ] = checar_local(m[ 7 ][ 4 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==4 && x2==3 && y2==5 ) || ( x==3 && y==5 && x2==3 && y2==4 ) )
											{
												if( m[ 5 ][ 4 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 5 ][ 4 ] = checar_local(m[ 5 ][ 4 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==5 && x2==3 && y2==6 ) || ( x==3 && y==6 && x2==3 && y2==5 ) )
											{
												if( m[ 3 ][ 4 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 3 ][ 4 ] = checar_local(m[ 3 ][ 4 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==6 && x2==3 && y2==7 ) || ( x==3 && y==7 && x2==3 && y2==6 ) )
											{
												if( m[ 1 ][ 4 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 1 ][ 4 ] = checar_local(m[ 1 ][ 4 ] ,aux ,&turn);
												}
											}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  COLUNA       4        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==4 && y==1 && x2==4 && y2==2 ) || ( x==4 && y==2 && x2==4 && y2==1 ) )
											{
												if( m[ 11 ][ 6 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 11 ][ 6 ] = checar_local(m[ 11 ][ 6 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==2 && x2==4 && y2==3 ) || ( x==4 && y==3 && x2==4 && y2==2 ) )
											{
												if( m[ 9 ][ 6 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 9 ][ 6 ] = checar_local(m[ 9 ][ 6 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==3 && x2==4 && y2==4 ) || ( x==4 && y==4 && x2==4 && y2==3 ) )
											{
												if( m[ 7 ][ 6 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 7 ][ 6 ] = checar_local(m[ 7 ][ 6 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==4 && x2==4 && y2==5 ) || ( x==4 && y==5 && x2==4 && y2==4 ) )
											{
												if( m[ 5 ][ 6 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 5 ][ 6 ] = checar_local(m[ 5 ][ 6 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==5 && x2==4 && y2==6 ) || ( x==4 && y==6 && x2==4 && y2==5 ) )
											{
												if( m[ 3 ][ 6 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 3 ][ 6 ] = checar_local(m[ 3 ][ 6 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==7 && x2==4 && y2==6 ) || ( x==4 && y==6 && x2==4 && y2==7 ) )
											{
												if( m[ 1 ][ 6 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 1 ][ 6 ] = checar_local(m[ 1 ][ 6 ] ,aux ,&turn);
												}
											}
											
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  COLUNA       5        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==5 && y==1 && x2==5 && y2==2 ) || ( x==5 && y==2 && x2==5 && y2==1 ) )
											{
												if( m[ 11 ][ 8 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 11 ][ 8 ] = checar_local(m[ 11 ][ 8 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==2 && x2==5 && y2==3 ) || ( x==5 && y==3 && x2==5 && y2==2 ) )
											{
												if( m[ 9 ][ 8 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 9 ][ 8 ] = checar_local(m[ 9 ][ 8 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==3 && x2==5 && y2==4 ) || ( x==5 && y==4 && x2==5 && y2==3 ) )
											{
												if( m[ 7 ][ 8 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 7 ][ 8 ] = checar_local(m[ 7 ][ 8 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==4 && x2==5 && y2==5 ) || ( x==5 && y==5 && x2==5 && y2==4 ) )
											{
												if( m[ 5 ][ 8 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 5 ][ 8 ] = checar_local(m[ 5 ][ 8 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==5 && x2==5 && y2==6 ) || ( x==5 && y==6 && x2==5 && y2==5 ) )
											{
												if( m[ 3 ][ 8 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 3 ][ 8 ] = checar_local(m[ 3 ][ 8 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==6 && x2==5 && y2==7 ) || ( x==5 && y==7 && x2==5 && y2==6 ) )
											{
												if( m[ 1 ][ 8 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 1 ][ 8 ] = checar_local(m[ 1 ][ 8 ] ,aux ,&turn);
												}
											}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  COLUNA       6        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==6 && y==1 && x2==6 && y2==2 ) || ( x==6 && y==2 && x2==6 && y2==1 ) )
											{
												if( m[ 11 ][ 10 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 11 ][ 10 ] = checar_local(m[ 11 ][ 10 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==2 && x2==6 && y2==3 ) || ( x==6 && y==3 && x2==6 && y2==2 ) )
											{
												if( m[ 9 ][ 10 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 9 ][ 10 ] = checar_local(m[ 9 ][ 10 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==3 && x2==6 && y2==4 ) || ( x==6 && y==4 && x2==6 && y2==3 ) )
											{
												if( m[ 7 ][ 10 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 7 ][ 10 ] = checar_local(m[ 7 ][ 10 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==4 && x2==6 && y2==5 ) || ( x==6 && y==5 && x2==6 && y2==4 ) )
											{
												if( m[ 5 ][ 10 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 5 ][ 10 ] = checar_local(m[ 5 ][ 10 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==5 && x2==6 && y2==6 ) || ( x==6 && y==6 && x2==6 && y2==5 ) )
											{
												if( m[ 3 ][ 10 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 3 ][ 10 ] = checar_local(m[ 3 ][ 10 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==6 && x2==6 && y2==7 ) || ( x==6 && y==7 && x2==6 && y2==6 ) )
											{
												if( m[ 1 ][ 10 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 1 ][ 10 ] = checar_local(m[ 1 ][ 10 ] ,aux ,&turn);
												}
											}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  COLUNA       7        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==7 && y==1 && x2==7 && y2==2 ) || ( x==7 && y==2 && x2==7 && y2==1 ) )
											{
												if( m[ 11 ][ 12 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 11 ][ 12 ] = checar_local(m[ 11 ][ 12 ] ,aux ,&turn);
												}
											}
											else if( ( x==7 && y==2 && x2==7 && y2==3 ) || ( x==7 && y==3 && x2==7 && y2==2 ) )
											{
												if( m[ 9 ][ 12 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 9 ][ 12 ] = checar_local(m[ 9 ][ 12 ] ,aux ,&turn);
												}
											}
											else if( ( x==7 && y==3 && x2==7 && y2==4 ) || ( x==7 && y==4 && x2==7 && y2==3 ) )
											{
												if( m[ 7 ][ 12 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 7 ][ 12 ] = checar_local(m[ 7 ][ 12 ] ,aux ,&turn);
												}
											}
											else if( ( x==7 && y==4 && x2==7 && y2==5 ) || ( x==7 && y==5 && x2==7 && y2==4 ) )
											{
												if( m[ 5 ][ 12 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 5 ][ 12 ] = checar_local(m[ 5 ][ 12 ] ,aux ,&turn);
												}
											}
											else if( ( x==7 && y==5 && x2==7 && y2==6 ) || ( x==7 && y==6 && x2==7 && y2==5 ) )
											{
												if( m[ 3 ][ 12 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 3 ][ 12 ] = checar_local(m[ 3 ][ 12 ] ,aux ,&turn);
												}
											}
											else if( ( x==7 && y==7 && x2==7 && y2==6 ) || ( x==7 && y==6 && x2==7 && y2==7 ) )
											{
												if( m[ 1 ][ 12 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn = 1;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 1 ][ 12 ] = checar_local(m[ 1 ][ 12 ] ,aux ,&turn);
												}
											}
											else
											{
												printf("\n\t\tJogada invalida!\n\n");
												system("pause");
												turn = 1;
											}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  	FINAL  JOGADOR 1         FINAL  JOGADOR 1         FINAL  JOGADOR 1         FINAL  JOGADOR 1          ////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////                                     	1 ª FILEIRA DE QUADRADOS                                         ////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		
										if( ( m[ 0 ][ 1 ]=='-' ) &&  ( m[ 2 ][ 1 ]=='-' ) && ( m[ 1 ][ 0 ]=='|' ) &&  ( m[ 1 ][ 2 ]=='|' ) &&  ( m[ 1 ][ 1 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 1 ][ 1 ]='1';
											}
										}
										else if( ( m[ 0 ][ 3 ]=='-' ) &&  ( m[ 2 ][ 3 ]=='-' ) && ( m[ 1 ][ 2 ]=='|' ) &&  ( m[ 1 ][ 4 ]=='|' ) &&  ( m[ 1 ][ 4 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 1 ][ 4 ]='1';
											}
										}
										else if( ( m[ 0 ][ 5 ]=='-' ) &&  ( m[ 2 ][ 5 ]=='-' ) && ( m[ 1 ][ 4 ]=='|' ) &&  ( m[ 1 ][ 6 ]=='|' ) &&  ( m[ 1 ][ 6 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 1 ][ 6 ]='1';
											}
										}
										else if( ( m[ 0 ][ 7 ]=='-' ) &&  ( m[ 2 ][ 7 ]=='-' ) && ( m[ 1 ][ 6 ]=='|' ) &&  ( m[ 1 ][ 8 ]=='|' ) &&  ( m[ 1 ][ 7 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 1 ][ 7 ]='1';
											}
										}
										else if( ( m[ 0 ][ 9 ]=='-' ) &&  ( m[ 2 ][ 9 ]=='-' ) && ( m[ 1 ][ 8 ]=='|' ) &&  ( m[ 1 ][ 10 ]=='|' ) &&  ( m[ 1 ][ 9 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 1 ][ 9 ]='1';
											}
										}
										else if( ( m[ 0 ][ 11 ]=='-' ) &&  ( m[ 2 ][ 11 ]=='-' ) && ( m[ 1 ][ 10 ]=='|' ) &&  ( m[ 1 ][ 12 ]=='|' ) &&  ( m[ 1 ][ 11 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 1 ][ 11 ]='1';
											}
										}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////                                     	2 ª FILEIRA DE QUADRADOS                                         ////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
										else if( ( m[ 2 ][ 1 ]=='-' ) &&  ( m[ 4 ][ 1 ]=='-' ) && ( m[ 3 ][ 0 ]=='|' ) &&  ( m[ 3 ][ 2 ]=='|' ) &&  ( m[ 3 ][ 1 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 3 ][ 1 ]='1';
											}
										}
										else if( ( m[ 2 ][ 3 ]=='-' ) &&  ( m[ 4 ][ 3 ]=='-' ) && ( m[ 3 ][ 2 ]=='|' ) &&  ( m[ 3 ][ 4 ]=='|' ) &&  ( m[ 3 ][ 3 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 3 ][ 3 ]='1';
											}
										}
										else if( ( m[ 2 ][ 5 ]=='-' ) &&  ( m[ 4 ][ 5 ]=='-' ) && ( m[ 3 ][ 4 ]=='|' ) &&  ( m[ 3 ][ 6 ]=='|' ) &&  ( m[ 3 ][ 5 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 3 ][ 5 ]='1';
											}
										}
										else if( ( m[ 2 ][ 7 ]=='-' ) &&  ( m[ 4 ][ 7 ]=='-' ) && ( m[ 3 ][ 6 ]=='|' ) &&  ( m[ 3 ][ 8 ]=='|' ) &&  ( m[ 3 ][ 7 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 3 ][ 7 ]='1';
											}
										}
										else if( ( m[ 2 ][ 9 ]=='-' ) &&  ( m[ 4 ][ 9 ]=='-' ) && ( m[ 3 ][ 8 ]=='|' ) &&  ( m[ 3 ][ 10 ]=='|' ) &&  ( m[ 3 ][ 9 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 3 ][ 9 ]='1';
											}
										}
										else if( ( m[ 2 ][ 11 ]=='-' ) &&  ( m[ 4 ][ 11 ]=='-' ) && ( m[ 3 ][ 10 ]=='|' ) &&  ( m[ 3 ][ 12 ]=='|' ) &&  ( m[ 3 ][ 11 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 3 ][ 11 ]='1';
											}
										}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////                                     	3 ª FILEIRA DE QUADRADOS                                         ////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
										else if( ( m[ 4 ][ 1 ]=='-' ) &&  ( m[ 6 ][ 1 ]=='-' ) && ( m[ 5 ][ 0 ]=='|' ) &&  ( m[ 5 ][ 2 ]=='|' ) &&  ( m[ 5 ][ 1 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 5 ][ 1 ]='1';
											}
										}
										else if( ( m[ 4 ][ 3 ]=='-' ) &&  ( m[ 6 ][ 3 ]=='-' ) && ( m[ 5 ][ 2 ]=='|' ) &&  ( m[ 5 ][ 4 ]=='|' ) &&  ( m[ 5 ][ 3 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 5 ][ 3 ]='1';
											}
										}
										else if( ( m[ 4 ][ 5 ]=='-' ) &&  ( m[ 6 ][ 5 ]=='-' ) && ( m[ 5 ][ 4 ]=='|' ) &&  ( m[ 5 ][ 6 ]=='|' ) &&  ( m[ 5 ][ 5 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 5 ][ 5 ]='1';
											}
										}
										else if( ( m[ 4 ][ 7 ]=='-' ) &&  ( m[ 6 ][ 7 ]=='-' ) && ( m[ 5 ][ 6 ]=='|' ) &&  ( m[ 5 ][ 8 ]=='|' ) &&  ( m[ 5 ][ 7 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 5 ][ 7 ]='1';
											}
										}
										else if( ( m[ 4 ][ 9 ]=='-' ) &&  ( m[ 6 ][ 9 ]=='-' ) && ( m[ 5 ][ 8 ]=='|' ) &&  ( m[ 5 ][ 10 ]=='|' ) &&  ( m[ 5 ][ 9 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 5 ][ 9 ]='1';
											}
										}
										else if( ( m[ 4 ][ 11 ]=='-' ) &&  ( m[ 6 ][ 11 ]=='-' ) && ( m[ 5 ][ 10 ]=='|' ) &&  ( m[ 5 ][ 12 ]=='|' ) &&  ( m[ 5 ][ 11 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 5 ][ 11 ]='1';
											}
										}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////                                     	4 ª FILEIRA DE QUADRADOS                                         ////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
										else if( ( m[ 6 ][ 1 ]=='-' ) &&  ( m[ 8 ][ 1 ]=='-' ) && ( m[ 7 ][ 0 ]=='|' ) &&  ( m[ 7 ][ 2 ]=='|' ) &&  ( m[ 7 ][ 1 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 7 ][ 1 ]='1';
											}
										}
										else if( ( m[ 6 ][ 3 ]=='-' ) &&  ( m[ 8 ][ 3 ]=='-' ) && ( m[ 7 ][ 2 ]=='|' ) &&  ( m[ 7 ][ 4 ]=='|' ) &&  ( m[ 7 ][ 3 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 7 ][ 3 ]='1';
											}
										}
										else if( ( m[ 6 ][ 5 ]=='-' ) &&  ( m[ 8 ][ 5 ]=='-' ) && ( m[ 7 ][ 4 ]=='|' ) &&  ( m[ 7 ][ 6 ]=='|' ) &&  ( m[ 7 ][ 5 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 7 ][ 5 ]='1';
											}
										}
										else if( ( m[ 6 ][ 7 ]=='-' ) &&  ( m[ 8 ][ 7 ]=='-' ) && ( m[ 7 ][ 6 ]=='|' ) &&  ( m[ 7 ][ 8 ]=='|' ) &&  ( m[ 7 ][ 7 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 7 ][ 7 ]='1';
											}
										}
										else if( ( m[ 6 ][ 9 ]=='-' ) &&  ( m[ 8 ][ 9 ]=='-' ) && ( m[ 7 ][ 8 ]=='|' ) &&  ( m[ 7 ][ 10 ]=='|' ) &&  ( m[ 7 ][ 9 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 7 ][ 9 ]='1';
											}
										}
										else if( ( m[ 6 ][ 11 ]=='-' ) &&  ( m[ 8 ][ 11 ]=='-' ) && ( m[ 7 ][ 10 ]=='|' ) &&  ( m[ 7 ][ 12 ]=='|' ) &&  ( m[ 7 ][ 11 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 7 ][ 11 ]='1';
											}
										}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////                                     	5 ª FILEIRA DE QUADRADOS                                         ////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
										else if( ( m[ 8 ][ 1 ]=='-' ) &&  ( m[ 10 ][ 1 ]=='-' ) && ( m[ 9 ][ 0 ]=='|' ) &&  ( m[ 9 ][ 2 ]=='|' ) &&  ( m[ 9 ][ 1 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 9 ][ 1 ]='1';
											}
										}
										else if( ( m[ 8 ][ 3 ]=='-' ) &&  ( m[ 10 ][ 3 ]=='-' ) && ( m[ 9 ][ 2 ]=='|' ) &&  ( m[ 9 ][ 4 ]=='|' ) &&  ( m[ 9 ][ 3 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 9 ][ 3 ]='1';
											}
										}
										else if( ( m[ 8 ][ 5 ]=='-' ) &&  ( m[ 10 ][ 5 ]=='-' ) && ( m[ 9 ][ 4 ]=='|' ) &&  ( m[ 9 ][ 6 ]=='|' ) &&  ( m[ 9 ][ 5 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 9 ][ 5 ]='1';
											}
										}
										else if( ( m[ 8 ][ 7 ]=='-' ) &&  ( m[ 10 ][ 7 ]=='-' ) && ( m[ 9 ][ 6 ]=='|' ) &&  ( m[ 9 ][ 8 ]=='|' ) &&  ( m[ 9 ][ 7 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 9 ][ 7 ]='1';
											}
										}
										else if( ( m[ 8 ][ 9 ]=='-' ) &&  ( m[ 10 ][ 9 ]=='-' ) && ( m[ 9 ][ 8 ]=='|' ) &&  ( m[ 9 ][ 10 ]=='|' ) &&  ( m[ 9 ][ 9 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 9 ][ 9 ]='1';
											}
										}
										else if( ( m[ 8 ][ 11 ]=='-' ) &&  ( m[ 10 ][ 11 ]=='-' ) && ( m[ 9 ][ 10 ]=='|' ) &&  ( m[ 9 ][ 12 ]=='|' ) &&  ( m[ 9 ][ 11 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 9 ][ 11 ]='1';
											}
										}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////                                     	6 ª FILEIRA DE QUADRADOS                                         ////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
										else if( ( m[ 10 ][ 1 ]=='-' ) &&  ( m[ 12 ][ 1 ]=='-' ) && ( m[ 11 ][ 0 ]=='|' ) &&  ( m[ 11 ][ 2 ]=='|' ) &&  ( m[ 11 ][ 1 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 11 ][ 1 ]='1';
											}
										}
										else if( ( m[ 10 ][ 3 ]=='-' ) &&  ( m[ 12 ][ 3 ]=='-' ) && ( m[ 11 ][ 2 ]=='|' ) &&  ( m[ 11 ][ 4 ]=='|' ) &&  ( m[ 11 ][ 3 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 11 ][ 3 ]='1';
											}
										}
										else if( ( m[ 10 ][ 5 ]=='-' ) &&  ( m[ 12 ][ 5 ]=='-' ) && ( m[ 11 ][ 4 ]=='|' ) &&  ( m[ 11 ][ 6 ]=='|' ) &&  ( m[ 11 ][ 5 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 11 ][ 5 ]='1';
											}
										}
										else if( ( m[ 10 ][ 7 ]=='-' ) &&  ( m[ 12 ][ 7 ]=='-' ) && ( m[ 11 ][ 6 ]=='|' ) &&  ( m[ 11 ][ 8 ]=='|' ) &&  ( m[ 11 ][ 7 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 11 ][ 7 ]='1';
											}
										}
										else if( ( m[ 10 ][ 9 ]=='-' ) &&  ( m[ 12 ][ 9 ]=='-' ) && ( m[ 11 ][ 8 ]=='|' ) &&  ( m[ 11 ][ 10 ]=='|' ) &&  ( m[ 11 ][ 9 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 11 ][ 9 ]='1';
											}
										}
										else if( ( m[ 10 ][ 11 ]=='-' ) &&  ( m[ 12 ][ 11 ]=='-' ) && ( m[ 11 ][ 10 ]=='|' ) &&  ( m[ 11 ][ 12 ]=='|' ) &&  ( m[ 11 ][ 11 ]==' ' ) )
										{
											if(turn == 2)
											{
												printf("\n\t\tJOGADOR 1: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_1++;
												turn = 1;
												m[ 11 ][ 11 ]='1';
											}
										}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////                                  	FIM DAS CONDIÇÕES DE PONTUAÇÃO                                        ///////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		}
		

//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////                    COMANDO DO JOGADOR 1         / \       ////////////////////////
///////////////////////                                                  |        ////////////////////////
///////////////////////                                                  |        ////////////////////////
///////////////////////                                                           ////////////////////////
///////////////////////                                     |                     ////////////////////////
///////////////////////                                     |                     ////////////////////////
///////////////////////       COMANDO  DO JOGADOR 2        \ /                    ////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

		if(turn == 2)
		{
			linha=7;
			turn = 1;
			system("cls");
			printf("\n\n\t\t\tSEGUNDO JOGADOR\n\n\n");
			printf("\t\t\tJOGADOR 1 = %i  PONTOS\n\n\t\t\tJOGADOR 2 = %i  PONTOS\n\n",pontos_1,pontos_2);
			for(l=0;l<13;l++)
			{
				if(l%2==0)
				{
					printf("\n\t\t\t%i %c%c  ",linha,a,a);
					linha--;
				}
				else
				{
					printf("\n\t\t\t      ");
				}
				for(j=0;j<13;j++)
				{
					printf("%c",m[l][j]);
				}
			}
			printf("\n\n\t\t\t      ");
			for(l=1;l<8;l++)
			{
				printf("%c ",b);
			}
			printf("\n\n\t\t\t      ");
			for(l=1;l<8;l++)
			{
				printf("%i ",l);
			}
			printf("\n\n");
			printf("\t\tCoordenada X: ");
			scanf("%i-%i",&x,&y);
			fflush(stdin);
			printf("\t\tCoordenada y: ");
			scanf("%i-%i",&x2,&y2);
			fflush(stdin);

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  LINHA        1        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											if( ( x==1 && y==1 && x2==2 && y2==1 ) || ( x==2 && y==1 && x2==1 && y2==1 ) )
											{
												if( m[ 12 ][ 1 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 12 ][ 1 ] = checar_local(m[ 12 ][ 1 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==1 && x2==3 && y2==1 ) || ( x==3 && y==1 && x2==2 && y2==1 ) )
											{
												if( m[ 12 ][ 3 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 12 ][ 3 ] = checar_local(m[ 12 ][ 3 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==1 && x2==4 && y2==1 ) || ( x==4 && y==1 && x2==3 && y2==1 ) )
											{
												if( m[ 12 ][ 5 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 12 ][ 5 ] = checar_local(m[ 12 ][ 5 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==1 && x2==5 && y2==1 ) || ( x==5 && y==1 && x2==4 && y2==1 ) )
											{
												if( m[ 12 ][ 7 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 12 ][ 7 ] = checar_local(m[ 12 ][ 7 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==1 && x2==6 && y2==1 ) || ( x==6 && y==1 && x2==5 && y2==1 ) )
											{
												if( m[ 12 ][ 9 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 12 ][ 9 ] = checar_local(m[ 12 ][ 9 ] ,aux ,&turn);
												}
											}
											else if( ( x==7 && y==1 && x2==6 && y2==1 ) || ( x==6 && y==1 && x2==7 && y2==1 ) )
											{
												if( m[ 12 ][ 11 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 12 ][ 11 ] = checar_local(m[ 12 ][ 11 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  LINHA        2        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==1 && y==2 && x2==2 && y2==2 ) || ( x==2 && y==2 && x2==1 && y2==2 ) )
											{
												if( m[ 10 ][ 1 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 10 ][ 1 ] = checar_local(m[ 10 ][ 1 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==2 && x2==3 && y2==2 ) || ( x==3 && y==2 && x2==2 && y2==2 ) )
											{
												if( m[ 10 ][ 3 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 10 ][ 3 ] = checar_local(m[ 10 ][ 3 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==2 && x2==4 && y2==2 ) || ( x==4 && y==2 && x2==3 && y2==2 ) )
											{
												if( m[ 10 ][ 5 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 10 ][ 5 ] = checar_local(m[ 10 ][ 5 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==2 && x2==5 && y2==2 ) || ( x==5 && y==2 && x2==4 && y2==2 ) )
											{
												if( m[ 10 ][ 7 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 10 ][ 7 ] = checar_local(m[ 10 ][ 7 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==2 && x2==6 && y2==2 ) || ( x==6 && y==2 && x2==5 && y2==2 ) )
											{
												if( m[ 10 ][ 9 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 10 ][ 9 ] = checar_local(m[ 10 ][ 9 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==2 && x2==7 && y2==2 ) || ( x==7 && y==2 && x2==6 && y2==2 ) )
											{
												if( m[ 10 ][ 11 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 10 ][ 11 ] = checar_local(m[ 10 ][ 11 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  LINHA        3        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==1 && y==3 && x2==2 && y2==3 ) || ( x==2 && y==3 && x2==1 && y2==3 ) )
											{
												if( m[ 8 ][ 1 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 8 ][ 1 ] = checar_local(m[ 8 ][ 1 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==3 && x2==3 && y2==3 ) || ( x==3 && y==3 && x2==2 && y2==3 ) )
											{
												if( m[ 8 ][ 3 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 8 ][ 3 ] = checar_local(m[ 8 ][ 3 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==3 && x2==4 && y2==3 ) || ( x==4 && y==3 && x2==3 && y2==3 ) )
											{
												if( m[ 8 ][ 5 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 8 ][ 5 ] = checar_local(m[ 8 ][ 5 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==3 && x2==5 && y2==3 ) || ( x==5 && y==3 && x2==4 && y2==3 ) )
											{
												if( m[ 8 ][ 7 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 8 ][ 7 ] = checar_local(m[ 8 ][ 7 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==3 && x2==6 && y2==3 ) || ( x==6 && y==3 && x2==5 && y2==3 ) )
											{
												if( m[ 8 ][ 9 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 8 ][ 9 ] = checar_local(m[ 8 ][ 9 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==3 && x2==7 && y2==3 ) || ( x==7 && y==3 && x2==6 && y2==3 ) )
											{
												if( m[ 8 ][ 11 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 8 ][ 11 ] = checar_local(m[ 8 ][ 11 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  LINHA        4        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==1 && y==4 && x2==2 && y2==4 ) || ( x==2 && y==4 && x2==1 && y2==4 ) )
											{
												if( m[ 6 ][ 1 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 6 ][ 1 ] = checar_local(m[ 6 ][ 1 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==4 && x2==3 && y2==4 ) || ( x==3 && y==4 && x2==2 && y2==4 ) )
											{
												if( m[ 6 ][ 3 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 6 ][ 3 ] = checar_local(m[ 6 ][ 3 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==4 && x2==4 && y2==4 ) || ( x==4 && y==4 && x2==3 && y2==4 ) )
											{
												if( m[ 6 ][ 5 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 6 ][ 5 ] = checar_local(m[ 6 ][ 5 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==4 && x2==5 && y2==4 ) || ( x==5 && y==4 && x2==4 && y2==4 ) )
											{
												if( m[ 6 ][ 7 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 6 ][ 7 ] = checar_local(m[ 6 ][ 7 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==4 && x2==6 && y2==4 ) || ( x==6 && y==4 && x2==5 && y2==4 ) )
											{
												if( m[ 6 ][ 9 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 6 ][ 9 ] = checar_local(m[ 6 ][ 9 ] ,aux ,&turn);
												}
											}
											else if( ( x==7 && y==4 && x2==6 && y2==4 ) || ( x==6 && y==4 && x2==7 && y2==4 ) )
											{
												if( m[ 6 ][ 11 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 6 ][ 11 ] = checar_local(m[ 6 ][ 11 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  LINHA        5        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==1 && y==5 && x2==2 && y2==5 ) || ( x==2 && y==5 && x2==1 && y2==5 ) )
											{
												if( m[ 4 ][ 1 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 4 ][ 1 ] = checar_local(m[ 4 ][ 1 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==5 && x2==3 && y2==5 ) || ( x==3 && y==5 && x2==2 && y2==5 ) )
											{
												if( m[ 4 ][ 3 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 4 ][ 3 ] = checar_local(m[ 4 ][ 3 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==5 && x2==4 && y2==5 ) || ( x==4 && y==5 && x2==3 && y2==5 ) )
											{
												if( m[ 4 ][ 5 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 4 ][ 5 ] = checar_local(m[ 4 ][ 5 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==5 && x2==5 && y2==5 ) || ( x==5 && y==5 && x2==4 && y2==5 ) )
											{
												if( m[ 4 ][ 7 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 4 ][ 7 ] = checar_local(m[ 4 ][ 7 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==5 && x2==6 && y2==5 ) || ( x==6 && y==5 && x2==5 && y2==5 ) )
											{
												if( m[ 4 ][ 9 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 4 ][ 9 ] = checar_local(m[ 4 ][ 9 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==5 && x2==7 && y2==5 ) || ( x==7 && y==5 && x2==6 && y2==5 ) )
											{
												if( m[ 4 ][ 11 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 4 ][ 11 ] = checar_local(m[ 4 ][ 11 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  LINHA        6        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==1 && y==6 && x2==2 && y2==6 ) || ( x==2 && y==6 && x2==1 && y2==6 ) )
											{
												if( m[ 2 ][ 1 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 2 ][ 1 ] = checar_local(m[ 2 ][ 1 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==6 && x2==3 && y2==6 ) || ( x==3 && y==6 && x2==2 && y2==6 ) )
											{
												if( m[ 2 ][ 3 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 2 ][ 3 ] = checar_local(m[ 2 ][ 3 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==6 && x2==4 && y2==6 ) || ( x==4 && y==6 && x2==3 && y2==6 ) )
											{
												if( m[ 2 ][ 5 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 2 ][ 5 ] = checar_local(m[ 2 ][ 5 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==6 && x2==5 && y2==6 ) || ( x==5 && y==6 && x2==4 && y2==6 ) )
											{
												if( m[ 2 ][ 7 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 2 ][ 7 ] = checar_local(m[ 2 ][ 7 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==6 && x2==6 && y2==6 ) || ( x==6 && y==6 && x2==5 && y2==6 ) )
											{
												if( m[ 2 ][ 9 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 2 ][ 9 ] = checar_local(m[ 2 ][ 9 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==6 && x2==7 && y2==6 ) || ( x==7 && y==6 && x2==6 && y2==6 ) )
											{
												if( m[ 2 ][ 11 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 2 ][ 11 ] = checar_local(m[ 2 ][ 11 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  LINHA        7        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==1 && y==7 && x2==2 && y2==7 ) || ( x==2 && y==7 && x2==1 && y2==7 ) )
											{
												if( m[ 0 ][ 1 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 0 ][ 1 ] = checar_local(m[ 0 ][ 1 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==7 && x2==3 && y2==7 ) || ( x==3 && y==7 && x2==2 && y2==7 ) )
											{
												if( m[ 0 ][ 3 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 0 ][ 3 ] = checar_local(m[ 0 ][ 3 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==7 && x2==4 && y2==7 ) || ( x==4 && y==7 && x2==3 && y2==7 ) )
											{
												if( m[ 0 ][ 5 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 0 ][ 5 ] = checar_local(m[ 0 ][ 5 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==7 && x2==5 && y2==7 ) || ( x==5 && y==7 && x2==4 && y2==7 ) )
											{
												if( m[ 0 ][ 7 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 0 ][ 7 ] = checar_local(m[ 0 ][ 7 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==7 && x2==6 && y2==7 ) || ( x==6 && y==7 && x2==5 && y2==7 ) )
											{
												if( m[ 0 ][ 9 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 0 ][ 9 ] = checar_local(m[ 0 ][ 9 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==7 && x2==7 && y2==7 ) || ( x==7 && y==7 && x2==6 && y2==7 ) )
											{
												if( m[ 0 ][ 11 ] == '-' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '-';
													m[ 0 ][ 11 ] = checar_local(m[ 0 ][ 11 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  COLUNA       1        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==1 && y==1 && x2==1 && y2==2 ) || ( x==1 && y==2 && x2==1 && y2==1 ) )
											{
												if( m[ 11 ][ 0 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 11 ][ 0 ] = checar_local(m[ 11 ][ 0 ] ,aux ,&turn);
												}
											}
											else if( ( x==1 && y==2 && x2==1 && y2==3 ) || ( x==1 && y==3 && x2==1 && y2==2 ) )
											{
												if( m[ 9 ][ 0 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 9 ][ 0 ] = checar_local(m[ 9 ][ 0 ] ,aux ,&turn);
												}
											}
											else if( ( x==1 && y==3 && x2==1 && y2==4 ) || ( x==1 && y==4 && x2==1 && y2==3 ) )
											{
												if( m[ 7 ][ 0 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 7 ][ 0 ] = checar_local(m[ 7 ][ 0 ] ,aux ,&turn);
												}
											}
											else if( ( x==1 && y==5 && x2==1 && y2==4 ) || ( x==1 && y==4 && x2==1 && y2==5 ) )
											{
												if( m[ 5 ][ 0 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 5 ][ 0 ] = checar_local(m[ 5 ][ 0 ] ,aux ,&turn);
												}
											}
											else if( ( x==1 && y==5 && x2==1 && y2==6 ) || ( x==1 && y==6 && x2==1 && y2==5 ) )
											{
												if( m[ 3 ][ 0 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 3 ][ 0 ] = checar_local(m[ 3 ][ 0 ] ,aux ,&turn);
												}
											}
											else if( ( x==1 && y==6 && x2==1 && y2==7 ) || ( x==1 && y==7 && x2==1 && y2==6 ) )
											{
												if( m[ 1 ][ 0 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 1 ][ 0 ] = checar_local(m[ 1 ][ 0 ] ,aux ,&turn);
												}
											}
											
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  COLUNA       2        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==2 && y==1 && x2==2 && y2==2 ) || ( x==2 && y==2 && x2==2 && y2==1 ) )
											{
												if( m[ 11 ][ 2 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 11 ][ 2 ] = checar_local(m[ 11 ][ 2 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==2 && x2==2 && y2==3 ) || ( x==2 && y==3 && x2==2 && y2==2 ) )
											{
												if( m[ 9 ][ 2 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 9 ][ 2 ] = checar_local(m[ 9 ][ 2 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==3 && x2==2 && y2==4 ) || ( x==2 && y==4 && x2==2 && y2==3 ) )
											{
												if( m[ 7 ][ 2 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 7 ][ 2 ] = checar_local(m[ 7 ][ 2 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==5 && x2==2 && y2==4 ) || ( x==2 && y==4 && x2==2 && y2==5 ) )
											{
												if( m[ 5 ][ 2 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 5 ][ 2 ] = checar_local(m[ 5 ][ 2 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==5 && x2==2 && y2==6 ) || ( x==2 && y==6 && x2==2 && y2==5 ) )
											{
												if( m[ 3 ][ 2 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 3 ][ 2 ] = checar_local(m[ 3 ][ 2 ] ,aux ,&turn);
												}
											}
											else if( ( x==2 && y==6 && x2==2 && y2==7 ) || ( x==2 && y==7 && x2==2 && y2==6 ) )
											{
												if( m[ 1 ][ 2 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 1 ][ 2 ] = checar_local(m[ 1 ][ 2 ] ,aux ,&turn);
												}
											}	
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  COLUNA       3        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==3 && y==1 && x2==3 && y2==2 ) || ( x==3 && y==2 && x2==3 && y2==1 ) )
											{
												if( m[ 11 ][ 4 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 11 ][ 4 ] = checar_local(m[ 11 ][ 4 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==2 && x2==3 && y2==3 ) || ( x==3 && y==3 && x2==3 && y2==2 ) )
											{
												if( m[ 9 ][ 4 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 9 ][ 4 ] = checar_local(m[ 9 ][ 4 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==3 && x2==3 && y2==4 ) || ( x==3 && y==4 && x2==3 && y2==3 ) )
											{
												if( m[ 7 ][ 4 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 7 ][ 4 ] = checar_local(m[ 7 ][ 4 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==4 && x2==3 && y2==5 ) || ( x==3 && y==5 && x2==3 && y2==4 ) )
											{
												if( m[ 5 ][ 4 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 5 ][ 4 ] = checar_local(m[ 5 ][ 4 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==5 && x2==3 && y2==6 ) || ( x==3 && y==6 && x2==3 && y2==5 ) )
											{
												if( m[ 3 ][ 4 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 3 ][ 4 ] = checar_local(m[ 3 ][ 4 ] ,aux ,&turn);
												}
											}
											else if( ( x==3 && y==6 && x2==3 && y2==7 ) || ( x==3 && y==7 && x2==3 && y2==6 ) )
											{
												if( m[ 1 ][ 4 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 1 ][ 4 ] = checar_local(m[ 1 ][ 4 ] ,aux ,&turn);
												}
											}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  COLUNA       4        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==4 && y==1 && x2==4 && y2==2 ) || ( x==4 && y==2 && x2==4 && y2==1 ) )
											{
												if( m[ 11 ][ 6 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 11 ][ 6 ] = checar_local(m[ 11 ][ 6 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==2 && x2==4 && y2==3 ) || ( x==4 && y==3 && x2==4 && y2==2 ) )
											{
												if( m[ 9 ][ 6 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 9 ][ 6 ] = checar_local(m[ 9 ][ 6 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==3 && x2==4 && y2==4 ) || ( x==4 && y==4 && x2==4 && y2==3 ) )
											{
												if( m[ 7 ][ 6 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 7 ][ 6 ] = checar_local(m[ 7 ][ 6 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==4 && x2==4 && y2==5 ) || ( x==4 && y==5 && x2==4 && y2==4 ) )
											{
												if( m[ 5 ][ 6 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 5 ][ 6 ] = checar_local(m[ 5 ][ 6 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==5 && x2==4 && y2==6 ) || ( x==4 && y==6 && x2==4 && y2==5 ) )
											{
												if( m[ 3 ][ 6 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 3 ][ 6 ] = checar_local(m[ 3 ][ 6 ] ,aux ,&turn);
												}
											}
											else if( ( x==4 && y==7 && x2==4 && y2==6 ) || ( x==4 && y==6 && x2==4 && y2==7 ) )
											{
												if( m[ 1 ][ 6 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 1 ][ 6 ] = checar_local(m[ 1 ][ 6 ] ,aux ,&turn);
												}
											}
											
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  COLUNA       5        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==5 && y==1 && x2==5 && y2==2 ) || ( x==5 && y==2 && x2==5 && y2==1 ) )
											{
												if( m[ 11 ][ 8 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 11 ][ 8 ] = checar_local(m[ 11 ][ 8 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==2 && x2==5 && y2==3 ) || ( x==5 && y==3 && x2==5 && y2==2 ) )
											{
												if( m[ 9 ][ 8 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 9 ][ 8 ] = checar_local(m[ 9 ][ 8 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==3 && x2==5 && y2==4 ) || ( x==5 && y==4 && x2==5 && y2==3 ) )
											{
												if( m[ 7 ][ 8 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 7 ][ 8 ] = checar_local(m[ 7 ][ 8 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==4 && x2==5 && y2==5 ) || ( x==5 && y==5 && x2==5 && y2==4 ) )
											{
												if( m[ 5 ][ 8 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 5 ][ 8 ] = checar_local(m[ 5 ][ 8 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==5 && x2==5 && y2==6 ) || ( x==5 && y==6 && x2==5 && y2==5 ) )
											{
												if( m[ 3 ][ 8 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 3 ][ 8 ] = checar_local(m[ 3 ][ 8 ] ,aux ,&turn);
												}
											}
											else if( ( x==5 && y==6 && x2==5 && y2==7 ) || ( x==5 && y==7 && x2==5 && y2==6 ) )
											{
												if( m[ 1 ][ 8 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 1 ][ 8 ] = checar_local(m[ 1 ][ 8 ] ,aux ,&turn);
												}
											}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  COLUNA       6        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==6 && y==1 && x2==6 && y2==2 ) || ( x==6 && y==2 && x2==6 && y2==1 ) )
											{
												if( m[ 11 ][ 10 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 11 ][ 10 ] = checar_local(m[ 11 ][ 10 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==2 && x2==6 && y2==3 ) || ( x==6 && y==3 && x2==6 && y2==2 ) )
											{
												if( m[ 9 ][ 10 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 9 ][ 10 ] = checar_local(m[ 9 ][ 10 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==3 && x2==6 && y2==4 ) || ( x==6 && y==4 && x2==6 && y2==3 ) )
											{
												if( m[ 7 ][ 10 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 7 ][ 10 ] = checar_local(m[ 7 ][ 10 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==4 && x2==6 && y2==5 ) || ( x==6 && y==5 && x2==6 && y2==4 ) )
											{
												if( m[ 5 ][ 10 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 5 ][ 10 ] = checar_local(m[ 5 ][ 10 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==5 && x2==6 && y2==6 ) || ( x==6 && y==6 && x2==6 && y2==5 ) )
											{
												if( m[ 3 ][ 10 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 3 ][ 10 ] = checar_local(m[ 3 ][ 10 ] ,aux ,&turn);
												}
											}
											else if( ( x==6 && y==6 && x2==6 && y2==7 ) || ( x==6 && y==7 && x2==6 && y2==6 ) )
											{
												if( m[ 1 ][ 10 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 1 ][ 10 ] = checar_local(m[ 1 ][ 10 ] ,aux ,&turn);
												}
											}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  COLUNA       7        DE        ACORDO         COM       O     TABULEIRO    DO   JOGO   ////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
											else if( ( x==7 && y==1 && x2==7 && y2==2 ) || ( x==7 && y==2 && x2==7 && y2==1 ) )
											{
												if( m[ 11 ][ 12 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 11 ][ 12 ] = checar_local(m[ 11 ][ 12 ] ,aux ,&turn);
												}
											}
											else if( ( x==7 && y==2 && x2==7 && y2==3 ) || ( x==7 && y==3 && x2==7 && y2==2 ) )
											{
												if( m[ 9 ][ 12 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 9 ][ 12 ] = checar_local(m[ 9 ][ 12 ] ,aux ,&turn);
												}
											}
											else if( ( x==7 && y==3 && x2==7 && y2==4 ) || ( x==7 && y==4 && x2==7 && y2==3 ) )
											{
												if( m[ 7 ][ 12 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 7 ][ 12 ] = checar_local(m[ 7 ][ 12 ] ,aux ,&turn);
												}
											}
											else if( ( x==7 && y==4 && x2==7 && y2==5 ) || ( x==7 && y==5 && x2==7 && y2==4 ) )
											{
												if( m[ 5 ][ 12 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 5 ][ 12 ] = checar_local(m[ 5 ][ 12 ] ,aux ,&turn);
												}
											}
											else if( ( x==7 && y==5 && x2==7 && y2==6 ) || ( x==7 && y==6 && x2==7 && y2==5 ) )
											{
												if( m[ 3 ][ 12 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 3 ][ 12 ] = checar_local(m[ 3 ][ 12 ] ,aux ,&turn);
												}
											}
											else if( ( x==7 && y==7 && x2==7 && y2==6 ) || ( x==7 && y==6 && x2==7 && y2==7 ) )
											{
												if( m[ 1 ][ 12 ] == '|' )
												{
													printf("\n\t\tLocal X( %i,%i ) e Y( %i,%i ) ja esta preenchido!\n\n",x,y,x2,y2);
													turn=2;
													system("pause");
												}
												else
												{
													aux = '|';
													m[ 1 ][ 12 ] = checar_local(m[ 1 ][ 12 ] ,aux ,&turn);
												}
											}
											else
											{
												printf("\n\t\tJogada invalida!\n\n");
												system("pause");
												turn = 2;
											}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////  	FINAL  JOGADOR 2         FINAL  JOGADOR 2         FINAL  JOGADOR 2         FINAL  JOGADOR 2          ////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////                                     	1 ª FILEIRA DE QUADRADOS                                         ////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		
										if( ( m[ 0 ][ 1 ]=='-' ) &&  ( m[ 2 ][ 1 ]=='-' ) && ( m[ 1 ][ 0 ]=='|' ) &&  ( m[ 1 ][ 2 ]=='|' ) &&  ( m[ 1 ][ 1 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 1 ][ 1 ]='2';  
											}
										}
										else if( ( m[ 0 ][ 3 ]=='-' ) &&  ( m[ 2 ][ 3 ]=='-' ) && ( m[ 1 ][ 2 ]=='|' ) &&  ( m[ 1 ][ 4 ]=='|' ) &&  ( m[ 1 ][ 4 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 1 ][ 4 ]='2';  
											}
										}
										else if( ( m[ 0 ][ 5 ]=='-' ) &&  ( m[ 2 ][ 5 ]=='-' ) && ( m[ 1 ][ 4 ]=='|' ) &&  ( m[ 1 ][ 6 ]=='|' ) &&  ( m[ 1 ][ 6 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 1 ][ 6 ]='2';  
											}
										}
										else if( ( m[ 0 ][ 7 ]=='-' ) &&  ( m[ 2 ][ 7 ]=='-' ) && ( m[ 1 ][ 6 ]=='|' ) &&  ( m[ 1 ][ 8 ]=='|' ) &&  ( m[ 1 ][ 7 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 1 ][ 7 ]='2';  
											}
										}
										else if( ( m[ 0 ][ 9 ]=='-' ) &&  ( m[ 2 ][ 9 ]=='-' ) && ( m[ 1 ][ 8 ]=='|' ) &&  ( m[ 1 ][ 10 ]=='|' ) &&  ( m[ 1 ][ 9 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 1 ][ 9 ]='2';  
											}
										}
										else if( ( m[ 0 ][ 11 ]=='-' ) &&  ( m[ 2 ][ 11 ]=='-' ) && ( m[ 1 ][ 10 ]=='|' ) &&  ( m[ 1 ][ 12 ]=='|' ) &&  ( m[ 1 ][ 11 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 1 ][ 11 ]='2';  
											}
										}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////                                     	2 ª FILEIRA DE QUADRADOS                                         ////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
										else if( ( m[ 2 ][ 1 ]=='-' ) &&  ( m[ 4 ][ 1 ]=='-' ) && ( m[ 3 ][ 0 ]=='|' ) &&  ( m[ 3 ][ 2 ]=='|' ) &&  ( m[ 3 ][ 1 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 3 ][ 1 ]='2';  
											}
										}
										else if( ( m[ 2 ][ 3 ]=='-' ) &&  ( m[ 4 ][ 3 ]=='-' ) && ( m[ 3 ][ 2 ]=='|' ) &&  ( m[ 3 ][ 4 ]=='|' ) &&  ( m[ 3 ][ 3 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 3 ][ 3 ]='2';  
											}
										}
										else if( ( m[ 2 ][ 5 ]=='-' ) &&  ( m[ 4 ][ 5 ]=='-' ) && ( m[ 3 ][ 4 ]=='|' ) &&  ( m[ 3 ][ 6 ]=='|' ) &&  ( m[ 3 ][ 5 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 3 ][ 5 ]='2';  
											}
										}
										else if( ( m[ 2 ][ 7 ]=='-' ) &&  ( m[ 4 ][ 7 ]=='-' ) && ( m[ 3 ][ 6 ]=='|' ) &&  ( m[ 3 ][ 8 ]=='|' ) &&  ( m[ 3 ][ 7 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 3 ][ 7 ]='2';  
											}
										}
										else if( ( m[ 2 ][ 9 ]=='-' ) &&  ( m[ 4 ][ 9 ]=='-' ) && ( m[ 3 ][ 8 ]=='|' ) &&  ( m[ 3 ][ 10 ]=='|' ) &&  ( m[ 3 ][ 9 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 3 ][ 9 ]='2';  
											}
										}
										else if( ( m[ 2 ][ 11 ]=='-' ) &&  ( m[ 4 ][ 11 ]=='-' ) && ( m[ 3 ][ 10 ]=='|' ) &&  ( m[ 3 ][ 12 ]=='|' ) &&  ( m[ 3 ][ 11 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 3 ][ 11 ]='2';  
											}
										}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////                                     	3 ª FILEIRA DE QUADRADOS                                         ////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
										else if( ( m[ 4 ][ 1 ]=='-' ) &&  ( m[ 6 ][ 1 ]=='-' ) && ( m[ 5 ][ 0 ]=='|' ) &&  ( m[ 5 ][ 2 ]=='|' ) &&  ( m[ 5 ][ 1 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 5 ][ 1 ]='2';  
											}
										}
										else if( ( m[ 4 ][ 3 ]=='-' ) &&  ( m[ 6 ][ 3 ]=='-' ) && ( m[ 5 ][ 2 ]=='|' ) &&  ( m[ 5 ][ 4 ]=='|' ) &&  ( m[ 5 ][ 3 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 5 ][ 3 ]='2';  
											}
										}
										else if( ( m[ 4 ][ 5 ]=='-' ) &&  ( m[ 6 ][ 5 ]=='-' ) && ( m[ 5 ][ 4 ]=='|' ) &&  ( m[ 5 ][ 6 ]=='|' ) &&  ( m[ 5 ][ 5 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 5 ][ 5 ]='2';  
											}
										}
										else if( ( m[ 4 ][ 7 ]=='-' ) &&  ( m[ 6 ][ 7 ]=='-' ) && ( m[ 5 ][ 6 ]=='|' ) &&  ( m[ 5 ][ 8 ]=='|' ) &&  ( m[ 5 ][ 7 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 5 ][ 7 ]='2';  
											}
										}
										else if( ( m[ 4 ][ 9 ]=='-' ) &&  ( m[ 6 ][ 9 ]=='-' ) && ( m[ 5 ][ 8 ]=='|' ) &&  ( m[ 5 ][ 10 ]=='|' ) &&  ( m[ 5 ][ 9 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 5 ][ 9 ]='2';  
											}
										}
										else if( ( m[ 4 ][ 11 ]=='-' ) &&  ( m[ 6 ][ 11 ]=='-' ) && ( m[ 5 ][ 10 ]=='|' ) &&  ( m[ 5 ][ 12 ]=='|' ) &&  ( m[ 5 ][ 11 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 5 ][ 11 ]='2';  
											}
										}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////                                     	4 ª FILEIRA DE QUADRADOS                                         ////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
										else if( ( m[ 6 ][ 1 ]=='-' ) &&  ( m[ 8 ][ 1 ]=='-' ) && ( m[ 7 ][ 0 ]=='|' ) &&  ( m[ 7 ][ 2 ]=='|' ) &&  ( m[ 7 ][ 1 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 7 ][ 1 ]='2';  
											}
										}
										else if( ( m[ 6 ][ 3 ]=='-' ) &&  ( m[ 8 ][ 3 ]=='-' ) && ( m[ 7 ][ 2 ]=='|' ) &&  ( m[ 7 ][ 4 ]=='|' ) &&  ( m[ 7 ][ 3 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 7 ][ 3 ]='2';  
											}
										}
										else if( ( m[ 6 ][ 5 ]=='-' ) &&  ( m[ 8 ][ 5 ]=='-' ) && ( m[ 7 ][ 4 ]=='|' ) &&  ( m[ 7 ][ 6 ]=='|' ) &&  ( m[ 7 ][ 5 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 7 ][ 5 ]='2';  
											}
										}
										else if( ( m[ 6 ][ 7 ]=='-' ) &&  ( m[ 8 ][ 7 ]=='-' ) && ( m[ 7 ][ 6 ]=='|' ) &&  ( m[ 7 ][ 8 ]=='|' ) &&  ( m[ 7 ][ 7 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 7 ][ 7 ]='2';  
											}
										}
										else if( ( m[ 6 ][ 9 ]=='-' ) &&  ( m[ 8 ][ 9 ]=='-' ) && ( m[ 7 ][ 8 ]=='|' ) &&  ( m[ 7 ][ 10 ]=='|' ) &&  ( m[ 7 ][ 9 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 7 ][ 9 ]='2';  
											}
										}
										else if( ( m[ 6 ][ 11 ]=='-' ) &&  ( m[ 8 ][ 11 ]=='-' ) && ( m[ 7 ][ 10 ]=='|' ) &&  ( m[ 7 ][ 12 ]=='|' ) &&  ( m[ 7 ][ 11 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 7 ][ 11 ]='2';  
											}
										}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////                                     	5 ª FILEIRA DE QUADRADOS                                         ////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
										else if( ( m[ 8 ][ 1 ]=='-' ) &&  ( m[ 10 ][ 1 ]=='-' ) && ( m[ 9 ][ 0 ]=='|' ) &&  ( m[ 9 ][ 2 ]=='|' ) &&  ( m[ 9 ][ 1 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 9 ][ 1 ]='2';  
											}
										}
										else if( ( m[ 8 ][ 3 ]=='-' ) &&  ( m[ 10 ][ 3 ]=='-' ) && ( m[ 9 ][ 2 ]=='|' ) &&  ( m[ 9 ][ 4 ]=='|' ) &&  ( m[ 9 ][ 3 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 9 ][ 3 ]='2';  
											}
										}
										else if( ( m[ 8 ][ 5 ]=='-' ) &&  ( m[ 10 ][ 5 ]=='-' ) && ( m[ 9 ][ 4 ]=='|' ) &&  ( m[ 9 ][ 6 ]=='|' ) &&  ( m[ 9 ][ 5 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 9 ][ 5 ]='2';  
											}
										}
										else if( ( m[ 8 ][ 7 ]=='-' ) &&  ( m[ 10 ][ 7 ]=='-' ) && ( m[ 9 ][ 6 ]=='|' ) &&  ( m[ 9 ][ 8 ]=='|' ) &&  ( m[ 9 ][ 7 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 9 ][ 7 ]='2';  
											}
										}
										else if( ( m[ 8 ][ 9 ]=='-' ) &&  ( m[ 10 ][ 9 ]=='-' ) && ( m[ 9 ][ 8 ]=='|' ) &&  ( m[ 9 ][ 10 ]=='|' ) &&  ( m[ 9 ][ 9 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 9 ][ 9 ]='2';  
											}
										}
										else if( ( m[ 8 ][ 11 ]=='-' ) &&  ( m[ 10 ][ 11 ]=='-' ) && ( m[ 9 ][ 10 ]=='|' ) &&  ( m[ 9 ][ 12 ]=='|' ) &&  ( m[ 9 ][ 11 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 9 ][ 11 ]='2';  
											}
										}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////                                     	6 ª FILEIRA DE QUADRADOS                                         ////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
										else if( ( m[ 10 ][ 1 ]=='-' ) &&  ( m[ 12 ][ 1 ]=='-' ) && ( m[ 11 ][ 0 ]=='|' ) &&  ( m[ 11 ][ 2 ]=='|' ) &&  ( m[ 11 ][ 1 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 11 ][ 1 ]='2';  
											}
										}
										else if( ( m[ 10 ][ 3 ]=='-' ) &&  ( m[ 12 ][ 3 ]=='-' ) && ( m[ 11 ][ 2 ]=='|' ) &&  ( m[ 11 ][ 4 ]=='|' ) &&  ( m[ 11 ][ 3 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 11 ][ 3 ]='2';  
											}
										}
										else if( ( m[ 10 ][ 5 ]=='-' ) &&  ( m[ 12 ][ 5 ]=='-' ) && ( m[ 11 ][ 4 ]=='|' ) &&  ( m[ 11 ][ 6 ]=='|' ) &&  ( m[ 11 ][ 5 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 11 ][ 5 ]='2';  
											}
										}
										else if( ( m[ 10 ][ 7 ]=='-' ) &&  ( m[ 12 ][ 7 ]=='-' ) && ( m[ 11 ][ 6 ]=='|' ) &&  ( m[ 11 ][ 8 ]=='|' ) &&  ( m[ 11 ][ 7 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 11 ][ 7 ]='2';  
											}
										}
										else if( ( m[ 10 ][ 9 ]=='-' ) &&  ( m[ 12 ][ 9 ]=='-' ) && ( m[ 11 ][ 8 ]=='|' ) &&  ( m[ 11 ][ 10 ]=='|' ) &&  ( m[ 11 ][ 9 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 11 ][ 9 ]='2';  
											}
										}
										else if( ( m[ 10 ][ 11 ]=='-' ) &&  ( m[ 12 ][ 11 ]=='-' ) && ( m[ 11 ][ 10 ]=='|' ) &&  ( m[ 11 ][ 12 ]=='|' ) &&  ( m[ 11 ][ 11 ]==' ' ) )
										{
											if(turn == 1)
											{
												printf("\n\t\tJOGADOR 2: +1 PTS, JOGA NOVAMENTE!\n\n");
												system("pause");
												pontos_2++;
												turn = 2;
												m[ 11 ][ 11 ]='2';  
											}
										}
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////                                  	FIM DAS CONDIÇÕES DE PONTUAÇÃO                                        ///////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		}


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////                                         	CONDIÇÕES VITÓRIA                                             ///////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
										if(pontos_2>=19)
										{
											printf("\n\n\\t\t\tJOGADOR 2 VENCEU ! PARABENS !");
											system("pause");
											break;
										}
										if(pontos_1>=19)
										{
											printf("\n\n\\t\t\tJOGADOR 2 VENCEU ! PARABENS !");
											system("pause");
											break;
										}
	}
}

int main()
{
	srand(time(NULL));
	int menu, sair=0;
	while(sair!=1)
	{
		system("cls");
		printf("\n\n\n\n\t\t\tDEBIRICHE\n\n\n\t\t\t1 - JOGAR\n\n\t\t\t2 - INSTRUCOES\n\n\t\t\t3 - FECHAR\n\n\t\t\t--> ");
		scanf("%i",&menu);
		fflush(stdin);
		switch(menu)
		{
			case 1:
				jogar();
				break;
			case 2:
				instrucoes();
				break;
			case 3:
				sair=1;
				fechar();
				break;
			default:
				printf("\n\n\n\t\t\tOPCAO INVALIDA !\n\n\n");
				system("pause");
		}
	}
	return 0;
}
