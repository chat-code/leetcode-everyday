public class Alex {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int res = 0;
        int tempTime = 0;
        if(timeSeries.length == 0)
        {
            return 0;
        }
        for(int i = 0;i < timeSeries.length - 1;i ++)
        {
            if(timeSeries[i + 1] - timeSeries[i] > duration)
            {
                tempTime += timeSeries[i + 1] - timeSeries[i] - duration;
            }
        }
        res = timeSeries[timeSeries.length - 1] - timeSeries[0] + duration - tempTime;
        return res;

    }
}