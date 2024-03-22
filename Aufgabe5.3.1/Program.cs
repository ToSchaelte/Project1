using System;
using System.Collections.Generic;
using System.Linq;

namespace Task_5_3_1
{
    internal static class Program
    {
        private const int PasswordValue = 'a' + 'u' + 't' + 'o';

        private static void Main()
        {
            var input = new char[4];
            for (var j = 0; j < 3; j++)
            {
                for (var i = 0; i < input.Length; i++)
                {
                    input[i] = Convert.ToChar(Console.Read());
                    if (input[i] == '\n' || input[i] == '\r') i--;
                }

                if (!IsPasswordCorrect(input))
                {
                    Console.WriteLine($"!!! WRONG PASSWORD. {3 - 1 - j} ATTEMPTS LEFT !!!.");
                    if (j >= 2) Console.WriteLine("!!! YOU FAILED !!!");
                    continue;
                }

                Console.WriteLine("LOGIN CORRECT");
                break;
            }
        }

        private static bool IsPasswordCorrect(IEnumerable<char> chars)
        {
            return chars.Select(char.ToLower).Aggregate(0, (val, c) => val + c) == PasswordValue;
        }
    }
}