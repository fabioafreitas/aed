#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int valor;
    int peso;
}Item;

// calcula o maior valor que se pode carregar numa mochila com uma determinada quantidade de itens
void MochilaBooleana (int capacidade, int qtd, Item* item) {

    // tabela que armazena os valores com relação aos itens e a capacidade atual da mochila no momento
    int tabela[qtd+1][capacidade+1];

    // limpar primeira line e coluna, pois o item 0 nao existe
    // na contagem de itens e com capacidade 0 nao é possível carregar nada
    int i, j;

    for( i = 0 ; i < qtd+1 ; i++) {
        for( j = 0 ; j < capacidade+1 ; j++ ) {

            // if resposável por zerar a primeira linha
            if(i == 0 || j == 0) {
                tabela[i][j] = 0;
            }

        }
    }

}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int capacidade, qtd;

    do { // recebe o valor da capacidade
        printf("\nDigite a capacidade da mochila: ");
        scanf("%i", &capacidade);
        if(capacidade < 0)
            printf("\nValor inválido!");
    }while(capacidade < 0);

    do { // recebe a quantidade de itens a serem calculados
        printf("\nDigite a quantidade de itens: ");
        scanf("%i", &qtd);
        if(qtd < 0)
            printf("\nValor inválido!");
    }while(qtd < 0);

    int i;
    Item item[qtd];

    for(i = 0 ; i < qtd ; i++) { //  - recebe o valor e peso respectivo de cada item (valores maiores que zero)

        printf("Item %i:\ndigite o valor - ",i+1);
        scanf("%i",&item[i].valor);
        printf("\ndigite o peso - ",i+1);
        scanf("%i",&item[i].peso);

        if(item[i].peso <= 0 || item[i].valor < 0) i--;

    }
}
