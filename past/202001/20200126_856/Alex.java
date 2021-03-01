class Alex {

    public int scoreOfParentheses(String S) {
        int sum = 0;
        int level = 0;

        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            if (c == '(') {
                level++;
            } else if (c == ')') {

                level--;
                if (S.charAt(i - 1) == '(') {
                    sum += 1 << level;
                }
            }

        }
        return sum;
    }
}