using System;

namespace Fraction
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Console.Write("Insert a fraction (x/y): ");
            var frac = (Fraction)Console.ReadLine();
            Console.Write("Insert a number (x,yz): ");
            var frac2 = (Fraction)Convert.ToDouble(Console.ReadLine());
            Console.WriteLine($"{frac} | {(double)frac}");
            Console.WriteLine($"{frac2} | {(double)frac2}");
            Console.WriteLine($"{frac} * {frac2} = {frac * frac2}");
            Console.WriteLine($"{frac} > {frac2} = {frac >= frac2}");
            Console.WriteLine($"{frac} > {0.5} = {frac > 0.5}");
        }
    }
}