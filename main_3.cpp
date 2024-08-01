#include<iostream>
#include<fstream>

using namespace std;

int input(istream& in=cin)
{
	int x;
	in >> x;
	return x;
}

int main()
{
	int board[3][3]; //creates a 9*9 matrix or a 2d array.
	char value;
	int posx;
	int posy;

	for(int i=0; i<3; i++)    //This loops on the rows.
	{
		for(int j=0; j<3; j++) //This loops on the columns
		{
			board[i][j] = input(); //you can also connect to the file
			//and place the name of your ifstream in the input after opening the file will
			//let you read from the file.

			if (board[i][j] == 0){
				posx = i;
				posy = j;
			}
		}
	}

	while (std::cin >> value) {
		if (value == 'U'){
			if (posx != 0){
				board[posx][posy] = board[posx-1][posy];
				board[posx-1][posy] = 0;
				posx --;
			}
		}
		else if (value == 'D'){
			if (posx != 2){
				board[posx][posy] = board[posx+1][posy];
				board[posx+1][posy] = 0;
				posx++;
			}
		}
		else if (value == 'L'){
			if (posy != 0){
				board[posx][posy] = board[posx][posy-1];
				board[posx][posy-1] = 0;
				posy--;
			}
		}
		else if (value == 'R'){
			if (posy != 2){
				board[posx][posy] = board[posx][posy+1];
				board[posx][posy+1] = 0;
				posy++;
			}
		}
		/*for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				std::cout << board[i][j] << " ";
			}
			std::cout << "\n";
		}*/
	}

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (i+j == 4){
				std::cout << "Solution is good!\n";
				return 0;
			}
			if (board[i][j] != (3*i + j + 1)){
				std::cout << "Wrong solution!\n";
				return 0;
			}
		}
	}
}