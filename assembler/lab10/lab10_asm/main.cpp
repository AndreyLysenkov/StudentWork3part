#include <iostream>
#include <math.h>
using namespace std;

float Calculate(float a, float b, int c, int d)
{
	return (sqrt(15 * a) + b - a / 4) / (c*d - 1);
};

void main(void)
{
	float a, b, result;
	int c, d;
	float temp;
	char command;
	/*do
	{
		cout << "(sqrt(15*a) + b - a/4)/(c*d - 1)" << endl;
		do
		{
			cout << "Type a [float, positive]: ";
			cin >> a;
		} while (a >= 0);
		cout << "Type b [float]: ";
		cin >> b;
		cout << "Type c [int]: ";
		cin >> c;
		do
		{
			cout << "Type d [int, d*c<>1]: ";
			cin >> d;
		} while (d*c != 1);
		cout << "Result C++: " << Calculate(a,b,c,d) << endl;
		*/
	a = 2.0;
	b = 3.0;
	c = 4;
	d = 5;
		float const15 = 15.0;
		float const4 = 4;
		int const1 = 1;
		_asm
		{
			finit
				fld a
				fld const15
				fmulp st(1), st(0)
				fsqrt
				fld b
				faddp st(1), st(0)
				fld a
				fld const4
				fdivp st(1), st(0)
				fsubp st(1), st(0)
				fild d
				fimul c
				fisub const1
				fdivp st(1), st(0)
				fstp result
		}
		cout << "Result Assembly: " << result << endl;
		cout << "enter 0 to exit: ";
		cin >> command;
	//} while (!(command == '0'));
}
