
#include "Worker.h"
using namespace std;



int fallControl(Board& b, int x);
void analyse(queue<Worker>& cID);
queue<Worker> queueControl(Board b, queue<Worker> cID,int x);
//void dealocationControl(queue<Worker> cID);
void isMovable(queue<Worker>& cID);
void checkState(Board& b, int x);
void routineCheck(Board& b);
void fullFallControl(Board& b);
void swapp(Blok& a, Blok& b);

//Glowna petla w ktorej wykonywane jest przeszukiwanie wszerz
vector<Move> MainLoop(Board orginal) {
	vector<Move>out;
	//Board* temp=new ;
	queue<Worker> currentlyImportantData;
	currentlyImportantData.push(Worker(Board(orginal)));

	//isMovable(*temp, currentlyImportantData);

	isMovable(currentlyImportantData);
	currentlyImportantData.pop();

	while (1) {
		analyse(currentlyImportantData);

		isMovable(currentlyImportantData);
		
		if (currentlyImportantData.front().stateOfBoard.movableObjects == 0){
			out=currentlyImportantData.front().step;
			currentlyImportantData.empty();
			return out;
		}
		//*temp = currentlyImportantData.front().stateOfBoard;
		currentlyImportantData.pop();
		//if (currentlyImportantData.empty())
		//	winFlag = 0;
	}

	return out;
}
//Funkcja sprawdzajoca co sie staniw po wykonaniu ruchu
void analyse(queue<Worker> &cID) {
	bool debbug = false;
	
	//if(debbug)cID.front().stateOfBoard.druk(); //<><><><><><><

	int i = cID.front().step.back().x + (cID.front().step.back().y * cID.front().stateOfBoard.row);
	
	if (cID.front().stateOfBoard.arr[i].movable == true) {
		if (cID.front().step.back().Direction == 'P') {
			switch (cID.front().stateOfBoard.arr[i + 1].val)
			{
			case '-':
				swapp(cID.front().stateOfBoard.arr[i], cID.front().stateOfBoard.arr[i + 1]);
				i = fallControl(cID.front().stateOfBoard, i+1);
				
				break;
			case '#':
				break;
			default:
				
				break;
			}
		}if (cID.front().step.back().Direction == 'L') {
			switch (cID.front().stateOfBoard.arr[i - 1].val)
			{

			case '-':
				swapp(cID.front().stateOfBoard.arr[i], cID.front().stateOfBoard.arr[i - 1]);
				i=fallControl(cID.front().stateOfBoard,i-1);
				
				break;
			case '#':
				break;
			default:
				
				break;
			}
		}
		
		
		//temp.step;
	}
	routineCheck(cID.front().stateOfBoard);
	/*if (debbug)cID.front().step.back().Display(); cout << endl;
	if (debbug)cout<<"size"<<cID.front().step.size(); cout << endl;*/

	//if (debbug) cout<<cID.front().stateOfBoard.movableObjects<<endl;
	//if (debbug) {
	//	int size = cID.front().step.size();
	//	for (int i = 0; i < size; i++) {
	//		cout << cID.front().step[i] << " ";
	//		//if (!(i % 4)) cout << endl;
	//	}
	//	cout << endl;
	//}
	//if (debbug)cID.front().stateOfBoard.druk(); //<><><><><><><
	//
	//if (debbug)system("pause");
	
	
}
//Funkcja sprawdzajoca czy czy sasiadujoce znaki nie sa takie same
void checkState(Board &b,int x) {
	if (b.arr[x + 1].val == b.arr[x].val )
	{
		b.arr[x].setEmpty();
		b.arr[x + 1].setEmpty();
		b.movableObjects -= 2;

	}
	else if (b.arr[x - 1].val == b.arr[x].val) {
		b.arr[x].setEmpty();
		b.arr[x - 1].setEmpty();
		b.movableObjects -= 2;
	}
	else if (b.arr[x + b.row].val == b.arr[x].val) {
		b.arr[x].setEmpty();
		b.arr[x +b.row].setEmpty();
		b.movableObjects -= 2;
	}
}
//funkcja sprawdzajoca stan tablicy. Zabezpieczenie
void routineCheck(Board &b) {
	for (int i = 1; i < b.row * b.col; i++) {
		if (b.arr[i].movable == true) {
			fullFallControl(b);
			checkState(b, i);
		}
	}
}
//funkcje modyfikujoca tablice jesli wartosc moze spasc
int fallControl(Board &b,int x) {
	while (b.arr[x + b.row].val == '-') {
		swapp(b.arr[x], b.arr[x + b.row]);
		x += b.row;
	}
	return x;
}
void fullFallControl(Board& b) {
	for (int x = 0; x < b.col * b.row; ++x)
		if(b.arr[x].movable == true)
			fallControl(b,x);
}
//funkcja pomocnicza do zamiany blokow tablicy miejscami
void swapp(Blok &a,Blok &b) {
	Blok temp;
	temp = a;
	a = b;
	b = temp;
}

//funkcja przeszukujoca tablice w calu znalezienia elemntow ruchomych. Tworzy takze kolejke ruchow jesli znajdzie takowy element 
void isMovable(queue<Worker> &cID) {
	Board b = cID.front().stateOfBoard;
	for (int i = 1; i < b.row * b.col; i++) {
		if (b.arr[i].movable == true) cID = queueControl(b, cID,i);
	}
}
//fukcja dodajaca do kolejki dla danego elementu ruch w prawo oraz w lewo
queue<Worker> queueControl(Board b,queue<Worker> cID,int x) {
	
	if (b.arr[x+1].val=='-') {
		Move m1(b.arr[x].val,x % b.row, x / b.row, 'P');
		Worker w1(cID.front().step, m1, b);
		cID.push(w1);
	}
	
	if (b.arr[x - 1].val == '-') {
		Move m2(b.arr[x].val,x%b.row, x/b.row, 'L');
		Worker w2(cID.front().step, m2, b);
		cID.push(w2);
	}
	
	return cID;
}

queue<Worker>dealocateControl(queue<Worker> cID){
	cID.pop();
	return cID;
}


int main()
{
	
	//Board plansza();
	//Move c(1, 1, 'L');
	//Worker b(c, a);
	//Board temp(a);
	//a.~Board();
	//Board* a = new Board();	
	ifstream file;
	file.open("data.txt");
	while (1) {
		Board a = Board(file);
		if (a.name == "END") return 0;
		vector<Move> b = MainLoop(a);
		
		cout << a.name << " Minimum solution Lenght = " << b.size() << endl;
		

		int size = b.size();
		for (int i = 0; i < size; i++) {
			cout << b[i] << " ";
			if (!((i + 1) % 4)) cout << endl;
		}
		cout << endl;
	}
	file.close();
	//a->druk();
	//cout << endl;
	//Move* m1 = new Move(1, 3, 'L');
	//Move* m2 = new Move(0, 1, 'P');
	//Worker* w = new Worker(*m1, *a);
	//Worker* w1 = new Worker(*m2, *a);
	//queue<Worker> cID;
	//cID.push(*w);
	//cID.push(*w1);
	//analyse( cID);
	////dealocateControl(cID);
	//cID.pop();
	//a->druk();
	//cout << endl;
	//analyse( cID);
	//a->druk();
	//cout <<endl;

	//fallControl(a, 2);
	//vector<Move> b;


	//a->druk();
	//b=MainLoop(*a);
	//b=MainLoop(*a);
	//b.front().Display();
	/*queue<Worker> h;
	h.push(c);
	h.back().stateOfBoard.druk();*/
	
	//c.stateOfBoard.druk();

	//swap(a.arr[3], a.arr[8]);
	//a.druk();
	//temp.druk();
	//cout << endl << a.movableObjects;
	//b.stateOfBoard.druk();
	//queue<int> kolejka;
	//kolejka.push(2);
	//cout << kolejka.front() << endl;; kolejka.pop();
	//kolejka.push(5);
	//kolejka.push(1);
	//
	//
	//kolejka.push(8);
	//cout << kolejka.front()<<endl; kolejka.pop();
	//cout << kolejka.front()<<endl; kolejka.pop();

	//string b=a.chopFirstLine("1 1 ha", 3);
	//cout << b;
	return 0;
}
