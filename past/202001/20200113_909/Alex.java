public class Alex {

    public int snakesAndLadders(int[][] board) {
        int len = board.length;
        Map<Integer, Integer> map = new HashMap<>();
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        map.put(1, 0);
        while (!queue.isEmpty()) {
            int target = queue.remove();
            if (target == len * len) {
                return map.get(target);
            }
            for (int i = target + 1; i <= Math.min(len * len, target + 6); i++) {
                int rc = get(i, len);
                int sFinal = board[rc / len][rc % len] == -1 ? i : board[rc / len][rc % len];
                if (!map.containsKey(sFinal)) {
                    map.put(sFinal, map.get(target) + 1);
                    queue.add(sFinal);
                }
            }
        }
        return -1;
    }

    public int get(int s, int N) {
        int quot = (s - 1) / N;
        int rem = (s - 1) % N;
        int row = N - 1 - quot;
        int col = row % 2 != N % 2 ? rem : N - 1 - rem;
        return row * N + col;
    }
}
