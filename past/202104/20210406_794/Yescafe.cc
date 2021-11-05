/*
 * @lc app=leetcode id=794 lang=cpp
 *
 * [794] Valid Tic-Tac-Toe State
 */

#include <string>
#include <vector>
using std::string;
using std::vector;
#include <iostream>

// @lc code=start
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 32.85 % of cpp submissions (8.5 MB)

class Solution {
public:
  bool validTicTacToe(vector<string>& board) {
    int count_x, count_o;
    count_x = count_o = 0;
    for (auto&& s : board) {
      for (auto&& c : s) {
        switch(c) {
         case 'X': ++count_x; break;
         case 'O': ++count_o; break;
        }
      }
    }
    if (count_x != count_o && count_x - 1 != count_o)
      return false;
    
    int threes = 0;
    char whoWon = 0;
    for (int i = 0; i < 3; ++i) {
      if (threes >= 2) break;
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
        whoWon = board[i][0];
        board[i][0] = board[i][1] = board[i][2] = ' ';
        ++threes;
      }
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
        whoWon = board[0][i];
        board[0][i] = board[1][i] = board[2][i] = ' ';
        ++threes;
      }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
      whoWon = board[1][1];
      board[0][0] = board[1][1] = board[2][2] = ' ';
      ++threes;
    } 
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
      whoWon = board[1][1];
      board[0][2] = board[1][1] = board[2][0] = ' ';
      ++threes;
    }
    
    if (threes > 1) return false;
    if ((count_x == count_o && whoWon == 'X') || 
        (count_x - 1 == count_o && whoWon == 'O'))
      return false;
    return true;
  }
};
// @lc code=end

// 评价：
// 非常脑筋急转弯的题，非常多特判，非常无趣，已举报

int main()
{
  std::vector<std::string> board {
    "XOX",
    "XOO",
    "OXX"
  };
  std::cout << std::boolalpha << Solution().validTicTacToe(board) << std::endl;
}
