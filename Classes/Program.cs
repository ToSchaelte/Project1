using System;

namespace Classes
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            var frac = new Fraction(4, 3);
            var frac2 = new Fraction(3, 1);
            Console.WriteLine(frac);
            Console.WriteLine(frac2);
        }
    }
}