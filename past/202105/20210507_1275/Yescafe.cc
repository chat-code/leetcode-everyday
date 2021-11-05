// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Winner on a Tic Tac Toe Game.
// Memory Usage: 8.4 MB, less than 51.02% of C++ online submissions for Find Winner on a Tic Tac Toe Game.


class Solution {
public:
  string tictactoe(vector<vector<int>>& moves) {
    vector<vector<char>> matrix(3, vector<char>(3, ' '));

    for (int i = 0; i < moves.size(); ++i) {
      auto& p = moves[i];
      matrix[p[0]][p[1]] = i % 2 ? 'O' : 'X';
    }

    auto who = whowin(matrix);
    if (who == 'X')
      return {"A"};
    else if (who == 'O')
      return {"B"};
    else {
      if (moves.size() == 9) {
        return {"Draw"};
      } else {
        return {"Pending"};
      }
    }
  }

private:
  char whowin(vector<vector<char>>& matrix) {
    for (int i = 0; i < 3; ++i) {
      if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][0] != ' ') {
        return matrix[i][0];
      } else if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[0][i] != ' ') {
        return matrix[0][i];
      }
    }
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[1][1] != ' ') {
      return matrix[1][1];
    }
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[1][1] != ' ') {
      return matrix[1][1];
    }
    return ' ';
  }
};
