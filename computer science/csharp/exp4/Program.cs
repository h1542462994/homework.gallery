using System;

namespace exp4
{
    class TimeSpan
    {
        private uint totalSeconds;    
        
        public TimeSpan(uint initialTotalSeconds)
        {
            totalSeconds = initialTotalSeconds;
        }
        
        public void PrintSeconds()
        {
            Console.WriteLine("Total seconds: {0}", totalSeconds);
        }
        
        public static implicit operator TimeSpan(uint convertFrom)
        {
            TimeSpan newTimeSpan;
            
            newTimeSpan = new TimeSpan(convertFrom);
            Console.WriteLine("Converting from uint to TimeSpan");
            return newTimeSpan;
        }
    }

    class ImplicitConversionTester
    {
        public static void Main()
        {
            uint simpleTimeSeconds = 30;
            TimeSpan myTime;
            
            myTime = simpleTimeSeconds;
            myTime.PrintSeconds();
        }
    }

}
