// Homework 9. Task 2

#include <iostream>
#include <clocale>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	Fraction reduceFraction() 
	{
		int tmp1 = denominator_;
		int tmp2 = numerator_;
		while (true)
		{
			int remDiv  = tmp1 % tmp2;
			if ( remDiv == 0)
			{
				if (numerator_ > 0)
				{
					return Fraction((numerator_ / tmp2), (denominator_ / tmp2));
				}
				return Fraction((-numerator_ / tmp2), (-denominator_ / tmp2));
			}
			tmp1 = tmp2;
			tmp2 = remDiv;
		}
	}
	Fraction operator+(Fraction fraction)
	{ 
		int out_numerator = this->numerator_ * fraction.denominator_ + this->denominator_ * fraction.numerator_;
		int out_denominator = this->denominator_ * fraction.denominator_;
		return Fraction(out_numerator, out_denominator); 
	}
	Fraction operator-(Fraction fraction)
	{
		int out_numerator = this->numerator_ * fraction.denominator_ - this->denominator_ * fraction.numerator_;
		int out_denominator = this->denominator_ * fraction.denominator_;
		return Fraction(out_numerator, out_denominator);
	}
	Fraction operator*(Fraction fraction)
	{
		int out_numerator = this->numerator_ * fraction.numerator_;
		int out_denominator = this->denominator_ * fraction.denominator_;
		return Fraction(out_numerator, out_denominator);
	}
	Fraction operator/(Fraction fraction)
	{
		int out_numerator = this->numerator_ * fraction.denominator_;
		int out_denominator = this->denominator_ * fraction.numerator_;
		return Fraction(out_numerator, out_denominator);
	}
	Fraction& operator++()
	{ 
		numerator_ += denominator_;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction tmp = *this;
		++(*this);
		return tmp;
	}
	Fraction& operator--()
	{
		numerator_ -= denominator_;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction tmp = *this;
		--(*this);
		return tmp;
	}
	Fraction operator-() 
	{ 
		numerator_ = -numerator_;
		return *this; 
	}
	int getNumerator() { return numerator_; }
	int getDenominator() { return denominator_; }
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	int numenator = 0;
	int denominator = 0;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numenator;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator;
	Fraction f1(numenator, denominator);
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numenator;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator;
	Fraction f2(numenator, denominator);
	
	Fraction f3 = (f1 + f2).reduceFraction();
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " + " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << f3.getNumerator() << "/" << f3.getDenominator() << '\n';
	
	f3 = (f1 - f2).reduceFraction();
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " - " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << f3.getNumerator() << "/" << f3.getDenominator() << '\n';
	
	f3 = (f1 * f2).reduceFraction();
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " * " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << (f1 * f2).getNumerator() << "/" << (f1 * f2).getDenominator() << '\n';

	f3 = (f1 / f2).reduceFraction();
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " / " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << (f1 / f2).getNumerator() << "/" << (f1 / f2).getDenominator() << '\n';
	
	std::cout << "++" << f1.getNumerator() << "/" << f1.getDenominator() << " * " << f2.getNumerator() << "/" << f2.getDenominator() << " = ";
	f3 = (++f1 * f2).reduceFraction();
	std::cout << f3.getNumerator() << "/" << f3.getDenominator() << '\n';
	std::cout << "Значение дроби 1 = " << f1.getNumerator() << "/" << f1.getDenominator() << '\n';
	
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << "--" " * " << f2.getNumerator() << "/" << f2.getDenominator() << " = ";
	f3 = (f1-- * f2).reduceFraction();
	std::cout << f3.getNumerator() << "/" << f3.getDenominator() << '\n';
	std::cout << "Значение дроби 1 = " << f1.getNumerator() << "/" << f1.getDenominator() << '\n';

	//f3 = -f1;
	//std::cout << f3.getNumerator() << "/" << f3.getDenominator() << '\n';
	
	//auto f4 = f1++;
	//std::cout << f1.getNumerator() << "/" << f1.getDenominator() << '\n';
	//std::cout << f4.getNumerator() << "/" << f4.getDenominator() << '\n';

	//auto f4 = ++f1;
	//std::cout << f1.getNumerator() << "/" << f1.getDenominator() << '\n';
	//std::cout << f4.getNumerator() << "/" << f4.getDenominator() << '\n';
	
	return 0;
}