/**
 * @Author: xck
 * @File: MaximumNestingDepthofTwoValidParenthesesStrings
 * @Time: 2:09 2020/1/2
 */
public class Alex {

    public int[] maxDepthAfterSplit(String seq) {
        int[] res = new int[seq.length()];
        int level = 0;
        for (int i = 0; i < seq.length(); i++) {
            if (seq.charAt(i) == '(') {
                res[i] = ++level % 2;
            } else {
                res[i] = level-- % 2;
            }
        }
        return res;
    }
}