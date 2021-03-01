class Alex{
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        helper(nums,res,new ArrayList<Integer>());
        return res;
    }

    public void helper(int[] nums,List<List<Integer>> res,List<Integer> list){
        if(list.size() == nums.length){
            res.add(new ArrayList<Integer>(list));
            return;
        }else{
            for(int i = 0;i < nums.length;i++){
                if(list.contains(nums[i])) continue;
                list.add(nums[i]);
                helper(nums,res,list);
                list.remove(list.size() - 1);
            }
        }
    }
}