using VI = vector<int>;

class Solution {
public:
  vector<int> memLeak(int a, int b) {
    int n = 1;
    while (a >= n || b >= n) {
      if (a >= b) a -= n;
      else b -= n;
      ++n;
    }
    VI res {n, a, b};

    return res;
  }
};
