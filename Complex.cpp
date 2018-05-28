#include <stdio.h>
#include <conio.h>
#include <math.h>

class Complex
{
	friend void SetComplex(Complex *pComp, double r, double i);
	friend void Input(Complex &a);
	friend void Output(Complex &a);

public:
	// Construction/destruction
	Complex(void) { re = 0; im = 0; };
	Complex(double r, double i) { re = r; im = i; };
	~Complex(void) { re = 0; im = 0; };

	// Operators
	inline Complex operator-(void) const { return Complex(-re, -im); }
	inline int operator==(const Complex &z) const { return (z.re == re && z.im == im); }
	inline int operator!=(const Complex &z) const { return (z.re != re || z.im != im); }
	 Complex operator+(const Complex &z) const { return Complex(re + z.re, im + z.im); }
	 Complex operator-(const Complex &z) const { return Complex(re - z.re, im - z.im); }
	 Complex operator*(const Complex &z) const { return Complex(re*z.re, im*z.im); }
	 Complex operator/(const Complex &z) const { return Complex(re / z.re, im / z.im); }
	 Complex operator+(double fl) const { return Complex(re + fl, im); }
	 Complex operator-(double fl) const { return Complex(re - fl, im); }
	 Complex operator*(double fl) const { return Complex(re*fl, im*fl); }
	 Complex operator/(double fl) const { return Complex(re / fl, im / fl); }
	 Complex operator^(double p) const { return Complex(pow(re, p), pow(im, p)); }

	// Methods
	void Set(double r, double i);
	void Set(Complex &a);
	double GetRe(void) { return re; }
	double GetIm(void) { return im; }

private:
	// Members
	double re;
	double im;
};

void Complex::Set(double r, double i)
{
	re = r;
	im = i;
}

void Complex::Set(Complex &a)
{
	re = a.re;
	im = a.im;
}

void SetComplex(Complex *pComp, double r, double i)
{
	pComp->re = r;
	pComp->im = i;
}

void Input(Complex &a)
{
	printf("Enter Re Im: ");
	scanf_s("%lf %lf", &a.re, &a.im);
}

void Output(Complex &a)
{
	printf("%lf %lf\n", a.re, a.im);
}


int main(void)
{
	Complex z1 = Complex();
	Complex z2(1, 2);
	printf("Re=1  Im=2\n");
	Output(z2);
	z2 = (z2 * 2) + (z2 + 1)*exp(5);
	printf("Result Re=1 and Im=2\n");
	Output(z2);
	Input(z1);
	printf("Result \n");
	z2 = (z1 * 2) + (z1 + 1)*exp(5);
	Output(z2);
	SetComplex(&z1, 1, 2);
	Output(z1);
	printf(" -------------\n");
	z1.Set(1, 2);
	z2 = (z1 * 2) + (z1 + 1)*exp(5);
	Output(z2);
	_getch();
}