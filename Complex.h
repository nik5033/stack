#include "Number.h"

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
