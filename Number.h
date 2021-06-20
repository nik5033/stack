#include<iostream>

using namespace std;

template <typename T>
class Number
{
protected:
	T num;
	double mod;
public:
	virtual void Set(T num)
	{
		this->num = num;
		mod = num;
	}
	virtual T Get_Real()
	{
		return num;
	}
	virtual void Show_Num()
	{
		cout << num << " ";
	}
	virtual double Get_Module()
	{
		return mod;
	}
};
