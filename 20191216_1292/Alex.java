public class MaximumSideLengthofaSquarewithSumLessthanorEqualtoThreshold {

    public int maxSideLength(int[][] mat, int threshold) {
        int m = mat.length;
        if (m == 0) {
            return 0;
        }
        int max = 0;
        int n = mat[0].length;
        int[][] pre = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            int sum = 0;
            for (int j = 1; j <= n; j++) {
                sum += mat[i - 1][j - 1];
                pre[i][j] = pre[i - 1][j] + sum;
            }
        }
        int kk = Math.min(m, n);
        for (int k = 1; k <= kk; k++) {
            for (int i = 1; i + k <= m; i++) {
                for (int j = 1; j + k <= n; j++) {
                    if (pre[i + k][j + k] - pre[i - 1][j + k] - pre[i + k][j - 1] + pre[i - 1][j
                        - 1] <= threshold) {
                        max = Math.max(k + 1, max);
                    }
                }
            }
        }
        return max;
    }
}
