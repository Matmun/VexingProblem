#include "Worker.h"

//konstruktor uzywany do debugowania, zbedny
Worker::Worker() {
	stateOfBoard = Board(1);
}

Worker::Worker(Board b) {
	step.clear();
	stateOfBoard = b;
}

//konstruktor dla pierwszej iteracji wektorow. Uzywany przy pierwszym wywolywaniu Workerow
Worker::Worker(Move& r, Board& b) {
	step.push_back(r);
	stateOfBoard = b;
}
//glowny konstruktor uzywany w kazdej(oprocz pierwszej ) iteracji workerow
Worker::Worker(vector<Move>v, Move &r,Board &b) {
	step = v;
	step.push_back(r);
	stateOfBoard.copy(b);
}
//destrutor, prawdopodobnie zbedy, uzywany do debuggowania
Worker::~Worker() {
	//step.clear();
	//vector<Move>().swap(step);

	//stateOfBoard.~Board();
}
//operator przypisania, dodany dla pewnosci aby dzialala kolejka 
Worker& Worker::operator=(const Worker& w) {
	step = w.step;
	stateOfBoard = w.stateOfBoard;
	return *this;
}
//podobnie jak powyzej. Uzywany glownie do debuggowania
bool Worker::operator==(const Worker& w) {
	int pom1 = step.size();
	int pom2 = w.step.size();
	if (pom1 != pom2)return false;
	if (!(stateOfBoard == w.stateOfBoard))return false;
	for (int i = 0; i < pom1; i++)
		if (!(step[i] == w.step[i]))return false;
	return true;
}