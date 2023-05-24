#include <iostream>
#include <string>
using namespace std;

class tictactoe {
public: 
	tictactoe();
	void displayBoard();
	void getMove(char player);
	void playGame();
private: 
	static const int BSIZE = 3;
	const int maxMoves = 9; 
	int minMovesToWin = 5;
	char board[BSIZE][BSIZE];
	int totalMoves;
	bool checkForWins(char player)const;
	bool checkForDraw()const;
	void fill_board();
	char togglePlayer(char player);
	
};

tictactoe::tictactoe(){
	totalMoves = 0;
	fill_board();
	}

void tictactoe::fill_board() {
	for (int row = 0; row < BSIZE; row++) {
		for (int col = 0; col < BSIZE;col++) {
			board[row][col] = ' ';
		}
	}
}
void tictactoe::displayBoard() {
	cout << "\t\t ----------------\n";
	for (int row = 0; row < BSIZE; row++) {
		cout <<"\t\t"<< " | ";
		for (int col = 0; col < BSIZE; col++) {
			cout <<  board[row][col] << "  | ";
		}
	
		cout << "\n\t\t ----------------\n";
	}
}
void tictactoe::getMove(char player){
	char input; 
	char ch; 
	int num_entered, row, col, index; 
	
	while (true) {
		cout <<"\t\t[ "<< player << " ] Select a number from 1-9: ";
		cin>>input;

		if (input != ' ') {
			ch = input;
			if (ch >= '1' && ch <= '9') {
				num_entered = ch - '0';
				index = num_entered - 1;  
				row = index / 3; 
				col = index % 3; 
				
				char b_pos = board[row][col];
				if (b_pos != 'X' && b_pos != 'O') {
					board[row][col] = player;
					totalMoves++;
					break; 
				}
				else
					cout << "Wrong move. Position is already taken. Try again" << endl;
			}
			else
				cout << "You must enter a number between 1-9 to make your move." 
				<< "Try again. \n";
		}
		else 
			cout << "You must enter something!!" << endl;
	}
	cout << "\tTotal moves: " << this->totalMoves << endl;
}

char tictactoe::togglePlayer(char player) {
	
	player = player == 'X' ? 'O' : 'X';
	return (player);
}

bool tictactoe::checkForWins(char player)const{
	if (totalMoves >= minMovesToWin) {
		//check rows for winner
		if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
			return true;
		}
		if (board[1][0] == player && board[1][1] == player && board[1][2] == player)
		{
			return true;
		}
		if (board[2][0] == player && board[2][1] == player && board[2][2] == player)
		{
			return true;
		}
		//columns 
		if (board[0][0] == player && board[1][0] == player && board[2][0] == player)
		{
			return true;
		}
		if (board[0][1] == player && board[1][1] == player && board[2][1] == player)
		{
			return true;
		}
		if (board[0][2] == player && board[1][2] == player && board[2][2] == player)
		{
			return true;
		}
		//Accross
		if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
		{
			return true;
		}
		if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
		{
			return true;
		}

	}
	return false;

}

bool tictactoe::checkForDraw()const{
	return totalMoves == maxMoves;
}

void tictactoe::playGame(){
	char player = 'X';
	bool gameOver = false;
	do {
		displayBoard();
		getMove(player);
		if (checkForWins(player)) {
			cout << "\n\t\t[ "<< player << " ] WON !!! ---------> :):):)\n"<<endl;
			gameOver = true;
		}
		else if (checkForDraw()) {
			cout << "\t\tIT'S A DRAW! Play again!" << endl;
			gameOver = true;
		}
		player = togglePlayer(player);
	} while (!gameOver);

	displayBoard();
}

int main() {
	tictactoe game;
	game.playGame();
	return 0;
}
