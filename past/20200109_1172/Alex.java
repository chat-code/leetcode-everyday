class Alex{
    public int reachNumber(int target) {
        //f(0) = 0
        // f(1) = 1
        // f(2) = 3
        // f(3) = 2
        target = Math.abs(target);
        int sum = 0;
        int i = 0;
        while(sum < target){
            i++;
            sum += i;
        }
        while((sum - target) % 2 != 0){
            i++;
            sum += i;
        }
        return i;
    }
}