#include<iostream>
#include<fstream>

using namespace std;

bool check_box (int matrix[3][3]){
    int array[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int j = 0;
    for (int r = 0; r < 3; r++){
        for (int c = 0; c < 3; c++){
            for (int i = 0; i < j; i++){
                if (array[i] == matrix[r][c]){
                    return false;
                }
            }
            array[j] = matrix[r][c];
            j++;
        }
    }
    return true;
}

bool check_row (int row [9]){
    int array[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int j = 0;
    for (int r = 0; r < 9; r++){
        for (int i = 0; i < j; i++){
            if (array[i] == row[r]){
                return false;
            }
        }
        array[j] = row[r];
        j++;
    }
    return true;
}

bool check_col (int col[9]){
    int array[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int j = 0;
    for (int c = 0; c < 9; c++){
        for (int i = 0; i < j; i++){
            if (array[i] == col[c]){
                return false;
            }
        }
        array[j] = col[c];
        j++;
    }
    return true;
}

int input(istream& in=cin)
{
	int x;
	in >> x;
	return x;
}

int main()
{
	int board[9][9]; //creates a 9*9 matrix or a 2d array.
	int board2 [3][3];
	int rc [9];
	int numr = 0;
	int numc = 0;
	bool ans = true;

	for(int i=0; i<9; i++)    //This loops on the rows.
	{
		for(int j=0; j<9; j++) //This loops on the columns
		{
			board[i][j] = input(); //you can also connect to the file
			//and place the name of your ifstream in the input after opening the file will
			//let you read from the file.
		}
	}

	for (int i = 0; i < 3; i++){
		if (ans == false){
			std::cout << "Wrong solution!\n";
			return 0;
		}
	    for (int j = 0; j < 3; j++){
	        for (int r = 0; r < 3; r++){
    	        for (int c = 0; c < 3; c++){
    	            board2[r][c] = board[i*3+r][j*3+c];
    	        }
	        }
	        ans = check_box(board2);
	    }
	}
	
	for (int i = 0; i < 9; i++){
		if (ans == false){
			std::cout << "Wrong solution!\n";
			return 0;
		}
		numr = 0;
	    for (int j = 0; j < 9; j++){
	        rc[numr] = board[i][j];
	        numr++;
	    }
	    ans = check_row(rc);
	}
	
	for (int i = 0; i < 9; i++){
		if (ans == false){
			std::cout << "Wrong solution!\n";
			return 0;
		}
		numc = 0;
	    for (int j = 0; j < 9; j++){
	        rc[numc] = board[j][i];
	        numc++;
	    }
	    ans = check_row(rc);
	}
	
	std::cout << "Solution is good!\n";
}