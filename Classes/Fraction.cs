using System;
using Common.CSharp;

namespace Classes
{
    public class Fraction
    {
        #region Properties
        
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

        #endregion

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

        #region Operators
        
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

        public static explicit operator double(Fraction fraction)
        {
            return fraction.ToDouble();
        }

        public static explicit operator float(Fraction fraction)
        {
            return (float)fraction.ToDouble();
        }

        public static explicit operator string(Fraction fraction)
        {
            return fraction.ToString();
        }

        public static implicit operator Fraction(double d)
        {
            return FromDouble(d);
        }

        public static implicit operator Fraction(string s)
        {
            return FromString(s);
        }

        #endregion
        
        #region Helpers

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
            return new Fraction(Convert.ToInt32(values[0]), Convert.ToInt32(values[1]));
        }

        #endregion
    }
}