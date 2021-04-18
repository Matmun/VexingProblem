#include "Blok.h"

Blok::Blok(int xt, int yt,char v){
	x = xt;
	y = yt;
	val = v;
	if (val != '#' && val != '-')movable = true;
	else movable = false;
}
Blok::Blok() {
	x = 0;
	y = 0;
	val='#';
	movable = false;
}
Blok &Blok:: operator =(const Blok &b) {
	x = b.x;
	y = b.y;
	val = b.val;
	movable = b.movable;
	return *this;
}

void Blok::setEmpty() {
	if (movable) {
		val = '-';
		movable = false;
	}
}

