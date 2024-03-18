public class RemoveCoveredIntervals {

    public int removeCoveredIntervals(int[][] intervals) {
        int count = 0;
        int temp = 0;
        Arrays.sort(intervals, (a, b) -> a[0] != b[0] ? a[0] - b[0] : b[1] - a[1]);
        for (int[] i : intervals) {
            if (i[1] > temp) {
                count++;
                temp = i[1];
            }

        }
        return count;
    }
}