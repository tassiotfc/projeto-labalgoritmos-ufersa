#include <stdio.h>

void inicializa(int tabuleiro[3][3])
{
  int i, j;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      tabuleiro[i][j] = 0;
}

char caractere(int celula)
{
  if(celula == 1)
    return 'O';

  if(celula == 4)
    return 'X';

  return ' ';
}

void mostra(int tabuleiro[3][3])
{
  printf("%c|%c|%c\n",  caractere(tabuleiro[0][0]),
                        caractere(tabuleiro[0][1]),
                        caractere(tabuleiro[0][2]));

  printf("-+-+-\n");
  
  printf("%c|%c|%c\n",  caractere(tabuleiro[1][0]),
                        caractere(tabuleiro[1][1]),
                        caractere(tabuleiro[1][2]));

  printf("-+-+-\n");
  printf("%c|%c|%c\n",  caractere(tabuleiro[2][0]),
                        caractere(tabuleiro[2][1]),
                        caractere(tabuleiro[2][2]));
}

/**
 * Deve retornar o status do jogo no tabuleiro:
 *   1 se for a vez do jogador 1
 *   4 se for a vez do jogador 2
 *   0  se a partida terminou em empate
 *   -1  se o jogador 1 venceu
 *   -4  se o jogador 2 venceu
 */
int status(int tabuleiro[3][3])
{
  int casas = 0, i, j,aux=2,soma3=0,soma=0,soma1=0,soma2=0;
  for(i = 0; i < 3; i++){
	soma=0;
    soma1=0;
    soma2=0;
    soma3=0;
		for(j = 0; j < 3; j++,aux--){
    		soma+=tabuleiro[i][j];
    		soma1+=tabuleiro[j][j];
    		soma2+=tabuleiro[j][aux];
    		soma3+=tabuleiro[j][i];
			if(soma3==12){
    			return -4;
    			break;
			}
			if(soma3==3){
    			return -1;
    			break;
			}
			if(soma2==12){
    			return -4;
    			break;
			}
			if(soma2==3){
    			return -1;
    			break;
			}
			if(soma1==12){
    			return -4;
    			break;
			}
			if(soma1==3){
    			return -1;
    			break;
			}
			if(soma==3){
    			return -1;
    			break;
			}
			if(soma==12){
    			return -4;
    			break;
			}
      		if(tabuleiro[i][j]){
      		casas++;
      		}
      	}
	}
	if(casas == 9)
    return 0;

  	return ((casas%2) == 0)? 1 : 4;
}

void joga(int tabuleiro[3][3], int jogador)
{
  int casa, i, j;

  do{
    do{
      printf("Entre com a casa a ser jogada: ");
      scanf("%d", &casa);
    }while(casa < 1 || casa > 9);

    casa--;
  }while(tabuleiro[casa/3][casa%3] != 0);
  
  tabuleiro[casa/3][casa%3] = jogador;
}

int main(void)
{
  int tabuleiro[3][3], situacao = 1;
  inicializa(tabuleiro);

  do {
    mostra(tabuleiro);
    joga(tabuleiro, situacao);
    situacao = status(tabuleiro);
  }while(situacao > 0);

  mostra(tabuleiro);

  switch(situacao) {
    case 0:
      printf("Partida empatada!\n");
    break;
    case -1:
      printf("Jogador 1 venceu!\n");
    break;
    case -4:
      printf("Jogador 2 venceu!\n");
    break;
    default:
      printf("Isto não deveria acontecer!\n");
  }

  return 0;
}
