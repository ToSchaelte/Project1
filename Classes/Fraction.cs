using System;
using Common.CSharp;

namespace Classes
{
    public class Fraction
    {
        public int Numerator { private set; get; }
        
        private int _denominator;
        public int Denominator
        {
            private set
            {
                if (value == 0) throw new ArgumentNullException(nameof(value));
                _denominator = value;
            }
            get => _denominator;
        }

        public Fraction(int numerator, int denominator)
        {
            if (denominator == 0) throw new ArgumentNullException(nameof(denominator));
            if (denominator < 0)
            {
                numerator *= -1;
                denominator *= -1;
            }
            Numerator = numerator;
            Denominator = denominator;
            Simplify();
        }

        public static Fraction operator +(Fraction fraction1, Fraction fraction2)
        {
            if (fraction1.Denominator == fraction2.Denominator)
                return new Fraction(fraction1.Numerator + fraction2.Numerator, fraction1.Denominator).Simplified();

            return new Fraction(
                fraction1.Numerator * fraction2.Denominator + fraction2.Numerator * fraction1.Denominator,
                fraction1.Denominator * fraction2.Denominator).Simplified();
        }

        public static Fraction operator -(Fraction fraction1, Fraction fraction2)
        {
            if (fraction1.Denominator == fraction2.Denominator)
                return new Fraction(fraction1.Numerator - fraction2.Numerator, fraction1.Denominator).Simplified();

            return new Fraction(
                fraction1.Numerator * fraction2.Denominator - fraction2.Numerator * fraction1.Denominator,
                fraction1.Denominator * fraction2.Denominator).Simplified();
        }

        public static Fraction operator *(Fraction fraction1, Fraction fraction2)
        {
            return new Fraction(fraction1.Numerator * fraction2.Numerator,
                fraction1.Denominator * fraction2.Denominator).Simplified();
        }

        public static Fraction operator /(Fraction fraction1, Fraction fraction2)
        {
            return new Fraction(fraction1.Numerator * fraction2.Denominator,
                fraction1.Denominator * fraction2.Numerator).Simplified();
        }

        public override bool Equals(object obj)
        {
            if (!(obj is Fraction fraction)) return false;
            return Equals(fraction);
        }

        public bool Equals(Fraction other)
        {
            return other.Numerator == Numerator && other.Denominator == Denominator;
        }

        public void Simplify()
        {
            var gcd = GetGreatestCommonDivisor();
            Numerator /= gcd;
            Denominator /= gcd;
        }

        public Fraction Simplified()
        {
            var frac = new Fraction(Numerator, Denominator);
            frac.Simplify();
            return frac;
        }

        public int GetGreatestCommonDivisor()
        {
            return Convert.ToInt32(MathHelpers.GetGreatestCommonDivisor(
                (uint)(Numerator < 0 ? Numerator * -1 : Numerator),
                (uint)(Denominator < 0 ? Denominator * -1 : Denominator)));
        }

        public override string ToString()
        {
            return $"{Numerator}/{Denominator}";
        }

        public double ToDouble()
        {
            return (double)Numerator / Denominator;
        }

        public static Fraction FromDouble(double d)
        {
            var full = (int)d;
            var part = d - full;
            var tmp = part;
            var i = 1;
            for (; tmp != Math.Round(tmp); i++) tmp += part;
            return new Fraction((int)tmp + i * full, i).Simplified();
        }
    }
}