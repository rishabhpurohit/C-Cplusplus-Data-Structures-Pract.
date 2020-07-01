#include <iostream>
#include <string>
#include <vector>
#include<fstream>
using std::ifstream;
using std::cout;
using std::string;
using std::vector;

void ReadBoard(){
  std::fstream my_file("./1.board");
  std::string line;
  while (getline(my_file,line)){
    std::cout<<line+" "+"\n";
    
  }
}

// PrintBoard not used in this exercise
void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

int main() {
  // TODO: Call the ReadBoardFile function here.
  ReadBoard();
  // Leave the following line commented out.
  //PrintBoard(board);
}