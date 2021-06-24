#include <string>
using namespace std;

class Complex{
	private:
		double real;
		double img;

	public:
		Complex();
		Complex(double real, double img);

		double getReal();
		double getImg();
		string toString();

		void setReal(double x);
		void setImg(double y);

		Complex operator+(Complex s);
		Complex operator-(Complex s);
		Complex operator*(Complex s);

		bool operator==(Complex s);
		bool operator!=(Complex s);
		
};

ostream& operator<<(ostream &write, Complex s);
istream& operator>>(istream &read, Complex &s);