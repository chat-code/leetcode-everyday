/**
 * @Author: xck
 * @File: MinimumSwapsToMakeSequencesIncreasing
 * @Time: 22:40 2019/12/25
 */
public class MinimumSwapsToMakeSequencesIncreasing {

    public int minSwap(int[] A, int[] B) {
        int len = A.length;
        int n = 0;
        int s = 1;
        for (int i = 1; i < len; i++) {
            if (A[i] <= A[i - 1] || B[i] <= B[i - 1]) {
                int temp = s;
                s = n + 1;
                n = temp;
            } else if (A[i] <= B[i - 1] || B[i] <= A[i - 1]) {
                s++;
            } else {
                int min = Math.min(n, s);
                n = min;
                s = min + 1;
            }
        }
        return Math.min(n, s);
    }
}