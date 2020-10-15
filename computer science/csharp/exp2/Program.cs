using System;

namespace exp2
{
    public class Power
    {
       //  public void MyPower(ref int x, ref int y)
        public void MyPower(ref int x,ref int y)
        {
            //x = 1; y = 2;
            Console.WriteLine("x={0},y={1}", x, y);
            Console.WriteLine("x*x={0},y*y={1}",x*x,y*y);           
        }
    }
    public class Tester
    {
        public static void Main()
        {
            int x, y;
            x = 3; y = 5;
            Power mp = new Power();
            // mp.MyPower(ref x,ref y);
            mp.MyPower(x,y);
            Console.WriteLine("x={0},y={1}",x,y);
            Console.ReadLine();

        }
    }

}
