class Solution {
public:
  int openLock(vector<string>& deadends, string target) {
    vector<bool> vis(10000, false);
    for (auto& d : deadends) {
      vis[stoi(d)] = true;
    }
    int t = stoi(target);
    if (vis[0] == true) {
      return -1;
    }
    
    deque<int> q;
    q.push_back(0);
    int times = 0;
    auto add = [&](int n) {
      if (!vis[n]) {
        vis[n] = true;
        q.push_back(n);
      }
    };
    while (!q.empty()) {
      int sz = q.size();
      while (sz--) {
        int top = q.front();
        if (top == t) {
          return times;
        }
        q.pop_front();
        
        for (int p = 0; p < 4; ++p) {
          int np = getNp(top, p);
          add(top + tens(p) * (np == 0 ? 9 : -1));
          add(top + tens(p) * (np == 9 ? -9 : 1));
        }
      }
      ++times;
    }
    
    return -1;
  }
  
private:
  int getNp(int n, int p) {
    switch (p) {
      case 0:
        return n % 10;
      case 1:
        return n / 10 % 10;
      case 2:
        return n / 100 % 10;
      case 3:
        return n / 1000;
    }
    return -1;
  }

  int tens(int p) {
    switch (p) {
      case 0:
        return 1;
      case 1:
        return 10;
      case 2:
        return 100;
      case 3:
        return 1000;
    }
    return -1;
  }
};