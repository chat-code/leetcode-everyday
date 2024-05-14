class Alex {

    int count = 0;

    public int numSquarefulPerms(int[] A) {
        Arrays.sort(A);
        dfs(A, new ArrayList<>(), new boolean[A.length]);
        return count;
    }

    public void dfs(int[] A, List<Integer> list, boolean[] used) {
        if (list.size() == A.length) {
            count++;
            return;
        }
        for (int i = 0; i < A.length; i++) {
            if (used[i] || (i - 1 >= 0 && A[i] == A[i - 1] && !used[i - 1])) {
                continue;
            }
            if (list.size() == 0 || isSquare(list.get(list.size() - 1) + A[i])) {
                list.add(A[i]);
                used[i] = true;
                dfs(A, list, used);
                list.remove(list.size() - 1);
                used[i] = false;
            }
        }
    }

    public boolean isSquare(int x) {
        double r = Math.sqrt(x);
        if ((r - Math.floor(r)) == 0) {
            return true;
        }
        return false;

    }
}