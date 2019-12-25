#include <iostream>
#include <vector>

using namespace std;

using VI = vector<int>;

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
  Node* construct(vector<vector<int>>& grid) {
    return helper(0, 0, int(grid.size()), grid);
  }

  Node* helper(int x, int y, int w, vector<VI>& grid)
  {
    Node* res = new Node(false, false, nullptr, nullptr, nullptr, nullptr);
    int s = 0, ts = w * w;

    for (int i = x; i < x + w; i++)
        for (int j = y; j < y + w; j++)
          s += grid[i][j];

    if (s == ts)
      {
        res->isLeaf = true;
        res->val = true;
        return res;
      }
    else if (s == 0)
      {
        res->isLeaf = true;
        res->val = false;
        return res;
      }
    int w1 = w / 2;
    res->topLeft = helper(x, y, w1, grid);
    res->topRight = helper(x, y + w1, w1, grid);
    res->bottomLeft = helper(x + w1, y, w1, grid);
    res->bottomRight = helper(x + w1, y + w1, w1, grid);
    return res;
  }
};

int main()
{

  return 0;
}
