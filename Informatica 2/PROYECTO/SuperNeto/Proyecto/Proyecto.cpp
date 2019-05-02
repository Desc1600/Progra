#include "pch.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <MMSystem.h>

#pragma comment(lib,"Winmm.lib")

#define FIL 20 
#define COL 20

#define Izquierda 75
#define Derecha 77
#define Arriba 72
#define Abajo 80

#define Salir 27
#define Inicio 13
#define Reinicio 114


using namespace System;
using namespace std;

bool estaEnCajaAzul = false, estaElChampEnAzul = false;
int nivel = 0, winCond = 0;
int mapa[FIL][COL];
char tecla;
int x, y;


void ubicacion(int x, int y) {
	Console::SetCursorPosition(x, y); //ubicacion del objeto en el mapa x y 
}
int musica1() {
	PlaySound(L"C:\\Users\\Artorias\\Desktop\\SuperNeto\\Proyecto\\Inicio.wav", NULL, SND_FILENAME | SND_ASYNC);
	return 0;
}

int musica2() {
	PlaySound(L"C:\\Users\\Artorias\\Desktop\\SuperNeto\\Proyecto\\RolonaJugadora.wav", NULL, SND_FILENAME | SND_ASYNC);
	return 0;
}

int musica3() {
	PlaySound(L"C:\\Users\\Artorias\\Desktop\\SuperNeto\\Proyecto\\FinalPrron.wav", NULL, SND_FILENAME | SND_ASYNC);
	return 0;
}
int musica4() {
	PlaySound(L"C:\\Users\\Artorias\\Desktop\\SuperNeto\\Proyecto\\PerdistePrro.wav", NULL, SND_FILENAME | SND_ASYNC);
	return 0;
}

void moveCaja(int x, int y, char dir) {
	if (dir == 'r' && mapa[y][x + 1] != 1)
	{
		mapa[y][x] = 0;
		if (mapa[y][x + 1] == 3)
		{
			if (estaEnCajaAzul)//verifica si esta en en el coso azul
			{
				mapa[y][x] = 3;//vuelve el coso azul denuevo :v
				ubicacion(x, y);
				Console::ForegroundColor = ConsoleColor::Blue;
				cout << (char)177;
				mapa[y][x + 1] = 2;
				winCond++;
			}
			else
			{
				mapa[y][x + 1] = 2;
				winCond++;
			}
		}
		else
		{
			if (estaEnCajaAzul)
			{
				mapa[y][x] = 3;
				ubicacion(x, y);
				Console::ForegroundColor = ConsoleColor::Blue;
				cout << (char)177;
				mapa[y][x + 1] = 2;
				estaEnCajaAzul = false;
			}
			else
			{
				mapa[y][x + 1] = 2;
			}
		}
		ubicacion(x + 1, y);//posicion de la caja en x yS
		Console::ForegroundColor = ConsoleColor::Yellow;
		cout << (char)254;
	}
	if (dir == 'l' && mapa[y][x - 1] != 1)
	{
		mapa[y][x] = 0;
		if (mapa[y][x - 1] == 3)
		{
			if (estaEnCajaAzul)//verifica si esta en en el coso azul
			{
				mapa[y][x] = 3;//vuelve el coso azul denuevo :v
				ubicacion(x, y);
				Console::ForegroundColor = ConsoleColor::Blue;//vuelve a pintar el coso azul
				cout << (char)177;
				mapa[y][x - 1] = 2;
				winCond++;
			}
			else
			{
				mapa[y][x - 1] = 2;
				winCond++;
			}
		}
		else
		{
			if (estaEnCajaAzul)
			{
				mapa[y][x] = 3;
				ubicacion(x, y);
				Console::ForegroundColor = ConsoleColor::Blue;
				cout << (char)177;
				mapa[y][x - 1] = 2;
				estaEnCajaAzul = false;
			}
			else
			{
				mapa[y][x - 1] = 2;
			}
		}
		ubicacion(x - 1, y);//posicion de la caja en x yS
		Console::ForegroundColor = ConsoleColor::Yellow;
		cout << (char)254;
	}
	if (dir == 'u' && mapa[y - 1][x] != 1)
	{
		mapa[y][x] = 0;
		if (mapa[y - 1][x] == 3)
		{
			if (estaEnCajaAzul)//verifica si esta en en el coso azul
			{
				mapa[y][x] = 3;//vuelve el coso azul denuevo :v
				ubicacion(x, y);
				Console::ForegroundColor = ConsoleColor::Blue;
				cout << (char)177;
				mapa[y - 1][x] = 2;
				winCond++;
			}
			else
			{
				mapa[y - 1][x] = 2;
				winCond++;
			}
		}
		else
		{
			if (estaEnCajaAzul)
			{
				mapa[y][x] = 3;
				ubicacion(x, y);
				Console::ForegroundColor = ConsoleColor::Blue;
				cout << (char)177;
				mapa[y - 1][x] = 2;
				estaEnCajaAzul = false;
			}
			else
			{
				mapa[y - 1][x] = 2;
			}
		}
		ubicacion(x, y - 1);//posicion de la caja en x yS
		Console::ForegroundColor = ConsoleColor::Yellow;
		cout << (char)254;
	}
	if (dir == 'd' && mapa[y + 1][x] != 1)
	{
		mapa[y][x] = 0;
		if (mapa[y + 1][x] == 3)
		{
			if (estaEnCajaAzul)//verifica si esta en en el coso azul
			{
				mapa[y][x] = 3;//vuelve el coso azul denuevo :v
				ubicacion(x, y);
				Console::ForegroundColor = ConsoleColor::Blue;
				cout << (char)177;
				mapa[y + 1][x] = 2;
				winCond++;
			}
			else
			{
				mapa[y + 1][x] = 2;
				winCond++;
			}
		}
		else
		{
			if (estaEnCajaAzul)
			{
				mapa[y][x] = 3;
				ubicacion(x, y);
				Console::ForegroundColor = ConsoleColor::Blue;
				cout << (char)177;
				mapa[y + 1][x] = 2;
				estaEnCajaAzul = false;
			}
			else
			{
				mapa[y + 1][x] = 2;
			}
		}
		ubicacion(x, y + 1);//posicion de la caja en x yS
		Console::ForegroundColor = ConsoleColor::Yellow;
		cout << (char)254;
	}
}


//niveles 

void Nivel1() {
	int mapa1[FIL][COL] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,3,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,2,0,2,3,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,3,0,2,4,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,1,2,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,3,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};

	//copiar el contenido de mapa en mapa1
	for (int f = 0; f < FIL; f++) {
		for (int c = 0; c < COL; c++) {
			mapa[f][c] = mapa1[f][c];
		}
	}
	nivel = 1;
}
void Nivel2() {
	int mapa2[FIL][COL] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,3,0,0,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,2,0,2,1,0,0,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,1,4,2,0,1,0,0,1,3,1,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,0,1,1,1,1,0,1,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0},
		{0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0},
		{0,0,0,0,1,1,1,1,0,1,0,0,1,1,1,1,0,0,0,0},
		{0,0,0,1,3,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},




	};
	for (int f = 0; f < FIL; f++) {
		for (int c = 0; c < COL; c++) {
			mapa[f][c] = mapa2[f][c];
		}
	}
	nivel = 2;

}
void Nivel3() {
	int mapa3[FIL][COL] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,1,3,2,0,0,3,1,1,1,0,0,0,0,},
		{0,0,0,0,0,0,1,1,0,0,1,0,2,0,3,1,0,0,0,0,},
		{0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,1,0,0,0,0,},
		{0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,},
		{0,0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,},
		{0,0,0,0,0,0,0,1,1,1,1,0,0,0,1,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,1,2,2,1,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,},
		{5,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},


	};

	//copiar el contenido de mapa en mapa1
	for (int f = 0; f < FIL; f++) {
		for (int c = 0; c < COL; c++) {
			mapa[f][c] = mapa3[f][c];
		}
	}
	nivel = 3;

}
void Nivel4() {
	int mapa4[FIL][COL] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
		{0,0,0,1,3,2,0,0,0,0,0,0,0,3,1,0,0,0,0,0},
		{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,1,0,1,1,1,1,0,0,1,0,0,1,0,0,0,0,0},
		{0,0,0,1,0,1,1,1,1,0,2,1,1,1,1,0,0,0,0,0},
		{0,0,0,1,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0},
		{0,0,0,1,0,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0},
		{0,0,0,1,0,1,1,4,0,0,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,1,0,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0},
		{0,0,0,1,2,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0},
		{0,0,0,1,3,1,1,1,1,1,1,3,2,0,1,0,0,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};
	for (int f = 0; f < FIL; f++) {
		for (int c = 0; c < COL; c++) {
			mapa[f][c] = mapa4[f][c];
		}
	}nivel = 4;
}
void Bienvenida() {
	int bienvenida[FIL][COL] = {
		{8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,1,1,0,1,0,1,0,1,1,1,0,1,1,0,1,1,1,7},
		{7,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,7},
		{7,0,1,1,0,1,0,1,0,1,1,1,0,1,1,0,1,1,1,7},
		{7,0,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,1,0,7},
		{7,0,1,1,0,1,1,1,0,1,0,0,0,1,1,0,1,0,1,7},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,0,7},
		{7,0,0,1,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,7},
		{7,0,0,1,0,1,0,1,1,0,0,1,0,0,1,0,1,0,0,7},
		{7,0,0,1,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,7},
		{7,0,0,1,0,1,0,1,1,0,0,1,0,0,1,1,1,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8},
	};
	for (int f = 0; f < FIL; f++) {
		for (int c = 0; c < COL; c++) {
			mapa[f][c] = bienvenida[f][c];
		}
	}nivel = 5;
}
void Win() {
	int win[FIL][COL] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0},
		{0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,1,0,1,1,0,0,1,0,1,1,0,0,1,0,0,0,0},
		{0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0},
		{0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0},
		{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};
	for (int f = 0; f < FIL; f++) {
		for (int c = 0; c < COL; c++) {
			mapa[f][c] = win[f][c];
		}
	}nivel = 6;
}
void Lose() {
	int lose[FIL][COL] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0},
		{0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0},
		{0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0},
		{0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0},
		{0,0,1,0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0},
		{0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0},
		{0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0},
		{0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0},
		{0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,0,0,0},
		{0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0},
		{0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0},
		{0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0},
		{0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0},
		{0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

	};
	for (int f = 0; f < FIL; f++) {
		for (int c = 0; c < COL; c++) {
			mapa[f][c] = lose[f][c];
		}
	}nivel = 7;
}


//pintado del mapa 
void dibujarMapa() {
	for (int fil = 0; fil < FIL; fil++) {
		for (int col = 0; col < COL; col++) {
			Console::SetCursorPosition(col, fil);
			if (nivel < 5) {
				if (mapa[fil][col] == 1) {
					Console::ForegroundColor = ConsoleColor::Gray;
					cout << (char)219;
				}
				if (mapa[fil][col] == 2) {
					Console::ForegroundColor = ConsoleColor::DarkCyan;
					cout << (char)254;
				}
				if (mapa[fil][col] == 3) {
					Console::ForegroundColor = ConsoleColor::DarkBlue;
					cout << (char)178;
				}
				if (mapa[fil][col] == 5) {
					Console::ForegroundColor = ConsoleColor::DarkYellow;
					printf("%cAtorado?\n", 168);
					cout << "Preciona la R\n";
					cout << "Para Reiniciar\n";
				}
			}
			if (nivel == 5) {
				if (mapa[fil][col] == 1) {
					Console::ForegroundColor = ConsoleColor::DarkGreen;
					cout << (char)219;
					Console::ForegroundColor = ConsoleColor::White;
					cout << (char)219;
				}
				if (mapa[fil][col] == 7) {
					Console::ForegroundColor = ConsoleColor::Red;
					cout << (char)219;
				}
				if (mapa[fil][col] == 8) {
					Console::ForegroundColor = ConsoleColor::Blue;
					cout << "#";
				}
				if (mapa[fil][col] == 9) {
					Console::ForegroundColor = ConsoleColor::Red;
					cout << "PRECIONE:";
				}
				if (mapa[fil][col] == 2) {
					Console::ForegroundColor = ConsoleColor::DarkBlue;
					cout << "ENTER para Iniciar";
				}
				if (mapa[fil][col] == 3) {
					Console::ForegroundColor = ConsoleColor::DarkBlue;
					cout << "ESC para Salir";
				}
				Sleep(3);
			}
			if (nivel == 6) {
				if (mapa[fil][col] == 1) {
					Console::ForegroundColor = ConsoleColor::DarkYellow;
					cout << (char)219;
					Console::ForegroundColor = ConsoleColor::Yellow;
					cout << (char)219;
				}
				if (mapa[fil][col] == 9) {
					Console::ForegroundColor = ConsoleColor::Green;
					cout << "FELICIDADES\n";
					cout << "Precione cualquier\n";
					cout << "tecla para continuar";
				}
			}
			if (nivel == 7) {
				if (mapa[fil][col] == 1) {
					Console::ForegroundColor = ConsoleColor::DarkRed;
					cout << (char)219;
					Console::ForegroundColor = ConsoleColor::Red;
					cout << (char)219;
				}
				if (mapa[fil][col] == 9) {
					Console::ForegroundColor = ConsoleColor::Red;
					cout << "Precione cualquier\n";
					cout << "Tecla para Continuar\n";
				}

			}
		}
	}
}

//para jugar 

void principal(int x, int y) {
	int lel = 1, v = 4, lvl = 1;
	while (lel == 1) {
		if (_kbhit()) {
			char tecla = _getch();
			ubicacion(x, y); cout << " ";
			switch (tecla) {
			case Derecha:
				if (tecla == Derecha && mapa[y][x + 1] != 1) {
					if (estaElChampEnAzul)//verifica si el personaje esta en casilla azul
					{
						mapa[x][y] = 3;
						ubicacion(x, y);
						Console::ForegroundColor = ConsoleColor::Blue;
						cout << (char)177;
					}
					if (mapa[y][x + 1] == 2 && mapa[y][x + 2] != 1 && mapa[y][x + 2] != 2)
					{
						if (mapa[y][x + 1] == 3)
						{
							estaElChampEnAzul = true;
						}if (mapa[y][x + 1] != 3)
						{
							estaElChampEnAzul = false;
						}
						moveCaja(x + 1, y, 'r');//llama a moveCaja con la posicion de la caja :v
						x++;
					}
					else if ((mapa[y][x + 1] == 2 && mapa[y][x + 2] == 1) || (mapa[y][x + 2] == 1 && mapa[y][x + 1] == 2))//evita borrar la caja al haber pared del otro lado
					{
						if (mapa[y][x + 1] == 3)
						{
							estaElChampEnAzul = true;
						}if (mapa[y][x + 1] != 3)
						{
							estaElChampEnAzul = false;
						}
					}
					else
					{
						if (mapa[y][x + 1] == 3)
						{
							estaElChampEnAzul = true;
						}if (mapa[y][x + 1] != 3)
						{
							estaElChampEnAzul = false;
						}
						x++;
					}
				}
				break;
			case Izquierda:
				if (tecla == Izquierda && mapa[y][x - 1] != 1) {
					if (estaElChampEnAzul)//verifica si el personaje esta en casilla azul
					{
						mapa[x][y] = 3;
						ubicacion(x, y);
						Console::ForegroundColor = ConsoleColor::Blue;
						cout << (char)177;
					}
					if (mapa[y][x - 1] == 2 && mapa[y][x - 2] != 1 && mapa[y][x - 2] != 2)
					{
						if (mapa[y][x - 1] == 3)
						{
							estaElChampEnAzul = true;
						}if (mapa[y][x - 1] != 3)
						{
							estaElChampEnAzul = false;
						}
						moveCaja(x - 1, y, 'l');
						x--;
					}
					else if ((mapa[y][x - 1] == 2 && mapa[y][x - 2] == 1) || (mapa[y][x - 2] == 1 && mapa[y][x - 1] == 2))
					{
						if (mapa[y][x - 1] == 3)
						{
							estaElChampEnAzul = true;
						}if (mapa[y][x - 1] != 3)
						{
							estaElChampEnAzul = false;
						}
					}
					else
					{
						if (mapa[y][x - 1] == 3)
						{
							estaElChampEnAzul = true;
						}if (mapa[y][x - 1] != 3)
						{
							estaElChampEnAzul = false;
						}
						x--;
					}
				}
				break;
			case Arriba:
				if (tecla == Arriba && mapa[y - 1][x] != 1) {
					if (estaElChampEnAzul)//verifica si el personaje esta en casilla azul
					{
						mapa[x][y] = 3;
						ubicacion(x, y);
						Console::ForegroundColor = ConsoleColor::Blue;
						cout << (char)177;
					}
					if (mapa[y - 1][x] == 2 && mapa[y - 2][x] != 1 && mapa[y - 2][x] != 2)
					{
						if (mapa[y - 1][x] == 3)
						{
							estaElChampEnAzul = true;
						}if (mapa[y - 1][x] != 3)
						{
							estaElChampEnAzul = false;
						}
						moveCaja(x, y - 1, 'u');
						y--;
					}
					else if ((mapa[y - 1][x] == 2 && mapa[y - 2][x] == 1) || (mapa[y - 1][x] == 2 && mapa[y - 2][x] == 2))
					{
						if (mapa[y - 1][x] == 3)
						{
							estaElChampEnAzul = true;
						}if (mapa[y - 1][x] != 3)
						{
							estaElChampEnAzul = false;
						}
					}
					else
					{
						if (mapa[y - 1][x] == 3)
						{
							estaElChampEnAzul = true;
						}if (mapa[y - 1][x] != 3)
						{
							estaElChampEnAzul = false;
						}
						y--;
					}
				}
				break;
			case Abajo:
				if (tecla == Abajo && mapa[y + 1][x] != 1) {
					if (estaElChampEnAzul)//verifica si el personaje esta en casilla azul
					{
						mapa[x][y] = 3;
						ubicacion(x, y);
						Console::ForegroundColor = ConsoleColor::Blue;
						cout << (char)177;
					}
					if (mapa[y + 1][x] == 2 && mapa[y + 2][x] != 1 && mapa[y + 2][x] != 2)
					{
						if (mapa[y + 1][x] == 3)
						{
							estaElChampEnAzul = true;
						}if (mapa[y + 1][x] != 3)
						{
							estaElChampEnAzul = false;
						}
						moveCaja(x, y + 1, 'd');
						y++;
					}
					else if ((mapa[y + 1][x] == 2 && mapa[y + 2][x] == 1) || (mapa[y + 1][x] == 2 && mapa[y + 2][x] == 2))
					{
						if (mapa[y + 1][x] == 3)
						{
							estaElChampEnAzul = true;
						}if (mapa[y + 1][x] != 3)
						{
							estaElChampEnAzul = false;
						}
					}
					else
					{
						if (mapa[y + 1][x] == 3)
						{
							estaElChampEnAzul = true;
						}if (mapa[y + 1][x] != 3)
						{
							estaElChampEnAzul = false;
						}
						y++;
					}
				}
				break;
			case Salir:
				if (tecla == Salir) {
					lel = 0;
					Console::Clear();
					Lose();
					dibujarMapa();
					musica4();

				}
				break;
			case Inicio:
				if (tecla == Inicio) {
					Console::Clear();
					Nivel1();
					dibujarMapa();
					x = 11; y = 10;
					musica2();
				}
				break;
			case Reinicio:
				if (tecla == Reinicio) {
					if (lvl == 1) {
						Console::Clear();
						Nivel1();
						dibujarMapa();
						x = 11; y = 10;
						ubicacion(x, y);
						Console::ForegroundColor = ConsoleColor::Green;
						cout << (char)169;
						winCond = 0;
						v = 4;
					}
					if (lvl == 2) {
						Console::Clear();
						Nivel2();
						dibujarMapa();
						x = 7; y = 8;
						ubicacion(x, y);
						Console::ForegroundColor = ConsoleColor::Green;
						cout << (char)169;
						winCond = 0;
						v = 3;
					}
					if (lvl == 3) {
						Console::Clear();
						Nivel3();
						dibujarMapa();
						x = 8; y = 7;
						ubicacion(x, y);
						Console::ForegroundColor = ConsoleColor::Green;
						cout << (char)169;
						winCond = 0;
						v = 4;
					}
					if (lvl == 4) {
						Console::Clear();
						Nivel4();
						dibujarMapa();
						x = 9; y = 7;
						ubicacion(x, y);
						Console::ForegroundColor = ConsoleColor::Green;
						cout << (char)169;
						winCond = 0;
						v = 3;
					}
				}
				break;
			}
			ubicacion(x, y);
			Console::ForegroundColor = ConsoleColor::Green;
			cout << (char)169;//caracter principal
		}
		if (winCond == v)
		{
			lvl++;
			if (lvl == 2)
			{
				Console::Clear();
				Nivel2();
				dibujarMapa();
				x = 7; y = 8;
				ubicacion(x, y);
				Console::ForegroundColor = ConsoleColor::Green;
				cout << (char)169;
				winCond = 0;
				v = 3;
			}if (lvl == 3)
			{
				Console::Clear();
				Nivel3();
				dibujarMapa();
				x = 8; y = 7;
				ubicacion(x, y);
				Console::ForegroundColor = ConsoleColor::Green;
				cout << (char)169;
				winCond = 0;
				v = 4;
			}if (lvl == 4)
			{
				Console::Clear();
				Nivel4();
				dibujarMapa();
				x = 8; y = 10;
				ubicacion(x, y);
				Console::ForegroundColor = ConsoleColor::Green;
				cout << (char)169;
				winCond = 0;
				v = 4;
			}
			if (lvl == 5)
			{
				lel = 0;
				Console::Clear();
				Win();
				dibujarMapa();
				musica3();
			}
		}
	}
}


int main() {
	Console::SetWindowSize(21, 21); // definir el tamaño de la consola 
	Console::CursorVisible = false;// permite que no se mueva el cursor en la pantalla 
	Console::Clear();
	Bienvenida();
	dibujarMapa();
	musica1();
	principal(x, y);
	_getch();
	return 0;
}