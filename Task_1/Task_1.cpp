// Homework 9. Task 1

#include <iostream>

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
	bool operator==(Fraction fraction) { return ((this->numerator_ * fraction.denominator_) == (this->denominator_ * fraction.numerator_)); }
	bool operator!=(Fraction fraction) { return !(*this == fraction); }
	bool operator<(Fraction fraction) { return ((this->numerator_ * fraction.denominator_) < (this->denominator_ * fraction.numerator_)); }
	bool operator>(Fraction fraction) { return fraction < *this; }
	bool operator<=(Fraction fraction) { return !(*this > fraction); }
	bool operator>=(Fraction fraction) { return !(*this < fraction); }
};

int main(int argc, char** argv)
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}