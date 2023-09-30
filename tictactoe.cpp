#include <iostream>
using namespace std;

void printBoard(string board[3][3]);
void newMove(string tokens[2], int turn, string board[3][3]);
bool checkWin(string board[3][3], bool tie);

int main() {
  // initialize tictactoe board
  string board[3][3] = {{" "," "," "},{" "," "," "},{" "," "," "}};

  // print tictactoe board
  printBoard(board);

  string tokens[2] = {"x","o"};
  int turn = 1;
  bool tie = false;
  bool win = false;

  while (win == false && tie == false) {
    newMove(tokens, turn, board);
    printBoard(board);
    win = checkWin(board, tie);
    turn++;
  }

  if (win == true) {
    cout << "Player " << tokens[(turn-2)%2] << " wins!" << endl;
  } else if (tie == true) {
    cout << "Tie!" << endl;
  }

  return 0;
}

void printBoard(string board[3][3]) {
  // print tictactoe board
  cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << endl;
  cout << "---|---|---" << endl;
  cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << endl;
  cout << "---|---|---" << endl;
  cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << endl;
}

void newMove(string tokens[2], int turn, string board[3][3]) {
  int row, col;
  string token = tokens[(turn-1)%2];

  cout << "Turn " << turn << ", player " << token << endl;

  int count = 0;
  do {
    if (count > 0) {
      cout << "Position already taken, enter another" << endl;
    }

    cout << "Enter row: ";
    cin >> row;
    while (row < 1 || row > 3) { // check if row is valid
      cout << "Invalid row, enter another" << endl;
      cin >> row;
    }
    row--;

    cout << "Enter column: ";
    cin >> col;
    while (col < 1 || col > 3) { // check if column is valid
      cout << "Invalid column, enter another" << endl;
      cin >> col;
    }
    col--;
    count++;
  } while (board[row][col] != " ");

  board[row][col] = token;

}

bool checkWin(string board[3][3], bool tie) {
  // check if there is a winner

  for (int i=0; i < 3; i++) {
    if ((board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != " ") // check rows
    || (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != " ")) { // check cols
      return true;
    }
  }
  if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != " ")
  || (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != " ")) {
    return true;
  }

  // check if there is a tie
  for (int i=0; i < 3; i++){
    for (int j=0; j < 3; j++) {
      if (board[i][j] != "x" && board[i][j] != "o") {
        return false;
      }
    }
  }

  tie = true;
  return false;
}
