'''
Assigning values to the grid
The grid will look like this:
  0,0 | 0,1 | 0,2
  1,0 | 1,1 | 1,2
  2,0 | 2,1 | 2,2
'''
N = 3
grid = [['-']*7 for _ in range(7)]
marks = ['X', 'O']
#This function prints the grid of Tic-Tac-Toe as the game progresses
def print_grid():
    print("Player 1: X  vs  Player 2: O")
    print('--' + '---' * N + '--')
    for i in range(N):
        print(end='|  ')
        for j in range(N):
            print(grid[i][j], end='  ')
        print(end='|')
        print()
        print('--' + '---' * N + '--')
#This function checks if row or column or diagonal is full with same characters
def check_win():
    orow, xrow, ocolumn, xcolumn, odiagonal, xdiagonal, oreverse, xreverse = 0,0,0,0,0,0,0,0
    #check row
    for i in range(N):
      for j in range(N):
        if grid[i][j] == 'O':  # check row
          orow += 1
        elif grid[i][j] == 'X':
          xrow += 1
        if grid[j][i] == 'O': #check column
          ocolumn += 1
        elif grid[j][i] == 'X': #check column
          xcolumn += 1
        if i == j:            #check diagonal
          if grid[i][j] == 'X':
            xdiagonal += 1
          elif grid[i][j] == 'O':
            odiagonal += 1
        if i + j == 2:        #check reverse diagonal
          if grid[i][j] == 'X':
            xreverse += 1
          elif grid[i][j] == 'O':
                  oreverse += 1
      if xrow == N or xcolumn == N or xdiagonal == N or xreverse == N:
          mark = 'X'
          return True
      elif orow == N or ocolumn == N or odiagonal == N or oreverse == N :
          mark = 'O'
          return True
      else:
          orow, xrow, ocolumn, xcolumn = 0,0,0,0
    return False
#This function checks if row or column or diagonal is full with same characters
def check_tie(mark):
    row, column, diagonal, reverse = 0,0,0,0
    for i in range(N):
        for j in range(N):
            if grid[i][j] == mark :  # check row
                row += 1
                break
    for i in range(N):
        for j in range(N):
            if grid[j][i] == mark : #check column
                column += 1
                break
    for i in range(N):
        for j in range(N):
            if i == j:            #check diagonal
                if grid[i][j] == mark:
                    diagonal = 1
                    break;
    for i in range(N):
        for j in range(N):
            if i + j == 2:        #check reverse diagonal
                if grid[i][j] == mark :
                    reverse = 1
                    break
    if row == N and column == N and diagonal == 1 and reverse == 1:
        return True
    else:
        return False
#This function checks if given cell is empty or not
def check_empty(i, j):
    if grid[i][j] == '-':
        return 1
    else:
        return 0
#This function checks if given position is valid or not
def check_valid_position(i, j):
    if i <= 2 and i >=0 and j <= 2 and j >= 0:
        return 1
    else:
        return 0
#This function sets a value to a cell
def set_cell(i, j, mark):
    grid[i][j] = mark
#This function clears the grid
def grid_clear():
    for i in range(N):
        for j in range(N):
            grid[i][j] = '-'
#MAIN FUNCTION
def play_game():
    print("Tic-Tac-Toe Game!")
    print("Welcome...")
    print("============================")
    player = 0
    while True:
        #Prints the grid
        print_grid()
        #Set mark value based on the player
        mark = 'X' if player == 0 else 'O'
        #Takes input from the user to fill in the grid
        print('Player %s' % mark)
        i, j = map(int, input('Enter the row index and column index: ').split())
        while not check_valid_position(i, j) or not check_empty(i, j):
            i, j = map(int, input('Enter a valid row index and a valid column index: ').split())
        #Set the input position with the mark
        set_cell(i, j, mark)
        #Check if the state of the grid has a win state
        if check_win():
            #Prints the grid
            print_grid()
            print('Congrats, Player %s is won!' % mark)
            break
        #Check if the state of the grid has a tie state
        if check_tie(marks[player]) and check_tie(marks[1-player]):
            #Prints the grid
            print_grid()
            print("Woah! That's a tie!")
            break
        #Player number changes after each turn
        player = 1 - player
while True:
   grid_clear()
   play_game()
   c = input('Play Again [Y/N] ')
   if c not in 'yY':
      break
