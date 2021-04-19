class Solution {
public:
  using VI = vector<int>;

  string pushDominoes(string a) {
    int n = a.size();
    VI d(n, 0);

    for (int i = 0; i < n; ++i) {
      if (a[i] == 'L' || a[i] == 'R') d[i] = 1;
    }

    for (int i = n - 1; i >= 0; --i) {
      if (a[i] == 'L' && d[i] == 1) {
        int j = i - 1;
        while (j >= 0 && a[j] == '.') {
          a[j] = 'L';
          d[j] = d[j + 1] + 1;
          --j;
        }
        i = j + 1;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (a[i] == 'R' && d[i] == 1) {
        int j = i + 1;
        while (j < n && a[j] != 'R') {
          int t = d[j - 1] + 1;
          if (a[j] == '.') {
            a[j] = 'R';
            d[j] = t;
            ++j;
            continue;
          }
          if (t < d[j]) {
            d[j] = t;
            a[j] = 'R';
            ++j;
          } else if (t == d[j]) {
            a[j] = '.';
            ++j;
          } else {
            break;
          }
        }
        i = j - 1;
      }
    }

    return a;
  }
};
