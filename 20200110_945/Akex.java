class Alex{
    public int minIncrementForUnique(int[] A) {
        int max = 100000;
        int[] tem = new int[max];
        for(int i:A)
            tem[i]++;
        int count = 0;
        int taken = 0;
        for(int i = 0;i < tem.length;i++){
            if(tem[i] > 1){
                taken += tem[i] - 1;
                count -= i * (tem[i] - 1);
            }else if(tem[i] == 0 && taken > 0){
                taken--;
                count += i;
            }
        }
        return count;
    }
}