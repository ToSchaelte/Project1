namespace Common.CSharp
{
    public static class MathHelpers
    {
        public static ulong GetGreatestCommonDivisor(ulong a, ulong b)
        {
            while (b != 0) (a, b) = (b, a % b);
            return a;
        }
    }
}