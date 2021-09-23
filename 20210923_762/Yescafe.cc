class Solution {
public:
  int countPrimeSetBits(int left, int right) {
    int cnt = 0;
    for (int n = left; n <= right; ++n) {
      switch (counts(n)) {
        case 2: case 3: case 5: case 7: case 11:
        case 13: case 17: case 19: case 23: case 29: case 31: {
          ++cnt;
          break;
        }
      }
    }
    return cnt;
  }
  
private:
  int counts(int x) {
    int cnt = 0;
    while (x) {
      x &= (x - 1);
      ++cnt;
    }
    return cnt;
  }
};
