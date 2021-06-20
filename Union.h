#include "Complex.h"

class Union
{
private:
	Number<double> type1;
	Number<int> type2;
	Complex type3;
	int flag;
public:
	void Enter();
	double Module();
	Number <double> Get1();
	Number <int> Get2();
	Complex Get3();
	int Get_Flag();
	void operator=(Union &other);
	bool operator==(Union other);
	void Set(Number<double> type);
	void Set(Number<int> type);
	void Set(Complex type);
	void Show();
};
