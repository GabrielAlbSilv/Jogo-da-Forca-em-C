#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "mold.cpp"

/*Aluno: Gabriel Albuquerque de Moura Silva
Número: Até agora não me falaram qual é o meu número :(
Professor: Fernando Souza de Faria
Curso: Desenvolvimento de Sistema-Módulo 1
Turma: 1ºH
Data de criação: 17/06/2021*/
void main()
{
	int  tecla=0, pos=60, tiro, x,y, tela[120][30], ponto=0, inimigo=0, xant=0, yant=0;//fase 1 e 2 variaveis
	int vida=3, acerto=0;//fase 3 e 4 variaveis
	char res;
	DesligaCursor();
	system("cls");
	moldura();
	Cor(0xF9);
	gotoxy(pos,26);
	printf("A");
	gotoxy(pos-1,27);
	printf("\xC9 \xBB");
	gotoxy(2,28);
	printf("Pontos = %d",ponto);
	gotoxy(15,28);
	printf("Inimigos: %02d",inimigo);
	gotoxy(30,28);
	printf("Vidas: %02d",vida);
	
	//fase 1
	while(ponto<15)
	{
		srand(time(NULL));
		if(kbhit())
		{
			tecla = getch();
			gotoxy(pos,26);
			printf(" ");
			gotoxy(pos-1,27);
			printf("   ");
			printf(" ");
			if(tecla == 77)
			{
				if(pos<116)
				{
					pos++;
				}
			}
			if(tecla == 75)
			{
				if(pos>2)
				{
					pos--;
				}
			}
			gotoxy(pos,26);
			printf("A");
			gotoxy(pos-1,27);
			printf("\xC9 \xBB");
			if(tecla==32)
			{
				for(tiro=25;tiro>=1;tiro--)
				{
					gotoxy(pos,tiro);
					printf("^");
					Sleep(30);
					gotoxy(pos,tiro);
					printf(" ");	
					if(tela[pos][tiro]==1)
					{
						ponto++;
						gotoxy(30,28);
						printf("Vidas: %02d",vida);
						gotoxy(2,28);
						printf("Pontos = %02d",ponto);
						tela[pos][tiro]=0;
						Beep (261,250);
						if (ponto%5==0)
						{
							vida++;
						}
						break;	
						
					}			
				}
			}
		}
		if(!kbhit())
		{
			x=rand() % 110+5;
			y=rand() % 20+1;	
			if(x != xant || y != yant)	
			{	
				gotoxy(x,y);
				printf("%c",01);
				tela[x][y]=1;
				inimigo++;	
				gotoxy(15,28);
				printf("Inimigos: %02d",inimigo);
				xant = x;
				yant = y;
				if(inimigo % 20 == 0 && inimigo!=0)
				{
					vida--;
					gotoxy(30,28);
					printf("Vidas: %02d",vida);
					if(vida < 0)
					{
						system("cls");
						moldura();
						gotoxy(50,15);
						printf("Game Over!!!");
						Sleep(2000);
						getch();
						exit(1);
					}
				}
			}
		}
	}
	//fase 2
	ponto=15;	
	gotoxy(pos,26);
	printf("A");
	gotoxy(pos-1,27);
	printf("\xC9 \xBB");
	tecla=0, pos=60, tiro, x,y, tela[120][30], inimigo=0, xant=0, yant=0;
	system("cls");
	gotoxy(50,15);
	printf("Bem vindo ao segundo Mundo!!!");
	getch();
	system("cls");
	Cor(0xFC);
	moldura();
	gotoxy(2,28);
	printf("Pontos = %d",ponto);
	gotoxy(15,28);
	printf("Inimigos: %02d",inimigo);
	gotoxy(30,28);
	printf("Vidas: %02d",vida);
	while(ponto<30)
	{
		gotoxy(2,28);
		printf("Pontos = %d",ponto);
		gotoxy(15,28);
		printf("Inimigos: %02d",inimigo);
		gotoxy(30,28);
		printf("Vidas: %02d",vida);	
		srand(time(NULL));
		if(kbhit())
		{
			tecla = getch();
			gotoxy(pos,26);
			printf(" ");
			gotoxy(pos-1,27);
			printf("   ");
			printf(" ");
			if(tecla == 77)
			{
				if(pos<116)
				{
					pos++;
				}
			}
			if(tecla == 75)
			{
				if(pos>2)
				{
					pos--;
				}
			}
			gotoxy(pos,26);
			printf("A");
			gotoxy(pos-1,27);
			printf("\xC9 \xBB");
			if(tecla==32)
			{
				for(tiro=25;tiro>=1;tiro--)
				{
					gotoxy(pos,tiro);
					printf("^");
					Sleep(30);
					gotoxy(pos,tiro);
					printf(" ");	
					if(tela[pos][tiro]==1)
					{
						inimigo--;
						ponto++;
						gotoxy(2,28);
						gotoxy(15,28);
						printf("Inimigos: %02d",inimigo);
						gotoxy(2,28);
						printf("Pontos = %d",ponto);
						tela[pos][tiro]=0;
						Beep (261,250);
						if (ponto%5==0)
						{
							vida++;
						}
						break;	
					}			
				}
			}
		}
		if(!kbhit())
		{
			x=rand() % 110+5;
			y=rand() % 20+1;	
			if(x != xant || y != yant)	
			{	
				gotoxy(x,y);
				printf("%c",01);
				tela[x][y]=1;
				inimigo++;	
				gotoxy(15,28);
				printf("Inimigos: %02d",inimigo);
				xant = x;
				yant = y;
				if(inimigo % 20 == 0 && inimigo!=0)
				{
					vida--;
					gotoxy(30,28);
					printf("Vidas: %02d",vida);
					if(vida < 0)
					{
						system("cls");
						moldura();
						gotoxy(50,15);
						printf("Game Over!!!");
						Sleep(2000);
						getch();
						exit(1);
					}
				}
			}
		}
	}
	//fase3
	system("cls");
	gotoxy(45,10);
	printf("Bem vindo ao Terceiro Mundo!");
	gotoxy(42,11);
	printf("Dessa vez vamos de Jogo da Forca :D");
	gotoxy(41,12);
	printf("Voc\x88 ter\xA0 que adivinhar tr\x88s palavras!!");
	gotoxy(41,13);
	printf("Voc\x88 recebeu mais cinco vidas, boa sorte :D");
	getch();
	system("cls");
	Cor(0xFC);
	moldura();
	srand(time(NULL));
	gotoxy(2,28);
	printf("Pontos = %d",ponto);
	vida=vida+5;
	gotoxy(15,28);
	printf("Vidas: %02d",vida);
	//abaixo desenho forca
	for(x=30; x<40; x++) //base esquerda da forca
	{
		gotoxy(x,20);
		printf("\xCD");
	}
	for(x=40; x<51; x++)//base direita da forca
	{
		gotoxy(x,20);
		printf("\xCD");
	}
	gotoxy(40,20);//"interligador" da base (esquerda e direita) e a haste da forca
	printf("\xCA");
	for(x=19; x>10; x--)//haste da forca
	{
		gotoxy(40,x);
		printf("\xBA");
	}
	gotoxy(40,10);//"interligador" da haste e da base superio da forca
	printf("\xC9");
	for(x=41; x<50; x++)//base superior da forca
	{
		gotoxy(x,10);
		printf("\xCD");
	}
	gotoxy(50,10);//"interligador" da base superior e da corda da forca
	printf("\xBB");
	for(x=11; x<14; x++)//corda da forca
	{
		gotoxy(50,x);
		printf("\x7C");
	}
	gotoxy(50,14);//cabeça da vítima
	printf("O");
	gotoxy(49,15);//braço esquerdo da vítima
	printf("/");
	gotoxy(51,15);//braço direito da vítima
	printf("\\");
	gotoxy(50,15);//tronco da vítima
	printf("|");
	gotoxy(50,16);//tronco da vítima
	printf("|");
	gotoxy(49,17);//perna esquerda da vítima
	printf("/");
	gotoxy(51,17);//perna direita da vítima
	printf("\\");
	//acima desenho forca/embaixo espaço para as letras
	
	//espaço entre as letras gotoxy(coluna+2,linha 19)
	
	gotoxy(73,19); //Espaço para a letra que o usuário digitar  um coloque o scanf (ou getchar) em gotoxy(55,18)
	printf("-");
	
	gotoxy(55,19); //Espaço para Letra 1=T
	printf("-");
	
	gotoxy(57,19); //Espaço para Letra 2=i
	printf("-");
	
	gotoxy(59,19); //Espaço para Letra 3=t
	printf("-");
	
	gotoxy(61,19); //Espaço para Letra 4=a
	printf("-");
	
	gotoxy(63,19); //Espaço para Letra 5=n
	printf("-");
	
	gotoxy(65,19); //Espaço para Letra 6=i
	printf("-");
	
	gotoxy(67,19); //Espaço para Letra 7=c
	printf("-");
	while (acerto<=5)
	{
		gotoxy (55,8);
		printf("Tema da vez: Filmes!!");
		gotoxy(2,28);
		printf("Pontos = %d",ponto);
		gotoxy(15,28);
		printf("Vidas: %02d",vida);
		gotoxy(76,19);
		printf("<---A letra digitada t\xA0 aqui!");
		gotoxy(73,18);
		fflush(stdin);
		res = getchar();
  		if (res == 'T' || res == 't')
  		{
  			gotoxy(55,18);
  			printf("T");
  			gotoxy(59,18);
  			printf("t");
			acerto++;
			ponto++;
			vida=vida+1;
  		}
  		else
  		{
  			vida--;
		}
  		if (res == 'I' || res == 'i')
  		{
  			gotoxy(57,18);
  			printf("i");
  			gotoxy(65,18);
  			printf("i");
			acerto++;
			ponto++;
			vida=vida+2;
  		}
  		if (res == 'A' || res == 'a')
  		{
  			gotoxy(61,18);
  			printf("a");
			acerto++;
			ponto++;
			vida=vida+2;
  		}
  		if (res == 'N' || res == 'n')
  		{
  			gotoxy(63,18);
  			printf("n");
			acerto++;
			ponto++;
			vida=vida+2;
  		}
  		if (res == 'C' || res == 'c')
  		{
  			gotoxy(67,18);
  			printf("c");
			acerto++;
			ponto++;
			vida=vida+1;
  		}
  		else
  		{
  			vida--;
		}
		if(acerto==5)
		{
			gotoxy(10,9);
			printf("Voc\x88 venceu!");
			getch();
			break;
		}
		if(acerto%3==0)
		{
			vida=vida+1;
		}
		if(vida<3)
		{
			gotoxy(55,10);
			printf("Dica: Esse filme estreiou em 1998 e foi um sucesso absoluto");
		}
		if(vida==0)
		{
			gotoxy(55,12);
			printf("Cuidado! Mais um erro e voc\x88 perde o jogo!");
		}
		if(vida<0)
		{
			break;
		}
	}
	//fase4
	acerto=0;
	system("cls");
	gotoxy(45,10);
	printf("Bem vindo ao Quarto Mundo!");
	gotoxy(42,11);
	printf("Dessa vez vamos de Jogo da Forca :D");
	gotoxy(41,12);
	printf("Voc\x88 ter\xA0 que adivinhar tr\x88s palavras!!");
	gotoxy(41,13);
	printf("Voc\x88 recebeu mais cinco vidas, boa sorte :D");
	getch();
	system("cls");
	Cor(0xFC);
	moldura();
	srand(time(NULL));
	gotoxy(2,28);
	printf("Pontos = %d",ponto);
	vida=vida+5;
	gotoxy(15,28);
	printf("Vidas: %02d",vida);
	//abaixo desenho forca
	for(x=30; x<40; x++) //base esquerda da forca
	{
		gotoxy(x,20);
		printf("\xCD");
	}
	for(x=40; x<51; x++)//base direita da forca
	{
		gotoxy(x,20);
		printf("\xCD");
	}
	gotoxy(40,20);//"interligador" da base (esquerda e direita) e a haste da forca
	printf("\xCA");
	for(x=19; x>10; x--)//haste da forca
	{
		gotoxy(40,x);
		printf("\xBA");
	}
	gotoxy(40,10);//"interligador" da haste e da base superio da forca
	printf("\xC9");
	for(x=41; x<50; x++)//base superior da forca
	{
		gotoxy(x,10);
		printf("\xCD");
	}
	gotoxy(50,10);//"interligador" da base superior e da corda da forca
	printf("\xBB");
	for(x=11; x<14; x++)//corda da forca
	{
		gotoxy(50,x);
		printf("\x7C");
	}
	gotoxy(50,14);//cabeça da vítima
	printf("O");
	gotoxy(49,15);//braço esquerdo da vítima
	printf("/");
	gotoxy(51,15);//braço direito da vítima
	printf("\\");
	gotoxy(50,15);//tronco da vítima
	printf("|");
	gotoxy(50,16);//tronco da vítima
	printf("|");
	gotoxy(49,17);//perna esquerda da vítima
	printf("/");
	gotoxy(51,17);//perna direita da vítima
	printf("\\");
	//acima desenho forca/embaixo espaço para as letras
	
	//espaço entre as letras gotoxy(coluna+2,linha 19)
	
	gotoxy(73,19); //Espaço para a letra que o usuário digitar  um coloque o scanf (ou getchar) em gotoxy(55,18)
	printf("-");
	
	gotoxy(55,19); //Espaço para Letra 1=P
	printf("-");
	
	gotoxy(57,19); //Espaço para Letra 2=h
	printf("-");
	
	gotoxy(59,19); //Espaço para Letra 3=y
	printf("-");
	
	gotoxy(61,19); //Espaço para Letra 4=t
	printf("-");
	
	gotoxy(63,19); //Espaço para Letra 5=o
	printf("-");
	
	gotoxy(65,19); //Espaço para Letra 6=n
	printf("-");

	while (acerto<8)
	{
		gotoxy (55,8);
		printf("Tema da vez: Linguagem de Programa\x87\xC6o Orientada a objetos!!");
		gotoxy(2,28);
		printf("Pontos = %d",ponto);
		gotoxy(15,28);
		printf("Vidas: %02d",vida);
		gotoxy(76,19);
		printf("<---A letra digitada t\xA0 aqui!");
		gotoxy(73,18);
		fflush(stdin);
		res = getchar();
  		if (res == 'P' || res == 'p')
  		{
  			gotoxy(55,18);
  			printf("P");
			acerto++;
			ponto++;
			vida=vida+1;
  		}
  		else
  		{
  			vida--;
		}
  		if (res == 'h' || res == 'h')
  		{
  			gotoxy(57,18);
  			printf("h");
			acerto++;
			ponto++;
			vida=vida+2;
  		}
  		if (res == 'Y' || res == 'y')
  		{
  			gotoxy(59,18);
  			printf("y");
			acerto++;
			ponto++;
			vida=vida+2;
  		}
  		if (res == 'T' || res == 't')
  		{
  			gotoxy(61,18);
  			printf("t");
			acerto++;
			ponto++;
			vida=vida+2;
  		}
  		if (res == 'O' || res == 'o')
  		{
  			gotoxy(63,18);
  			printf("o");
			acerto++;
			ponto++;
			vida=vida+1;
  		}
  		if (res == 'N' || res == 'n')
  		{
  			gotoxy(65,18);
  			printf("n");
			acerto++;
			ponto++;
			vida=vida+1;
  		}
  		else
  		{
  			vida--;
		}
		if(acerto>5)
		{
			getch();
			break;
		}
		if(acerto%3==0)
		{
			vida=vida+1;
		}
		if(vida<3)
		{
			gotoxy(55,10);
			printf("Dica: Essa linguagem foi criada recentemente");
		}
		if(vida==0)
		{
			gotoxy(55,12);
			printf("Cuidado! Mais um erro e voc\x88 perde o jogo!");
		}
		if(vida<0)
		{
			break;
		}
	}
	system("cls");
	gotoxy(45,10);
	printf("Fim do Jogo!!!");
	getch();
}
