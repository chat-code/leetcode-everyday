class Solution {
    public int balancedStringSplit(String s) {
        int slow = 0;
        int fast = 0;
        int i = 0;
        int count = 0;
        while(slow < s.length() && fast < s.length() && i < s.length()){
            if(s.charAt(i) == 'L'){
                slow++;
            }else if(s.charAt(i) == 'R'){
                fast++;
            }
            
            if(slow == fast && slow > 0){
                count++;
                slow = fast = 0;
            }
            i++;
        }
        return count;
    }
}
