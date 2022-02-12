class Solution {
public:
  vector<int> decrypt(vector<int>& code, int k) {
    if (k == 0) {
      fill(code.begin(), code.end(), 0);
      return code;
    }
    vector<int> decrypt(code.begin(), code.end());
    int diff = 0;
    int n = code.size();
    if (k > 0) {
      for (int i = 1; i < k + 1; ++i) {
        diff += code[i % n];
      }
      for (int i = 0; i < n; ++i) {
        decrypt[i] = diff;
        diff -= code[(i + 1) % n];
        diff += code[(i + 1 + k) % n];
      }
    } else {    // k < 0
      for (int i = 1; i < -k + 1; ++i) {
        diff += code[(-i + n) % n];
      }
      for (int i = 0; i < n; ++i) {
        decrypt[i] = diff;
        diff -= code[(i + k + n) % n];
        diff += code[i];
      }
    }
    return decrypt;
  }
};

