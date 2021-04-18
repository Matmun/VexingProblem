#pragma once
#include "Board.h"

//Klasa ruch.Jest rozkazem jaki element nalezy przesunac i w jaka strone. Jest takze elementem wektora , ktory jest finalnym wynikiem przeszukwiania

class Move
{
public:
	int x, y;
	char val;
	char Direction;
	Move();
	Move(char,int,int,char);
	void Display();
	bool operator==(const Move&);
	friend ostream& operator<<(ostream& s, const Move& m);
};

