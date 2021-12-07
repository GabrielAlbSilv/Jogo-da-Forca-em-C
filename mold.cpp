#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ControlesDaTela.cpp"
void moldura()
{
	int x;
	Cor(0xF4);
	system("cls");
	
	gotoxy(0,0);
	printf("\xC9");
	gotoxy(119,0);
	printf("\xBB");
	
	gotoxy(0,29);
	printf("\xC8");
	gotoxy(119,29);
	printf("\xBC");
	
	for(x=1; x<=118; x++)
	{
		gotoxy(x,0);
		printf("\xCD");
		gotoxy(x,29);
		printf("\xCD");
	}
	
	for(x=1; x<=28; x++)
	{
		gotoxy(0,x);
		printf("\xBA");
		gotoxy(119,x);
		printf("\xBA");
	}
}
