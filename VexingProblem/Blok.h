#pragma once

//Najwyzsza klasa. Elementy planszy. Kazdy bloczek zawiera swoje wpolrzedne,wartosc pola oraz informacje czy sa elementem, ktory nalezy usunoc

class Blok
{
public:
	char val;
	int x,y;
	bool movable;
	Blok(int,int,char);
	Blok();
	Blok& operator=(const Blok&);
	void setEmpty();
};

