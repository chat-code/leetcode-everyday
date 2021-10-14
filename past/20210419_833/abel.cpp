#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string findReplaceString(string s, vector<int>& idxes, 
        vector<string>& a, vector<string>& b) {
      int n = idxes.size();
      vector<int> id(n);

      for (int i = 0; i < n; ++i) id[i] = i;
      sort(id.begin(), id.end(), [&](const int x, const int y) {
          return idxes[x] > idxes[y];
      });

      for (int i = 0; i < n; ++i) {
        int j = id[i], idx = idxes[j];
        if (s.substr(idx, a[j].size()) == a[j]) {
          s.replace(idx, a[j].size(), b[j]);
        }
      }
      return s;
    }
};
