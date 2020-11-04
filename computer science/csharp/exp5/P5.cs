using System;
public class TimeSpan
{
    private uint totalSeconds;
    
    public TimeSpan(uint initialTotalSeconds)
    {
        totalSeconds = initialTotalSeconds;
    }
    
    public uint Seconds
    {
        get
        {
            return totalSeconds;
        }

        set
        {
            totalSeconds = value;
        }
    }
}

class Tester
{
    public static void Main()
    {
        TimeSpan myTime = new TimeSpan(480);
        
        UpdateTime(myTime);
        Console.WriteLine("Time outside UpdateTime method: {0}", myTime.Seconds);
    }
    
    public static void UpdateTime(TimeSpan timeUpdate)
    {
        timeUpdate.Seconds = timeUpdate.Seconds + 50;
        Console.WriteLine("Time inside UpdateTime method: {0}", timeUpdate.Seconds);
    }
}
