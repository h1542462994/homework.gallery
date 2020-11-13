using System;
using System.Collections.Generic;
using System.Linq;

public class AgePrint 
{
    public static void Main() {
        int[] ages = new int[5];
        foreach (var (v, i) in ages.Select((v, i) => (v, i)))
        {
           Console.Write($"Enter age for number {i}:");
           ages[i] = int.Parse(Console.ReadLine());
        }

        Console.WriteLine();

        foreach (var (v, i) in ages.Select((v, i) => (v, i)))
        {
           Console.WriteLine($"Age for number {i}: {v}");
        }
       
        Console.WriteLine();

        int average = ages.Sum() / 5;

        Console.WriteLine($"Average Age : {average}");
    }
}