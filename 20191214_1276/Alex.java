class Solution {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int jumbo = 0;
        int small = 0;
        for(;jumbo <= tomatoSlices / 4;jumbo++){
             small = (tomatoSlices - jumbo * 4) / 2;
            int other = (tomatoSlices - jumbo * 4) % 2;
            if(other == 0 && jumbo + small == cheeseSlices)
                    return Arrays.asList(jumbo,small);
            
        }
        return new ArrayList<>();
    }
}
