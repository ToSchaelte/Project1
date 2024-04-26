using System;

namespace Fraction
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Console.Write("Insert a fraction (x/y): ");
            var frac = Fraction.FromString(Console.ReadLine());
            Console.Write("Insert a number (x,yz): ");
            var frac2 = Fraction.FromDouble(Convert.ToDouble(Console.ReadLine()));
            Console.WriteLine(frac);
            Console.WriteLine(frac2);
            Console.WriteLine($"{frac} * {frac2} = {frac * frac2}");
            Console.WriteLine($"{frac} > {frac2} = {frac >= frac2}");
            Console.WriteLine($"{frac} > {0.5} = {frac > 0.5}");
        }
    }
}