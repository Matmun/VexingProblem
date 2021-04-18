#include "Move.h"
//konstruktor domyslny, uzywany przy debugowaniu
Move::Move() {
	x = 0;
	y = 0;
	Direction = '-';
}
//glowny konstruktor, wspolrzedne x,y oraz kieunek przesuniecia
Move::Move(char valt,int xt,int yt, char dir){
	val = valt;
	x = xt;
	y = yt;
	Direction = dir;
}
//funckja pomocnicza, debuggowanie
void Move::Display() {
	printf("(%c,%d,%d,%c)",val,  x, y, Direction);
}


bool Move::operator==(const Move& m) {
	if (x == m.x && y == m.y && Direction == m.Direction)return true;
	else return false;

}

ostream& operator<<(ostream &s,const Move& m) {
	
	s << "(" << m.val << "," << m.x << "," << m.y << "," << m.Direction << ")";
	return s;
}