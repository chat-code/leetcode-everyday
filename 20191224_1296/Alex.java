public class DivideArrayinSetsofKConsecutiveNumbers {

    public static boolean isPossibleDivide(int[] nums, int k) {
        int len = nums.length;
        if (len % k != 0) {
            return false;
        }
        int size = k;
        Arrays.sort(nums);
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < len; i++) {
            list.add(nums[i]);
        }
        while (list.size() >= size) {
            int start = list.get(0);
            for (int i = 0; i < size; i++) {
                if (!list.remove((Object) (start + i))) {
                    return false;
                }
            }
        }
        return true;
    }
}