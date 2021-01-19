class Alex{
    Set<String> set = new HashSet<>();
    boolean[] vis;

    public static void main(String[] args) {
        LetterTilePossibilities l = new LetterTilePossibilities();
        l.numTilePossibilities("AB");
//        [A, AA, AAB, AABB, AABBA, AABBAB]
    }

    public int numTilePossibilities(String tiles) {
        int n = tiles.length();
        vis = new boolean[n];
        dfs(new StringBuilder(), tiles);
        System.out.println(set);
        return set.size();
    }

    public void dfs(StringBuilder sb, String tiles) {
        if (sb.length() > 0) {
            set.add(sb.toString());
        }
        if (sb.length() >= tiles.length()) {
            return;
        }
        for (int i = 0; i < tiles.length(); i++) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            int len = sb.length();
            dfs(sb.append(tiles.charAt(i)), tiles);
            sb.setLength(len);
            vis[i] = false;
        }
    }
}