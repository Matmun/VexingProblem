#pragma once
#include "Move.h"

//Klasa pracujoca, Zawiera najwazniejsze informacje potrzebne do przeszukiwania. Jest elementem przeszukiwanej kolejki 

class Worker
{
public:
	vector<Move> step;
	Board stateOfBoard;
	Worker();
	Worker(Board);
	Worker(Move&, Board&);
	Worker(vector<Move>,Move &,Board&);
	Worker &operator=(const Worker&);
	bool operator==(const Worker&);
	~Worker();
};

