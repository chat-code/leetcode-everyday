class Alex{
    public  void nextPermutation(int[] nums){
        for(int i = nums.length - 2;i >= 0;i--){
            if(nums[i] < nums[i + 1]){
                for(int j = nums.length - 1;j > i ; j--){
                    if(nums[j] > nums[i]){
                        int tmp = nums[j];
                        nums[j] = nums[i];
                        nums[i] = tmp;
                        break;
                    }
                }
                reverseArray(nums,i + 1,nums.length - 1);
                return;
            }


        }
        reverseArray(nums,0,nums.length - 1);
    }

    private   void reverseArray(int[] nums, int begin, int end){
        for(int i = begin, j = end;i<j;i++,j--){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}