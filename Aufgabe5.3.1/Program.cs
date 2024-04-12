using System;
using System.Collections.Generic;
using System.Linq;

namespace Task_5_3_1
{
    internal static class Program
    {
        private const int PasswordValue = 'a' + 'u' + 't' + 'o';
        private const int PasswordLetterCount = 4;
        private const int Trys = 3;

        private static int Main()
        {
            if (!Login())
            {
                Console.WriteLine("!!! YOU FAILED !!!");
                return 1;
            }

            Console.WriteLine("LOGIN CORRECT");
            return 0;
        }

        private static bool Login()
        {
            var input = new char[PasswordLetterCount];
            for (var j = 0; j < Trys; j++)
            {
                Console.Write("PASSWORD PLEASE: ");
                for (var i = 0; i < input.Length; i++)
                {
                    input[i] = Convert.ToChar(Console.Read());
                    if (input[i] == '\n' || input[i] == '\r') i--;
                }

                if (IsPasswordCorrect(input)) return true;
                Console.WriteLine($"!!! WRONG PASSWORD. {Trys - 1 - j} ATTEMPTS LEFT !!!.");
            }
            
            return false;
        }

        private static bool IsPasswordCorrect(IEnumerable<char> chars) => chars.Aggregate(0, (current, c) => current + char.ToLower(c)) == PasswordValue;

        private static bool IsPasswordCorrect_Simple(char[] chars)
        {
            var val = 0;
            for (var i = 0; i < chars.Length; i++) val += char.ToLower(chars[i]);
            return val == PasswordValue;
        }
    }
}