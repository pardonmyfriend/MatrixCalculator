#pragma once

#include <iostream>
#include <Windows.h>
//funkcje: SetConsoleTextAttribute(), SetConsoleCursorPosition(),GetStdHandle()
//struktury: COORD, HANDLE, CONSOLE_CURSOR_INFO
//makro STD_OUTPUT_HANDLE

#include <conio.h> //funkcja _getch()
#include <fstream> //obsluga plikow
#include <iomanip> //funkcja setw()

using namespace std;

extern int count_f; //licznik wejscia do funkcji createMatrix(); pozwala na odpowiednie nazwanie macierzy (A lub B)
const double eps = 1e-12; //otocznie zera do sprawdzenia czy jest dzielenie przez zero w funkcji inverse()

struct Matrix
{
	int row; //wiersze
	int col; //kolumny
	double** matrix; //tablica wskaznikow - wskazniki na elementy macierzy
};

void color(int color);
void gotoxy(int x, int y);
void ShowConsoleCursor(bool showFlag);
COORD GetConsoleCursorPosition(HANDLE hConsoleOutput);
void menu();
void calculator();
Matrix createMatrix();
void displayMatrix(Matrix m);
void add_substr(Matrix m2, Matrix m1, bool czyDodawac);
void scalar(Matrix m);
void multiplication(Matrix m2, Matrix m1);
void power(Matrix m);
void transpose(Matrix m);
void determinant(Matrix m);
double laplace(Matrix m);
void inverse(Matrix m);
bool LUdist(Matrix m);
bool LUsolve(int k, Matrix m, Matrix w);
void learn();
void download(string s);
void what_next();