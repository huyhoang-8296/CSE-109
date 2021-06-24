// Class
#include <string>
using namespace std;

class Fraction{
	private:
		int numerator;
		int denominator;

	public:
		// Default contructor
		Fraction();
		// Constructor
		Fraction(int numerator, int denominator);
		// Getter
		
		int getNumerator();
		int getDenominator();
		string toString();
		
		void reduce();
		Fraction operator+(Fraction f);
		Fraction operator-(Fraction f);
		Fraction operator*(Fraction f);
		Fraction operator/(Fraction f);
		bool operator==(Fraction f);
		bool operator!=(Fraction f);
		bool operator<(Fraction f);
		bool operator<=(Fraction f);
		bool operator>(Fraction f);
		bool operator>=(Fraction f);
		

		void setNumerator(int x);
		void setDenominator(int y);
};
int gcd(int a, int b);
ostream& operator<<(ostream &write, Fraction s);
istream& operator>>(istream &read, Fraction &s);