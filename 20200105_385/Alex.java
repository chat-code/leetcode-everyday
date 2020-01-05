public class Alex {

    public NestedInteger deserialize(String s) {
        if (!s.contains("[")) {
            return new NestedInteger(Integer.valueOf(s));
        }

        Stack<NestedInteger> stack = new Stack<>();
        NestedInteger curr = null;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '[') {
                if (curr != null) {
                    stack.push(curr);
                }
                curr = new NestedInteger();
                start = i + 1;
            } else if (c == ']') {
                String num = s.substring(start, i);
                if (num != null && num.length() > 0) {
                    curr.add(new NestedInteger(Integer.valueOf(num)));
                }
                if (!stack.isEmpty()) {
                    NestedInteger n = stack.pop();
                    n.add(curr);
                    curr = n;
                }
                start = i + 1;
            } else if (c == ',') {
                if (s.charAt(i - 1) != ']') {
                    String num = s.substring(start, i);
                    if (num != null && num.length() > 0) {
                        curr.add(new NestedInteger(Integer.valueOf(num)));
                    }
                }
                start = i + 1;
            }
        }
        return curr;
    }
}