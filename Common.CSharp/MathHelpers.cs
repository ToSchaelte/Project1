namespace Common.CSharp
{
    public static class MathHelpers
    {
        public static uint GetGreatestCommonDivisor(uint a, uint b)
        {
            while (b != 0) (a, b) = (b, a % b);
            return a;
        }
    }
}