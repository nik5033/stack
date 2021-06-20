#include "Number.h"
#include <iostream>

using namespace std;

class Complex :public Number<double>
{
private:
	double Im;
public:
	void Set(double num, double Im);
	double Get_Real();
	double Get_Im();
	void Show_Num() override;
};

void Complex:: Set(double num, double Im)
{
	this->num = num;
	this->Im = Im;
	mod = sqrt(num*num + Im * Im);
}
double Complex::Get_Real()
{
	return num;
}
double Complex::Get_Im()
{
	return Im;
}
void Complex::Show_Num() 
{
	cout << num << '+' << Im << 'i' << " ";
}