#include<iostream>
#include<fstream>

using namespace std;

char input(istream& in=cin)
{
	char x;
	in >> x;
	return x;
}

char rule1 (char board[3][3]){
	int count = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (board[i][j] == '*'){
				count++;
			}
		}
	}
	if (count > 2 && count < 5) {
		return '*';
	}
	else{
		return '.';
	}
}

char rule4 (char board[3][3]){
	int count = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (board[i][j] == '*'){
				count++;
			}
		}
	}
	if (count == 3) {
		return '*';
	}
	else{
		return '.';
	}
}

int main()
{
	int m;
	int n;
	int g;
	std::cin >> m;
	std::cin >> n;
	std::cin >> g;

	char board[m][n]; //creates a 9*9 matrix or a 2d array.
	char board2 [3][3];
	char nextGen[m][n];

	for(int i=0; i<m; i++)    //This loops on the rows.
	{
		for(int j=0; j<n; j++) //This loops on the columns
		{
			board[i][j] = input(); //you can also connect to the file
			//and place the name of your ifstream in the input after opening the file will
			//let you read from the file.
		}
	}

	for (int x = 0; x < g; x++){
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				int negi = i-1;
				int negj = j-1;
				int posi = i+1;
				int posj = j+1;
				board2[1][1] = board [i][j];
				if (negi < 0){
					board2[0][0] = 'N';
					board2[0][1] = 'N';
					board2[0][2] = 'N';
				}
				else {
					if (negj < 0){
						board2[0][0] = 'N';
					}
					else {
						board2[0][0] = board[negi][negj];
					}
					board2[0][1] = board[negi][j];
					if (posj == n){
						board2[0][2] = 'N';
					}
					else{
						board2[0][2] = board[negi][posj];
					}
				}
				if (posi == m){
					board2[2][0] = 'N';
					board2[2][1] = 'N';
					board2[2][2] = 'N';
				}
				else{
					if (negj < 0){
						board2[2][0] = 'N';
					}
					else {
						board2[2][0] = board[posi][negj];
					}
					board2[2][1] = board[posi][j];
					if (posj == n){
						board2[2][2] = 'N';
					}
					else{
						board2[2][2] = board[posi][posj];
					}
				}
				if (negj < 0){
					board2[1][0] = 'N';
				}
				else{
					board2[1][0] = board[i][negj];
				}
				if (posj == n){
					board2[1][2] = 'N';
				}
				else {
					board2[1][2] = board[i][posj];
				}
				if (board[i][j] == '*'){
					char r1 = rule1(board2);
					nextGen[i][j] = r1;
				}
				else{
					char r1 = rule4(board2);
					nextGen[i][j] = r1;
				}
			}
		}
		/*std::cout << "\n";
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				std::cout << nextGen[i][j] << " ";
			}
			std::cout << "\n";
		}*/

		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				board[i][j] = nextGen[i][j];
			}
		}
	}

	//std::cout << "\n";

	for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (j == n-1){
					std::cout << board[i][j] << "\n";
				}
				else{
					std::cout << board[i][j] << " ";
				}
			}
		}
}