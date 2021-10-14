class Solution {
public:
  int countTriples(int n) {
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
        auto sr = sqrt(i * i + j * j);
        if (sr > n) break;
        if (sq((int) sr) == i * i + j * j)
          ++cnt;
      }
    }
    return cnt;
  }
  
private:
  int sq(int a) {
    return a * a;
  }
};
