class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        String core = "123456789";
        List<Integer> lst = new ArrayList<>();
        for(int i = 2;i < 10;i++){
            for(int j = 0;j + i < 10;j++){
                lst.add(Integer.valueOf(core.substring(j,j + i)));
            }
        }

        return lst.stream().filter(i -> i <= high && i >= low).collect(Collectors.toList());
    }


}