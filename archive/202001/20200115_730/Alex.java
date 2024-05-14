class Alex {
    public int countPalindromicSubsequences(String S) {
        final int M = 1000000007;
        int len = S.length();
        int[][][] dp = new int[4][len][len];
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                for (int k = 0; k < 4; k++) {
                    char c = (char) (k + 'a');
                    if (i == j) {
                        if (S.charAt(i) == c) {
                            dp[k][i][j] = 1;
                        } else {
                            dp[k][i][j] = 0;
                        }
                    } else {
                        if (S.charAt(i) != c) {
                            dp[k][i][j] = dp[k][i + 1][j];
                        } else if (S.charAt(j) != c) {
                            dp[k][i][j] = dp[k][i][j - 1];
                        } else {
                            if (i + 1 == j) {
                                dp[k][i][j] = 2;
                            } else {
                                dp[k][i][j] = 2;
                                for (int l = 0; l < 4; l++) {
                                    dp[k][i][j] += dp[l][i + 1][j - 1];
                                    dp[k][i][j] %= M;
                                }
                            }

                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int k = 0; k < 4; ++k) {
            ans += dp[k][0][len - 1];
            ans %= M;
        }

        return ans;
    }
}