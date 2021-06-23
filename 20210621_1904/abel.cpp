class Solution {
public:
  int numberOfRounds(string startTime, string finishTime) {
    int t1 {}, t2{}, h1 {}, h2{}, m1 {}, m2{};
    sscanf(startTime.c_str(), "%02d:%02d", &h1, &m1);
    sscanf(finishTime.c_str(), "%02d:%02d", &h2, &m2);
    t1 = h1 * 60 + m1; t2 = h2 * 60 + m2;
    int res{};
    const int N = 2881;
    vector<int> a(N, 0);
    for (int i = 0; i < N; i += 15) {
      a[i] = 1;
    }

    if (t2 < t1) t2 += 1440;
    for (int i = t1; i <= t2; ++i) {
      if (a[i] == 1 && i + 15 <= t2) {
        res++;
      }
    }

    return res;
  }
};
