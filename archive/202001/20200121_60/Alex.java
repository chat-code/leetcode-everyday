class Alex{
    public String getPermutation(int n, int k) {
        StringBuffer sb = new StringBuffer();
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n ; i++) {
            f[i] = f[i - 1] * i;
        }

        List<Integer> numbers = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            numbers.add( i + 1);
        }

        k--;
        for (int i = 1;i <= n;i++){
            int index = k / f[n - i];
            sb.append(numbers.get(index));
            numbers.remove(index);
            k -= index * f[n - i];
        }
        return sb.toString();
    }
}