    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        if (s == " ") return 1;
        Set<Character> set = new HashSet<>();

        int i =0; int j = 0;int count =0 ;

        while (j < s.length()&&i < s.length()){
            if(!set.contains(s.charAt(j))) {
                set.add(s.charAt(j));
                j++;
                count = Math.max(count, j -i);
            }
            else set.remove(i++);
        }

        return count;
    }
