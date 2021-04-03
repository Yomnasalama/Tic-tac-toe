#include <bits/stdc++.h>
using namespace std;

const int N = 3;
const char marks[2] = {'X', 'O'};
char grid[N][N];

//This function prints the grid of Tic-Tac-Toe Game as the game progresses
void print_grid() {
    cout << "Player 1: " << marks[0] << "  vs  Player 2: " << marks[1] << "\n";
    cout << "--";
    for (int i = 0; i < N; cout << "---", i++);
    cout << "--\n";
    for (int i = 0; i < N; i++) {
        cout << "|  ";
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << "  ";
        cout << "|\n";
        cout << "--";
        for (int i = 0; i < N; cout << "---", i++);
        cout << "--\n";
    }
}
//This function checks if given cell is empty or not
bool check_empty(int i, int j)
{
  if (grid[i][j] == '-')
    return true;
  else
    return false;
}
//This function checks if the game has a win state or not
bool check_win() {
  int i; int j ;
  int orow = 0; int ocolumn = 0; int xrow = 0; int xcolumn = 0; int odiagonal = 0; int xdiagonal = 0; int oreverse = 0; int xreverse = 0;
  for (i = 0; i < N; i++)
  {
    for(j = 0; j < N; j++)
    {
      if (grid[i][j] == 'X')
      {
         xrow++;
      }
      else if (grid[i][j] == 'O')
      {
        orow++;
      }
      if(grid[j][i] == 'X')
      {
        xcolumn++;
      }
      else if (grid[j][i] == 'O')
        ocolumn++;
      if (i == j)
      {
        if (grid[i][j] == 'X')
          xdiagonal++;
        else if (grid[i][j] == 'O')
          odiagonal++;
      }
      if (i + j == 2)
      {
        if (grid[i][j] == 'X')
          xreverse++;
        else if (grid[i][j] == 'O')
          oreverse++;
      }

    }
    if (orow == N || ocolumn == N || odiagonal == N || oreverse == N )
        return true;
      else if (xrow == N || xcolumn == N || xdiagonal == N || xreverse == N)
        return true;
      else
      {
        orow = 0;
        ocolumn = 0;
        xrow = 0;
        xcolumn = 0;
      }
  }
  return false;

}

//This function checks if the game has a tie state or not
bool check_tie(char mark) {
    int row = 0, column = 0, diagonal = 0, reverse = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (grid[i][j] == mark)  // check row
            {
                row++;
                break;
            }

        }
    }

    for(int i = 0; i < N; i++)
    {
         for(int j = 0; j < N; j++)
         {
            if (grid[j][i] == mark)
            {
                column += 1;
                break;
            }

         }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (i == j)
            {
                if(grid[i][j] == mark)
                {
                    diagonal = 1;
                    break;
                }
            }

        }

    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0;j < N; j++)
        {
            if (i + j == 2)
            {
                if( grid[i][j] == mark)
                {
                    reverse = 1;
                    break;
                }
            }
        }
    }

    if (row == N && column == N && diagonal == 1 && reverse == 1)
        return true;
    else
        return false;
}



//This function checks if given position is valid or not
bool check_valid_position(int i, int j) {
  if (i >= 0 && i <= 2 && j >= 0 && j <= 2)
    return 1;
  else
    return 0;
}

//This function sets the given mark to the given cell
void set_cell(int i, int j, char mark) {
  grid[i][j] = mark;

}
//This function clears the game structures
void grid_clear() {
  int i; int j;
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      grid[i][j] = '-';
    }
  }

}
//This function reads a valid position input
void read_input(int &i, int &j) {
	cout << "Enter the row index and column index: ";
	cin >> i >> j;
    while (!check_valid_position(i, j) || !check_empty(i, j)) {
		cout << "Enter a valid row index and a valid column index: ";
		cin >> i >> j;
	}
}
//MAIN FUNCTION
void play_game() {
    cout << "Tic-Tac-Toe Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    bool player = 0;
    while (true) {
        //Prints the grid
        print_grid();
        //Read an input position from the player
        cout << "Player " << marks[player] << " is playing now\n";
        int i, j;
		read_input(i, j);
        //Set the player mark in the input position
        set_cell(i, j, marks[player]);
        //Check if the grid has a win state
        if (check_win()) {
            //Prints the grid
            print_grid();
			//Announcement of the final statement
            cout << "Congrats, Player " << marks[player] << " is won!\n";
            break;
        }
        //Check if the grid has a tie state
        if (check_tie(marks[player]) && check_tie(marks[1-player])) {
            //Prints the grid
            print_grid();
			//Announcement of the final statement
            cout << "Woah! That's a tie!\n";
            break;
        }
        //Player number changes after each turn
        player = 1 - player;
    }
}
int main() {
    while (true) {
    	grid_clear();
    	play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
}
