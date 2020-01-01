class Solution {
    public int lengthOfLongestSubstring(String s) {

        int max = 0;
        Set<Character> set = new HashSet<>();
        int j = 0;
        for(int i = 0;i < s.length();){
            if(!set.contains( s.charAt(i))){
                set.add(s.charAt(i));
                i++;
            }else{
                set.remove( s.charAt(j++));
            }
            max = Math.max(set.size(),max);
        }
        return max;
    }
}