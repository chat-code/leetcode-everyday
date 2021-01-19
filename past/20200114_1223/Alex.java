class Alex{
    final int mod = 1000000007;
    int[][][] dp = new int[5000][6][16];

    public int dieSimulator(int n, int[] rollMax) {
        return dfs(n, 0, rollMax, -1);

    }

    public int dfs(int dieLeft, int curLen, int[] rollMax, int last) {
        if (dieLeft == 0) {
            return 1;
        }

        if (last > 0 && dp[dieLeft][last][curLen] > 0) {
            return dp[dieLeft][last][curLen];
        }
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            if (i == last && rollMax[i] == curLen) {
                continue;
            }

            sum = (dfs(dieLeft - 1, i == last ? curLen + 1 : 1, rollMax, i) + sum) % mod;
        }
        if (last > 0) {
            dp[dieLeft][last][curLen] = sum;
        }
        return sum;
    }
}