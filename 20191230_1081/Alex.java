public class SmallestSubsequence {

    public String smallestSubsequence(String S) {
        Stack<Integer> stack = new Stack<>();
        int[] last = new int[26], seen = new int[26];
        for (int i = 0; i < S.length(); ++i) {
            last[S.charAt(i) - 'a'] = i;
        }
        for (int i = 0; i < S.length(); ++i) {
            int c = S.charAt(i) - 'a';
            if (seen[c]++ > 0) {
                continue;
            }
            while (!stack.isEmpty() && stack.peek() > c && i < last[stack.peek()]) {
                seen[stack.pop()] = 0;
            }
            stack.push(c);
        }
        StringBuilder sb = new StringBuilder();
        for (int i : stack) {
            sb.append((char) ('a' + i));
        }
        return sb.toString();
    }
}
