  
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int result=0;
        for (int i = 0; i < timeSeries.length; i++){
            if (i  != timeSeries.length-1 &&timeSeries[i] + duration -1 >= timeSeries[i+1])
                result = timeSeries[i+1] - timeSeries[i] + result;
            else result = duration + result;
        }
        return result;
    }
