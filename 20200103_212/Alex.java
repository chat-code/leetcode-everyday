class Alex{
    int[][] path = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    boolean[][] visited;

    public static void main(String[] args) {
        char[][] board = {
            {'o', 'a', 'a', 'n'},
            {'e', 't', 'a', 'e'},
            {'i', 'h', 'k', 'r'},
            {'i', 'f', 'l', 'v'}
        };
        String[] s = {"oath", "pea", "eat", "rain"};
        WordSearchII wordSearchII = new WordSearchII();
        System.out.println(wordSearchII.findWords(board, s));
    }

    public List<String> findWords(char[][] board, String[] words) {
        List<String> lst = new ArrayList<>();
        for (String word : words) {
            if (hasPath(board, word)) {
                lst.add(word);
            }
        }
        return lst;
    }

    public boolean hasPath(char[][] board, String word) {
        visited = new boolean[board.length][board[0].length];
        int x = -1, y = -1;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == word.charAt(0)) {
                    x = i;
                    y = j;
                    visited[i][j] = true;
                    if (dfs(board, word, x, y, 0)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

    public boolean dfs(char[][] board, String word, int x, int y, int start) {
        if (start + 1 == word.length()) {
            return true;
        }
        boolean res = false;
        for (int[] p : path) {
            int x1 = x + p[0];
            int y1 = y + p[1];
            if (x1 < 0 || x1 >= board.length || y1 < 0 || y1 >= board[0].length || start + 1 >= word
                .length()) {
                continue;
            }
            if (!visited[x1][y1] && board[x1][y1] == word.charAt(start + 1)) {
                visited[x1][y1] = true;
                res |= dfs(board, word, x1, y1, start + 1);
                visited[x1][y1] = false;
            }
        }
        return res;
    }
}