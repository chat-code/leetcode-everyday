class Solution {

    public String convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        int original = Math.abs(num);
        StringBuilder sb = new StringBuilder();
        while (original != 0) {
            int mod = original % 7;
            original = original / 7;
            sb.append(mod);
        }
        return num < 0 ? "-" + sb.reverse().toString() : sb.reverse().toString();

    }
}