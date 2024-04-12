using System;
using System.Collections.Generic;
using System.Linq;

namespace Task_5_3_2
{
    internal abstract class Program
    {
        private const int CodeLength = 5;
        public static void Main()
        {
            var input = new char[CodeLength];
            var errorMessage = string.Empty;
            var isValid = true;
            do
            {
                if (!isValid) Console.WriteLine(errorMessage);
                Console.Write("Please enter the Code: ");
                for (var i = 0; i < input.Length; i++)
                {
                    input[i] = Convert.ToChar(Console.Read());
                    if (input[i] == '\n' || input[i] == '\r') i--;
                }
            } while (!(isValid = IsCodeValid(input, out errorMessage)));

            Console.WriteLine("INPUT CORRECT");
        }

        private static bool IsCodeValid(IReadOnlyList<char> wannabeCode, out string errorMessage)
        {
            errorMessage = "!!! INVALID CODE !!!";
            var inputAsNumber = ToNumber(wannabeCode);
            if (inputAsNumber % 3 == 0 || inputAsNumber % 5 == 0 || inputAsNumber % 7 == 0) return false;
            if ('1' == wannabeCode[0] && '1' != wannabeCode[4]) return false;
            if (wannabeCode.Aggregate('0' - wannabeCode[wannabeCode.Count - 1], (sum, c) => sum + c - '0') % 7 !=
                wannabeCode[4] - '0') return false;
            errorMessage = string.Empty;
            return true;
        }

        private static int ToNumber(IReadOnlyList<char> chars)
        {
            var num = 0;
            for (var i = 0; i < chars.Count; i++)
            {
                if (!char.IsDigit(chars[i])) throw new ArgumentException("char is not a number");
                num += (chars[i] - '0') * (int)Math.Pow(10, i);
            }

            return num;
        }
    }
}