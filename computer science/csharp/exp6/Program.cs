using System;
using System.Linq;

class AccountBalanceTraversal
{
    public static void Main()
    {
        const decimal interestRate = 0.1m;
        decimal [] accountBalances;
        accountBalances = new decimal [5];
        Console.WriteLine("Please enter {0} account balances:", accountBalances.Length);

        // for (int i = 0; i < accountBalances.Length; i++)
        // {
        //     Console.Write("Enter balance with index {0}: ", i);
        //     accountBalances[i] = Convert.ToDecimal(Console.ReadLine());
        // }

        foreach (var (value, i) in accountBalances.Select((value, i) => (value, i))) {
            Console.Write($"Enter balance with index {i}:");
            accountBalances[i] = Decimal.Parse(Console.ReadLine());
        }
 
        Console.WriteLine("\nAccount balances after adding interest\n");
        // for (int i = 0; i < accountBalances.Length; i++)
        // {
        //     accountBalances[i] = accountBalances[i]
        //         + (accountBalances[i] * interestRate);
        //     Console.WriteLine("Account balance with index {0}: {1:C}",
        //         i, accountBalances[i]);
        // }

        foreach (var (value, i) in accountBalances.Select((value, i) => (value, i))) {
            accountBalances[i] = accountBalances[i] * (1 + interestRate);
            Console.WriteLine("Account balance with index {0}: {1:C}",
                i, accountBalances[i]);
        }        
    }
}

