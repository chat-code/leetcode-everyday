public class IntegerReplacement {

    Map<Integer, Integer> map = new HashMap<>();

    {
        map.put(1, 0);
        map.put(2, 1);
    }

    public int integerReplacement(int n) {
        if (map.get(n) != null) {
            return map.get(n);
        }
        if (n % 2 == 0) {
            int t = integerReplacement(n / 2) + 1;
            map.put(n, t);
            return t;
        } else {
            int t = Math.min(integerReplacement(n / 2 + 1), integerReplacement(n / 2)) + 2;
            map.put(n, t);
            return t;
        }
    }
}