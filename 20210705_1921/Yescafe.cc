class Solution {
public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    const int S = dist.size();
    vector<double> v(S, 0.);
    for (int i = 0; i < S; ++i) {
      v[i] = double(dist[i]) / speed[i];
    }
    sort(v.begin(), v.end());
    
    int sec = 0;
    for (; sec < S; ++sec) {
      if (v[sec] <= sec) {
        return sec;
      }
    }
    return S;
  }
};