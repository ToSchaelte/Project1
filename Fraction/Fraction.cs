using System;
using Common.CSharp;

namespace Fraction
{
    public class Fraction
    {
        #region Properties

        public static int Count { get; private set; } = 0;
        
        public long Numerator { private set; get; }
        
        private ulong _denominator;
        public ulong Denominator
        {
            private set
            {
                if (value == 0) throw new DivideByZeroException();
                _denominator = value;
            }
            get => _denominator;
        }

        #endregion
        
        #region Con- & Destructors

        public Fraction(long numerator, long denominator, bool simplify = true)
        {
            if (denominator == 0) throw new DivideByZeroException();
            if (denominator < 0)
            {
                numerator *= -1;
                denominator *= -1;
            }
            Numerator = numerator;
            Denominator = (ulong)denominator;
            if (simplify) Simplify();
            Count++;
        }

        public Fraction(long numerator, ulong denominator, bool simplify = true)
        {
            if (denominator == 0) throw new DivideByZeroException();
            Numerator = numerator;
            Denominator = denominator;
            if (simplify) Simplify();
            Count++;
        }

        ~Fraction()
        {
            Count--;
        }
        
        #endregion

        #region Operators
        
        public static Fraction operator +(Fraction fraction1, Fraction fraction2)
        {
            if (fraction1.Denominator == fraction2.Denominator)
                return new Fraction(fraction1.Numerator + fraction2.Numerator, fraction1.Denominator).Simplified();

            return new Fraction(
                fraction1.Numerator * (long)fraction2.Denominator + fraction2.Numerator * (long)fraction1.Denominator,
                fraction1.Denominator * fraction2.Denominator).Simplified();
        }

        public static Fraction operator -(Fraction fraction1, Fraction fraction2)
        {
            if (fraction1.Denominator == fraction2.Denominator)
                return new Fraction(fraction1.Numerator - fraction2.Numerator, fraction1.Denominator).Simplified();

            return new Fraction(
                fraction1.Numerator * (long)fraction2.Denominator - fraction2.Numerator * (long)fraction1.Denominator,
                fraction1.Denominator * fraction2.Denominator).Simplified();
        }

        public static Fraction operator *(Fraction fraction1, Fraction fraction2)
        {
            return new Fraction(fraction1.Numerator * fraction2.Numerator,
                fraction1.Denominator * fraction2.Denominator).Simplified();
        }

        public static Fraction operator /(Fraction fraction1, Fraction fraction2)
        {
            return new Fraction(fraction1.Numerator * (long)fraction2.Denominator,
                (long)fraction1.Denominator * fraction2.Numerator).Simplified();
        }

        public static bool operator <(Fraction fraction1, Fraction fraction2)
        {
            return fraction1.ToDouble() < fraction2.ToDouble();
        }

        public static bool operator <=(Fraction fraction1, Fraction fraction2)
        {
            return fraction1.ToDouble() <= fraction2.ToDouble();
        }

        public static bool operator >(Fraction fraction1, Fraction fraction2)
        {
            return fraction1.ToDouble() > fraction2.ToDouble();
        }

        public static bool operator >=(Fraction fraction1, Fraction fraction2)
        {
            return fraction1.ToDouble() >= fraction2.ToDouble();
        }

        public static bool operator ==(Fraction fraction1, Fraction fraction2)
        {
            return ReferenceEquals(fraction1, fraction2);
        }

        public static bool operator !=(Fraction fraction1, Fraction fraction2)
        {
            return !(fraction1 == fraction2);
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

        public static implicit operator double(Fraction fraction)
        {
            return fraction.ToDouble();
        }

        public static explicit operator float(Fraction fraction)
        {
            return (float)fraction.ToDouble();
        }

        public static explicit operator string(Fraction fraction)
        {
            return fraction?.ToString();
        }

        public static implicit operator Fraction(double d)
        {
            return FromDouble(d);
        }

        public static explicit operator Fraction(string s)
        {
            return FromString(s);
        }

        #endregion
        
        #region Helpers

        public void Simplify()
        {
            var gcd = GetGreatestCommonDivisor();
            Numerator /= (long)gcd;
            Denominator /= gcd;
        }

        public Fraction Simplified()
        {
            var frac = new Fraction(Numerator, Denominator);
            frac.Simplify();
            return frac;
        }

        public ulong GetGreatestCommonDivisor()
        {
            return MathHelpers.GetGreatestCommonDivisor((ulong)(Numerator < 0 ? Numerator * -1 : Numerator), Denominator);
        }
        
        #endregion

        #region Converters

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
            long denominator = 1;
            for (;d != Math.Round(d); d *= 2, denominator *= 2) { }
            return new Fraction((int)d, denominator).Simplified();
        }

        public static Fraction FromDoubleOld(double d)
        {
            var full = (int)d;
            var part = d - full;
            var tmp = part;
            var i = 1;
            for (; tmp != Math.Round(tmp); i++) tmp += part;
            return new Fraction((int)tmp + i * full, i).Simplified();
        }

        public static Fraction FromString(string s)
        {
            var values = s.Split('/');
            if (values.Length != 2) throw new InvalidCastException();
            return new Fraction(Convert.ToInt64(values[0]), Convert.ToInt64(values[1]));
        }

        #endregion
    }
}