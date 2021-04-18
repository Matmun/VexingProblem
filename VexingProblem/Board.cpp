#include "Board.h"

//Konstruktor
Board::Board() {
	arr = new Blok[1];
}

Board::Board(ifstream &file){
	
	string line;

	movableObjects = 0;
	
	file>>this->col >> this->row >>this->name;
	arr = new Blok[row * col];
	//getchar(file); // \n
	//setDimension(temp);
	int rowCount = 0;
	
	if (file.is_open()) {
		//while (getline(file, line) && line !="0 0 END") {
		for(int i=0;i< this->col ;++i){
			file>>line;
			Analyse(line,rowCount);
			rowCount++;
		}
	}
	else cout << "error" << endl;
	//cout << this->row<< "|" << this->col << "|" << this->name;
}
//
//Board::Board(int r) {
//	ifstream file;
//	string line;
//	int rowCount =r;
//	file.open("data.txt");
//	if (file.is_open()) {
//		while (getline(file, line) && line != "0 0 END") {
//			Analyse(line, rowCount);
//			rowCount++;
//		}
//		file.close();
//	}
//	else cout << "error" << endl;
//	//cout << this->row<< "|" << this->col << "|" << this->name;
//}
//Konstrutkor kopiujacy 
Board::Board(const Board& b) {
	copy(b);
	/*row = b.row;
	col = b.col;
	name = b.name;
	
	arr=new Blok[b.row * b.col];
	for (int i = 0; i < row * col; i++)
		arr[i] = b.arr[i];*/
}
//Destrukotor potencjalnie wadliwy
Board::~Board() {
	//cout << arr<<endl;
	delete[] arr;
	//cout << "blad"<<endl;
}
Board& Board::operator=(const Board& w) {
	copy(w);
	return* this;
}

//Analiza lini z pliku, budowa tablicy bloków,licznie liczby przesuwalnych obiektów.
void Board::Analyse(string line, int rowCount) {
	int pom = (rowCount );
	//if (rowCount == 1)setDimension(line);
	//else {
		for (int i = 0; i < row; i++) {
			arr[i + (row * pom)] = Blok(i, pom, line[i]);
			if (arr[i + (row * pom)].movable == true) movableObjects++;
		}
	//}
}
//Funkcja determinujaca wymiary i nazwe planszy. Dodatkowo alokuje pamiec dla tablicy blokow
void Board::setDimension(string line) {
	col = stoi(chopFirstLine(line, 0));
	row = stoi(chopFirstLine(line, 1));
	name = chopFirstLine(line, 2);
	Blok* tmp = new Blok[row*col];
	arr = tmp;
}
//Fukncja pomocnicza dzielaca string na trzy czesci, uzywaj¹c spacji jako znak rozdzielajacy 0-wiersz  1-kolumna 2-nazwa planszy
string Board::chopFirstLine( string line,int part){
	string tmp1;
	int count=0;
	stringstream ss(line);
	do {
		string word;
		ss >> word;
		if (count == part)tmp1 = word;
		count++;
	} while (ss);

	return tmp1;
}
//Funkcja do debuggowania
void Board::druk() {
	int pom = 0;
	for (int i = 0; i < (row * col); i++) {
		if(i==0)cout << name;
		if (pom % row == 0)cout << endl;
		pom++;
		//cout << arr[i].Val << "(" << arr[i].x << "," << arr[i].y << ")";
		cout << arr[i].val;
	}


}
//Metoda kopiujaca stworzona dla ulatwienia pracy przy przeszukiwaniu
void Board::copy(const Board &b) {
	row = b.row;
	col = b.col;
	name = b.name;
	movableObjects = b.movableObjects;
	delete[] arr;
	arr = new Blok[b.row * b.col];
	for (int i = 0; i < row * col; i++)
		arr[i] = b.arr[i];
}
//Przeciazenie operatora == dla queue
bool Board::operator==(const Board &b) {
	if(row==b.row && col == b.col)
		for (int i = 0; i < row * col;i++) {
			if (arr[i].val != b.arr[i].val)
				return false;
		}
	return true;
}

Board::Board(int i) {

}