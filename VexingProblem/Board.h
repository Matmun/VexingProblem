#pragma once
#include "Blok.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

//Klasa plansza. Zawiera liczbe kolumn, liczbe wierszy, nazwe planszy oraz jednowymiarowa tablice bloczkow tworzoca plansze

class Board
{
void Analyse(string, int);
void setDimension(string);
string chopFirstLine(string, int);
public:
	int row = NULL;
	int col = NULL;
	Blok* arr = NULL;
	int movableObjects = 0;
	string name = "empty";
	Board();
	Board(ifstream&);
	Board(const Board &);
	~Board();
	void druk();
	void copy(const Board &);
	bool operator==(const Board&);
	Board& operator=(const Board&);
	Board(int);
};

